/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeaure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 21:00:01 by ybeaure           #+#    #+#             */
/*   Updated: 2016/12/14 21:44:30 by ybeaure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <stdlib.h>
# include <ncurses.h>
# include "op.h"
# include "../libft/includes/libft.h"

#define BUFF_SIZE 256

typedef struct		s_ram
{
	unsigned char	value;
	int				champ;
	int				execute;
}					t_ram;

typedef struct		s_champs
{
	int				position;
	int				number;
	int				len;
	t_header		header;
	char			*color;
	unsigned char	*data;
}					t_champs;

typedef struct		s_vm
{
	unsigned int	dump_cycles;
	int				o_dump;
	int				o_graphic;
	int				nbr_live;
	short			nbr_champs;
	int				last_to_live;
	char			**av;
	t_ram			*ram;
	t_champs		*champs;
}					t_vm;
//ERROR
void			ft_error(char *str);

//BOOT
t_vm			*boot_vm(t_vm *vm, int ac, char **av);

//OTHERS
char			**ft_arrsub(char **src, unsigned int start, unsigned int len);
int				array_size(char **array);

//INIT
t_champs		*init_champs(t_vm *vm);
t_ram			*init_ram(void);
//PLACE
void			put_champs_on_map(t_vm **vm);
//READ
void			read_header(unsigned char *data, t_champs *champs);
void			read_prog(unsigned char *data, t_champs *champs);
unsigned char	*read_file(char *fn, t_champs *champs);
//BSWAP
unsigned short	bswap_16(unsigned short value);
unsigned int	bswap_32(unsigned int value);
//START
void	start_fight(t_vm *vm);

#endif
