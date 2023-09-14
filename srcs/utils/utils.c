/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyamen <dyamen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:07:34 by dyamen            #+#    #+#             */
/*   Updated: 2023/09/14 17:08:57 by dyamen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	clamp(long value, long min, long max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;
	return (value);
}
