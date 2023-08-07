#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

int main(void){
	int socketid, clientsock , clientsize;
	char server_message[2000],client_message[2000]; 
	
	struct sockaddr_in serveraddr , clientaddr;
	
	memset(server_message,'\0',sizeof(server_message));
	memset(client_message,'\0',sizeof(client_message));
	
	socketid=socket(AF_INET,SOCK_STREAM,0);
	
	if(socketid<0){
		printf("\nsocket id is not connected !!!!!!");
	}
	else{
		printf("\nsocket id is connected ");	
	}
	
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(2000);
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if(connect(socketid,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
		printf("\nunable to connect !!!!");
		return -1;
	}
	printf("\nconnected with server successfully \n");
	bzero(client_message,100);
	bzero(server_message,100);
	while(1){
		printf("\n send message from client:");
		gets(server_message);
		write(socketid,server_message,sizeof(server_message));
		if(strcmp(server_message,"quit")==0 || strcmp(client_message,"quit")==0 ){
			printf("closed");
			exit(0);
			close(socketid);
		}
		printf("\n send message to server:");
		read(socketid,client_message,100);
		puts(client_message);
	}
	
	return 0;
}
	
	
