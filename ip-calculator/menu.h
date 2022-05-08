#pragma once
#include "includes.h"

typedef struct
{
	char *title;
	char *options[MAX_MENU_OPTIONS_COUNT];
	int options_count;
	int choice;
} menu_t;

void init_menu(menu_t *menu, char *title, int options_count, ...);

void draw_menu(menu_t *menu);

void draw_main_menu();
