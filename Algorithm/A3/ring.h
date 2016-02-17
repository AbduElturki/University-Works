#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Ring ring;
typedef struct List list;
ring *MakeNewRing();

ring *ChangeCurrent(ring *Ring, int data);

list *MakeNewNode(int new_data);

ring *AddAfter(ring *Ring, int new_data);

int ReturnCurrent(ring *Ring);
