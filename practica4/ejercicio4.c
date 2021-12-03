#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

const int TAM = 256;

int main(int argc, char **argv){
    if(argc<2){
	printf("Falta un argumento\n");
	return -1;
    }
    int pd = open("tuberia",O_WRONLY,0222);
    if(pd == -1){
	pd = mkfifo("tuberia",0666);//Si no existe la creo, tengo que permitir la lectura para que se lea
    }
    write(pd, argv[1], strlen(argv[1])+1);
    close(pd);
    return 0;
}
