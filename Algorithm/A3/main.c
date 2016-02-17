#include "ring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  ring* test = NULL;
  if(test == NULL){
    printf("ring is empty\n");
  }
  else {
   printf("ring is not empty\n");
  }

  test = MakeNewRing();
  if(test == NULL){
    printf("new ring is empty\n");
  }
  else {
   printf("new ring is not empty\n");
  }
  free(test);
}
