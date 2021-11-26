#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sched.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>
int main(){
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
    printf("PID: %d\n",pid);
    printf("PPID: %d\n",ppid);
    printf("PGID: %d\n",pgid);
    printf("SID: %d\n",sid);
    printf("Nº maximo de ficheros que se pueden abrir: %d\n",limit.rlim_max);
    printf("Directorio actual: %s\n",dir);
    return 0;
}


