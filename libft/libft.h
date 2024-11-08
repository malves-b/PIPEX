/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:56:22 by malves-b          #+#    #+#             */
/*   Updated: 2024/08/09 17:40:18 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *str, char *str2);
int		ft_strlen(char *str);
int		ft_strcmp(char *str, char *str2, int size);
char	*ft_strdup(char *s);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
char	*ft_strnstr(const char	*big, const char *little, size_t len);

#endif
