/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:53:43 by malves-b          #+#    #+#             */
/*   Updated: 2024/08/12 17:12:06 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char const *argv[], char **envp)
{
	if (check_envp(envp))
		ft_exit("Envp error");
	if (argc != 5 || check_cmds(argv[2], argv[3]))
	{
		perror("Bad arguments");
		return (1);
	}
	if (!access(argv[1], F_OK) && !access(argv[1], R_OK))
	{
		pipex((char **)argv, envp);
		return (0);
	}
	else
	{
		perror("File1");
		return (1);
	}
}
/* -------------------------------------------------------------------------- */

void	child_proccess(char *file1, char *cmd1, char **envp, int pipefd[2])
{
	char	**args;
	char	*aux;
	int		infile;

	infile = open (file1, O_RDONLY);
	if (infile < 0)
		ft_exit("open infile");
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(infile);
	close(pipefd[1]);
	args = ft_split(cmd1, ' ');
	aux = ft_strdup(args[0]);
	free(args[0]);
	args[0] = find_path(aux, envp);
	if (!args[0])
	{
		free(aux);
		free_args(args);
		ft_exit("invalid command");
	}
	if (execve(args[0], args, envp) == -1)
		ft_exit("execve");
}

int	parent_proccess(char *file2, char *cmd2, char **envp, int fd)
{
	char	**args;
	int		outfile;
	char	*aux;

	outfile = open(file2, O_RDWR | O_CREAT, 0777);
	if (outfile < 0)
		ft_exit("open outfile");
	dup2(fd, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd);
	args = ft_split(cmd2, ' ');
	aux = ft_strdup(args[0]);
	free(args[0]);
	args[0] = find_path(aux, envp);
	if (!args[0])
	{
		free(aux);
		free_args(args);
		ft_exit("invalid command");
	}
	if (execve(args[0], args, envp) == -1)
		ft_exit("execve");
	return (0);
}

int	pipex(char **args, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		child_proccess((char *)args[1], (char *)args[2], envp, pipefd);
	}
	close(pipefd[1]);
	waitpid(pid, NULL, 0);
	parent_proccess((char *)args[4], (char *)args[3], envp, pipefd[0]);
	close(pipefd[0]);
	return (0);
}

void	ft_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
