#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX=10 };

typedef char colony[MAX][MAX];


void readline(int n, char line[n]) {
  fflush(stdout);
  fgets(line, n, stdin);
  line[strcspn(line, "\r\n")] = '\0';
}

void readColony(colony col) {
  for (int i=0; ! feof(stdin); i++) {
      readline(MAX, col[i]);
      if (feof(stdin)) strcpy(col[i], "");
  }
}

void print(colony col) {
    for (int i=0; strlen(col[i]) != 0; i++) {
        printf("%s\n", col[i]);
    }
}

int count_alive(colony col, int x, int y){
  int count = 0;
  if(col[x+1][y] == '#') count++;
  if(col[x-1][y] == '#') count++;
  if(col[x][y+1] == '#') count++;
  if(col[x][y-1] == '#') count++;
  if(col[x+1][y+1] == '#') count++;
  if(col[x-1][y-1] == '#') count++;
  if(col[x+1][y-1] == '#') count++;
  if(col[x-1][y+1] == '#') count++;
  return count;
}

void evolve(colony col){
  int i, j, alive;
  colony new;
  int input;
  int repeats;
  printf("\nHow many ticks you would like to see?: ");
  scanf("%d", &input);
  if(input == 0) print(col);
  else while(repeats != input){
    for (i = 0; i < MAX; i++){
      if(col[i][0] == '\0') break;
      for (j = 0; j < MAX; j++){
        alive = count_alive(col,i,j);
        if (col[i][j] == '\0') break;
        if (col[i][j] == '#'){
          if ((alive > 3) || (alive <2))
            new[i][j] = '.';
          else
            new[i][j] = '#';
        }
        else if (col[i][j] == '.'){
          if (alive == 3)
            new[i][j] = '#';
          else
            new[i][j] = '.';
        }
      }
      new[i][j] = '\0';
    }
    new[i][0] = '\0';
    memcpy(col,new,sizeof(colony));
    printf("\n");
    print(col);
    printf("\n");
    repeats++;
  }
}

int main(int n, char *args[n]) {
  colony col;
  readColony(col);
  evolve(col);
  return 0;
}
