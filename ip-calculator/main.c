#include "includes.h"

int main()
{
	unsigned int network_count;
	network_t base_network;
	char *base_name = malloc(MAX_NETWORK_NAME_LENGTH),
			 *base_ip_string = malloc(IP_STRING_LENGTH),
			 *base_mask_string = malloc(INT_MASK_STRING_LENGTH);
	ip_t base_ip;
	mask_t base_mask;
	narray_t networks;
	
	init_narray(&networks);
	
	printf("Ammount of networks: ");
	scanf_s("%u", &network_count);

	read_line("Base network name: ", true, true, base_name, MAX_NETWORK_NAME_LENGTH);
	read_line("Base network IP: ", true, false, base_ip_string, IP_STRING_LENGTH);
	read_line("Base network mask: ", true, false, base_mask_string, INT_MASK_STRING_LENGTH);

	parse_ip_string(&base_ip, base_ip_string);
	parse_mask_string(&base_mask, base_mask_string);
	
	create_base_network(&base_network, base_name, network_count, base_ip, base_mask);
	
	for (unsigned int i = 0; i < network_count; i++)
	{
		char *name = malloc(128);
		unsigned int host_count;
		network_t network;
		
		read_line("Network name: ", true, true, name, MAX_NETWORK_NAME_LENGTH);
		printf("Ammount of hosts: ");
		scanf_s("%u", &host_count);
		
		create_network(&network, name, host_count);
		narray_append(&networks, &network);
	}

	return 0;
}
