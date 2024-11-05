/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:37:27 by malves-b          #+#    #+#             */
/*   Updated: 2024/08/06 17:08:44 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Funcao que faz uma copia da string passada como parametro
*/
char	*ft_strdup(char *s)
{
	char	*a;
	int		i;

	i = 0;
	a = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (a == NULL)
		return (NULL);
	while (s[i])
	{
		a[i] = s[i];
		i++;
	}
	a[i] = 0;
	return (a);
}
