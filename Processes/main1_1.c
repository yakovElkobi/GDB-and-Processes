#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/*
	output on terminal when typing pstree 'pid' is:
	bash───main1_1───main1_1───main1_1
*/

void print(const char* text){
    for (int i = 0; i < 20; i++){
        printf("Hello from %s\n",text);
        usleep(1000000);
    }
}

int main(){
    /*create child */
    pid_t pid = fork();

    if(pid == 0){
     /*create grandchild */
        pid_t pid_child = fork();
        if(pid_child == 0){
            print("grandchild");
        }else{
            print("child");
        }
    }else{
        print("main process");
    }
    return 0;
}
