/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:54:51 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 15:59:20 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void	_memset(void *dst, int c, unsigned int n);

int		read_n_bytes(int fd, void *ptr, unsigned long byte_count);
int		read_long(int fd, void *ptr);
int		read_int(int fd, void *ptr);

#endif