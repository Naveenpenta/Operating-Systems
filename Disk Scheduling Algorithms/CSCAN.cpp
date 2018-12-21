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
	int dist=0,choice;
	
	printf("Enter\n1 for moving towards larger value \n2for moving towards lesser value");
	scanf("%d",&choice);
	if(choice==1){
	
				int value=end-r[tnt-1];
				for(int i=mid+1;i<tnt;i++){
						dist=r[i]-ptr;
						ptr=r[i];
						sum=sum+dist;
						printf("went to datablock =%d\n",ptr);
						printf("Travelled dataheads =%d\n",dist);
				}
				
				sum=sum+value;
				ptr=sum;
				printf("went to datablock =%d\n",ptr);
				printf("Travelled dataheads =%d\n",value);
				
				ptr=0;
				dist=end-0;
				sum=sum+dist;
				
				printf("went to datablock =%d\n",ptr);
				printf("Travelled dataheads =%d\n",value);
				
				
				for(int i=0;i<=mid;i++){
					dist=r[i]-ptr;
					ptr=r[i];
					sum=sum+dist;
					printf("went to datablock =%d\n",ptr);
					printf("Travelled dataheads =%d\n",dist);
				}
	
				printf("\n\n\ntotal tracks %d ::",sum);

	}
	if(choice==2){
		
		int value=r[0]-0;
		for(int i=mid;i>=0;i--){
			dist=ptr-r[i];
			ptr=r[i];
			sum=sum+dist;
			printf("went to datablock =%d\n",ptr);
			printf("Travelled dataheads =%d\n",dist);
		}
		
		sum=sum+value;
		ptr=sum;
		printf("went to datablockk =%d\n",ptr);
		printf("Travelled dataheadss =%d\n",value);
		
		ptr=end;
		sum=sum+end;
		
		printf("went to datablock =%d\n",ptr);
		printf("Travelled dataheads =%d\n",end);
		
		for(int i=tnt-1;i>=mid+1;i--){
			dist=ptr-r[i];
			ptr=r[i];
			sum=sum+dist;
			printf("went to datablock =%d\n",ptr);
			printf("Travelled dataheads =%d\n",dist);
		}
		
		printf("\n\n\ntotal tracks %d ::",sum);		
		
	}
		
}
