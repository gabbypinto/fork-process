//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define MAX_LINE 80

int main (void) {
   char *args[MAX_LINE/2+1];
   int should_run =1;
   pid_t pid;

   char input[MAX_LINE/2+1];

   //stdin

   printf("Enter a command");
   scanf("%[^\n]s",args);
   //char* input[MAX_LINE/2+1]  = args;
   strcpy(input,args);
   printf("%s\n", input);


   // while(should_run){
   //   printf("osh>");
   //   fflush(stdout);
   //   pid = fork();
   //   if(pid<0){
   //     printf("forking error :()");
   //   }
   //   else if(pid==1){
   //     execelp(
   //   }
   //
   // }



   return 0;
}
