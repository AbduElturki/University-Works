#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ring.h"
  //-----------//
 // Structure //
//-----------//

struct List {
  int data;
  struct List *next;
  struct List *prev;
};

struct Ring {
  double data;
  struct List *current;
  struct List *sentinel;
};

struct Ring *MakeNewRing(){
  struct Ring *NewRing = malloc(sizeof(struct Ring));
  struct List *sentinel = malloc(sizeof(struct List));
  NewRing->sentinel = sentinel;
  NewRing->current = sentinel;
  sentinel->next = sentinel;
  sentinel->prev = sentinel;
  return NewRing;
}

struct Ring *Forward(struct Ring *Ring){
  Ring->current = Ring->current->next;
  return Ring;
}

struct Ring *Backward(struct Ring *Ring){
  Ring->current = Ring->current->prev;
  return Ring;
}

struct List *MakeNewNode(int new_data){
  struct List *NewNode = malloc(sizeof(struct List));
  NewNode->data = new_data;
  NewNode->next = NULL;
  NewNode->prev = NULL;
  return NewNode;
}

struct Ring *AddAfter(struct Ring *Ring, int new_data){
  struct List *New_node = malloc(sizeof(struct List));
  New_node = MakeNewNode(new_data);
  struct List *temp = Ring -> current->next;
  New_node->next = Ring->current->next;
  New_node->prev = Ring->current;
  Ring->current->next=New_node;
  temp->prev=New_node;
  return Ring;
}

struct Ring *AddBefore(struct Ring *Ring, int new_data){
  struct List *New_node = malloc(sizeof(struct List));
  New_node = MakeNewNode(new_data);
  struct List *temp = Ring -> current->prev;
  New_node->prev = Ring->current->prev;
  New_node->next = Ring->current;
  Ring->current->prev=New_node;
  temp->next=New_node;
  return Ring;
}

struct Ring *DeleteCurrent(struct Ring *Ring){
  if (Ring->current == Ring->sentinel){
    printf("\nYou can't delete the sentinel\n");
    return Ring;
  }
  else {
    struct List *Del = Ring->current;
    Ring->current = Ring->current->prev;
    Ring->current->next = Del->next;
    Ring->current->next->prev = Ring->current;
    free(Del);
    return Ring;
  }
}

void DrawRing(struct Ring *Ring){
  struct List *temp;
  temp = Ring->current;
  if(Ring->current == Ring->sentinel){
    temp = temp->next;
  }
  if(temp->prev != Ring->sentinel){
    while(temp->prev != Ring->sentinel){
      temp = temp->prev;
    }
  }
  while(temp != Ring->sentinel){
    printf("╔═╗\n");
    printf("║%d║", temp->data);
    if(temp == Ring->current){
      printf("<-- Current\n");
    }
    else printf("\n");
    printf("╚═╝\n");
    temp = temp->next;
  }
  if(Ring->current == Ring->sentinel){
    printf("\nThe current is set to sentinel.\n");
  }
}

struct Ring *GoToFirst(struct Ring *Ring){
  if (Ring->current->prev == Ring->sentinel){
    return Ring;
  }
  while(Ring->current->prev != Ring->sentinel){
    Ring->current = Ring->current->prev;
  }
  return Ring;
}

struct Ring *GoToLast(struct Ring *Ring){
  if (Ring->current->next == Ring->sentinel){
    return Ring;
  }
  while(Ring->current->next != Ring->sentinel){
    Ring->current = Ring->current->next;
  }
  return Ring;
}

void ReturnCurrent(struct Ring *Ring){
  if(Ring->current == Ring->sentinel){
    printf("Error: The current is sentinel.\n");
  }
  else {
    printf("The current's value is %d\n\n", Ring -> current -> data);
  }
}
