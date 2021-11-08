#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc,char **argv){  
    if (argc != 2) {
	printf("Se debe incluir la ruta del directorio como argumento\n");
	return -1;
    }
    DIR *dir= opendir(argv[1]);
    if (dir == NULL ) {
        printf("No existe el directorio o no se ha podido abrir.\n");
        return -1;
    }
    struct dirent *entrada;
    struct stat info;
    size_t tamSalida = strlen(argv[1]);
    entrada = readdir(dir);
    int tam = 0;
    while (entrada != NULL) {
	printf("%s",entrada->d_name);
	if (lstat(entrada->d_name, &info) == -1) {
            printf("No se puede analizar el archivo\n");
            closedir(dir);
            return -1;
        } else {
	    if (S_ISREG(info.st_mode)) {
       	        if (info.st_mode & S_IXUSR != 0)
   		    printf("*\n");
   		else
   		    printf("\n");
        	tam = tam + info.st_size;
            } else if (S_ISDIR(info.st_mode)) {
           	printf("/\n");
            } else if (S_ISLNK(info.st_mode)) {
            	char *enlace = malloc(info.st_size + 1);
           	printf("->%s\n", enlace);
		tam = tam + info.st_size;
            	free(enlace);
	    }
    	}
	entrada = readdir(dir);
    }
    printf("Tamaño archivos: %fKB\n", tam / 1024.0);
    closedir(dir);
    return 0;
}
