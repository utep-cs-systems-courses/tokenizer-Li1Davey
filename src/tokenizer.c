#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c){
  if(c == '\t' || c == ' ' || c == '\n'){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c == '\t' || c == ' ' || c == '\n'){
    return 0;
  }
  return 1;
}


char *word_start(char *str){
  while(*str){
    if(non_space_char(*str)){
      return str;
    }
    str++;
  }   
  return NULL;
}


char *word_terminator(char *word){
  word = word_start(word);
  while(*word){
    if(space_char(*word)){
      return word;
    }
    word++;
  }
  return NULL;
}

int count_words(char *str){
  int word = 0;
  int count = 0;
  while(*str){
    if (space_char(*str)){
      word = 0;
    }
    else if (!word){
      word = 1;
      ++count;
      printf("%s,\n", str);
    }
    ++str;
  }
  return count;
}

char *copy_str(char *inStr, short len){
  int i;
  char *copy = (char*) malloc((len+1) *sizeof(char));
  if(len > sizeof(inStr)){
    printf("Length is larger then the String size.\n");
    return NULL;
  }
  else if(copy != NULL){
    while(i < len){
      copy[i] = inStr[i];
      i++;
    }
    copy[i] = '\0';
    return copy;
  }
  return NULL;
}

