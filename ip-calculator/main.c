#include "includes.h"

int main()
{
	int network_count, i;
	int *hosts_total = 0;
	char *base_name = malloc(MAX_NETWORK_NAME_LENGTH),
			 *base_ip_string = malloc(IP_STRING_LENGTH),
			 *base_mask_string = malloc(INT_MASK_STRING_LENGTH);
	network_t base_network;
	ip_t base_ip;
	mask_t base_mask;
	network_t *networks[MAX_NETWORK_COUNT];

	init_array(&networks);
	
	printf("Ammount of networks: ");
	scanf_s("%i", &network_count);

	read_line("Base network name: ", true, true, base_name, MAX_NETWORK_NAME_LENGTH);
	read_line("Base network IP: ", true, false, base_ip_string, IP_STRING_LENGTH);
	read_line("Base network mask: ", true, false, base_mask_string, INT_MASK_STRING_LENGTH);

	parse_ip_string(base_ip_string, &base_ip);
	parse_mask_string(base_mask_string, &base_mask);
	
	create_base_network(&base_network, base_name, 0, base_ip, base_mask);

	printf("\n\nWARNING: INPUT NETWORKS IN DESCENDING HOST COUNT ORDER!!\n");
	printf("         (else the calculations will be wrong)\n\n");
	
	for (i = 0; i < network_count; i++)
	{
		char *name = malloc(MAX_NETWORK_NAME_LENGTH);
		int host_count = 0;
		network_t *network = (network_t *) malloc(sizeof(network_t));
		
		read_line("Network name: ", true, true, name, MAX_NETWORK_NAME_LENGTH);
		printf("Ammount of hosts: ");
		scanf_s("%i", &host_count);
		
		create_network(network, name, host_count);
		
		networks[i] = network;
	}

	calculate_networks(networks, network_count, &base_network);
	print_networks_in_table(networks, network_count);

	return 0;
}
