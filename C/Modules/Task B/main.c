#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void quary(tree *root){
  tree *newtree;
  int choice;
  char Search[20];
  char Name[20];
  char Number[20];

  printf("\n[1] Add new contact\n");
  printf("[2] Search for contact\n");
  printf("[3] Exit.\n");
  printf("Choice: ");
  scanf("%d", &choice);

  if(choice == 1){
    printf("Please enter the new contact's Name: ");
    scanf("%s",Name);
    printf("Please enter the new contact's Number: ");
    scanf("%s",Number);
    printf("Saving the new contact...\n");
    newtree = MakeNode(Name,Number);

    if(root == NULL){
      root = newtree;
    }
    else{
      root = insert(root, newtree);
    }
    printf("Contact saved!\n\n");
  }
  if(choice == 2){
    printf("\nEnter the name to search for: ");
    scanf("%s", Search);
    search(root, Search);
    }
  if(choice == 3){
    printf("Thank you for using the phonebook app.\n");
    exit(0);
  }
  quary(root);
}

int main(){
  printf("Welcome to phone book app.\n");
  printf("Please input one of the following choices.\n");
  tree *root = NULL;
  quary(root);
}
