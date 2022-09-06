
#include "push_swap.h"
int	which_is_better(int highest_position, int second_position, int len)
{
	int difference;
	int half;
	int actions_second;
	int actions_highest;
	
	half = len/2;
	actions_highest = 0;
	actions_second = 0;

	while (second_position <= half)
	{
		if (second_position == 1)
		{
			actions_second++;
			break;
		}
		second_position--;
		actions_second++;
	}
	while (second_position > half)
	{
		if (second_position == len)
		{
			actions_second += 2;
			break;
		}
		second_position++;
		actions_second++;
	}
	while (highest_position <= half)
	{
		if (highest_position == 1)
		{
			actions_highest++;
			break;
		}
		highest_position--;
		actions_highest++;
	}
	while (highest_position > half)
	{
		if (highest_position == len)
		{
			actions_highest += 2;
			break;
		}
		highest_position++;
		actions_highest++;
	}
	if (actions_second < actions_highest)
		return(1);
	else
		return(0);
	return (0);
}
