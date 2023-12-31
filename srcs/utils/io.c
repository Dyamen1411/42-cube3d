/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:34:42 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/06 01:39:40 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <unistd.h>

int	read_n_bytes(int fd, void *buf, unsigned long byte_count)
{
	long	n;
	char	*_buf;

	_buf = buf;
	while (byte_count)
	{
		n = read(fd, _buf, byte_count);
		if (n <= 0)
			return (1);
		_buf += n;
		byte_count -= n;
	}
	return (0);
}

int	read_long(int fd, void *ptr)
{
	return (read_n_bytes(fd, ptr, sizeof(long)));
}

int	read_int(int fd, void *ptr)
{
	return (read_n_bytes(fd, ptr, sizeof(int)));
}
