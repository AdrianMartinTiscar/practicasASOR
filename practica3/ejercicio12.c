#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sched.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>

volatile int countint = 0;
volatile int counttstp = 0;

void hler(int senial){
    if (senial == SIGINT) countint++;
    if (senial == SIGTSTP) counttstp++;
}

int main(int argc, char **argv){
    struct sigaction sig;
    sigaction(SIGINT, NULL, &sig);
    sig.sa_handler = hler;
    sigaction(SIGINT, &sig, NULL);
    sigaction(SIGTSTP, NULL, &sig);
    sig.sa_handler = hler;
    sigaction(SIGTSTP, &sig, NULL);

    sigset_t sigset;
    sigemptyset(&sigset);
    while((countint+counttstp) < 10)
	sigsuspend(&sigset);

    printf("Se ha recibido la señal SIGINT %d veces\n",countint);	
    printf("Se ha recibido la señal SIGTSTP %d veces\n",counttstp);
	
    return 0;
}


