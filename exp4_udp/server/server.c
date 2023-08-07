#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#define MAXLINE 1000

void main(){
	int socketid,len;
	char recline[2000],sendline[2000];
	
	struct sockaddr_in server_addr,client_addr;
	
	bzero(&recline,sizeof(server_addr));
	bzero(&sendline,sizeof(client_addr));
	
	socketid = socket(AF_INET,SOCK_DGRAM,0);
	
	if(socketid<0){
		printf("\n Socket cannot be created \n");
	}
	else{
		printf("\n Socket created \n");
	}
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(3001);
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	//server_addr.sin_addr.s_addr=inet_addr("10.0.4.23");
	
	if(bind(socketid,(struct sockaddr_in*)&server_addr,sizeof(server_addr))<0){
		printf("\n cannot bind socket");
	}
	printf("\n Successful: bind socket ");
	len=sizeof(client_addr);
	while(strcmp(sendline,"quit")!=0){
		int n = recvfrom(socketid,recline,sizeof(recline),0,(struct sockaddr*)&client_addr,&len);
		recline[n] = '\0';
		printf("Message from client : ");
		puts(recline);
		printf("Message to client : ");
		gets(sendline);
		sendto(socketid,sendline,MAXLINE,0,(struct sockaddr*)&client_addr,sizeof(client_addr));
		if(strcmp(sendline,"quit")==0){
			exit(0);
		}
	}
}
		
