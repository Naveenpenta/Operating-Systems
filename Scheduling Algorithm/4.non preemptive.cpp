#include<stdio.h>
#define MAX 99999
int main(){
	int nop;
//	printf("Enter no of processes: ");
//	scanf("%d",&nop);
	nop=6;	
	//int arr[6][5]={1,2,3,4,5,6,2,4,6,3,8,7,0,1,2,3,4,5,4,2,3,5,1,4,0,0,0,0,0,0};
	int p[6]={1,2,3,4,5,6};
	int pri[6]={2,4,1,0,5,6};
	int a[6]={0,7,10,12,5,13};
	int b[6]={4,2,1,3,1,4};
	int c[6]={0,0,0,0,0,0};
	
	for(int i=0;i<nop;i++)
		printf("%d %d %d %d %d \n",p[i],pri[i],a[i],b[i],c[i]);
	int first=0,min,pos,ctime=0;
	for(int i=0;i<nop;i++){
		int position=-1;
		
		if(first==0){
			min=a[0];
			for(int j=1;j<nop;j++){
				if(min>a[i]){	
					min=a[i];
					pos=i;
				}
			}
			
		c[pos]=ctime+a[pos]+b[pos];
		ctime=c[pos];	
		first=1;
		pri[pos]=MAX;
		continue;	
		}
		min=pri[0];
		for(int j=0;j<nop;j++){
		
			if(pri[j]!=MAX && a[j]<=ctime && min>pri[j]){
				min=pri[j];
				position=j;
			}
		}
		if(position==-1){
			int minn=ctime;
			for(int j=0;j<nop;j++){
				for(int k=0;k<nop-1;k++){
					
					if(a[k]>a[k+1]){
						int temp=a[k];
						a[k]=a[k+1];
						a[k+1]=temp;
						
						temp=b[k];
						b[k]=b[k+1];
						b[k+1]=temp;
						
						temp=pri[k];
						pri[k]=pri[k+1];
						pri[k+1]=temp;
						
						temp=c[k];
						c[k]=c[k+1];
						c[k+1]=temp;
						
					}
				}
			}
			
			for(int i=0;i<nop;i++){
				if(a[i]>minn && pri[i]!=MAX){
					c[i]=a[i]+b[i];
					ctime=c[i];
					pri[i]=MAX;
					break;
				}
				
			}
		}
		else{
			c[position]=ctime+b[position];
			ctime=c[position];
			pri[position]=MAX;
			
		}	
		
				
	}
	
	for(int i=0;i<nop;i++)
		printf("%d\n",c[i]);
	
}
