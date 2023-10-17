#include "main.h"

/**
 * _ispercent - funtion that haddle %
 * Return: printed %
 */

int _ispercent(void)
{
	return (write(1, "%%", 1));
}
