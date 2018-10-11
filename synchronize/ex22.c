/*Pipes example.  
   The program creates a pipe and two processes.  The parent 
   writes to the write end of the pipe (fildes[1]).  The child
   reads from the read end of the pipe (fildes[0]).  If the child
   runs first, it blocks because the pipe is empty. 
*/ 


#include <unistd.h>
#include <wait.h>
#include <stdio.h>

void child(int []);
void parent(int []);

int main(void)
{ 
  int fildes[2];
  int value;

  pipe(fildes);                        /*create pipe*/
  
  if ( (value = fork()) < 0)
      printf("Child could not be created\n");
  else
    if (value == 0)
        child(fildes);
     else
         parent(fildes);

}

void child(int fildes[])
{
 char buffer[1];
 int i;

 printf("Simcha Announces: ho fame, ho fame, ho fame!!!!!\n"); 
 printf("Simcha Announces: I'm waiting\n\n");
 //blocks waiting for a message
 read(fildes[0], buffer,1);

 printf("Simcha receives a  message from Paul: \n");
 while (1)
  {
    if (buffer[0] == '+')  //end of msg flag
      break;
    printf("%c",buffer[0]);
    read(fildes[0], buffer,1);
  }
 printf("\nSimcha Announces: Mangiato bene!!!!\n");
   
}

void parent(int fildes[])
{
 //+ indicates end of message
 char s1[] = " I hear you, Birdie\n";
 char s2[] = " Simcha, ";
 char s3[] = " Do you want a nut\n+";
 sleep(3);
 
 printf("Paul is sending a message\n\n");
 write(fildes[1], s1, sizeof(s1));
 write(fildes[1], s2, sizeof(s2));
 write(fildes[1], s3, sizeof(s3));
 wait(NULL);
 //sleep(3);
 
 printf("Paul Announces: I'm glad you liked it, Simcha\n");
 
 printf("n");
}     

