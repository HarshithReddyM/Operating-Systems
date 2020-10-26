#include "types.h"
#include "user.h"
#include "procThread.h"

void* stack;
int procThread_create(void)
{    
    stack =(void*) malloc(4096); 
    int tid = clone((void *)stack);
    return tid;
}


void procThread_exit(int ret_val)
{
   thread_exit(ret_val);    
}


void procThread_join(int tid, int * ret_val_p)
{
    stack =(void*) malloc(4096);
    join(tid,ret_val_p,&stack);   
}

