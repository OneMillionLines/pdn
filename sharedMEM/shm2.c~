#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

char * shm;

void semPost() 
{

	 shm[1023] = 1; 

}
void semWait() 
{
	 while (shm[1023] == 0); 
	 
}

void modified() 
{ 

	shm[1022] = 1; 

}

int main()
{
	key_t key = ftok("shmfile",65);

	int shmid = shmget(key,1024,IPC_CREAT|0666);

	shm = (char*)shmat(shmid,NULL,0);

	int i;

	char buf[1024], c;

	for (i=0; i<1024; i++)
		
		 shm[i] = 0;
	
	

	semPost();
	
	printf("\n\nusing shared memory : \n\n");
	
	while (1)
	{
		i = 0;
		
		while ((c = getchar()) != '\n')
			 buf[i++] = c;
		
		buf[i] = '\0';
		
		shm[0] = 0;
		
		semWait();
		for (i=0; buf[i]; i++) 
		
			shm[i] = buf[i];
		
		shm[i] = 0;
		
		modified();
		
		semPost();

		if (strcmp(buf,"EXIT") == 0) break;
	}
	
	return 0;
}
