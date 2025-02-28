#include <stdio.h>
#include<stdlib.h>

#define no_of_packets 15
#define window_size 5
int main(){
	
	int p,i=1,a,w,nac,ack;
	a=no_of_packets;
	w=window_size;
	
	printf("Transmitting begins...! No of Packets : %d\n",a);
	while(i<=a){
		printf("Sending Packets from %d to %d\n",i,w+i-1);
		for(p=i;p<w+i;p++)
			printf("Transmitting Packet %d\n",p);
		
		nac = i+rand()%w;
		printf("NACK : %d\n",nac);
		printf("Sending Packet : %d\n",nac);
		printf("Ack : %d\n",nac+1);
		printf("Ack : %d\n",i+w);
		i = i + w;
	}
return 0;
}