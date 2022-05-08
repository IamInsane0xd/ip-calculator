#include "includes.h"

void create_network(network_t *network, char *name, int hosts)
{
	network->name = name;
	network->hosts = hosts;
}

void create_base_network(network_t *base_network, char *name, int hosts, ip_t ip, mask_t mask)
{
	base_network->name = name;
	base_network->hosts = hosts;
	base_network->network = ip;
	base_network->mask = mask;
}

void network_add_ips(network_t *network, ip_t network_ip, ip_t first_assignable, ip_t broadcast)
{
	network->network = network_ip;
	network->first_assignable = first_assignable;
	network->broadcast = broadcast;
}

void network_add_mask(network_t *network, mask_t mask)
{
	network->mask = mask;
}

void network_add_ips_and_mask(network_t *network, ip_t network_ip, ip_t first_assignable, ip_t broadcast, mask_t mask)
{
	network_add_ips(network, network_ip, first_assignable, broadcast);
	network_add_mask(network, mask);
}

void network_get_slash_mask(network_t network, char *out)
{
	mask_t mask = network.mask;
	char *bin_octet_4 = malloc(sizeof(char) * BIN_OCTET_LENGTH);
	int count = 0, i;
	
	bin_octet_4 = mask_get_bin_octet(mask, 3);

	for (i = 0; i < BIN_OCTET_LENGTH; i++)
	{
		if (bin_octet_4[i] == '1')
			count++;
	}
	
	out = _itoa_s(24 + count, out, BIN_OCTET_LENGTH, 10);
}

void calculate_networks(network_t *networks[MAX_NETWORK_COUNT], int network_count, network_t *base_network)
{
	int i, previous_hosts = MAX_INDIVIDUAL_HOST_COUNT + 2,
			mask_octet_1, mask_octet_2, mask_octet_3, mask_octet_4,
			ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4, prev_ip_octet_4 = 0;
	mask_t mask;
	ip_t network_ip;
	ip_t first_assignable;
	ip_t broadcast;

	for (i = 0; i < network_count; i++)
	{
		if (networks[i]->hosts > MAX_INDIVIDUAL_HOST_COUNT)
		{
			printf("\n\nERROR: network '%s' has %d hosts, which is more than the maximum of %d hosts.\n", networks[i]->name, networks[i]->hosts, MAX_INDIVIDUAL_HOST_COUNT);
			printf("       (thats bad)\n");
			exit(-1);
		}

		else if (networks[i]->hosts <= 2)
			networks[i]->hosts = 4;

		else if (networks[i]->hosts <= 6)
			networks[i]->hosts = 8;

		else if (networks[i]->hosts <= 14)
			networks[i]->hosts = 16;

		else if (networks[i]->hosts <= 30)
			networks[i]->hosts = 32;

		else if (networks[i]->hosts <= 62)
			networks[i]->hosts = 64;

		else
			networks[i]->hosts = 128;

		base_network->hosts += networks[i]->hosts;

		if (networks[i]->hosts > previous_hosts)
		{
			printf("\n\nERROR: network '%s' has %d hosts, which is more than the previous network '%s' (has %d hosts).\n", networks[i]->name, networks[i]->hosts, networks[i - 1]->name, previous_hosts);
			printf("       (thats bad)\n");
			exit(-1);
		}
		
		else if (base_network->hosts > MAX_HOST_COUNT)
		{
			printf("\n\nERROR: total number of hosts is %d, which is more than the maximum of %d hosts.\n", base_network->hosts, MAX_HOST_COUNT);
			printf("       (thats bad)\n");
			exit(-1);
		}

		previous_hosts = networks[i]->hosts;

		mask_octet_1 = base_network->mask.int_octet_1;
		mask_octet_2 = base_network->mask.int_octet_2;
		mask_octet_3 = base_network->mask.int_octet_3;

		switch (networks[i]->hosts)
		{
		case 4:
			mask_octet_4 = 252;
			break;
			
		case 8:
			mask_octet_4 = 248;
			break;
			
		case 16:
			mask_octet_4 = 240;
			break;

		case 32:
			mask_octet_4 = 224;
			break;
			
		case 64:
			mask_octet_4 = 192;
			break;

		case 128:
			mask_octet_4 = 128;
			break;
		}

		create_mask(&mask, mask_octet_1, mask_octet_2, mask_octet_3, mask_octet_4);

		ip_octet_1 = base_network->network.octet_1;
		ip_octet_2 = base_network->network.octet_2;
		ip_octet_3 = base_network->network.octet_3;
		ip_octet_4 = prev_ip_octet_4;

		prev_ip_octet_4 += networks[i]->hosts;
		
		create_ip(&network_ip, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4);
		create_ip(&first_assignable, ip_octet_1, ip_octet_2, ip_octet_3, ip_octet_4 + 1);
		create_ip(&broadcast, ip_octet_1, ip_octet_2, ip_octet_3, prev_ip_octet_4 - 1);
		
		network_add_ips_and_mask(networks[i], network_ip, first_assignable, broadcast, mask);
	}
}

