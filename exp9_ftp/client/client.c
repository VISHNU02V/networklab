#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


char buff[4096];
FILE *f1;
int MAX = 60;

void main(){
	int socketid , n;
	char send[MAX],recline[MAX],s[MAX],name[MAX];
	
	struct sockaddr_in server_addr , client_addr;
	
	socketid = socket(AF_INET,SOCK_STREAM,0);
	
	if(socketid>0){
		printf("sucessfully connected\n");
	}
	else{
		printf("cannot connect !!!!!!!");
	}
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(3000);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	 
	connect(socketid,(struct sockaddr*)&server_addr,sizeof(server_addr));
	
	while(1){
		printf("enter the name of the file :");
		scanf("%s",send);
		write(socketid,send,MAX);
		if(strcmp(send,"exit")==0){
			exit(0);
		}
		read(socketid,recline,MAX);
		printf("\n %s\n",recline);
	}
	close(socketid);
}

	

	

