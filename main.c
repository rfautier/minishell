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
    ft_putstr("\033[34;1m");
    ft_putstr("$> ");
    while (!(get_next_line(0, &line)))
        ;
    ft_putstr("\033[0m"); //Multicolor ?
    tab = ft_strsplit(line, ' ');
    return (tab);
}

char *get_env(char *str)
{
    extern char **environ;
    int i;
    int o;

    i = 0;
    o = 0;
    while (environ[i])
    {
        while (str[o] != '\0' && environ[i][o] == str[o])
            o++;
        if (str[o] == '\0')
        {
            //printf("environ[i] = %s\n", environ[i]);
            return (environ[i]);
        }
        o = 0;
        i++;
    }
    return (NULL);
}

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
    father = fork();
    if (father > 0)
    {
        wait(0);
        return (1);
        //printf("Yo\n");
    }
    if (father == 0)
    {
        test = ft_strjoin(tab[i], "/");
        test = ft_strjoin(test, argv[0]);
        //printf("test = %s\n", test);
        while (tab[i] && execve(test, argv, environ) == -1)
        {
            test = ft_strjoin(tab[i], "/");
            test = ft_strjoin(test, argv[0]);
            //printf("Here = %s\n", test);
            i++;
        }
    }
    return (0);
}

void check_cd(char **tab)
{
    char **str;

    if (tab[1])
    {
        if (chdir(tab[1]) != -1)
            return;
        ft_putstr("Error\n");
        return;
    }
    else
    {
        str = ft_strsplit(get_env("HOME="), '=');
        if (chdir(str[1]) != -1)
            return;
        ft_putstr("Error\n");
        return;
    }
}

void check_env(char **tab, char **environ)
{
    int i;

    i = 0;
    if (!tab[1])
    {
        while (environ[i])
        {
            ft_putstr(environ[i]);
            ft_putchar('\n');
            i++;
        }
        return;
    }
    else if (ft_strcmp(tab[1], "-i") == 0)
    {
        //lunchprocess NULL
        return;
    }
}

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

int good_arg(char **tab)
{
    int i;

    i = 0;
    while (tab[1][i])
    {
        if ((tab[1][i] >= 'A' && tab[1][i] <= 'Z') || (tab[1][i] >= 'a' && tab[1][i] <= 'z'))
            i++;
        else
        {
            ft_putstr("Variable must contain alphanumeric characters\n");
            return (0);
        }
    }
    return (1);
}

char **check_setenv(char **tab, char **environ) //pas gere le cas  est egale a une variable
{
    char **new;
    int i;
    char *str;
    char **env_split;

    if (!tab[1])
    {
        check_env(tab, environ);
        //ft_putstr("met un argument fdp\n");
        return (environ);
    }
    if (tab[3])
    {
        ft_putstr("Too much arguments\n");
        return (environ);
    }
    if (!good_arg(tab))
        return (environ);
    i = 0;
    while (environ[i])
    {
        env_split = ft_strsplit(environ[i], '=');
        if (ft_strcmp(env_split[0], tab[1]) == 0)
        {
            str = ft_strjoin(tab[1], "=");
            if (tab[2])
                str = ft_strjoin(str, tab[2]);
            else
                str = ft_strjoin(str, "\0");
            environ[i] = str;
            return (environ);
        }
        i++;
    }
    new = malloc(sizeof(char *) * i + 2);
    i = 0;
    while (environ[i])
    {
        new[i] = environ[i];
        i++;
    }
    str = ft_strjoin(tab[1], "=");
    if (tab[2])
        str = ft_strjoin(str, tab[2]);
    else
        str = ft_strjoin(str, "\0");
    new[i] = malloc(sizeof(char) * ft_strlen(str));
    new[i] = str;
    new[i + 1] = NULL;
    environ = new;
    return (environ);
}

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
        if (!tab[0])
            ;
        else if (ft_strcmp(tab[0], "exit") == 0)
            return (0);
        else if (ft_strcmp(tab[0], "clear") == 0)
            ft_putstr("\033[H\033[2J");
        else if (ft_strcmp(tab[0], "cd") == 0)
            check_cd(tab);
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
    printf("%s\n", tab[0]);
    return (0);
}

/*int main(int argc, char **argv)
{
    int i;
    extern char
     **environ;
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