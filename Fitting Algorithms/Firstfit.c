#include<stdio.h>
int main(){
	
	int no_of_process,no_of_blocks,ii=0,jj=0,i=0,j=0;
	printf("enter number of processess  you have :\n");
	scanf("%d",&no_of_process);
	printf("enter number of blocks you have :\n");
	scanf("%d",&no_of_blocks);
	int block[no_of_blocks][no_of_blocks],pro[no_of_process];
	
	for(ii=1;ii<=no_of_process;ii++){
		printf("enter process p %d size::",ii);
		scanf("%d",&pro[ii]);
	}
	
	for(jj=1;jj<=no_of_blocks;jj++){
		printf("enter block %d size::",jj);
		scanf("%d",&block[jj][0]);
		block[jj][1]=-1;
		
	}
	
	//for(i=1;i<=no_of_blocks;i++){
	//	printf("%d ff %d  ff  %d\n",pro[i],block[i][0],block[i][1]);
		
	
	int m;
	for(i=1;i<=no_of_process;i++){
	
		for(j=1;j<=no_of_blocks;j++){
			if((pro[i]<=block[j][0]) && (block[j][1]==-1)){
				block[j][1]=i;
				//printf("%d",j);
				break;
				
				
			}
			
		}
		
		
		
	}
	
	for(m=1;m<=no_of_process;m++){
		int kk=0;
		for(j=1;j<=no_of_blocks;j++){
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
