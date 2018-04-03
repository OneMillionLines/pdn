#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <string.h>
#include <fcntl.h>

char * shm;

void semPost() 
{ 
	shm[1023] = 1; 
}

void semWait() 
{
	 while (shm[1023] == 0); 
	 	
}
int isModified()
{

	 return shm[1022]; 

}

void written()
 { 
 
 	shm[1022] = 0;
 
  }

int main()
{
	key_t key = ftok("shmfile",65);
	
	int shmid = shmget(key,1024,IPC_CREAT|0666);
	
	shm = (char*)shmat(shmid,NULL,0);

	int i;
	while (1)	
	{
		semWait();
	
			if (isModified())
			 {
			 
			 	 printf("%s\n",shm); 
			 
			 	 written(); 
			 
			 }
	
			if (strcmp(shm,"EXIT") == 0) break;
	
			semPost();
	
	}
		
	semPost();
	
	return 0;

}
