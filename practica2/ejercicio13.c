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
    dup2(out,2);
    dup2(out,1);    
    printf("Hola mundo\n");
    printf("Esto se esta escribiendo en un fichero\n");
    printf("Y no en la salida estandar\n");
    fprintf(stderr, "Ahora también se escriben los errores por aqui\n");
    fprintf(stderr, "Error1\n");
    fprintf(stderr, "Ya no se que escribir\n");
    close(out);
    return 0;
}
/*Da igual en que orden se hagan las redirecciones, se muestra siempre primero la salida de error y luego la normal.
ls > dirlist 2>&1 vuelca la salida de ls en dirlist y luego la salida de error la manda a la salida estandar (1) pero en este momento esta salida se ha concebido como dirlist, por lo que tanto ls como la salida de error iran a dirlist.
ls 2>&1 > dirlist  se muestra la salida de error por pantalla (salida estandar) y lo de la salida estandar se vuelca en el fichero dirlist
*/
