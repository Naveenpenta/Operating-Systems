
#include<stdio.h>
void sort(int p[],int a[],int b[],int nop){
	
	for(int i=0;i<nop;i++){
		for(int j=0;j<nop-i-1;j++){
			if(a[j]>a[j+1]){
				
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;			
		
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
	
	int nop=5;	
	//int arr[6][5]={1,2,3,4,5,6,2,4,6,3,8,7,0,1,2,3,4,5,4,2,3,5,1,4,0,0,0,0,0,0};
	int p[5]={1,2,3,4,5};
	int a[5]={1,2,3,4,5};
	int b[5]={7,5,1,2,8 };
	int c[5]={0,0,0,0,0};
	sort(p,a,b,nop);
	for(int i=0;i<nop;i++)
		printf("%d %d %d %d \n",p[i],a[i],b[i],c[i]);
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
			
			c[0]=ctime+a[0]+b[0];
			b[0]=0;
			ctime=c[0];
			first=1;
			continue;
		}
		
		for(int i=0;i<nop;i++){
			
			if(a[i]<=ctime && b[i]!=0){
				index=i;
			}
		}
		int ind=0, min=9999;
		if(index==-1){
			for(int i=0;i<nop;i++){
				if(a[i]>ctime && b[i]!=0){
					ind=i;
					flag=1;
					break;
				}
			}
		}
		else{
			
			for(int i=0;i<=index;i++){
				
				if(min>b[i] && b[i]!=0){
					min=b[i];
					ind=i;
				}
				
				
			}
		}
		if(flag==1){
			c[ind]=a[ind]+b[ind];
			ctime=c[ind];
			b[ind]=0;
		}
		else{
			c[ind]=ctime+b[ind];
			ctime=c[ind];
			b[ind]=0;
		}
	}
	
		for(int i=0;i<nop;i++)
		printf("%d %d %d %d \n",p[i],a[i],b[i],c[i]);
}
