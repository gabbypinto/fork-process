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

  if (pid< 0){
    printf("Fork error: %d (%s) \n", errno, strerror(errno));
    exit(1);
  }
  else if (pid == 0){
    printf("this is the child\n");
    printf("\n");
    if (execvp(args[0],args)<0){
      printf("error didn't execute\n");
      exit(1);
    }
  }
  else{
    printf("This is a parent \n");
    while (wait(NULL) != pid) {/* wait for completion  */
      ;
    }
  }
}

int main(void){
  char *args[MAX_LINE/2+1];
  char input[MAX_LINE/2+1];
  int should_run = 1;
  /* allocate buffers */
  while(should_run == 1){
    printf("osh> ");
    fflush(stdout);

    //gets(input);//fgets**
    fgets(input, MAX_LINE/2+1, stdin);

    //parse(input,args);
    char *found;
    found = strtok(input," ");
    if(found==NULL){
      printf("\t'%s'\n",input);
      puts("\tNo separators found");
      return(1);
    }
    int count=0;
    while(found){
      //printf("\t'%s'\n",found);
      args[count]=found;
      found = strtok(NULL," ");
      printf("%s", args[count]);
      count++;
    }
    /*if(strcmp(found[0],"exit") == 0){
            printf("adios...");
            should_run = 0;
          }*/
        //printf("%s", found[0]);
    forking(args);
    should_run=0;
  }
  return 0;
}
