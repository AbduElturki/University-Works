#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "map.h"

struct Tree *MakeNode(char Name[20],char Number[20]){
  struct Tree *temp = malloc(sizeof(struct Tree));
  strcpy(temp->Name,Name);
  strcpy(temp->Number,Number);
  temp->leftbranch = NULL;
  temp->rightbranch = NULL;
  return temp;
}

struct Tree *insert(struct Tree *root,struct Tree *new_node){
  if(strcmp(new_node->Name,root->Name) > 0 ){
    if(root->leftbranch == NULL){
      root->leftbranch = new_node;
    }
    else{
      insert(root->leftbranch, new_node);
    }
  }
  else{
    if(root->rightbranch == NULL){
      root->rightbranch = new_node;
    }
    else{
      insert(root->rightbranch, new_node);
    }
  }
  return root;
}

void search(struct Tree *root, char *name){
  struct Tree *temp = malloc(sizeof(struct Tree));
  temp = root;
  bool found = false;

  while (temp != NULL) {
    if (strcmp(temp->Name, name) == 0){
      printf("\nContact found:\nName:%s\nNumber:%s\n",temp->Name,temp->Number);
      found = true;
      break;
    }
    if(strcmp(temp->Name,name) < 0 ){
      temp = temp->leftbranch;
    }
    else{
      temp = temp->rightbranch;
    }
  }
  if(found == false){
    printf("The contact doesn't exisit.\n");
  }

}
