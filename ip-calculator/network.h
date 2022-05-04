#pragma once
#include "includes.h"

typedef struct
{
	char *name;
	int hosts;
	ip_t network;
	ip_t first_assignable;
	ip_t broadcast;
	mask_t mask;
} network_t;

void create_network(network_t *network, char *name, int hosts);

void create_base_network(network_t *base_network, char *name, int hosts, ip_t ip, mask_t mask);

void network_add_ips(network_t *network, ip_t network_ip, ip_t first_assignable, ip_t broadcast);

void network_add_mask(network_t *network, mask_t mask);

void network_add_ips_and_mask(network_t *network, ip_t network_ip, ip_t first_assignable, ip_t broadcast, mask_t mask);

void network_get_slash_mask(network_t network, char *out);
