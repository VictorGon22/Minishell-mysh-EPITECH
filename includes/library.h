/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** lib my_hunterexercise
*/

#ifndef LIBRAY_H_
    #define LIBRAY_H_
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <ctype.h>
    #include "./structs.h"
    #include <limits.h>
    #include<stdio.h>
    #include<unistd.h>
    #include<errno.h>
    #include<sys/types.h>
    #include<sys/stat.h>
    #include<fcntl.h>
    #include <sys/types.h>
    #include <sys/wait.h>


void my_itoa(long i, char *string);
void *my_memset(void *s, int c, int n);
void *my_calloc(int nmemb, int size);
void revstr(char *str1);
char *my_charcat(char *dest, char src);
int my_getnbr(char const *str);
int my_nbrlen(int nb);
char *ext_my_return_char(int nb, char *str, int neg);
char *my_return_char(int nb);
char *my_revstr(char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(char *str);
char *my_strcpy(char *destination, char *source);
int my_strlen(char const *str);
void my_putchar(char letter);
char **get_env_params(char *str);
long my_put_nbr(long nb);
int my_isdigit(char c);
int my_ischar(char c);

//MAIN
char **paths(char *str);
char *exercise_one(t_var *var);
void print_arg(char ** arg);
void create_new(t_info_files *file, char *envp);

//ARRAY_FUNCTIONS
int quantity_words(char *str);
char **str_word_array(char *type, char *str, char *delimitador);
int my_isalnum(char *string);

char *supres_notalphanum(char *string);
char *supres_char(char *string, char sup_char);
char *supres_dot_path(char *string);
void change_value_linked(t_var *var, char *value, char *name);
void supres_value_linked(t_var *var, char *name);

//ENV_FUNCTIONS
void printenv_func(t_var *var, char *params);
void external_setenv(t_var *var, char **param, int i);
void setenv_func(t_var *var, char *params);
void unsetenv_func(t_var *var, char *params);

//EXEC_FUNCTIONS
char **save_exec_params(t_var *var, char *params, char *type);
void ext_execute(pid_t pid, int wstatus);
void try_execute(t_var *var, char *params, char *type);
void try_execute_2(pid_t pid, char **exec_params, char *type);

//FIND_FUNC
int find_in_linked(t_var *var, char *name);
int find_in_str(char *str, char *to_find);
char *find_func(char **paths, char *function);
int find_str_array(t_var *var, char *to_find);

//FUNC_PTR
void type_comands(calculator *flags);
int func_pointer(t_var *var, char *params, char *type);

//GET_INFORMATION
char *clean_last_space(char *string);
char *clean_string(char *string);
int get_line_function(t_var *var);
void ext_get_line_function(t_var *var, char *string, int bytes_read);
char *get_path(t_var *var);

//GET_INFORMATION2
char *get_params(char *str);
char *get_command(char *str);
char **ext_get_env_params(char **comand);
char **get_env_params(char *str);
char *get_info_linked(t_var *var, char *name);
char *supres_dot_path(char *string);

//LINKED_FUNCTIONS
t_info_files *ini_linked_envp(char *envp);
void create_new(t_info_files *file, char *envp);
void save_envplinked(t_info_files *file, char **envp);
void change_oldpwd(t_var *var);
void change_pwdenv(t_var *var);

//MAIN
char **paths(char *str);
void print_arg(char ** arg);
t_info_files *init_file(void) ;

//MY_SH_FUNCS
char *ext_cd_func(t_var *var, char * path, char *current_folder);
char *ext_cd_null(t_var *var, char *current_folder);
void cd_func(t_var *var, char *path);
void my_lsfunc(t_var *var, char *params);
void lsfunc(t_var *var, char *params);

//MY_SH_FUNCS2
char *pwd_func(void);
void my_pwdfunc(t_var *var, char *params);
void pwdfunc(t_var *var, char *params);
void exit_func(t_var *var, char *params);

//FUNDAMENTAL_FUNC
void my_putstr(char const *str);
long my_put_nbr(long nb);

char *supres_notalphanum(char *string);
char **str_word_array(char *type, char *str, char *delimitador);
char **save_exec_params(t_var *var, char *params, char *type);
char *supres_char(char *string, char sup_char);

void save_list_exec(t_var *var, char* string);
char **save_word(char *arraytext);
#endif
