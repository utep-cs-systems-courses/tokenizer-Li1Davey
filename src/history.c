#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *history = (List*)malloc(sizeof(List));
  return history;
}

void add_history(List *list, char *str){
  int idHis = 0;
  int length;
  Item *addition = (Item*)malloc(sizeof(Item));
  while(str[length] != '\0'){
    length++;
  }
  char *copy = copy_str(str, length - 1);
  addition->str = copy;

  if(list->root == NULL){
    addition->id = 0;
    list->root = addition;
  }
  else{
    Item *traverse = list->root;
    idHis++;
    while(traverse != NULL){
      if(traverse->next == NULL){
	addition->id = idHis;
	traverse->next = addition;
	break;
      }
      traverse = traverse->next;
      idHis++;
    }
    
  }
  
}

char *get_history(List *list, int id){
  Item * traverse = list->root;
  while(traverse != NULL){
    if(traverse->id == id){
      return traverse->str;
    }
    traverse = traverse->next;
  }
  return NULL;
}

void print_history(List *list){
  Item *traverse = list->root;
  while(traverse != NULL){ 
    printf("[%d] %s \n", traverse->id, traverse->str);
    traverse = traverse->next;
  }
}

void free_history(List *list){
  Item *traverse = list->root;
  Item *nextItem;
  while(traverse != NULL){
    nextItem = traverse->next;
    free(traverse->str);
    free(traverse);
    traverse = nextItem;
  }
  free(list);
}
