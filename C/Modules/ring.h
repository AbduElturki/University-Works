#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Ring ring;

ring *MakeNewRing();

struct Ring *Forward(struct Ring *Ring);

struct Ring *Backward(struct Ring *Ring);

ring *ChangeCurrent(ring *Ring, int data);

ring *AddAfter(ring *Ring, int new_data);

ring *AddBefore(ring *Ring, int new_data);

ring *DeleteCurrent(struct Ring *Ring);

void ReturnCurrent(ring *Ring);

ring *GoToFirst(struct Ring *Ring);

ring *GoToLast(struct Ring *Ring);

ring *MergeNext(struct Ring *Ring);

ring *MergeBefore(struct Ring *Ring);

void DrawRing(ring *Ring);
