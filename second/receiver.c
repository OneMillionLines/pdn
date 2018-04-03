#include<sys/types.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<sys/msg.h>
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
  //int msgflg=IPC_CREAT|0666;
  key_t key;
  struct msgbuf  recbuf;
   key=1234;
  if((msgid=msgget(key,0666))<0)
     die("msgget");
   if(msgrcv(msgid,&recbuf,maxsize,1,0)<0)
   {
     //printf(" %d,%d,%s,5zu\n",msgid,sbuf.mtype,sbuf_mtext,buflen);
      die("msgrcv");
  }
 else
 {
   printf(" %s",recbuf.mtext);
}
exit(0);
}
     
   
   

