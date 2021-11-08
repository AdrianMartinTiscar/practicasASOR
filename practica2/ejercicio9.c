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
    printf("Major: %d\n", major(statbuf.st_dev));
    printf("Minor: %d\n", minor(statbuf.st_dev));
    printf("i-nodo: %ld\n", statbuf.st_ino);
    mode_t m = statbuf.st_mode;
    printf("Tipo de fichero: ");
    if (S_ISDIR(m))
	printf("Directorio.\n");
    else if (S_ISLNK(m))
	printf("Enlace simbólico.\n");
    else if (S_ISREG(m))
	printf("Fichero ordinario.\n");
    else
	printf("Otro.\n");
    time_t time = statbuf.st_mtime;
    struct tm* t=localtime(&time);
    printf("Ultimo acceso: %d:%d\n", t->tm_hour, t->tm_min);
    return 0;
}

/*st_mtime registra la modificacion cuando hay cambios en el fichero (cuando se crea, se trunca,
se escribe), mientras que st_ctime registra como cambios cuando se modifica algún tipo de
información del i-nodo*/
