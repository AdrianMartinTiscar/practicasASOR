#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>

int main(){   
   time_t tim = time(NULL);
   struct tm* ltime = localtime(&tim);
   printf("El año actual es: %i\n",ltime->tm_year + 1900);

   return 0;
}
