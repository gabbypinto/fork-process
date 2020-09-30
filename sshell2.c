#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define MAX_LINE 80

void forking(char **args, int hasAmp){
  //fork process begins
  pid_t pid;
  int n;
  pid = fork();

  if (pid< 0){
    printf("Fork error: %d (%s) \n", errno, strerror(errno));
    exit(1);
  }
  else if (pid == 0){
    if (execvp(args[0],args)<0){
      printf("Error: Command not found\n");
      exit(1);
    }
  }
  else{
    if(hasAmp==0){
      while (wait(&n) != pid) {/* wait for completion  */
        ;
      }
    }
  }
}

int main(void){
  char *args[MAX_LINE/2+1];
  char input[MAX_LINE/2+1];
  int should_run = 1;
  int hasAmp;

  /* allocate buffers */
  while(should_run == 1){
    printf("osh> ");
    fflush(stdout);

    fgets(input, MAX_LINE/2+1, stdin);

    //Removing \n character from end of input
    if(input[strlen(input)-1] == '\n'){
      input[strlen(input)-1] = 0;
    }

    hasAmp=0;
    for(int i=0; i<MAX_LINE/2+1;i++){
      if(input[i] == '&'){
        hasAmp=1;
        i=MAX_LINE/2+1; //break loop
      }
    }


    char *found;
    found = strtok(input," ");
    if(found==NULL){
      puts("\tNo separators found");
      return(1);
    }

    int count=0;
    while(found){
      if(*found=='&'){
        found = strtok(NULL," ");
        count++;
      }
      else{
        args[count]=found;
        found = strtok(NULL," ");
        count++;
      }
    }

    //check if user wants to exit
    if(strcmp(args[0],"exit") == 0){
      printf("Exiting...\n");
      should_run = 0;
    }

    //don't include & in the args
    else{
      forking(args, hasAmp);
    }

    //cleaning out args array
    for(int i=0; i<MAX_LINE/2+1;i++){
      args[i]=NULL;
    }
  }
  return 0;
}
