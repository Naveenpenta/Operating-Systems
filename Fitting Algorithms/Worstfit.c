#include<stdio.h>
#define MAX -99999
int main(){
	int nop,nob,i,j,k,l;
	
	printf("Enter number of processess you have: ");
	scanf("%d",&nop);
	
	printf("Enter number of Blocks you have: ");
	scanf("%d",&nob);
	
	int block[nob][nob], process[nop];
	
	for(i=1;i<=nop;i++){
		printf("Enter process p %d size: ",i);
		scanf("%d",&process[i]);
		
	}
	for(i=1;i<=nob;i++){
		printf("Enter Block b %d size: ",i);
		scanf("%d",&block[i][0]);
		block[i][1]=-1;
	}
/*	for(i=1;i<=nob;i++){
		printf("%d ff %d  ff  %d\n",process[i],block[i][0],block[i][1]);
		
	}*/
	
	for(j=1;j<=nop;j++){
		int max=MAX,present=0,position=0;
		for(k=1;k<=nob;k++){	
			if(process[j]<=block[k][0] && block[k][1]==-1){
				int min=block[k][0];
				present++;
				if(min>=max){
					position=k;
					max=min;
				}
			}		
		}
		if(present!=0 && block[position][1]==-1){
			block[position][1]=j;
				
		}
		
	}
	int m=0;
	for(m=1;m<=nop;m++){
		int kk=0;
		for(j=1;j<=nob;j++){
			if(block[j][1]==m && block[j][1]!=-1){
				kk=j;
				break;
			}
			
		}
		if(kk!=0)
			printf("\nprocess p %d  fit in :%d block at %d location \n",m,block[kk][0],kk);
			
		else{
			printf("process p %d must wait:\n",m);
		}	
			
	}
}
