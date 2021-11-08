#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* fichero = "fich7";
    mode_t mask = umask(027);
    int fd = open(fichero, O_CREAT,0645);
    if(fd == -1){
	printf("No se puedo abrir o crear el fichero");
	return -1;
    }
    return 0;
}
