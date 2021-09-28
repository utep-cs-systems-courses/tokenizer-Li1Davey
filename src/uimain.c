#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  int i = 1;
  int k = 1;
  char userin[100];
  List *history = init_history();
  printf("-------Simple UI-------\n");
  printf("Type anything on the console to have it printed on the console. However, there are special commands\n-Type '!q' to escape the loop\n-Type '!h' to view the strings you've entered\n-Type '!#' (# for any id number from 0 to n) to recall a certain history item.\n");
  while(i == 1){
    putchar('$');
    fgets(userin, 100, stdin);
    
    if(userin[0] == '!' && userin[1] == 'q' &&  userin[2] == '\n'){
      i = 0;
    }
    else if(userin[0] == '!' && userin[1] == 'h' && userin[2] == '\n'){
      printf("***HISTORY***\n");
      print_history(history);
      printf("*************\n");
    }
    else if(userin[0] == '!'){
      int index = atoi(userin + 1);
      printf("***Item***\n[%d] %s\n**********\n", index, get_history(history, index));
    }
    else{
      add_history(history, userin);
      printf("%s", userin);
    }
  }
  printf("-------Tokenizer-------\n");
  
  while(k == 1) {
    
    printf("Type anything on the console for the string to be analyze. However, there are special commands\n-Type '!q' to escape loop\n-Type '!h' to view the strings you've entered\n-Type '!#' (# for any id number from 0 to n) to recall a certain history item\n");
    fgets(userin, 100, stdin);

    if(userin[0] == '!' && userin[1] == 'q' &&  userin[2] == '\n'){
      k = 0;
    }
    else if(userin[0] == '!' && userin[1] == 'h' && userin[2] == '\n'){
      printf("***HISTORY***\n");
      print_history(history);
      printf("*************");
    }
    else if(userin[0] == '!'){
      int index = atoi(userin + 1);
      printf("***Item***\n[%d] %s\n**********\n", index, get_history(history, index));
    }
    else{
      add_history(history, userin);
      printf("Original string is:%s", userin);
      printf("Start of Word is:%s", word_start(userin));
      printf("End of Word after h:%s", word_terminator(word_start(userin)));
      printf("Number of words is: %d\n", count_words(userin));
      char **tokens = tokenize(userin);
      printf("Tokens\n");
      print_tokens(tokens);
      printf("-------------\n");
      free_tokens(tokens);
      printf("Tokens freed.\n");
      printf("-------------\n");
    }
  }
  
  print_history(history);
  free_history(history);
  
  return 0;
}
  
