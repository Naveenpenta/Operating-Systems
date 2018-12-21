#include<stdio.h>
#define true 1
#define false 0
int main(){
	
	int nob,pos=0,nof,j,k,f=0,c=0,f3,max,count=0;
	
	printf("enter number of pages:");
	scanf("%d\n",&nob);
	
	int i,block[nob];
	for(i=0;i<nob;++i){
		scanf("%d",&block[i]);
		
	}
	printf("enter number of frames:");
	scanf("%d",&nof);
	int frame[nof],f1,f2;
	int temp[nof];
		for(i=0;i<nof;i++){
		
			frame[i]=-1;
		}
	
	for(j=0;j<nob;j++){
		f1=f2=0;
		for(i=0;i<nof;i++){
				if(frame[i]==block[j]) {
				
					f1=f2=1;
					break;
			}
		}
		
		if(f1==0){
			for(i=0;i<nof;i++){
				if(frame[i]==-1){
					frame[i]=block[j];
					count++;
					f2=1;
					break;
					
				}
				
			}
		}
		
		if(f2==0){
			f3=0;
			for(i=0;i<nof;i++){
				temp[i]=-1;	
				for(k=j+1;k<nob;k++){
					if(frame[i]==block[k]){
						temp[i]=k;
						break;
							
					}	
				}
			}
			for(i=0;i<nof;i++){
				if(temp[i]==-1){
					pos=i;
					f3=1;
					break;					
				}
			}			
		
			if(f3==0){
				max=temp[0];
				pos=0;
				for(i=1;i<nof;i++	){
					if(temp[i]>max){
						max=frame[i];
						pos=i;
						
					}
					
				}
				
			}
				
			frame[pos]=block[j];
			count++;	
				
				
		}
			
		for(i=0;i<nof;i++){
			printf("%d ",frame[i]);
			
		}
		printf("\n");
			
		
		
	}
	printf("\npage faults:: %d",count);
}
