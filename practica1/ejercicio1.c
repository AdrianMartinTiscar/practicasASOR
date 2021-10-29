#include<sys/types.h>
#include<unistd.h>
#include<errno.h>

int main(){
   int err = setuid(0);
   if(err == -1) return -1;
   else return 1;
}
