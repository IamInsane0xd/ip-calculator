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
	
	mask_get_bin_octet(mask, 4, bin_octet_4);

	for (i = 0; i < BIN_OCTET_LENGTH; i++)
	{
		if (bin_octet_4[i] == '1')
			count++;
	}
	
	out = _itoa_s(24 + count, out, BIN_OCTET_LENGTH, 10);
}
