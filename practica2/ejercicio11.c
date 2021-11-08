#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <time.h>

int main(int argc,char **argv){
    struct stat statbuf;    
    if (argc < 2) {
	printf("Se debe incluir la ruta del archivo como argumento\n");
	return -1;
    }
    int existe= stat(argv[1], &statbuf);
    if (existe == -1){
	printf("El fichero no existe\n");
	return -1;
    }
    mode_t m = statbuf.st_mode;
    if (!S_ISREG(m)){
	printf("Error: %s no es un fichero regular.\n", argv[1]);
        return -1;
    } else {
	char* s = malloc(sizeof(char)*(strlen(".sym")+strlen(argv[1])));
	char* h = malloc(sizeof(char)*(strlen(".hard")+strlen(argv[1])));
	strcpy(s, argv[1]);
	strcpy(h, argv[1]);
	int sim = symlink(argv[1], strcat(s,".sym"));
	if(sim == -1){
	    printf("Error al crear el enlace simbolico");
	    return -1;
	}
	int hard = link(argv[1], strcat(h,".hard"));
	if(hard == -1){
	    printf("Error al crear el enlace rigido");
	    return -1;
	}
    }
    return 0;
}

