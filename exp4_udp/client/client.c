#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

void main(){
	int socketid,length;
	char sendline[100],recline[100];
	struct sockaddr_in server_addr,client_addr;
	
	bzero(&server_addr,sizeof(server_addr));
	
	socketid = socket(AF_INET,SOCK_DGRAM,0);
	
	if(socketid<0){
		printf("socket cannot be connected");
	}
	else{
		printf("Socket created");
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(3001);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(connect(socketid , (struct sockaddr*)&server_addr,sizeof(server_addr))<0){
		printf("connection failed !!!!!");
	}
	bzero(sendline,100);
	bzero(recline,100);
	sendline[10]="test";
	do{
		printf("Message to server :");
		gets(sendline);
		if(strcmp(sendline,"quit")==0){
			exit(0);
		}
		sendto(socketid,sendline,MAXLINE,0,(struct sockaddr*)NULL,sizeof(server_addr));
		printf("\n Message from server :");
		recvfrom(socketid,recline,sizeof(recline),0,(struct sockaddr*)NULL , NULL);
		puts(recline);
		if(strcmp(recline,"quit")==0){
			exit(0);
		}
	}while(strcmp(recline,"quit")!=0 || strcmp(sendline,"quit")!=0);
	close(socketid);
}
