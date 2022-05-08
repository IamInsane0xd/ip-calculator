#include "includes.h"

void init_options(options_t *options, int option_count, ...)
{
	va_list args;
	int i;

	assert(option_count <= MAX_OPTIONS_OPTION_COUNT);
	
	va_start(args, option_count);
	
	for (i = 0; i < option_count; i++)
	{
		options->option_names[i] = va_arg(args, char *);
		options->options[i] = va_arg(args, bool);
		assert(strlen(options->option_names[i]) <= MAX_MENU_OPTION_LENGTH);
	}
	
	va_end(args);

	options->option_count = option_count;
}

void draw_options()
{
	menu_t options_menu;
	bool loop = true;
	
	init_menu(&options_menu, "options", 3, "show full ips", "show full masks", "back");

	while (loop)
	{
		draw_menu(&options_menu);

		switch (options_menu.choice)
		{
		case 0:
			change_option(0);
			break;

		case 1:
			change_option(1);
			break;

		case 2:
			loop = false;
			break;
		}
	}

	draw_main_menu();
}

void change_option(int index)
{
	int choice;
	bool invalid_choice_err = false;

	assert(index >= 0 && index < OPTIONS.option_count);

	do
	{
		#ifdef _WIN32
		system("cls");
		#else
		system("clear");
		#endif // _WIN32
		
		printf("%s = %s\n", OPTIONS.option_names[index], OPTIONS.options[index] ? "True" : "False");

		if (invalid_choice_err)
			printf("\n%d is an invalid choice.", choice);

		printf("\nEnter 1 to change or 0 to go back: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 0:
			return;

		case 1:
			OPTIONS.options[index] = !OPTIONS.options[index];
			break;

		default:
			invalid_choice_err = true;
			break;
		}
	} while (choice != 0);
}
