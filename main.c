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

char **get_cmd()
{
    char **tab;
    char *line;

    line = NULL;
    ft_putstr("$> ");
    while (!(get_next_line(0, &line)))
        ; //ft_strsplit pour argv
    tab = ft_strsplit(line, ' ');
    return (tab);
}

char *get_path()
{
    extern char **environ;
    int i;
    int o;
    char *path = "PATH=";

    i = 0;
    o = 0;
    while (environ[i])
    {
        while (o < 5 && environ[i][o] == path[o])
            o++;
        if (o == 5)
        {
            //printf("environ[i] = %s\n", environ[i]);
            return (environ[i]);
        }
        o = 0;
        i++;
    }
    return (NULL);
}

void lunchprocessus(char **argv)
{
    pid_t father;
    char **tab;
    char *test;
    extern char **environ;
    char **argument;
    int i;

    i = 1;
    tab = ft_strsplit(get_path(), ':');
    father = fork();
    if (father > 0)
    {
        wait(0);
        //printf("Yo\n");
    }
    if (father == 0)
    {
        test = ft_strjoin(tab[i], "/");
        test = ft_strjoin(test, argv[0]);
        //printf("test = %s\n", test);
        while (execve(test, argv, environ) == -1)
        {
            test = ft_strjoin(tab[i], "/");
            test = ft_strjoin(test, argv[0]);
            //printf("Here = %s\n", test);
            i++;
        }
        ft_putstr("Command not found\n");
    }
}

int main(int argc, char **argv, char **env)
{
    char **tab;

    argc = 0;
    env = NULL;
    ft_putstr("\033[H\033[2J");
    while (1)
    {
        tab = get_cmd();
        lunchprocessus(tab);
    }
    printf("%s\n", tab[0]);
    return (0);
}

/*int main(int argc, char **argv)
{
    int i;
    extern char **environ;
    i = 0;

    while (environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
    }
    i = 0;
    printf("\n");

    while (environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
    }
}*/

/*int main(int argc, char **argv)
{
    pid_t father;

    father = fork();
    if (father > 0)
    {
        wait(0);
        printf("here\n");
    }
    if (father == 0)
    {
        sleep(3);
        execve("/bin/ls", argv, NULL);
    }
}*/