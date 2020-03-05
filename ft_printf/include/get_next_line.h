/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:42:04 by lhaired           #+#    #+#             */
/*   Updated: 2019/10/16 20:33:19 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 20
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
