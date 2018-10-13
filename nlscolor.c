

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   //chdir
#include <dirent.h>

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>


#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
/*
   printf("%sred\n", KRED);
   printf("%sgreen\n", KGRN);
   printf("%syellow\n", KYEL);
   printf("%sblue\n", KBLU);
   printf("%smagenta\n", KMAG);
   printf("%scyan\n", KCYN);
   printf("%swhite\n", KWHT);
   printf("%snormal\n", KNRM);
*/

int main( int argc, char *argv[])
{ 
    int my_arg_t = 0;

    if ( argc >= 2)
    {
      if ( strcmp( argv[1] , "-t" ) ==  0 )
      {
	 my_arg_t = 1;
         if ( argc >= 3)
          if ( strcmp( argv[2] , "" ) !=  0 )
	   chdir( argv[2] );
      }
      else 
      {
         if ( strcmp( argv[1] , "" ) !=  0 )
	   chdir( argv[ 1 ] );
      }
   }

   DIR *dirp;
   struct dirent *dp;
   dirp = opendir( "." );
   while  ((dp = readdir( dirp )) != NULL ) 
   {
         if (  strcmp( dp->d_name, "." ) != 0 )
         if (  strcmp( dp->d_name, ".." ) != 0 )
          if ( dp->d_name[0] != '.' ) 
          {
            if (dp->d_type == DT_DIR) 
              //printf("%s%s", KGRN, dp->d_name);
              printf("%s%s", KYEL, dp->d_name);
            else
              printf("%s%s", KNRM, dp->d_name);
              //printf("%s%s", KCYN, dp->d_name);

	    if ( my_arg_t == 1 ) 
               printf("\t");
	    else 
               printf("\n");

          }
   }
   closedir( dirp );
   //printf( "\n");

   printf("%s", KNRM);

   if ( my_arg_t == 1 ) 
     printf("%s\n", KNRM);

   return 0;
}



