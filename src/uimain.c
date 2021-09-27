#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  int i = 1;
  int j = 1;
  int k = 1;
  int count = 0;
  char userin[100];
  List *history = init_history();
 
  printf("Type anything on the console to have it printed on the console. type 'q' to escape the loop.\n");
  while(i == 1){
    putchar('$');
    fgets(userin, 100, stdin);
    add_history(history, userin);
    printf("%s\n", userin);
    count++;
    if(userin[0] == 'q' &&  userin[1] == '\n'){
      i = 0;
    }
  }
  printf("History (Backwards)\n");
  while(count > 0){
    printf("[%d] %s\n", count - 1, get_history(history, count - 1));
    count--;
  }
  
  while(k == 1) {
    int l = 1;
    printf("Type anything on the console for the string to be analyze.\n");
    fgets(userin, 100, stdin);
    add_history(history, userin);
    printf("Original string is:%s\n", userin);
    printf("Start of Word is:%s\n", word_start(userin));
    printf("End of Word after h:%s\n", word_terminator(word_start(userin)));
    printf("Number of words is: %d\n", count_words(userin));
    char **tokens = tokenize(userin);
    print_tokens(tokens);
    free_tokens(tokens);
    printf("Tokens freed.\n");
    printf("Would you like to analyze another string? 'y' or 'n'.\n");
    while(l == 1){
      fgets(userin, 100, stdin);
      if(userin[0] == 'n' && userin[1] == '\n'){
	l = 0;
	k = 0;
      }
      else if(userin[0] == 'y' && userin[1] == '\n'){
	l = 0;
	  }
      else{
	printf("Incorrect Input, please try again.\n");
      }
    }
  }

  printf("\n");
  print_history(history);
  free_history(history);
  
  return 0;
}
  
