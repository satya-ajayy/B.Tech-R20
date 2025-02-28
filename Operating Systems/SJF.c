#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
    int n,temp,tt=0,compl=0,d,i,j,index,idle=0;
    float avg_tat=0,avg_wt=0,sum_tat=0,sum_wt=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int a[10],b[10],cmpl[10]={0},tat[10]={0},wt[10]={0},p[10];
    int a_cpy[10],b_cpy[10];
    
    printf("\n");
    for(i=0;i<n;i++)
    {	
    	p[i]=i+1;
    	printf("Enter burst and arrival tyms P[%d]: ",i+1); 
		scanf("%d %d",&b[i],&a[i]);
		b_cpy[i]=b[i];a_cpy[i]=a[i];
    }
    for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(b[i]>b[j]){
				swap(&a[i],&a[j]);
    			swap(&b[i],&b[j]);
      			swap(&p[i],&p[j]);
        	}
		}
	}
	compl = 0;
    for(i=0;i<n;i++)
    {
    	index = p[i]-1;
    	if(a[i]>compl)
    	    idle=(a[i]-compl);
    	compl += (b[i]+idle);
    	idle=0;
    	cmpl[index]=compl;
	}
	for(i=0;i<n;i++)
	{
		tat[i]+=cmpl[i]-a[i];
		sum_tat += tat[i];
		wt[i]+=tat[i]-b[i];
		sum_wt += wt[i];
	}

    printf("\nPr\tat\tbt\tct\ttat\twt\n");
    for(i=0;i<n;i++)
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,a_cpy[i],b_cpy[i],cmpl[i],tat[i],wt[i]);
    printf("\nAverage Turn Around Time: %f",sum_tat/n);  
	printf("\nAverage Waiting Time: %f",sum_wt/n); 
return 0;  	
}