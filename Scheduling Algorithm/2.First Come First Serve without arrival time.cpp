#include<stdio.h>
int main(){
	int nop;
	
	printf("Enter Number of processes you have:: ");
	scanf("%d",&nop);
	
	int pro[nop],at[nop],bt[nop],ct[nop],bte[nop];
	
	int arr[nop][nop+1];
	
	printf("Enter burst times\n");
	for(int i=0;i<nop;i++){
		
		scanf("%d",&arr[i][1]);
		arr[i][2]=0;
		arr[i][0]=i+1;
	}
	for(int i=0;i<nop;i++)	
		printf("%d %d %d\n",arr[i][0],arr[i][1],arr[i][2]);
	printf("\n");
	arr[0][2]=arr[0][1];
	for(int i=1;i<nop;i++) {
		
		arr[i][2]+=arr[i-1][2]+arr[i][1];
		
	}
	


int atat=0,awt=0;
for(int i=0;i<nop;i++){
	printf("%d\n",arr[i][0]);	
	arr[i][3]=arr[i][2];
	arr[i][4]=arr[i][2]-arr[i][1];
			
	atat+=arr[i][3]	;
	awt+=arr[i][4];
		
	}
	printf("process  bt   ct   tat  wt\n");
	for(int i=0;i<nop;i++)	
		printf("%d \t %d \t  %d \t%d\t %d  \n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4]);
	printf("Average tat::%d ",atat/nop);
	printf("Average wt::%d ",awt/nop);	
}
