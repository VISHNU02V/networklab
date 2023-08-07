//Simulate sliding window flow control protocols.* (Stop and Wait, Go back N, Selective Repeat ARQ protocols)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

void stop_and_wait();
void selective();
void goback();
	
int r,n;

struct frame{						// frame
	int data;			
	char ack;
	char wait;
}frm[100];

// Stop and wait sliding window protocol :: from line [18 : 45]

void sender(int i){
	printf("enter the data to be sent :");
	scanf("%d",&frm[i].data);
	printf("\n");
	frm[i].ack='y';
	printf("Packet sent\nWaiting for acknowledgement \n");
	printf("\n");
	sleep(1);
}
	
void recack(int i){
	frm[i].ack='n';
	if(frm[i].ack=='n'){
		printf("Packet Lost\n");
		sleep(2);
		exit(0);
	}
	else{
		printf("Packet received with the data : %d ",frm[i].data);
		printf("\n");
	}
}
void stop_and_wait(){
	for(int i=1;i<=n;i++){
		sender(i);
		recack(i);
	}
}
void getvalues(){
	for(int i=1;i<=n;i++){
		printf("Enter the value of frame : %d",i);
		printf("\n");
		scanf("%d",&frm[i].data);
		frm[i].ack='y';
		rand();
		r=3;
	}
}

void selective(){
	getvalues();
	int lc=1;
	int w_size;
	printf("\n Enter the window size:");
	scanf("%d",&w_size);
	frm[r].ack='n';
	end:
	for(int i=lc ; i<=(n-w_size) + 1;){
		for(int j=i ;i+w_size;j++ ){
			if(frm[j].wait != 'n'){
				printf("\nsending value %d : ",frm[j].data);
			}
			frm[j].wait='y';
		}
		sleep(1);
		int count=0;
		for(int j=i;j<i+w_size;j++){
			if(frm[j].ack=='y'){
				if(j==i){
					count++;
					printf("\npacket received with data : %d",frm[j].data);
				}
				else{
					printf("\npacket lost %d",frm[j].data);
					goto skip;
				}
				if(count>0){
					lc++;
					printf("\nskipping");
					goto end;
				}
			}
		}
		skip:
		for(int i=lc;i<=n;i++){
			if(frm[i].ack != 'n'){
				printf("\nsending value : %d ",frm[i].data);
			}
			if(frm[i].ack == 'y'){
				printf("\npacket recieved with data : %d",frm[n].data);
			}
			else{
				frm[i].ack='y';
				printf("\nPacket lost :%d",frm[i].data);
			}
			if(i==lc+(w_size-1)){
				printf("\nPacket received with data : %d",frm[r].data);
			}
		}
	}
}
		
	

void main(){
	int option;
	printf("\n Enter the no of frames :");
	scanf("%d",&n);
	printf("\n");
	printf(" * * * M E N U * * * \n 1.Stop and Wait \n 2.Selective Repeat \n 3.Go Back N \n 4.Exit \n Enter the option(1/2/3/4) :: ");
	scanf("%d",&option);
	
	rand();
	r=rand()%n;
	
	switch(option){
		case 1:stop_and_wait();
			break;
		case 2:selective();
			break;
		case 4:exit(0);
	}
}
	
