#include "includes.h"

void create_network(network_t *network, char *name, int hosts)
{
	network->name = name;
	network->hosts = hosts;
}
