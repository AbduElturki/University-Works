#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

typedef struct Tree{
  char Name[20];
  char Number[20];
  struct Tree *leftbranch;
  struct Tree *rightbranch;
} tree;

tree *MakeNode(char Name[20],char Number[20]);

tree *insert(tree *root,tree *new_node);

void search(tree *root, char *name);
