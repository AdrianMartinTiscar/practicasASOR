#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <pwd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char**args){
   struct passwd* info;
   printf("uid: %d\ngid: %d\n", getuid(), geteuid());
   if ((info = getpwuid(getuid()) ) == NULL){
   	 fprintf(stderr, "%s", strerror(errno));
   	 return -1;
   }

   printf("Nombre usuario: %s\n", info->pw_name);
   printf("Directorio home: %s\n", info->pw_dir);
   printf("Descripción usuario: %s\n", info->pw_gecos);
   return 0;
}

