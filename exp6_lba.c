
#include <stdio.h>
#include <stdlib.h>

void main(){
	int input_pkt = 4,output_pkt = 1,bucket_size=10,packetnum=4 , storage=0;
	
	printf("\nEnter the input rate : ");
	scanf("%d",&input_pkt);
	
	printf("\nEnter the output rate : ");
	scanf("%d",&output_pkt);
	
	printf("\nEnter the bucket size : ");
	scanf("%d",&bucket_size);
	
	for(int i=0; i< packetnum ; i++){
		int size_left = bucket_size - storage ;
		if(input_pkt <= size_left){
			storage = storage + input_pkt;
		}
		else{
			printf("\nPacket Loss : %d",input_pkt);
		}
		printf("\nStorage : %d of bucket_size : %d",storage,bucket_size);
		storage=storage-output_pkt;
		printf("\n storage : %d of bucket_size : %d",storage,bucket_size);
		printf("\n \nDropping the packet request !!!!!!!");
	}
}			
