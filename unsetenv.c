/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:15:42 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/16 18:15:44 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char **check_unsetenv(char **tab, char **environ)
{
    char **new;
    int i;
    int o;
    char **env_split;

    o = 0;
    i = 0;
    if (!tab[1])
    {
        ft_putstr("met un argument fdp\n");
        return (environ);
    }
    while (environ[i])
        i++;
    new = malloc(sizeof(char *) * i - 1);
    i = 0;
    o = 0;
    while (environ[i])
    {
        env_split = ft_strsplit(environ[i], '=');
        if (ft_strcmp(env_split[0], tab[1]) == 0)
            ;
        else
        {
            new[o] = environ[i];
            o++;
        }
        i++;
    }
    new[o] = NULL;
    environ = new;
    return (environ);
}
