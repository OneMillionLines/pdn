#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  pid_t pid;

  char arr1[100];
  int num,num1;
  int fd[2]={0};
  pipe(fd);
    pid=fork();
 
  if(pid==0)
  { //write
    //close(fd[0]);
    printf("\n---child is executing---\n");
        printf("\nEnter the decimal number : ");
        scanf("%d",&num);
        //read(fd[0],&nu,sizeof(nu));
       int n; n=num;
    long int binaryNumber = 0;
    int remainder, i = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
      }
        printf("\nDecimal to binary : %ld\n",binaryNumber);
        write(fd[1], &binaryNumber,sizeof(binaryNumber));
        close(fd[1]);
        printf("----Child process completed----");
  }
  else if (pid>0)
  {
    long int binaryNumber;
    //close(fd[0]);
    wait(NULL);
    printf("\n-----Parent process running-----\n");
    //close(fd[0]);

    read(fd[0], &binaryNumber, sizeof(binaryNumber));
    long int octalnum = 0, j = 1, remainder;
    while (binaryNumber!= 0)

    {

        remainder = binaryNumber % 10;

        octalnum = octalnum + remainder * j;

        j = j * 2;

        binaryNumber= binaryNumber/ 10;
    }
    printf("Binary to Octal : %lo\n", octalnum);
    printf("----Parent process completed----");
  }


else 
  {

  printf("fork failed");
  }
}