void print_networks_in_table(network_t *networks[MAX_NETWORK_COUNT], int network_count)
{
	int i;
	char *array[MAX_NETWORK_COUNT * 7];
	print_type_t print_type;

	if (!OPTIONS.options[0] && !OPTIONS.options[1])
		print_type = NORMAL;

	else if (OPTIONS.options[0] && !OPTIONS.options[1])
		print_type = IP;
	
	else if (!OPTIONS.options[0] && OPTIONS.options[1])
		print_type = MASK;
	
	else
		print_type = BOTH;

	for (i = 0; i < network_count * 7; i += 7)
	{
		char *network_name = malloc(sizeof(char) * MAX_NETWORK_NAME_LENGTH),
			*addr_count = malloc(sizeof(char) * 4),
			*network = malloc(sizeof(char) * IP_STRING_LENGTH),
			*first_assign = malloc(sizeof(char) * IP_STRING_LENGTH),
			*broadcast = malloc(sizeof(char) * IP_STRING_LENGTH),
			*dot_mask = malloc(sizeof(char) * INT_MASK_STRING_LENGTH),
			*slash_mask = malloc(sizeof(char) * 4);

		switch (print_type)
		{
		case NORMAL:
		{
			network_name = networks[i / 7]->name;
			_itoa_s(networks[i / 7]->hosts, addr_count, sizeof(addr_count), 10);
			network = ip_get_octet(networks[i / 7]->network, 3);
			first_assign = ip_get_octet(networks[i / 7]->first_assignable, 3);
			broadcast = ip_get_octet(networks[i / 7]->broadcast, 3);
			dot_mask = mask_get_int_octet(networks[i / 7]->mask, 3);
			network_get_slash_mask(*networks[i / 7], slash_mask);

			array[i] = network_name;
			array[i + 1] = addr_count;
			array[i + 2] = network;
			array[i + 3] = first_assign;
			array[i + 4] = broadcast;
			array[i + 5] = dot_mask;
			array[i + 6] = slash_mask;

			break;
		}

		case IP:
		{
			network_name = networks[i / 7]->name;
			_itoa_s(networks[i / 7]->hosts, addr_count, sizeof(addr_count), 10);
			network = ip_to_string(networks[i / 7]->network);
			first_assign = ip_to_string(networks[i / 7]->first_assignable);
			broadcast = ip_to_string(networks[i / 7]->broadcast);
			dot_mask = mask_get_int_octet(networks[i / 7]->mask, 3);
			network_get_slash_mask(*networks[i / 7], slash_mask);

			array[i] = network_name;
			array[i + 1] = addr_count;
			array[i + 2] = network;
			array[i + 3] = first_assign;
			array[i + 4] = broadcast;
			array[i + 5] = dot_mask;
			array[i + 6] = slash_mask;

			break;
		}
		
		case MASK:
		{
			network_name = networks[i / 7]->name;
			_itoa_s(networks[i / 7]->hosts, addr_count, sizeof(addr_count), 10);
			network = ip_get_octet(networks[i / 7]->network, 3);
			first_assign = ip_get_octet(networks[i / 7]->first_assignable, 3);
			broadcast = ip_get_octet(networks[i / 7]->broadcast, 3);
			dot_mask = int_mask_to_string(networks[i / 7]->mask);
			network_get_slash_mask(*networks[i / 7], slash_mask);

			array[i] = network_name;
			array[i + 1] = addr_count;
			array[i + 2] = network;
			array[i + 3] = first_assign;
			array[i + 4] = broadcast;
			array[i + 5] = dot_mask;
			array[i + 6] = slash_mask;

			break;
		}

		case BOTH:
		{
			network_name = networks[i / 7]->name;
			_itoa_s(networks[i / 7]->hosts, addr_count, sizeof(addr_count), 10);
			network = ip_to_string(networks[i / 7]->network);
			first_assign = ip_to_string(networks[i / 7]->first_assignable);
			broadcast = ip_to_string(networks[i / 7]->broadcast);
			dot_mask = int_mask_to_string(networks[i / 7]->mask);
			network_get_slash_mask(*networks[i / 7], slash_mask);

			array[i] = network_name;
			array[i + 1] = addr_count;
			array[i + 2] = network;
			array[i + 3] = first_assign;
			array[i + 4] = broadcast;
			array[i + 5] = dot_mask;
			array[i + 6] = slash_mask;

			break;
		}			
		}
	}

	printf("\n\n");
	print_table(network_count, array, print_type);
}
