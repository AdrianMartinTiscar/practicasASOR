#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>

int main(){
   int e = setuid(0);
   if(e==-1){
        printf("Codigo de error: %d\nMensaje de	error: %s\n", errno, strerror(errno));
   }
   return 1;
}
