/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:08:42 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/16 18:08:44 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void check_echo(char **tab, char **environ)
{
    int i;
    int o;
    int flag;
    char **str;

    if (!tab[1])
    {
        ft_putchar('\n');
        return;
    }
    i = 1;
    while (tab[i])
    {
        flag = 0;
        o = 0;
        if (tab[i][0] == '$')
        {
            while (environ[o])
            {
                str = ft_strsplit(environ[o], '=');
                if (ft_strcmp(str[0], tab[i] + 1) == 0)
                {
                    ft_putstr(str[1]);
                    break;
                }
                o++;
            }
            if (!environ[o])
            {
                ft_putstr("Udefined variable.");
            }
            flag = 1;
        }
        o = 0;
        while (flag == 0 && tab[i][o])
        {
            while (tab[i][o] && tab[i][o] == '\\')
                o++;
            ft_putchar(tab[i][o]);
            o++;
        }
        ft_putchar(' ');
        i++;
    }
    ft_putchar('\n');
}