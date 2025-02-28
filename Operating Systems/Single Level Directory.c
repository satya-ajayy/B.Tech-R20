#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i=0,n=0,ch=0,flag=0;
	char name[10],dname[10],fname[10][10];
	printf("Enter the directory Name : \n");
	scanf("%s",&dname);
	do
	{
		printf("\n 1.Create \n 2.Delete \n 3.Search \n 4.Display \n 5.Exit \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the Name of the File : \n");
					scanf("%s",&name);
					flag=0;
					if(n==0)
					{
						strcpy(fname[n],name);
						n++;
					}
					else
					{
						for(int i=0;i<n;i++)
						{
							if(!strcmp(fname[i],name))
							{
								printf("Already Existing \n");
								flag=1;
								break;
							}
						}
						if(flag==0)
						{
							strcpy(fname[n],name);
							n++;
						}
					}
					break;
			case 2: printf("Enter the name of the file : \n");
					scanf("%s",name);
					for(i=0;i<n;i++)
					{
						if(!strcmp(name,fname[i]))
						{
							printf("\n File is Deleted %s \n",name);
							for(int j=i;j<n;j++)
							{
								strcpy(fname[j],fname[j+1]);
							}
							n--;
							break;
						}
					}
					break;
			case 3: printf("Enter the filename of the searched \n:");
					scanf("%s",&name);
					for(int i=0;i<n;i++)
					{
						if(!strcmp(name,fname[i]))
						{
							printf("File is found %s ",fname[i]);
							break;
						}
					}	
					if(i==n)
					{
						printf("File is Not Found \n");
					}
					break;
			case 4: printf("Displaying the files : \n");
					printf("\n Directory is %s : ",dname);
					printf("File Names are : \n");
					for(int i=0;i<n;i++)
					{
						printf("%s\n",fname[i]);
					}		
					break;
			case 5: exit(0);
			default: printf("Invalid Choice \n");
		}
	}while(ch!=5);
	return 0;	
}