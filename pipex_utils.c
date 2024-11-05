/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:11:42 by malves-b          #+#    #+#             */
/*   Updated: 2024/08/12 19:17:21 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_next_line(char **line)
{
	char	*buffer;
	char	buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buffer = ft_calloc(10000, 1);
	if (!buffer)
		return (0);
	j = read(0, &buff, 1);
	while (buff != '\n' && buff != EOF)
	{
		if (buff != '\n' && buff != '\0')
			buffer[i] = buff;
		i++;
		j = read(0, &buff, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (j);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

int	check_cmds(const char *cmd1, const char *cmd2)
{
	int	i;

	i = 0;
	while (cmd1[i])
	{
		if (cmd1[i] >= 'a' && cmd1[i] <= 'z')
			return (0);
		i++;
	}
	while (cmd2[i])
	{
		if (cmd2[i] >= 'a' && cmd2[i] <= 'z')
			return (0);
		i++;
	}
	return (1);
}

int	check_envp(char **envp)
{
	int	i;

	i = 0;
	if (!*envp || !envp)
		return (1);
	while (envp[i])
	{
		if (ft_strcmp(envp[i], "PATH", 4))
			return (0);
		i++;
	}
	return (1);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	while (args[i + 1])
	{
		free(args[i + 1]);
		i++;
	}
	free(args);
}
