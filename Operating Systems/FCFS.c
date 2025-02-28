#include<stdio.h>
#define SIZE 10

void swap(int *a,int *b)
{
	int temp=*a;*a=*b;*b=temp;
}

int main()
{
    int n,temp,tt=0,tym=0,index,i,j,idle=0;
    float sum_tat=0,sum_wt=0;
    printf("Enter Number of processes: ");
    scanf("%d",&n);
    int a[SIZE],b[SIZE],cmpl[SIZE],tat[SIZE];
	int wt[SIZE],p[SIZE],a_cpy[SIZE],b_cpy[SIZE];

    for(i=0;i<n;i++)
    {	
    	p[i]=i+1;
    	printf("Enter burst and arrival tyms P[%d]: ",i+1); 
		scanf("%d %d",&b[i],&a[i]);
		b_cpy[i]=b[i];a_cpy[i]=a[i];
    }
    
    for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(&a[i],&a[j]);
    			swap(&b[i],&b[j]);
      			swap(&p[i],&p[j]);
        	}
		}
	}
	tym= a[0];
    for(i=0;i<n;i++)
    {
    	index = p[i]-1;
    	if(a[i]>tym)
    	    idle= a[i]-tym;
    	tym += (b[i]+idle);
    	idle=0;
    	cmpl[index]=tym;
	}
	for(i=0;i<n;i++)
	{
		tat[i]=cmpl[i]-a_cpy[i];
		sum_tat += tat[i];
		wt[i]=tat[i]-b_cpy[i];
		sum_wt += wt[i];
	}
    
    printf("\nPr\tat\tbt\tct\ttat\twt\n");
    for(i=0;i<n;i++)
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,a_cpy[i],b_cpy[i],cmpl[i],tat[i],wt[i]);
    printf("\nAverage Turn Around Time: %f",sum_tat/n);  
	printf("\nAverage Waiting Time: %f",sum_wt/n); 
return 0; 	
}