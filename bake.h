/*CITS2002 Project 2018
 * Names: Christian Sivwright, Gemma Irving
 * Student Numbers: 21484775, 21282314
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdbool.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<string.h>

// flags


char c_flag[300];
char f_flag[200] ;
int i_flag;
int n_flag;
int p_flag;
int s_flag;


struct Node {
	char* variable;
	char* value ;
	struct Node* prev;
};


//user defined datatype
typedef struct _l{
	char * target;
	char * dependencies; //store as a string and split up later 
	char * action;
	struct _l *next;
} LISTITEM;


//target structure
extern void store_struct(FILE *); //param is not named
extern LISTITEM* store_target(FILE *);
bool is_target(char *);
void trimline(char *);
char* nextline(FILE *);


//variable storage
extern char * find_in_linkedlist(char * line);
void handle_assignment(char *, int);
//void handle_dependency(char *, int);
void handle_line(char *);
void push_to_linkedlist(char*,char*);

//rebuild
extern void rebuild(char *);
extern void build(LISTITEM *item);

//build
extern LISTITEM* find_item(LISTITEM *list, char * targwanted);
extern void build(LISTITEM *list);

//variable expansion file
extern char * handle_expansions(char *);
char * expansion(char *);
int count(char *);

//url mod
char * get_mod1(char *);
extern char * should_rebuild_url(char *);
