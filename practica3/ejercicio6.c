#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sched.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>

int prints(char *quien){
    struct rlimit limit;
    int pid, ppid, pgid, sid, maxfich;
    char dir[1024];
    pid = getpid();
    ppid = getppid();
    pgid = getpgid(pid);
    if (pgid == -1) {
	printf("Error en grupo");
	return -1;
    }
    sid = getsid(pid);
    if (sid == -1) {
	printf("Error en sesion");
	return -1;
    }
    maxfich = getrlimit(RLIMIT_NOFILE,&limit);
    if (maxfich == -1) {
	printf("Error en maximo de ficheros");
	return -1;
    }
    getcwd(dir, 1024);
    if (dir == NULL) {
	printf("Error en el directorio");
	return -1;
    }
    printf("PID del %s: %d\n",quien,pid);
    printf("PPID del %s: %d\n",quien,ppid);
    printf("PGID del %s: %d\n",quien, pgid);
    printf("SID del %s: %d\n",quien,sid);
    printf("Nº maximo de ficheros que el %s puede abrir: %d\n",quien,limit.rlim_max);
    printf("Directorio actual del %s: %s\n",quien,dir);
    return 0;
}

int main(){
    int r;
    pid_t pid = fork();
    if(pid == 0){//Hijo
    	pid_t hsid = setsid();
	char *hdir = chdir("/tmp");
	r = prints("hijo");
    }
    else if(pid == -1){
	r = printf("Error al crear un nuevo proceso\n");
	return -1;
    }
    else prints("padre");//Padre
    return r;
}
//Si el padre termina antes del hijo, este es adoptado por el proceso raiz, el ppid del hijo pasa a ser 1
//Si el hijo termina antes que el padre su ppid es el pid del padre

