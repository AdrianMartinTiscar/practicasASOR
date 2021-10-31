#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main() {
   char* file = "ejercicio6.c";
   printf("Nº máximo de enlaces: %ld\n",pathconf(file,_PC_LINK_MAX));
   printf("Tamaño máximo de ruta: %ld\n",pathconf(file, _PC_PATH_MAX));
   printf("Tamaño máximo de nombre de fichero: %ld\n",pathconf(file, _PC_NAME_MAX));
   return 0;
}

