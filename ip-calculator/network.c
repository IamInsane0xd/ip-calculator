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
