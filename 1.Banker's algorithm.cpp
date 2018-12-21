#include<stdio.h>
#include<string.h>

int main()
{
	int nop,nor;
	printf("Enter No of processes: ");
	scanf("%d",&nop);
	
	printf("Enter No of resources: ");
	scanf("%d",&nor);
	
	int allocation[nop][nor],max[nop][nor],need[nop][nor];
	int available[nor],work[nor],finish[nop],safe_sequence[nop];
	
	memset(finish,0,nop*sizeof(int));
	
	printf("Enter Allocation\n");
	for(int i=0; i<nop; i++)
	{
		for(int j=0; j<nor; j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}
	
	printf("Enter Max Need\n");
	for(int i=0; i<nop; i++)
	{
		for(int j=0; j<nor; j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	
	printf("Enter Available\n");
	for(int i=0; i<nor; i++)
	{
		scanf("%d",&available[i]);
	}
	
	for(int i=0; i<nop; i++)
	{
		for(int j=0; j<nor; j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	
	for(int i=0; i<nor; i++)
	{
		work[i]=available[i];
	}
	
	int loop_count=nop;
	int count,index=0;
	while(loop_count)
	{
		for(int i=0; i<nop; i++)
		{
			if(finish[i]==0)
			{
				count=0;
				for(int j=0; j<nor; j++)
				{
					if(need[i][j]<=work[j])
					{
						count++;
					}
					else
						break;
				}
				if(count==nor)
				{
					for(int k=0; k<nor; k++)
					{
						work[k]=work[k]+allocation[i][k];
					}
					finish[i]=1;
					loop_count--;
					safe_sequence[index++]=i;
				}
			}
		}
	}
	
	printf("\nSafe Sequence\n< ");
	for(int i=0; i<nop; i++)
	{
		printf("p%d ",safe_sequence[i]);
	}
	printf(" >\n");
	
	return 0;
}
