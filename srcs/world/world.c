/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:44:28 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/05 15:46:21 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

#include <stdlib.h>

void	world_delete(t_world **world_ptr)
{
	if (*world_ptr == NULL)
		return ;
	if ((*world_ptr)->global_buffer)
		free((*world_ptr)->global_buffer);
	free(*world_ptr);
	*world_ptr = NULL;
}
