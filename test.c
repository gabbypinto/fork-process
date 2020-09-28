#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define MAX_LINE 80
//int i = 0;
int main(void){
  char *message;
  pid_t pid;
  int count = 0;
  int n;
  int should_run =1;
  char input[MAX_LINE/2+1];
  printf("osh>");
  fflush(stdout);
  scanf("%[^\n]s",input);
  int i =0;
  char delim[] = " ";
  char *parts[MAX_LINE/2+1];
  printf("%s\n", input);

  char *ptr = strtok(input, delim);

  //separates the string

  // while(ptr!=NULL){
  //     printf("%s\n", ptr);
  //     //printf("%d\n", i);  //prints indices
  //     ptr = strtok(NULL, delim);
  //     parts[i] = ptr;
  //     i++;
  // }

  // while(should_run ==1){
    pid = fork();


    if(pid<0){
        printf("Fork error: %d (%s) \n", errno, strerror(errno));
        return -1;
    }
    else if(pid==0){
        message = "This is the child";
        execvp("ls","ls -l");
        n=5;
    }
    else{
       message = "This is the parent";
       n=3;
    }

    for (; n > 0; n--) {
        puts(message);
        sleep(1);
    }
    // printf("osh>");
    // fflush(stdout);
    // sleep(30);
    // scanf("%[^\n]s",input);
    // printf("%s inputer is", input);
    // if (strcmp(input, "exit")==0)
    //   should_run=0;


  //}

  return 0;
}
