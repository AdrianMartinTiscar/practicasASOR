#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char** argv){
    if(argc < 2){
	printf("Parametros insuficientes\n");
	return -1;
    }
    char *prog;
    int tam = 0;
    for(int i = 1; i<argc;i++)
	tam += strlen(argv[i]) +1;
    prog = malloc(sizeof(char)*tam);    
    for (int i = 1; i < argc; i++) {
    	strcat(prog, argv[i]);
  	strcat(prog, " ");
    }
    prog[tam] = '\0';
    if(system(prog) == -1){
	printf("Error en la ejecución");
	return -1;
    }
    printf("El comando terminó de ejecutarse.\n");
    return 0;
}
