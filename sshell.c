//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define MAX_LINE 80

int main (void) {
   char args[MAX_LINE/2+1];
   int should_run =1;
   pid_t pid;
   char input[MAX_LINE/2+1];
   int n;
   char delim[] = " ";
   //stdin

   // printf("%s\n", input);
   char parts[MAX_LINE/2+1];


   printf("osh>");
   fflush(stdout);
   scanf("%[^\n]s",args);
   strcpy(input,args);


   // char *ptr = strtok(input, delim);
   // ptr= strtok(NULL,delim);
   // parts[0] = ptr;
   // //input[0] = parts[0];
   // strcpy(input[0],ptr);
   printf("%c\n",input[0]);
   int count=0;
   for(int i=0; i<(MAX_LINE/2+1); i++){
     if(strcmp(input[i], " ")!=0){
       //args[count]=strcat(input[i],args[count]);
     /*}
     else{
       count++;
     }*/

   }
   //execvp(input[0],input);

   // while(should_run){
   //   printf("osh>");
   //   fflush(stdout);
   //   scanf("%[^\n]s",args);
   //   printf("%s\n",args);
   //   pid = fork();
   //   if(pid<0){
   //     printf("forking error :()");
   //     return -1;
   //   }
   //   else if(pid==1){
   //     execvp(args[0], args);
   //     n=5;
   //   }
   //   else{
   //     printf("this is the parent");
   //     n=3;
   //   }
   //
   // }



   return 0;
}
