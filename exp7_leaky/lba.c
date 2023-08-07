//Implement congestion control using a leaky bucket algorithm.

#include <stdio.h>
#include <stdlib.h>

void main(){
	int storage=0 , inputpkt=4 , outputpkt=1 , bucketsize=10 ,packetnum=4 ;
	
	printf("Enter the input rate : ");           // inputing rate to the bucket
	scanf("%d",&input_pkt);
	
	printf("Enter the output rate : ");	     // output rate 
	scanf("%d",&output_pkt);
	
	printf("Enter the bucket size : ");          // size of the bucket
	scanf("%d",&bucket_size);
	
	for(int i=0; i < packetnum ; i++){
		int sizeleft = bucketsize - storage;
		
		if(input_pkt <= size_left){
			storage = storage + input_pkt;
		}
		else{
			printf("\nPacket Loss : %d",input_pkt);
		}
		
		printf("\n storage : %d of bucket_size : %d",storage,bucket_size);
	
	
