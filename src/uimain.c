#include <stdlib.h>
#include <stdio.h>

int main()
{
  int i =  1;
  char userin[100];
  while(i == 1){
    putchar('$');
    fgets(userin, 100, stdin);
    printf("%s\n", userin);
  }
  return 0;
}
  
