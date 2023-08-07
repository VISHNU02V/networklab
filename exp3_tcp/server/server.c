#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){	
	int socketid , clientsock , clientsize;
	char server_message[2000],client_message[2000];         // server_message and client_message is to store the messages
	 
	struct sockaddr_in server_addr,client_addr;	        // Address to refer server address and client address
	
	// STEP 1 :To clean buffers
	memset(server_message,'\0',sizeof(server_message)); 	// set the memeory address of the server message to NULL ,space of the size of server message isset
	memset(client_message,'\0',sizeof(client_message));	// set the memeory address of the client message to NULL ,space of the size of server message isset

	// STEP 2 :create socket
	socketid = socket(AF_INET,SOCK_STREAM,0);
	
	
	if(socketid < 0){
		printf("\nSocket not connected !!!! , Socket ");
		return -1;
	}	
	else{
		printf("\nSocket connected successfully !!!!!");
	}
	
	// STEP 3 :set port and IP
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(2000);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	// STEP 4 :Bind to the set port and IP
	if (bind(socketid , (struct sockaddr*)&server_addr, sizeof(server_addr))<0){
	
		printf("\nbinding not done !!!!!!");
	}
	else{
		printf("\nbinding done successfully");
	}
	
	// STEP 5 :Listen for clients
	if(listen(socketid,1)<0){
		printf("\nError while listening ");
		return -1;
	}
	printf("\nlistening..............................\n");
	clientsize = sizeof(client_addr);
	clientsock = accept(socketid, (struct sockaddr*)&client_addr, &clientsize);
	
	while(1){
		bzero(client_message,100);
		bzero(server_message,100);
		printf("\n message from client:");
		read(clientsock,server_message,100);
		
		if(strcmp(server_message,"quit")==0 || strcmp(client_message,"quit")==0 ){
			printf("closed\n");
			exit(0);
			close(socketid);
			close(clientsock);
		}
		puts(server_message);
		sleep(6);
		printf("\n send message to client:");
		gets(client_message);
		write(clientsock,client_message,sizeof(client_message));
	}		
} 
