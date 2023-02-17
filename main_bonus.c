/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:44:12 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/19 12:22:19 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exit(t_data d, char *s);
static void	ft_noheredoc(t_data *d, char *argv[]);
static void	ft_fork(int argc, char *argv[], char *envp[], t_data *d);
static void	ft_loop(int argc, char *argv[], char *envp[], t_data *d);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	d;

	d.hd = "here_doc";
	d.tmp = "tempZHsL5juDbhOSi5axlDant6MzTNYDcg8I";
	if (argc < 5)
		return (1);
	if (argc >= 6 && !ft_strncmp(argv[1], d.hd, ft_strlen(d.hd))
		&& ft_strlen(argv[1]) == ft_strlen(d.hd))
		ft_heredoc(&d, argv);
	else
		ft_noheredoc(&d, argv);
	d.paths = ft_getallpaths(envp);
	if (!d.paths)
		exit(1);
	while (d.i < argc - 1)
		ft_loop(argc, argv, envp, &d);
	ft_freearr(d.paths);
	//system("leaks pipex");
	return (0);
}

static void	ft_noheredoc(t_data *d, char *argv[])
{
	d->i = 2;
	d->fd = open(argv[1], O_RDONLY);
	if (d->fd == -1)
		perror("open: infile");
	if (dup2(d->fd, STDIN_FILENO) == 1)
		perror("dup2: infile");
	if (close(d->fd) == -1)
		perror("close: infile");
}

static void	ft_exit(t_data d, char *s)
{
	perror(s);
	ft_freearr(d.args);
	ft_freearr(d.paths);
	free(d.path);
}

static void	ft_fork(int argc, char *argv[], char *envp[], t_data *d)
{
	int	flag;

	if (d->i == argc - 2)
	{
		flag = O_WRONLY | O_CREAT;
		if (ft_strncmp(argv[1], d->hd, ft_strlen(d->hd)))
			flag = flag | O_TRUNC;
		else
			flag = flag | O_APPEND;
		d->fd = open(argv[argc - 1], flag,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (d->fd == -1)
			ft_exit(*d, "open: last fork");
		if (dup2(d->fd, STDOUT_FILENO) == -1)
			ft_exit(*d, "dup2: last fork");
		if (close(d->fd) == -1)
			ft_exit(*d, "close: last fork");
	}
	else
	{	
		if (dup2(d->pip[1], STDOUT_FILENO) == -1)
			ft_exit(*d, "dup2: fork");
	}
	if (execve(d->path, d->args, envp) == -1)//make sure execve proceeds if path is NULL
		ft_exit(*d, "execve");
}

static void	ft_loop(int argc, char *argv[], char *envp[], t_data *d)
{
	d->args = ft_split(argv[d->i], ' ');
	if (!d->args)
		ft_exit(*d, "ft_split: args");
	d->path = ft_getpath(d->args[0], d->paths);
	if (!d->path)
		ft_exit(*d, "ft_getpath: path");
	if (pipe(d->pip) == -1)
		ft_exit(*d, "pipe");
	d->pid = fork();
	if (d->pid == -1)
		ft_exit(*d, "fork");
	if (!(d->pid))
		ft_fork(argc, argv, envp, d);
	if (close(d->pip[1]) == -1)
		ft_exit(*d, "close: pipe write end");
	if (waitpid(d->pid, NULL, 0) == -1)
		ft_exit(*d, "waitpid");
	if (dup2(d->pip[0], STDIN_FILENO) == -1)
		ft_exit(*d, "dup2: after wait");
	ft_freearr(d->args);
	free(d->path);
	d->i++;
}
