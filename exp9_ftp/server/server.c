#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char buff[4096];
FILE *f1;
int MAX = 60;

void main(){
	int socketid,newSocketid;
	char recline[200],sendline[200];
	
	struct sockaddr_in server_addr,client_addr;
	
	char t[5] = "exit" , str[60];
	
	socketid = socket(AF_INET,SOCK_STREAM,0);
	
	if(socketid < 0){
		printf("\nSocket not created ?????????");
	}
	else{
		printf("\nSocket created !!!!!!!!");
	}
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(3000);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketid,(struct sockaddr*)&server_addr,sizeof(server_addr))>0){ // binding happening btw server and socket
		printf("Bind successfull !!!!!!!!!1");
	}
	else{
		printf("Bind failed ??????????");
	}
	
	listen(socketid,10);
	int clength = sizeof(client_addr);
	newSocketid = accept(socketid ,(struct sockaddr*)&client_addr,&clength);   // to acccepting the messages from the client

	do{
		read(newSocketid,&str,60);
		if(strcmp(str,"exit")==0){
			close(newSocketid);
			exit(0);
		}
		printf("\nClient message \n\nFile name: %s \n",str);
		f1=fopen(str,"r");
		if(f1==NULL){
			char err[100] = "error occurred :: no file exits";
			printf("\n%s\n",err);
			write(newSocketid,err,60);
			continue;
		}
		else{
			while(fgets(buff,4096,f1)!=NULL){
				write(newSocketid,buff,60);
				printf("\n");
			}
			fclose(f1);
		}
	}while(strcmp(str,"exit")!=0);
}		
			
		
