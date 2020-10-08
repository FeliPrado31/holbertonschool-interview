#include "slide_line.h"

/**
 * slide_line - merge and slide an array in a direction
 * 
 * @line: is the array that represent the line
 * @size: is the size of the line param
 * @direction: is the direction to merge
 * Return: 1 in success, 0 in error
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t initPos = 0, endPost = 0, cont = 1, stop = size;
	int d_flag = -1;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		initPos = size - 1;
		endPost = size - 1;
		cont = -1;
		stop = -1;
	}

	while (initPos != stop)
	{
		if (*(line + initPos) != 0)
		{
			if (d_flag == *(line + initPos))
			{
				*(line + initPos) += d_flag;
				d_flag = -1;
			}
			else
			{
				d_flag = *(line + initPos);
				if ((direction == SLIDE_LEFT && initPos != 0) ||
					((direction == SLIDE_RIGHT && initPos != (size - 1))))
					if (*(line + endPost) != 0)
						endPost += cont;
			}
			*(line + endPost) = *(line + initPos);
			if (endPost != initPos)
				*(line + initPos) = 0;
		}
		initPos += cont;
	}

	return (1);
}