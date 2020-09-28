#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define MAX_LINE 80


void forking(char **args){
  //fork process begins
    pid_t pid;
    int n;
    pid = fork();
    // printf("%s",*args);


    if (pid < 0){
      printf("Fork error: %d (%s) \n", errno, strerror(errno));
      exit(1);
    }
    else if (pid == 0){
      printf("this is the child\n");

      printf("\n");
      printf("%s\n",args[0]);
      printf("%s\n",args[1]);
      if (execvp(args[0],args)<0){
        printf("error didn't execute\n");
        exit(1);
      }
    }
    else{
      printf("This is a parent \n");
      while (wait(NULL) != pid) {/* wait for completion  */
        ;
      }

    }
}

int main(void){
  char *message;
  int count = 0;

  //char *args2[MAX_LINE/2+1];


  int n;
  int should_run =1;


  int i =0;
  char delim[] = " ";
  // char *args[MAX_LINE/2+1];
  // printf("%s\n", input);
  char input[1024];
  char *ptr = strtok(input, delim);
  char *args[MAX_LINE/2+1];



  while(should_run){

      printf("osh> ");
      fflush(stdout);
      gets(input);//fgets***
      // printf("\n");
//change to fgets
      // printf("%s\n", input);


      while(ptr!=NULL){
          args[i] = ptr;
          ptr = strtok(NULL, delim);
          i++;
      }
      // printf("%s\n",args[0]);

      if(strcmp(args[0],"exit") == 0){
        should_run = 0;
      }
      printf("Print before fork\n");
      printf("%s\n",args[0]);
      printf("%s\n",args[1]);
      fflush(stdout);
      forking(args);

      //memset(args,0,sizeof(args));

  }

  return 0;

}
