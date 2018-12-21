#include<stdio.h>
int main(){
int nop,i,k=1,l,g,a,r,m,p,p1,temp,temp1;
printf("enter how many number of processes");
scanf("%d",&nop);
int pr[nop];
int bt[nop];
int ct[nop];
int tat[nop];
int wt[nop];

	for (i=0;i<nop;i++){

		printf("enter processor p %d burst time :",i+1);
		scanf("%d",&bt[i]);
		pr[i]=k;
		k=k+1;
		printf("\n");

	}
	int j;
/*	for(j=0;j<nop;j++){
	
		printf("%d -- %d\n ",pr[j],bt[j]);
	
	}*/	printf("\n\n\n");
	
	for(l=1;l<nop;l++){
		for(m=0;m<i;m++){
			if(bt[l]<bt[m]){
				
				temp=bt[l];
				bt[l]=bt[m];
				bt[m]=temp;
				
				temp1=pr[l];
				pr[l]=pr[m];
				pr[m]=temp1;
			}
		}
	}
	/*
		for(j=0;j<nop;j++){
	
		printf("%d -- %d\n ",pr[j],bt[j]);
	}*/
	
	ct[0]=bt[0];
	tat[0]=ct[0];
	for(g=1;g<nop;g++){
		ct[g]=bt[g]+ct[g-1];
		tat[g]=ct[g];
		
	}
	
	for(r=0;r<nop;r++){
		
	wt[r]=tat[r]-bt[r];	
	}
	printf("\n********  |  ****** | ***** |  *****  |  *****");
	printf("\nProcess        BT       CT      TAT        WT  ");
	printf("\n********  |  ****** | ***** |  *****  |  *****");
	for( a=0;a<nop;a++){
	
		printf("\n%d\t\t%d\t%d\t%d\t%d\t",pr[a],bt[a],ct[a],tat[a],wt[a]);
	}
	printf("\n**************************************************");		
	int total=0;
	for(p=0;p<nop;p++){
			
		total=total+tat[p];
	}
	
	printf("\n\n\n Average turn around time : %d",total/nop);
	
		int total1=0;
	for(p1=0;p1<nop;p1++){
			
		total1=total1+wt[p1];
	}
	
	printf("\n\n\n Average Wating time : %d\n",total1/nop);

}
