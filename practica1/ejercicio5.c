#include <sys/utsname.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(){
   struct utsname b;
   int e = uname(&b);
   if(e!=-1){
	printf("Operating sistem: %s\n", b.sysname);
	printf("Nodename: %s\n", b.nodename);
	printf("Release: %s\n", b.release);
	printf("Version: %s\n", b.version);
	printf("Machine: %s\n", b.machine);
   }
   else{
	printf(stderr, "Error %d, %s\n", errno, strerror(errno));
   }
   return 0;
}
