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

void print_table(int row_count, ...)
{
	va_list args;
	int column_count, i;
	
	va_start(args, row_count);

	printf(TABLE_ROW_SEPARATOR);
	printf(TABLE_HEADER_ROW);
	printf(TABLE_ROW_SEPARATOR);

	for (i = 0; i < row_count; i++) {
		array_t row = va_arg(args, array_t);
		printf(TABLE_ROW(row.items[0], row.items[1], row.items[2], row.items[3], row.items[4], row.items[5], row.items[6]));
		printf(TABLE_ROW_SEPARATOR);
	}

	va_end(args);
}
