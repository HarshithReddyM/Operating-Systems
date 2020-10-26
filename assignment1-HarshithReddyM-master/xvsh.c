#include "types.h"
#include "fcntl.h"
#include "user.h"
#include "stat.h"
char *argv[]={0};
int
main(int argc, char *argv[])
{
  xvsh();

  int pid, wpid;                                                                                                                                             
  char buffer[200];
  int length;

  while(gets(buffer, sizeof(buffer)))
  { 
    if(strlen(buffer) < 2)
    {
      printf(1,"\nxvsh>");
      continue;
    }
    
    length = strlen(buffer);
    if(buffer[length -2] == '&')
    printf(1, "[pid %d ] runs as a background process \n",getpid());
	
    buffer[strlen(buffer) - 1] = '\0';
    pid = fork();
    if(pid > 0)
    {
    // printf(2, "parent: child=%d\n", pid);
     pid = wait();
    // printf(2, "child %d is done\n", pid);
    } 
    else if(pid == 0)
    {
    // printf(2, "child: exiting\n");
     exec(buffer,argv);
     exit();
    } 
    else
    {
     printf(1,"fork error\n");
    }
    
    while((wpid=wait()) >= 0 && wpid != pid)
      printf(1, "zombie!\n");

  }
                                                                                                                                                     
  exit();
}

