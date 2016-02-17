#include "ring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quary(ring *Ring){
  printf("\n[1] To Add a Node after the current pointer.\n");
  printf("[2] To Add a Node before the current pointer.\n");
  printf("[3] To move current forwards.\n");
  printf("[4] To move current backwards.\n");
  printf("[5] To change the current to the first value.\n");
  printf("[6] To change the current to the last value.\n");
  printf("[7] To delete the current.\n");
  printf("[8] To retrieve the current's value\n");
  printf("[9] To exit.\n");

  int Input;
  printf("Choice: ");
  scanf("%d", &Input);

  if(Input == 1){
    printf("Input for the new value to be added to ring: ");
    scanf("%d", &Input);
    Ring = AddAfter(Ring,Input);
  }
  else if(Input == 2){
    printf("Input for the new value to be added to ring: ");
    scanf("%d", &Input);
    Ring = AddBefore(Ring,Input);
  }
  else if(Input == 3){
    Ring = Forward(Ring);
  }
  else if(Input == 4){
    Ring = Backward(Ring);
  }
  else if(Input == 5){
    Ring = GoToFirst(Ring);
  }
  else if(Input == 6){
    Ring = GoToLast(Ring);
  }
  else if(Input == 7){
    Ring = DeleteCurrent(Ring);
  }
  else if(Input == 8){
    ReturnCurrent(Ring);
  }
  else if(Input == 9){
    exit(0);
  }
  else{
    printf("That's not a valid choice.\n");
  }
  DrawRing(Ring);
  quary(Ring);
}

int main(){
  int Input;
  printf("First input for the ring: ");
  scanf("%d", &Input);

  ring *Ring = AddAfter(MakeNewRing(),Input);
  DrawRing(Ring);

  quary(Ring);
}
