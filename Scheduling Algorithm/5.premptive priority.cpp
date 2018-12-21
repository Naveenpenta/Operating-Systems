#include<stdio.h>
void sort(int p[],int pri[],int a[],int b[],int nop){
	
	for(int i=0;i<nop;i++){
		for(int j=0;j<nop-i-1;j++){
			if(a[j]>a[j+1]){
				
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				
				t=pri[j];
				pri[j]=pri[j+1];
				pri[j+1]=t;			
		
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
				
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;		
				
			}
		}
		
	}
	
	
}
int main(){
	
	int nop=4;	
	//int arr[6][5]={1,2,3,4,5,6,2,4,6,3,8,7,0,1,2,3,4,5,4,2,3,5,1,4,0,0,0,0,0,0};
	int p[4]={1,2,3,4,};
	int pri[4]={1,2,3,4};
	int a[4]={2,8,12,17};
	int b[4]={4,2,3,1};
	int c[4]={0,0,0,0};
	sort(p,pri,a,b,nop);
	for(int i=0;i<nop;i++)
		printf("%d %d %d %d %d \n",p[i],pri[i],a[i],b[i],c[i]);
	int first=0,min,pos,ctime=0;
	while(1){
	int small=0,index=-1,flag=0;
		for(int i=0;i<nop;i++){
				
			if(b[i]!=0){
			   small=i;	
			}
		} 
		if(small==0)
			break;
		if(first==0){
			c[0]=ctime+a[0]+1;
			ctime=c[0];
			b[0]=b[0]-1;
			first=1;
			continue;
		}	
		
		for(int i=0;i<nop;i++){
			
			if(a[i]<=ctime && b[i]!=0){
				index=i;
			}
		}
		int priority=9999,ind=-1;
		for(int i=0;i<=index;i++){
			if(pri[i]<priority && b[i]!=0){
				priority=pri[i];
				ind=i;
			}	
		}
			
		printf("%d:",ctime);
		c[ind]=ctime+1;
		b[ind]=b[ind]-1;
		ctime=c[ind];	
		
	}

	for(int i=0;i<nop;i++)
		printf("%d %d %d %d %d \n",p[i],pri[i],a[i],b[i],c[i]);

}


