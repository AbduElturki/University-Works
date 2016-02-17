#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <strings.h>


  //-----------//
 // Structure //
//-----------//

typedef struct List {
  struct List *next;
  char word[20];
  int count;
  int steps;
} list;


  //---------------//
 // Read Function //
//---------------//

void read(FILE* book, char word[20]) {
  char character;
  if(fscanf(book,"%c",&character) != EOF){
    char omitted[]=". ,;:*!?()-\n\0\r" ;
    int i = 0;
    while (strchr(omitted,character)==0){
      word[i]=character;
  	  i++;
  	  if(fscanf(book,"%c",&character)==EOF){
        break;
      }
    }
      word[i]='\0';
  }
  else {strcpy(word,"EOF");}
}


  //-------------------------------------------//
 // Function to find a Bucket value of a word //
//-------------------------------------------//

int Find_Bucket(char *str){
  long hash = 5381;
  int c;

  //turn the input to lowercase.
  for(int i = 0; str[i]; i++){
    str[i] = tolower(str[i]);
  }

  //Find the bucket value of the input
  while (c = *str++){
    hash =( ((hash << 5) + hash) + c)%8000;
  }

  return hash;
}


  //------------------------------------//
 // Insert a node to the list Function //
//------------------------------------//

list *insert_list(list* head, char word[]){

  //Reserve memory for the new inserted Node, and set its count to 1.
  list* new = malloc(sizeof(list));
  new->count=1;

  //Copy the word over to the Node, and set the new node as head.
  strcpy(new->word,word);
  new->next = head;
  head = new;
  return head;
}


  //-------------------------//
 // Find a Node in the list //
//-------------------------//

list *FindinList(list *head,char word[20]){
  int comparisons = 0;

  //While loop that stops at the end of list
  while(head != NULL){

    //If the word found, return it with number of comparisons
    if(strcasecmp(word, head->word)==0){
      head->steps = comparisons;
      return head;
    }

    //If the word not found, increase number of comparisons by 1 and move on to the next node.
    comparisons++;
    head = head->next;
  }
  //If the node was not found, return NULL.
  return NULL;
}


  //-----------------------------------------------//
 // Read and Insert/Create a Linked List Function //
//-----------------------------------------------//

list *ReadAndInsertList(list *head, FILE* book){
  int word_count = 0;
  char word[20];
  read(book, word);

  //While loop that stops at the end of file.
  while(strcmp(word,"EOF") != 0){
    list *duplicate = FindinList(head,word);

    //duplicate found increase count by one
    if(duplicate != NULL) {
      duplicate->count++;
    }

    //there isn't a duplicate, insert it to the list.
    else {
      head = insert_list(head,word);
    }

   //Increase the word count and proceed to read the next word.
    word_count++;
    read(book, word);
  }
  printf("Number of words read/registered: %d\n", word_count);
  return head;
}


  //----------------------------------------------//
 // Read and Insert/Create a Hash Table Function //
//----------------------------------------------//

list *ReadAndInsertTable(list *table[], FILE* book){
  int word_count = 0;
  char word[20];
  read(book, word);

  //While loop that stops at the end of file.
  while(strcmp(word,"EOF") != 0){
    int bucket_value = Find_Bucket(word);
    list *duplicate = FindinList(table[bucket_value],word);

    //duplicate found increase count by one
    if(duplicate != NULL) {
      duplicate->count++;
    }

    //there isn't a duplicate, insert it to the list.
    else {
      table[bucket_value] = insert_list(table[bucket_value],word);
    }

    //Increase the word count and proceed to read the next word.
    word_count++;
    read(book, word);
  }
  printf("Number of words read/registered: %d\n", word_count);
}


  //----------------------------//
 // Find a Node in Hash Table //
//--------------------------//

list *FindinHash(list *table[],char word[20]){
  int bucket_value = Find_Bucket(word);
  return FindinList(table[bucket_value],word);
}


  //-----------------------//
 // Counts Empty Indexes //
//---------------------//

int EmptyIndexes(list *table[8000]) {
  int Empty = 0;
  int bucket = 0;

  //loop that stops at the bottom of the table.
  while(bucket != 8000){

    //if Index is empty, increase Empty value by 1.
    if(table[bucket] == NULL){
      Empty++;
    }

    //Increase the bucket value by 1.
    bucket++;
  }

  //return the empty value after the loop is done.
  return Empty;
}


  //-------------------------------------//
 // Hash table Percentage used Function //
//-------------------------------------//

double percentage_used(int EmptyIndexes){
  double d_EI = EmptyIndexes; //convert to double
  return ((8000-d_EI)/8000)*100; //calculate
}

  //-----------------------//
 // List lenght Function //
//---------------------//

int LengthList(list *head){
  int count = 0;

  //Loop untill the end of Linked List and increase the count by 1.
  while(head != NULL){
    head = head->next;
    count++;
  }

  //After the loop is done return the count.
  return count;
}


  //-----------------//
 // Quary Function //
//---------------//

void quary(list *table[],list *head){
  char input[20];
  printf("Enter word for retrieval: ");
  scanf("%s", input);

  //Try to find the node.
  list *locationByList;
  list *locationByTable;
  locationByList = FindinList(head,input);
  locationByTable = FindinHash(table,input);

  //if node wasn't found.
  if(locationByTable == NULL) {
      printf("The word '%s' was not found\n\n\n", input);
  }

  //if node was found.
  else {
    printf("the word '%s' occurs %d times. (using list)\n",input,locationByList->count);
    printf("Number of comparisons %d\n", locationByList->steps);
    printf("the word '%s' occurs %d times. (using table)\n",input,locationByTable->count);
    printf("Number of comparisons %d\n\n\n", locationByTable->steps);
  }

  //Asks for another query.
  printf("Another query? [y] to continue, else to quit: ");
  scanf("%s", input);

  //If yes calls it self again
  if(strcasecmp(input,"y") == 0) {
    quary(table, head);
  }
}


  //------//
 // MAIN //
//------//

int main(int argc,char *argv[]) {
  list *HashTable[8000] = { NULL };
  list *head=NULL;

  //Creating a Hash Table, and Timing it.
  printf("\n\nCreating a hash table...\n");
  FILE *book=fopen(argv[1],"r");
  clock_t start=clock();
  HashTable[8000] = ReadAndInsertTable(HashTable,book);
  clock_t stop =clock();
  fclose(book);
  printf("The hash table has been created.\n");
  double time_taken=(double)(stop-start)/CLOCKS_PER_SEC;
  printf("Reading into table took:  %f seconds.\n",time_taken);
  printf("Number of empty indexes: %d\n", EmptyIndexes(HashTable));
  printf("Hash table size: 8000\n");
  printf("Percentage used %f%%\n\n\n", percentage_used(EmptyIndexes(HashTable)));

  //Creating a Linked List, and Timing it.
  printf("Creating a linked list...\n");
  book=fopen(argv[1],"r");
  start=clock();
  head = ReadAndInsertList(head,book);
  stop =clock();
  fclose(book);
  printf("The linked list has been created.\n");
  time_taken=(double)(stop-start)/CLOCKS_PER_SEC;
  printf("Reading into list took:   %f seconds.\n",time_taken);
  printf("The lenght of the list is: %d\n\n\n", LengthList(head));

  //Starts the quary.
  quary(HashTable,head);

  return 0;
}
