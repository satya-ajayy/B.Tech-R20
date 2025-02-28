#include<stdio.h>

struct ed
{
	int v1,v2,w;
}edj[20],temp;

int main()
{
	int i,j,n=0,s,d,par[20],s1,d1;
	printf("Enter no of edges :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the node1,node2,Weight :");
		scanf("%d %d %d",&edj[i].v1,&edj[i].v2,&edj[i].w);
		par[i]=0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++)
			if(edj[j].w>edj[i].w){		
				temp=edj[i];
				edj[i]=edj[j];
				edj[j]=temp;
		}
	}
	printf("\nENTERED VALUES\n");
	for(i=0;i<n;i++)
	printf("%d  %d  %d\n",edj[i].v1,edj[i].v2,edj[i].w);
	printf("\nBROADCAST TREE FOR THE GIVEN GRAPH\n");
	for(i=0;i<n;i++){
		s=edj[i].v1;
		d=edj[i].v2;
		s1=s;d1=d;
		while(par[s1]>0)
		s1=par[s1];
		while(par[d1]>0)
		d1=par[d1];
		if(s1!=d1){
			par[d]=s;
			printf("%d  %d  %d\n",s,d,edj[i].w);
		}
	}
	return 0; 
}