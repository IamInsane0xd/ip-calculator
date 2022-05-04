#include "includes.h"

int main()
{
	unsigned int network_count;
	narray_t networks;

	init_narray(&networks);
	
	printf("Ammount of networks: ");
	scanf_s("%u", &network_count);
	
	for (int i = 0; i < network_count; i++)
	{
		char *name = malloc(128);
		unsigned int host_count;
		network_t network;
		
		read_line("Network name: ", true, name, 128);
		printf("Ammount of hosts: ");
		scanf_s("%u", &host_count);
		
		create_network(&network, name, host_count);
		narray_append(&networks, &network);
	}

	return 0;
}
