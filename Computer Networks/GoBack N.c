#include<stdio.h>
#define no_of_packets 5

int main()
{
	int npackets,sent=0,ack,i;
	npackets = no_of_packets;
	while(1)
	{
		for(i=0;i<npackets;i++)
		{
			printf("Frame %d has been transmitted.\n",sent);
			sent++;
			if(sent >= npackets)
				break;
		}
		printf("\nPlease enter the last Acknowledgement received :");
		scanf("%d",&ack);
		if(ack >= npackets)
			break;
		else
			sent = ack;
	}
return 0;
}