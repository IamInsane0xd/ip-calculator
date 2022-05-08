#pragma once
#include "includes.h"

typedef struct
{
	char *option_names[MAX_OPTIONS_OPTION_COUNT];
	bool options[MAX_OPTIONS_OPTION_COUNT];
	int option_count;
} options_t;

// example for setting options:
// init_options(&options, &options_menu, 2, "option1", false, "option2", true);
void init_options(options_t *options, int option_count, ...);

void draw_options();

void change_option(int index);
