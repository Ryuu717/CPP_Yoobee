#include <time.h>
#include <stdio.h>
 
int main(void)
{
   struct tm newtime;
   time_t ltime;
   char buf[50];
 
   ltime=time(&ltime);
   localtime_r(&ltime, &newtime);
   printf("The date and time is %s", asctime_r(&newtime, buf));
}
 
/**************  If the local time is 3 p.m. February 15, 2008,  **********
*************************  the output should be:  *********************
 
The date and time is Fri Feb 15 15:00:00 2008
*/