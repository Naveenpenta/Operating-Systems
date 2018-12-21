#include<stdio.h>
int checked(int rq[],int ele,int page_size)
{
	int count=0,j,i;
	for(i=0;i<page_size;i++)
	{
		if(rq[i]==ele)
		{
			j=i;
			count+=1;
			i=page_size;
		}
	}
	if(count==0)
	{
		return 999;
	}
	else
	{
		return j;
	}
}

main()
{
	int n;
	printf("enter the no of process");
	scanf("%d",&n);

	int a[n],temp=0,timer[3],checker[3],check[3],i,ct=0,m,established_count=0,index=0,l,k,replace_index,min,rq_fillcount=0,page_fault=0,page_size;
	printf("enter the size of the frame");
	scanf("%d",&page_size);
	int rq[page_size];
	for(i=0;i<n;i++)
	{
		printf("enter the element");
		scanf("%d",&a[i]);
	}
	for(i=0;i<3;i++)
	{
		check[i]=0;
	}
	for(i=0;i<page_size;i++)
	{
		rq[i]=-1;
	}
	
	for(i=0;i<n;i++)
	{
		printf("checking for %d element",a[i]);
		printf("\n");
		for(m=0;m<page_size;m++)
		{
			checker[m]=0;
		}
		int j =checked(rq,a[i],page_size);
		if(j==999)
		{
			//checker_time=0;
			established_count=0;
	
			if(rq_fillcount==page_size)
			{
			
						for(l=0;l<page_size;l++)
						{
							printf("\n");
							
							for(k=i+1;k<n;k++)
								{
									printf("\n");
									printf("checking for %d element with %d elemt from the array",rq[l],a[k]);	
									if(a[k]==rq[l])
									{
									
										printf(" the  %d element found at %d index  ",rq[l],k);
										checker[l]=k;
										k=n;
										established_count+=1;
										
										
									}
								}
						}
						printf("%d",established_count);
						if(established_count==page_size)
						{
						
							int max=-1;
							for(l=0;l<page_size;l++)
							{
								if(checker[l]>max)
								{
									max=checker[l];
									replace_index=l;
								}
							}
							
						}
						else
						{
							min=9999;
							for(l=0;l<page_size;l++)
							{
								if(checker[l]==0&&check[l]<min)
								{
									replace_index=l;
									min=check[l];
								}
							}
							
						}
				printf("replacinf at %d index",replace_index);
				printf("\n");
				rq[replace_index]=a[i];
				ct+=1;
				check[replace_index]=ct;
				printf("%d",page_fault);
				printf("\n");
				page_fault=page_fault+1;
				printf("%d",page_fault);
				printf("\n");
			}
			else
			{
				printf("\n");
				printf("found a page fault filling in %d indes",index);
				printf("\n");
				rq[index]=a[i];
				//changed place
				ct+=1;
				check[index]=ct;
				index+=1;
				printf(" in the upper loop %d",page_fault);
				printf("\n");
				page_fault=page_fault+1;
				rq_fillcount+=1;
				printf("%d in thr upperloop ",page_fault);
				printf("\n");
				
			
				
			}
		}
		else
		{
			printf("element already existing at %d index",j);
			printf("\n");
			ct+=1;
			check[j]=ct;
		
			
			
		}
	}
	printf("%d",page_fault);
	
}
