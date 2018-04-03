#include<sys/types.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
#define maxsize 128
void die( char *s)
{
   perror(s);
   exit(1);
}
struct msgbuf{
  long mtype;
  char mtext[maxsize];
  };
int main()
{
  int msgid;
  int msgflg=IPC_CREAT|0666;
  key_t key;
  struct msgbuf  sbuf;
  size_t buflen;
  key=1234;
  if((msgid=msgget(key,msgflg))<0)
     die("msgget");
   sbuf.mtype=1;
  printf(" enter the msg to add");
  scanf(" %s",sbuf.mtext);
   getchar();
   buflen=strlen(sbuf.mtext)+1;
   if(msgsnd(msgid,&sbuf,buflen,0)<0)
   {
     printf(" %d,%d,%s,%zu\n",msgid,sbuf.mtype,sbuf.mtext,buflen);
      die("msgsnd");
  }
 else
 {
   printf(" msg sent");
}
exit(0);
}
     
   
   

