/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:49:01 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/13 19:49:03 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char **argv, char **env)
{
    char **tab;
    extern char **environ;

    argc = 0;
    argv = NULL;
    env = NULL; //Rajouter un main
    ft_putstr("\033[H\033[2J");
    while (1)
    {
        tab = get_cmd();
        signal(SIGINT, sign);
        if (!tab[0])
            ;
        else if (ft_strcmp(tab[0], "exit") == 0)
            exit(0);
        else if (ft_strcmp(tab[0], "clear") == 0)
            ft_putstr("\033[H\033[2J");
        else if (ft_strcmp(tab[0], "cd") == 0)
            environ = check_cd(tab, environ);
        else if (ft_strcmp(tab[0], "env") == 0)
            check_env(tab, environ);
        else if (ft_strcmp(tab[0], "setenv") == 0)
            environ = check_setenv(tab, environ);
        else if (ft_strcmp(tab[0], "unsetenv") == 0)
            environ = check_unsetenv(tab, environ);
        else if (ft_strcmp(tab[0], "echo") == 0)
            check_echo(tab, environ);
        else if (lunchprocessus(tab, environ))
            ;
        else
            ft_putstr("Command not found\n");
    }
    return (0);
}