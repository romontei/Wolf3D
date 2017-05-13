/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:24:33 by romontei          #+#    #+#             */
/*   Updated: 2015/01/15 15:18:42 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/includes/libft.h"

# define BUF_SIZE		1
# define SPILL_MULT		2
# define MAX_FD			1000

typedef struct		s_stock
{
	char			*spill;
	long			length;
	long			lu;
	int				read_ret;
	char			*line_end;
}					t_stock;

int					get_next_line(int fd, char **line);

#endif
