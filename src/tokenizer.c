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
  if(!word){
    return NULL;
  }
  while(*word){
    if(space_char(*word)){
      return word;
    }
    word++;
  }
  return word;
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
    }
    ++str;
  }
  return count;
}

char *copy_str(char *inStr, short len){
  int i;
  char *copy = (char*) malloc((len+1) *sizeof(char));
  while(i < len){
    copy[i] = inStr[i];
    i++;
  }
  copy[i] = '\0';
  return copy;
}

char **tokenize(char* str){
  int i = 0;
  int numWords = count_words(str);
  char **tokens = malloc((numWords + 1) *sizeof(char*));
  char *start = str;
  char *end = str;
  while(i < numWords){
    start = word_start(end);
    end = word_terminator(start);
    tokens[i] = copy_str(start, (end - start));
    i++;
  }
  tokens[i] = NULL;
  return tokens;
}

void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    printf("tokens[%d] = %s\n", i, tokens[i]);
    i++;
  } 
}

void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  free(tokens[i]);
}
