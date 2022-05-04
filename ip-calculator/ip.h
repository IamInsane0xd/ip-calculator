#pragma once
#include "includes.h"

typedef struct
{
	unsigned int octet_1;
	unsigned int octet_2;
	unsigned int octet_3;
	unsigned int octet_4;
} ip_t;

void create_ip(ip_t* ip, unsigned int octet_1, unsigned int octet_2, unsigned int octet_3, unsigned int octet_4);

void parse_ip_string(ip_t* ip, char* ip_string);

// ip to string converter
char *ip_to_string(ip_t ip);
