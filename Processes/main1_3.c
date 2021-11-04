#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/types.h>

/*
	output on terminal when typing grep -a myDeamon /var/log/syslog is:
	date and computer name myDeamon[deamon 'pid']: Daemon Started
	date and computer name myDeamon[deamon 'pid']: doing some work
	date and computer name myDeamon[deamon 'pid']: Daemon Finished
*/

int main(){
    pid_t pid = fork();

    if(pid == 0){
        chdir("/");
        setsid;

        printf("start my deamon");

        close(stdout);
        close(stdin);
        close(stderr);

        openlog("myDeamon",LOG_PID,LOG_DAEMON);
        syslog(LOG_NOTICE,"Daemon Started");
        usleep(1000000);
        syslog(LOG_NOTICE,"doing some work...");
        usleep(3000000);
        syslog(LOG_NOTICE,"Daemon Finished");

    }else{
        printf("daemon pid: %d\n",pid);
    }
    return 0;
}
