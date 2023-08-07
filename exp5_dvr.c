#include <stdio.h>

int costmatrix[20][20],n;  // n is the order of the matrix

// Router
struct routers{
	int distance[20];
	int adjnodes[20];
}node[20];

// Fuction to read cost matrix

void readcostmatrix(){
	printf("\n Inputing . . . . . . \n ");
	printf("\n enter the cost matrix of size (%d * %d):",n,n);
	for(int i=0;i<n;++i){
		for(int j=0 ;j<n;++j){
			scanf("%d",&costmatrix[i][j]);
			costmatrix[i][i]=0;
			node[i].distance[j]=costmatrix[i][j];
			node[i].adjnodes[j]=j;
		}
	}
}

// Calculating routing table 

void calcroutingtable(){
	for(int i=0; i<n ; ++i){
		for(int j=0; j<n ; ++j){
			for(int k=0; k<n ; ++k){
				if(node[i].distance[j] > costmatrix[i][k]+node[k].distance[j]){          // if the cost of the path from x to y is lesser than the cost 
													 // of the path from x to y
					node[i].distance[j] = node[i].distance[k] + node[i].distance[j]; // subtitute with minimum distance 
					node[i].adjnodes[j]=k;						 // subtitute with minimum path
				}
			}
		}
	}
}

void displayroutes(){
	for(int i=0;i<n;++i){
		printf("\nRouter %d \n",i+1);
		for(int j=0;j<n;++j){
			printf("Node %d via %d : Distance %d \n",j+1,node[i].adjnodes[j]+1,node[i].distance[j]);
		}
		printf("\n");
	}
}

int main(){
	int i ,j;
	printf("Number of nodes:");
	scanf("%d",&n);
	readcostmatrix();
	calcroutingtable();
	displayroutes();
	return 0;
}

			
