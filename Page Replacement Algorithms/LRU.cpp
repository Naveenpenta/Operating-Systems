#include<stdio.h>
int main(){
	
	int nof;//=3;
	int nob;//=20;
	//int block[nob]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	
	printf("enter number of frames::\n");
	scanf("%d",&nof);
	
	printf("enter number of blocks::\n");
	scanf("%d",&nob);
	
	int block[nob];
	
	printf("enter %d blocks:\n",nob);
	for(int i=0;i<nob;i++){
		scanf("%d",&block[i]);
	}

	int frame[nof],f1,f2;
	int temp[nof];
		for(int i=0;i<nof;i++){
		
			frame[i]=-1;
		}
	int count=0,temp1[nof];
	for(int j=0;j<nob;j++){
		f1=f2=0;
			for(int i=0;i<nof;i++){
					if(frame[i]==block[j]) {		
						f1=f2=1;
						break;
				}
			}
		
			if(f1==0){
				for(int i=0;i<nof;i++){
					if(frame[i]==-1){
						frame[i]=block[j];
						count++;
						f2=1;
						break;		
					}
					
				}
			}
		
		if(f2==0){
		
			//printf("====%d====\n",block[j],block[j-1]);
					for(int k=0;k<nof;k++){
						temp1[k]=-1;
					}
					
					for(int k=j-1;k>=0;k--){
						int counting=0;
						//printf("--%d--\n",block[k]);
						for(int l=0;l<nof;l++){
							if(temp1[l]!=block[k]){
								counting=counting+1;
							}
						}
						
						if(counting==nof){
							int flagg=0;
							for(int m=0;m<nof;m++){
								if(temp1[m]==-1 && flagg==0){
									temp1[m]=block[k];
									flagg=1;
								}
							}
						}
						
						
						
					}	
			
							
		}
			
			
			for(int i=0;i<nof;i++){
				if(temp1[nof-1]==frame[i]){
					count++;
					frame[i]=block[j];
					break;
					
				}
				
			}
			
				
		
		
		for(int i=0;i<nof;i++){
			printf("%d ",frame[i]);
		}
		printf("\n");
	}
	printf("\npage faults:: %d",count);
}
