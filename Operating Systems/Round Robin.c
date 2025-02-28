#include<stdio.h>  
#include<conio.h>  
  
void main()  
{  
    int i, n, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    printf("Total number of process in the system : ");  
    scanf("%d", &n);  
    y = n; 

for(i=0; i<n; i++)  
{  
printf("Enter the Arrival and Burst time of the Process[%d]: ", i+1);   
scanf("%d %d", &at[i], &bt[i]);  
temp[i] = bt[i];
}  
  
printf("Enter the Time Quantum: ");  
scanf("%d", &quant);
printf("PNo    AT     BT     TAT    WT\n");  
for(sum=0,i=0; y!=0; )  
{  
if(temp[i] <= quant && temp[i] > 0) 
{  
    sum = sum + temp[i];  
    temp[i] = 0;  
    count=1;  
    }     
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - quant;  
        sum = sum + quant;    
    }  
    if(temp[i]==0 && count==1)  
    {  
        y--;
        printf("P%d    %2d     %2d     %2d     %2d \n",i+1,at[i],bt[i],
										     sum-at[i], sum-at[i]-bt[i]);  
        wt = wt+sum-at[i]-bt[i];  
        tat = tat+sum-at[i];  
        count =0;     
    }  
    if(i==n-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}  
avg_wt = wt * 1.0/n;  
avg_tat = tat * 1.0/n;  
printf("Average Turn Around Time: %f\n", avg_wt);  
printf("Average Waiting Time: %f", avg_tat);   
}  
