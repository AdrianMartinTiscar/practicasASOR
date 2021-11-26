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

volatile int stop = 0;

void hler(int senial){
    if (senial == SIGUSR1) stop = 1;
}

int main(int argc, char **argv){
    if(argc != 2){
	printf("Es necesario especificar el nº de segundos como argumento\n");
	return -1;
    }

    struct sigaction sig;
    sigaction(SIGUSR1, NULL, &sig);
    sig.sa_handler = hler;
    sigaction(SIGUSR1, &sig, NULL);

    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGUSR1);

    int segs = atoi(argv[1]);
    for(int i = 0;i< segs && stop == 0; i++)
	sleep(1);
    if(stop==1)
	printf("Borrado interrumpido\n");
    else{
	unlink(argv[0]);
	printf("Ejecutable borrado\n");
    }
    return 0;
}


