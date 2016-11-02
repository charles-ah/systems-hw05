#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  //DIR *d = malloc(sizeof(d));
  DIR d=*opendir(".");
  struct stat s;
  //struct dirent *info = malloc(sizeof(info));
  struct dirent *info;//=*readdir(&d);
  int size;
  //printf("%s\n",info.d_name);
  printf("printing out statistics of this directory .... \n");
  while(info=readdir(&d))
    {
      //info=*readdir(&d));
      if(opendir(info->d_name))
	{printf("directory: ");}
      else
	{
	  stat(info->d_name,&s);
	  size+=s.st_size;
	  printf("file: ");}
      printf("%s\n",info->d_name);
      
    }
  printf("size of directory: %d bytes\n",size);
  
  
  //closedir(&d);


  /*
  info=*readdir(&d);
  printf("%s\n",info.d_name);
  info=*readdir(&d);
  printf("%s\n",info.d_name);
  info=*readdir(&d);
  printf("%s\n",info.d_name);
  */
}
