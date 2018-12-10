#include <stdio.h>
#include <stdlib.h>
void toAscii(char*);

int main(int argc, char* argv[]) {
    printf("Enter a word: ");
    char ch;
    char buff[50];
    int count = 0;
    while ((ch = getchar()) != '\n') {
        buff[count] = ch;
        count ++;
    }
    buff[count++] = '\0';
    toAscii(buff);

}
void toAscii(char* buff) { 
   int i =0;
   char ch;
   while (buff[i] != '\0') {
      ch = buff[i];
      printf("%d ", ch);
      i++;
   } 
   printf("\n");
     
} 
