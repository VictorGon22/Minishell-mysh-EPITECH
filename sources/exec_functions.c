/*
** EPITECH PROJECT, 2021
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

void type_error(int wstatus)
{
    if (wstatus == 139)
        my_putstr("Segmentation fault");
    else if (wstatus == 136)
        my_putstr("Floating exception");
}

void core_dump_errors(int wstatus)
{
    if (WCOREDUMP(wstatus))
        my_putstr(" (core dumped)\n");
    else
        my_putstr("\n");
}

void ext_execute(pid_t pid, int wstatus)
{
    if (waitpid(pid, &wstatus, WUNTRACED | WCONTINUED) == -1)
        exit(84);
    if (WIFSIGNALED(wstatus)) {
        type_error(wstatus);
        core_dump_errors(wstatus);
    }
}

void try_execute(t_var *var, char *params, char *type)
{
    char *env = get_path(var);
    char **path = paths(env);
    pid_t pid = fork();
    int wstatus;
    char **exec_params = save_exec_params(var, params, type);

    if (pid == -1)
        return;
    else if (pid == 0 && type != NULL) {
        if (execve(find_func(path, type), exec_params, NULL) < 0
        && type[0] != '\0')
            try_execute_2(pid, exec_params, type);
        exit(0);
    } else
        ext_execute(pid, wstatus);
}

void try_execute_2(pid_t pid, char **exec_params, char *type)
{
    //pid_t pid = fork();
    int wstatus;

    if (pid == -1)
        return;
    else if (pid == 0 && type != NULL) {
        if (access(type, F_OK) != -1 && type[0] != '\0') {
            if (execve(type, exec_params, NULL) < 0) {
                if(waitpid(pid, &wstatus, 0) == -1) {
                    perror("wait failed\n");
                    exit(84);
                }
                if (WIFEXITED(wstatus)) {
                    printf("WIFEXITED: %d\n", WIFEXITED(wstatus));
                }
                my_putstr(type);
                my_putstr(": Permission denied.\n");
            }
        } else {
            my_putstr(type);
            my_putstr(": Command not found.\n");
        }
        exit(0);
    } else
        ext_execute(pid, wstatus);
}