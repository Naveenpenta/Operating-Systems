#include<stdio.h>

int main(){
	
	int starting_position=0,ending_position,total_no_of_tracks,position_read_write_head,track_movements=0;
	
	printf("Enter disk contains how many tracks:\n");
	scanf("%d",&ending_position);
	
	ending_position=ending_position-1;
	
	printf("\nEnter request queue has how many no of tracks::\n");
	scanf("%d",&total_no_of_tracks);
	
	int request_queue[total_no_of_tracks];
	
	printf("\nEnter request queue tracks:");
	
	for(int i=0;i<total_no_of_tracks;i++){
		
		scanf("%d",&request_queue[i]);
		
	}
	printf("Enter read write head position\n");
	scanf("%d",&position_read_write_head);
	
	int total_track_movements=0;;
	for(int i=0;i<total_no_of_tracks;i++){
		
		if(position_read_write_head>= request_queue[i]){
			
			track_movements=(position_read_write_head-request_queue[i]);
			
		}
		else{
			
			track_movements=(request_queue[i]-position_read_write_head);
		}
		position_read_write_head=request_queue[i];
		total_track_movements+=track_movements;
		printf("\n read write head position:: %d ",position_read_write_head);
		printf("\n Travelled track movements:: %d ",track_movements);
		
	}
	printf("Total track Movements::%d ",total_track_movements);
	
}
