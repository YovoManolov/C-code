 #include <stdio.h>
 #include <time.h>

  int main () {
         struct tm *systime;
         struct tm *gmt;
          time_t t;

          t = time (NULL);
          systime = localtime (&t);
          printf("time is %.2d :%.2d:%.2d\n",
                 systime -> tm_hour,systime->tm_min,
                 systime ->tm_sec);printf("Date:%.2d/%.2d/%.2d",systime ->tm_mon+1,
                 systime->tm_mday,systime->tm_year);

          gmt = gmtime (&t);
          printf(" Coordinated Universal time is %.2d :%.2d:%.2d\n",
                 gmt -> tm_hour,systime->tm_min,gmt ->tm_sec);
                 printf("Date:%.2d/%.2d/%.2d",systime ->tm_mon+1,
                 systime->tm_mday,systime->tm_year);

   return 0;
}

