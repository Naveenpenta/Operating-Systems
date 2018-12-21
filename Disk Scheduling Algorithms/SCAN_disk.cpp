#include<stdio.h>

int main(){
	
	int start=0,end,ptr,trmov,tnt,sum=0;
	
	printf("Enter disk contains how many tracks:\n");
	scanf("%d",&end);
	end-=1;
	
	printf("\nEnter request queue has how many no of tracks::\n");
	scanf("%d",&tnt);
	
	int r[tnt];
	int ref[tnt];
	printf("\nEnter request queue tracks between 0 to %d only:",end);
	
	for(int i=0;i<tnt;i++){
		
		scanf("%d",&r[i]);
		ref[i]=0;
		
	}
	printf("Enter read write head position\n");
	scanf("%d",&ptr);
	
	for(int i=0;i<tnt;i++){
		
		for(int j=i;j<tnt;j++){
			
			
			if(r[i]>r[j]){
				int temp=r[i];
				r[i]=r[j];
				r[j]=temp;
			}
		}
	}
	int mid=0;
	for(int i=0;i<tnt;i++){
		if(ptr>=r[i]){
			mid=i;
		}
		
	}
	int dist,option;
	printf("Enter \n1 for moving towards larger value  or\n 2 for moving to wards lesser value\n");
	scanf("%d",&option);
	if(option==1){
	
				int value=end-r[tnt-1];
				for(int i=mid+1;i<tnt;i++){
						
						dist=r[i]-ptr;
						ptr=r[i];
						printf("Went to data block %d\n",r[i]);
						printf("Travelled dataheads=%d\n",dist);
						sum=sum+dist;
				}
				
				printf("Went to data block %d\n",end);
				printf("Travelled dataheads=%d\n",value);
				sum=sum+value;
				ptr=end;
				
				
				for(int i=mid;i>=0;i--){
					
					dist=ptr-r[i];
					ptr=r[i];
					sum=sum+dist;
					printf("Went to data block %d\n",r[i]);
					printf("Travelled dataheads=%d\n",dist);
				}
				
				printf("Total travelled datapoints=%d\n",sum);
	
	}
	
	if(option==2){
		int value=r[0];
		for(int i=mid;i>=0;i--){
			dist=ptr-r[i];
			ptr=r[i];
			sum=sum+dist;
			printf("Went to data block %d\n",ptr);
			printf("Travelled dataheads=%d\n",dist);
			
		}
			printf("Went to data block %d\n",start);
			printf("Travelled dataheads=%d\n",value);
			sum=sum+value;
			ptr=0;
			
			
		for(int i=mid+1;i<tnt;i++){
			
			dist=r[i]-ptr;
			ptr=r[i];
			sum=sum+dist;
			printf("Went to data block %d\n",ptr);
			printf("Travelled dataheads=%d\n",dist);
		}	
		
	}
	
	printf("Total travelled datapoints=%d\n",sum);
//	for(int i=0;i<7;i++)
//		printf("%d\n",r[i]);
	
}
