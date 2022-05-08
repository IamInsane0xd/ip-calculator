#include "includes.h"

/* 
*  table layout :
*  +--------------+------------+---------+---------------+-----------+-------+-------+
*  | network name | addr count | network | first assign. | broadcast | .mask | /mask |
*  +--------------+------------+---------+---------------+-----------+-------+-------+
*  | lan_1        | 128        | .0      | .1            | .127      | .128  | /25   |
*  +--------------+------------+---------+---------------+-----------+-------+-------+
*  ...
*/

void print_table(int row_count, char *rows[MAX_NETWORK_COUNT * 7], print_type_t print_type)
{
	int i;

	switch (print_type)
	{
	case NORMAL:
		printf(TABLE_ROW_SEPARATOR_NORMAL);
		printf(TABLE_HEADER_ROW_NORMAL);
		printf(TABLE_ROW_SEPARATOR_NORMAL);
	
		for (i = 0; i < row_count * 7; i += 7)
		{
			printf(TABLE_ROW_NORMAL(rows[i], rows[i + 1], rows[i + 2], rows[i + 3], rows[i + 4], rows[i + 5], rows[i + 6]));
			printf(TABLE_ROW_SEPARATOR_NORMAL);
		}

		break;

	case IP:
		printf(TABLE_ROW_SEPARATOR_IP);
		printf(TABLE_HEADER_ROW_IP);
		printf(TABLE_ROW_SEPARATOR_IP);

		for (i = 0; i < row_count * 7; i += 7)
		{
			printf(TABLE_ROW_IP(rows[i], rows[i + 1], rows[i + 2], rows[i + 3], rows[i + 4], rows[i + 5], rows[i + 6]));
			printf(TABLE_ROW_SEPARATOR_IP);
		}
		break;
		
	case MASK:
		printf(TABLE_ROW_SEPARATOR_MASK);
		printf(TABLE_HEADER_ROW_MASK);
		printf(TABLE_ROW_SEPARATOR_MASK);

		for (i = 0; i < row_count * 7; i += 7)
		{
			printf(TABLE_ROW_MASK(rows[i], rows[i + 1], rows[i + 2], rows[i + 3], rows[i + 4], rows[i + 5], rows[i + 6]));
			printf(TABLE_ROW_SEPARATOR_MASK);
		}
		break;

	case BOTH:
		printf(TABLE_ROW_SEPARATOR_IP_MASK);
		printf(TABLE_HEADER_ROW_IP_MASK);
		printf(TABLE_ROW_SEPARATOR_IP_MASK);

		for (i = 0; i < row_count * 7; i += 7)
		{
			printf(TABLE_ROW_IP_MASK(rows[i], rows[i + 1], rows[i + 2], rows[i + 3], rows[i + 4], rows[i + 5], rows[i + 6]));
			printf(TABLE_ROW_SEPARATOR_IP_MASK);
		}
		break;
	}
}
