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
