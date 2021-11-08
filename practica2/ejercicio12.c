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
    int out = open (argv[1], O_CREAT|O_RDWR, 0777);
    if (out == -1){
	printf("No se ha podido crear el fichero\n");
	return -1;
    }
    dup2(out,1);
    printf("Hola mundo\n");
    printf("Esto se esta escribiendo en un fichero\n");
    printf("Y no en la salida estandar\n");
    close(out);
    return 0;
}

