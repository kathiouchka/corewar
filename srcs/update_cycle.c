/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeaure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:52:36 by ybeaure           #+#    #+#             */
/*   Updated: 2016/12/15 12:55:40 by ybeaure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		update_cycle(t_cycle *cycle, t_vm *vm)
{
	cycle->pro_nbr = count_pro(*(cycle->pro));
	if (cycle->cycles_done == cycle->cycle_to_die && cycle->dump_cycle)
	{
		while (find_dead_pro(cycle->pro))
			kill_pro(find_dead_pro(cycle->pro), vm);
		if (cycle->pro && *(cycle->pro))
		{
		cycle->cycles_done = 0;
		update_cycle_to_die(cycle);
		}
		else
			return (0);
		if (cycle->cycle_to_die <= 0)
			return (0);
	}
	else if (cycle->dump_cycle == 0)
		return (0);
	else
	{
		cycle->cycles_done++;
		if (cycle->dump_cycle != -1)
			cycle->dump_cycle--;
		return (1);
	}
	return (1);
}
