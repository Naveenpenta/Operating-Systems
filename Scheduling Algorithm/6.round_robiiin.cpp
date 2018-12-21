#include<stdio.h>
#include<conio.h>
main()
{
	int a[10],b[10],c[10],t[10],w[10],r_a[10],r_b[10],entries,tq;
	printf("\nEnter number of the processes:");
	scanf("%d",&entries);
	printf("\nEnter the time quantum:");
	scanf("%d",&tq);
	for(int i=0;i<entries;i++)
	{
		printf("\nEnter the arival time of P%d:",i+1);
		scanf("%d",&a[i]);
		printf("\nEnter the burst time of P%d:",i+1);
		scanf("%d",&b[i]);
		r_a[i]=a[i];
		r_b[i]=b[i];
	}
	int small=0,c_prev=0;
	while(1)
	{
		for(int i=0;i<entries;i++)
		{
			if(r_b[i]!=0)
			{
				small=i;
				break;
			}
		}
		if(r_b[small]==0)
			break;
		for(int i=0;i<entries;i++)
		{
			if(r_a[small]>r_a[i]&&r_b[i]!=0)
				small=i;
			else if(r_a[small]==r_a[i]&&r_b[i]!=0&&a[small]<a[i])
				small=i;
		}
		if(a[small]>c_prev)
			c_prev=a[small];
		if(r_b[small]<tq)
		{
			c[small]=c_prev+r_b[small];
			r_b[small]=0;
			c_prev=c[small];
			r_a[small]=c_prev;
		}
		else
		{
			c[small]=c_prev+tq;
			r_b[small]=r_b[small]-tq;
			c_prev=c[small];
			r_a[small]=c_prev;
		}
		printf("|P%d|",small+1,c_prev);
	}
	printf("\na\tb\tc");
	for(int i=0;i<entries;i++)
	{
		printf("\n%d\t%d\t%d",a[i],b[i],c[i]);
	}
}
