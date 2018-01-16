/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:06:14 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/16 18:09:55 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char ** check_cd(char **tab, char **environ)
{
    char **str;
    char **tmp;

    tmp = malloc(sizeof(char *) * 3);
    tmp[0] = malloc(sizeof(char) * 256);
    tmp[1] = malloc(sizeof(char) * 7);
    tmp[2] = malloc(sizeof(char) * 256);
    tmp[1] = "OLDPWD";
    if (tab[1] && ft_strcmp(tab[1], "-") != 0)
    {
        getcwd(tmp[2], 256);
        environ = check_setenv(tmp, environ);
        if (chdir(tab[1]) != -1)
        {
            tab[2] = malloc(sizeof(char) * 256);
            tab[1] = "PWD";
            getcwd(tab[2], 256);
            environ = check_setenv(tab, environ);
            return(environ);
        }
        ft_putstr("Error\n");
        return(environ);
    }
    else if (tab[1] && ft_strcmp(tab[1], "-") == 0)
    {
        str = ft_strsplit(get_env("OLDPWD"), '=');
        chdir(str[1]);
        tab[2] = malloc(sizeof(char) * 256);
        tab[1] = "PWD";
        getcwd(tab[2], 256);
        environ = check_setenv(tab, environ);
        return (environ);
    }
    else
    {
        getcwd(tmp[2], 256);
        environ = check_setenv(tmp, environ);
        str = ft_strsplit(get_env("HOME="), '=');
        if (chdir(str[1]) != -1)
            return(environ);
        ft_putstr("Error\n");
        return(environ);
    }
    return (environ);
}
