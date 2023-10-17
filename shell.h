#ifndef _SHELL_H_
#define _SHELL_H_

/****** ENVIRONMENT HANDLERS ******/

extern char **environ;
void create_environment(char **envi);
void free_environment(char **env);

/******** STRING HANDLER FUNCTIONS **********/

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);

/****** PRINTING FUNCTIONS *****/

void print_number_unsigned(unsigned int n);
void print_number_int(int n);
int print_echo(char **cmd);

/****** MISCELLANEOUS AND INPUT FUNCTIONS *******/

char *_getline();
char *space(char *str);
char *enter(char *string);
void hashtag_handler(char *buff);
void simple_prompt(void);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
int history(char *input);
char **separator(char *input);

/******* PATH FINDER *******/

int path_command(char **cmd);
char *build(char *token, char *value);
char *_getenv(char *name);

/*********** MEMORY HANDLERS ***********/

void free_environment(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_reallocate(void *ptr, unsigned int old_size, unsigned int new_size);
void free_allocated(char **input, char *line);

/******* HELP HANDLERS *******/

void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
int display_help(char **cmd, __attribute__((unused))int st);

/****** BUILTIN COMMAND HANDLERS AND EXECUTE ******/

int check_builtin(char **cmd);
int handle_builtin(char **cmd, int st);
int echo_bul(char **cmd, int st);
int history_dis(__attribute__((unused))char **c,
		__attribute__((unused)) int st);
void exit_bul(char **cmd, char *input, char **argv, int c, int stat);
int change_dir(char **cmd, __attribute__((unused))int st);
int dis_env(__attribute__((unused)) char **cmd,
	    __attribute__((unused)) int st);

/******* ERROR HANDLERS ******/

void print_error(char *input, int counter, char **argv);
void _prerror(char **argv, int c, char **cmd);
void error_file(char **argv, int c);

/****** PARSED ARGUMENT HANDLER FUNCTIONS *****/

char **parse_cmd(char *input);
int handle_builtin(char **cmd, int er);
int check_cmd(char **cmd, char *input, int c, char **argv);
void signal_to_handle(int sig);

/****** FILE ARGUMENT HANDLER FUNCTIONS ******/

void read_file(char *file, char **argv);
void treat_file(char *line, int count, FILE *fp, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

#endif /*shell.h*/



