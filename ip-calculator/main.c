#include "includes.h"

int main()
{
	unsigned int network_count;
	network_t base_network;
	char *base_name = malloc(128);
	char *base_ip_string = malloc(16);
	char *base_mask_string = malloc(16);
	ip_t base_ip;
	mask_t base_mask;
	narray_t networks;
	
	init_narray(&networks);
	
	printf("Ammount of networks: ");
	scanf_s("%u", &network_count);

	read_line("Base network name: ", true, true, base_name, 128);
	read_line("Base network IP: ", true, false, base_ip_string, 16);
	read_line("Base network mask: ", true, false, base_mask_string, 16);

	parse_ip_string(&base_ip, base_ip_string);
	parse_mask_string(&base_mask, base_mask_string);
	
	create_base_network(&base_network, base_name, network_count, base_ip, base_mask);
	
	for (unsigned int i = 0; i < network_count; i++)
	{
		char *name = malloc(128);
		unsigned int host_count;
		network_t network;
		
		read_line("Network name: ", true, true, name, 128);
		printf("Ammount of hosts: ");
		scanf_s("%u", &host_count);
		
		create_network(&network, name, host_count);
		narray_append(&networks, &network);
	}

	return 0;
}
