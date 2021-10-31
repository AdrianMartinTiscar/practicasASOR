#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char**args){
   printf("uid: %d\ngid: %d\n", getuid(), geteuid());
   return 0;
}

//Cuando el bit setuid esta activo en un fichero se permite que un usuario que no es el
//propietario ejecute el fichero dando al proceso los permisos del propietario. Para saber
//si esta activo hay que mirar los permisos del fichero, si tiene una s en el bit de 
//ejecución del propietario significa que el bit setuid esta activo.
