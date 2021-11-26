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

int main(int argc, char **argv){
    char* var;
    int seg;
    var = getenv("SLEEP_SECS");
    if(var == NULL){
	printf("Error con la variable de entorno SLEEP_SECS. Se pondran 20 segundos\n");
	seg = 20;
    } else
    	seg=atoi(var);
    sigset_t sig;
    sigemptyset(&sig);
    sigaddset(&sig, SIGINT);
    sigaddset(&sig, SIGTSTP);

    int block = sigprocmask(SIG_BLOCK, &sig, NULL);
    if(block == -1){
	printf("Error al bloquear las señales\n");
	return -1;
    }
    sleep(seg);

    sigset_t reciv;
    sigpending(&reciv);
    int sigint = sigismember(&reciv, SIGINT);
    if (sigint ==1) {
        printf("Se ha recibido la señal SIGINT\n");
	sigdelset(&sig, SIGINT);
    }else if (sigint ==-1){
	printf("Error con sigint\n");
	return -1;
    }
    int sigtstp = sigismember(&reciv, SIGTSTP);
    if (sigtstp ==1) {
        printf("Se ha recibido la señal SIGTSTP\n");
	sigdelset(&sig, SIGTSTP);
    }else if (sigtstp ==-1){
	printf("Error con sigstp\n");
	return -1;
    }
    int unblock = sigprocmask(SIG_UNBLOCK, &sig, NULL);
    if(unblock == -1){
	printf("Error al desbloquear las señales\n");
	return -1;
    }
    return 0;
}


