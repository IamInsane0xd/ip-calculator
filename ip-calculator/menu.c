#include "includes.h"

void init_menu(menu_t *menu, char *title, int options_count, ...)
{
	va_list args;
	int i;
	
	assert(options_count <= MAX_MENU_OPTIONS_COUNT);

	va_start(args, options_count);
	
	for (i = 0; i < options_count; i++)
	{
		menu->options[i] = va_arg(args, char *);
		assert(strlen(menu->options[i]) <= MAX_MENU_OPTION_LENGTH);
	}
	
	va_end(args);

	assert(strlen(title) <= MAX_MENU_TITLE_LENGTH);

	menu->title = title;
	menu->options_count = options_count;
	menu->choice = -1;
}

// draws the menu and gets choice
void draw_menu(menu_t *menu)
{
	int i, choice;
	bool invalid_choice_err = false;
	
	do
	{
		#ifdef _WIN32
		system("cls");
		#else
		system("clear");
		#endif // _WIN32

		printf("+-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
		printf("|    %-*s    |\n", MAX_MENU_TITLE_LENGTH, menu->title);
		printf("+-=-=-=-=-=-=-=-=-=-=-=-=-+\n");

		for (i = 0; i < menu->options_count; i++)
			printf("| %d. %*s |\n", i + 1, MAX_MENU_OPTION_LENGTH, menu->options[i]);

		printf("+-=-=-=-=-=-=-=-=-=-=-=-=-+\n");

		if (invalid_choice_err)
			printf("\n%d is an invalid choice.", choice);

		printf("\nEnter your choice : ");
		scanf_s("%d", &choice);

		if (choice < 1 || choice > menu->options_count)
			invalid_choice_err = true;
		
	} while (choice < 1 || choice > menu->options_count);

	menu->choice = choice - 1;
}

void draw_main_menu()
{
	menu_t menu;
	
	init_menu(&menu, "ip calculator", 3, "calculate ips", "options", "exit");
	draw_menu(&menu);

	switch (menu.choice)
	{
	case 0:
		calculate_ips_main();
		break;

	case 1:
		draw_options();
		break;

	case 2:
		exit(0);
		break;
	}
}
