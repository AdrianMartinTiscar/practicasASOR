#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>

int main(){
   for(int i = 0; i<255;i++){
   printf("Codigo de error: %d\nMensaje de error: %s\n", i, strerror(i));
   }
   return 1;
}

