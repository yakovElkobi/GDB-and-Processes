#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

/*
	output on terminal when typing pstree 'pid' is:
	bash───main1_4─┬─main1_1───main1_1───main1_1
               ├─3*[main1_2]
               └─main1_3
*/
char *args[] = {NULL};

int main() {
    printf("Main id is: %d\n",getpid());
    pid_t process = fork();
    if (process == 0) {
        printf("main1_1 pid: %d\n", getpid());
        execv("./main1_1", args);
        
    }else{
         process = fork();
        if(process == 0) {
            printf("main1_3 pid: %d\n", getpid());
            execv("./main1_3", args);
        }else {
            process = fork();
            if(process == 0) {
                printf("main1_2 pid: %d\n", getpid());
                execv("./main1_2", args);
            }
        }
    }
    waitpid(process, 0, WUNTRACED);
    return 0;
}
