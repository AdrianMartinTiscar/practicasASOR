#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char** argv){
    if(argc < 2){
	printf("Parametros insuficientes\n");
	return -1;
    }
    
    if(execvp(argv[1], argv +1) == -1){
	printf("Error en la ejecución");
	return -1;
    }
    printf("El comando terminó de ejecutarse.\n");
    return 0;
}
