#include "includes.h"

int main()
{
	unsigned int networks;
	array_t names;
	array_t host_counts;
	
	printf("Ammount of networks: ");
	scanf_s("%u", &networks);
	
	init_array(&names);
	init_array(&host_counts);
	
	for (int i = 0; i < networks; i++)
	{
		char *name = malloc(128);
		unsigned int host_count;
		
		read_line("Network name: ", true, name, 128);
		printf("Ammount of hosts: ");
		scanf_s("%u", &host_count);

		array_append(&names, name);
		array_append(&host_counts, host_count);
	}

	return 0;
}
