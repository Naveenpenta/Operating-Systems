#include<stdio.h>
#include<iostream>
#include<algorithm>
int main(){
	
	int start=0,end,prwh,trmov,total_no_of_tracks,total_track_movements=0;
	
	printf("Enter disk contains how many tracks:\n");
	scanf("%d",&end);
	end-=1;
	
	printf("\nEnter request queue has how many no of tracks::\n");
	scanf("%d",&total_no_of_tracks);
	
	int rqueue[total_no_of_tracks];
	int ref[total_no_of_tracks];
	printf("\nEnter request queue tracks between 0 to %d only:",end);
	
	for(int i=0;i<total_no_of_tracks;i++){
		
		scanf("%d",&rqueue[i]);
		ref[i]=0;
		
	}
	printf("Enter read write head position\n");
	scanf("%d",&prwh);
	
	for(int i=0;i<total_no_of_tracks;i++){
		
		for(int j=i;j<total_no_of_tracks;j++){
		//	printf("b");
			if(rqueue[i]>rqueue[j]){
		//		printf("c\n");
				int temp=rqueue[i];
				rqueue[i]=rqueue[j];
				rqueue[j]=temp;
				
			}
		}
	}
	
	for(int i=0;i<total_no_of_tracks;i++){
			
		int list_distance=9999,index=i;
		for(int j=0;j<total_no_of_tracks;j++){
			
			if(ref[j]!=1){
				int dist=0;
				if(prwh>=rqueue[j]){
					
					dist=prwh-rqueue[j];
				}
				else{
					dist=rqueue[j]-prwh;
				}
				
				if(list_distance>dist){
					
					list_distance=dist;
					index=j;
				}	
			}
			
			
		}
		
		if(prwh>=rqueue[index]){
			
			trmov=prwh-rqueue[index];
		}
		else{
			
			trmov=rqueue[index]-prwh;
		}
		
		prwh=rqueue[index];
		ref[index]=1;
		total_track_movements=total_track_movements+trmov;
		printf("\nposition of read write head %d:: ",prwh);
		printf("\ntrack postionss moved %d ::",trmov);
		printf("\n total track movements %d ",total_track_movements);
		
		
		
	}
	
	
	printf("\n total track movements %d ",total_track_movements);
	
	
//	for(int i=0;i<total_no_of_tracks;i++){
		//printf("d\n");
//		printf("\n %d",rqueue[i]);
//	}
}
