#include<stdio.h>
#define true 1
#define false 0

int check(int no_of_frames,int no_of_blocks,int Frame[],int i){
	int j,k;
	
	for(j=0;j<no_of_blocks;j++){
		
		if(Frame[j]==i)
		{
		return(false);
		break;			
		}
	}
	
	
	return(true);
	
}


int main(){
	
	int no_of_blocks,no_of_frames,j,k,f=0,c=0,count=0;
	printf("enter number of blocks:");
	scanf("%d\n",&no_of_blocks);
	int i,block[no_of_blocks];
	for(i=0;i<no_of_blocks;i++){
		scanf("%d",&block[i]);
		
	}
	printf("enter number of frames:");
	scanf("%d",&no_of_frames);
	int Frame[no_of_frames];
	Frame[f]=block[0];
	printf("%d  ",block[0]);
	
	for(j=1;j<no_of_blocks;j++){
			c=0;
		//	int kk=check(no_of_frames,no_of_blocks,Frame,block[j]);
			
		for(i=0;i<no_of_frames;i++){
				if(Frame[i]==block[j]) 
					c++;
		}
			if(c==0)
			{	printf("%d  ",block[j]);
				f++;
				Frame[f]=block[j];
				count++;
				if(f==no_of_frames-1) 
				{
				
					f=-1;
					
				}
				
			}
			
		
		//	printf("value %d::",kk);

	}
	printf("\ncount:: %d",count+1);
}
