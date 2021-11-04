#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 1000
char child_stack[STACK_SIZE+1];

/*
	output on terminal when typing pstree 'pid' is:
	bash───3*[main1_2]
*/

void print(const char* text){
    for (int i = 0; i < 20; i++){
        printf("Hello from %s\n",text);
        usleep(1000000);
    }
}

int first_child(void* params){
    print("first child");
}
int second_child(void* params){
    print("second child");
}

int main(){
    pid_t pid1;
    pid_t pid2;
    pid1 = clone(first_child,child_stack+STACK_SIZE,CLONE_PARENT,0);
    pid2 = clone(second_child,child_stack+STACK_SIZE,CLONE_PARENT,0);

    printf("clone result = %d\n",pid1);
    printf("clone result = %d\n",pid2);

    print("parent");

    return 0;
}
