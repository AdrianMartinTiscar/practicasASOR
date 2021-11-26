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

int demonio(char **argv){
    int in = open("/dev/null", O_CREAT | O_RDWR, 777);
    int sout = open("/tmp/daemon.out",O_CREAT | O_RDWR, 777);
    int eout = open("/tmp/daemon.err", O_CREAT | O_RDWR, 777);
    int din = dup2(in,0);
    int dsout = dup2(sout,1);
    int deout = dup2(eout,2);
    if (execvp(argv[1], argv + 1) == -1) {
        printf("Error en la ejecución.\n");
        return -1;
    }
    close(in);
    close(sout);
    close(eout);
    return 0;
}

int main(int argc, char **argv){
    if (argc < 2) {
        printf("Faltan argumentos.\n");
        return -1;
    }
    int r;
    pid_t pid = fork();
    if(pid == 0){//Hijo
    	pid_t hsid = setsid();
	r = demonio(argv);
    }
    else if(pid == -1){
	r = printf("Error al crear un nuevo proceso\n");
	return -1;
    }
    return r;
}


