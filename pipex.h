/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:23:13 by malves-b          #+#    #+#             */
/*   Updated: 2024/08/10 16:21:35 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include <sys/wait.h>

int		pipex(char **args, char **envp);
int		get_next_line(char **line);
void	ft_exit(char *str);
char	*find_path(char *cmd, char **envp);
int		check_cmds(const char *cmd1, const char *cmd2);
int		check_envp(char **envp);
void	free_args(char **args);

#endif
