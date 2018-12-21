#include<stdio.h>
int main(){
	int nop,tq;
	
	printf("Enter Number of processes you have:: ");
	scanf("%d",&nop);
	
	printf("Enter Time Quantam:: ");
	scanf("%d",&tq);
	int arr[nop][5];
	int bt[nop];
	printf("Enter Burst times\n");
	for(int i=0;i<nop;i++){
		
		scanf("%d",&arr[i][1]);
		bt[i]=arr[i][1];
		arr[i][2]=0;
		arr[i][0]=i+1;
	}
	for(int i=0;i<nop;i++)	
		printf("%d %d %d\n",arr[i][0],arr[i][1],arr[i][2]);
	printf("\n");
	int c=0;
	for(int j=0;j<(nop*2);j++){
			
		for(int i=0;i<nop;i++){
		
			if(arr[i][1]!=0 && arr[i][1]>tq){
				
				arr[i][2]=c+tq;
				arr[i][1]-=tq;
				c=arr[i][2];	
			}
			
			else if(arr[i][1]!=0 && arr[i][1]<=tq){
				
				arr[i][2]=c+arr[i][1];
				c=arr[i][2];
				arr[i][1]=0;
			}
		}
	}
	
	
	int atat=0,awt=0;
		for(int i=0;i<nop;i++){
			printf("%d\n",arr[i][0]);	
			arr[i][3]=arr[i][2];
			arr[i][4]=arr[i][2]-bt[i];
					
			atat+=arr[i][3]	;
			awt+=arr[i][4];
				
		}
			printf("process  bt      ct      tat     wt\n");
			for(int i=0;i<nop;i++)	
				printf("%d \t %d \t  %d \t%d\t %d  \n",arr[i][0],bt[i],arr[i][2],arr[i][3],arr[i][4]);
			printf("Average tat::%d ",atat/nop);
			printf("Average wt::%d ",awt/nop);	
}
	

	
