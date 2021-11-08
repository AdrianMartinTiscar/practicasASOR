#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <time.h>
#include <fcntl.h>

int main(int argc,char **argv){  
    if (argc < 2) {
	printf("Se debe incluir la ruta del archivo como argumento\n");
	return -1;
    }
    int fichero = open(argv[1], O_RDONLY);
    if(fichero == -1){
	printf("El fichero no existe o no se ha podido abrir.\n");
	return -1;
    }
    int lock = lockf(fichero, F_TEST, 0);
    if(lock == 0) {
	printf("El fichero %s esta desbloqueado.\n", argv[1]);
	lockf(fichero, F_TLOCK, 0);
	time_t t = time(NULL);
	struct tm *tms = localtime(&t);
	printf("Hora del cerrojo: %d:%d\n", tms->tm_hour, tms->tm_min);
	sleep(30);
	lockf(fichero, F_ULOCK, 0);
    }
    else{
	printf("El fichero %s esta bloqueado.\n", argv[1]);
    }
    return 0;
}
