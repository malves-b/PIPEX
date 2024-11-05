/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:41:19 by malves-b          #+#    #+#             */
/*   Updated: 2024/08/02 18:27:49 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str, char *str2)
{
	char	*ret;
	int		i;
	int		j;
	int		total_length;

	i = 0;
	j = 0;
	total_length = ft_strlen(str) + ft_strlen(str2);
	ret = malloc(total_length + 1);
	while (str[i])
	{
		ret[j++] = str[i++];
	}
	i = 0;
	while (str2[i])
		ret[j++] = str2[i++];
	ret[j] = '\0';
	return (ret);
}
