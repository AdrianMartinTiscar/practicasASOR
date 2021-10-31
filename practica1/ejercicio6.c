#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main() {
   printf("Longitud máxima de argumentos: %ld\n",sysconf(_SC_ARG_MAX));
   printf("Nº máximo de hijos: %ld\n",sysconf(_SC_CHILD_MAX));
   printf("Nº máximo de ficheros: %ld\n",sysconf(_SC_OPEN_MAX));
   return 0;
}

