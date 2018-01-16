/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:10:26 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/16 18:10:27 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int lunchprocessus(char **argv, char **environ)
{
    pid_t father;
    char **tab;
    char *test;
    int i;

    i = 1;
    if (ft_strcmp(argv[0], "env") == 0 || ft_strcmp(argv[0], "echo") == 0)
        return (0);
    tab = ft_strsplit(get_env("PATH="), ':');
    //Checker si possible avant de fork /!\//
    father = fork();
    if (father > 0)
    {
        wait(0);
        return (1);
    }
    if (father == 0)
    {
        test = ft_strjoin(tab[i], "/");
        test = ft_strjoin(test, argv[0]);
        while (tab[i] && execve(test, argv, environ) == -1)
        {
            test = ft_strjoin(tab[i], "/");
            test = ft_strjoin(test, argv[0]);
            i++;
        }
        execve(argv[0], argv, environ);
    }
    return (0);
}