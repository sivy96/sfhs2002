/*CITS2002 Project 2018
 * Names: Christian Sivwright, Gemma Irving
 * Student Numbers: 21484775, 21282314
 */

#include "bake.h"

//func to count amount of '$' in a line 
int count(char * line) {
	int length=strlen(line);
	int count=0;

	for(int i=0; i<length; i++){
		if(line[i]=='$') {
			count++;
		}
	}
	return count;
}

//func to expand all variables 
//accepts char * and int as paramters
//returns a char * line with variables expanded
char * expansion(char * line) {
	
	int length=strlen(line);
	int start=0;
	int end=0;

	//find start of var expansion
	for(int i=0; i<length; i++) {
		start++;
		if(line[i]=='$') {
			break;
		}
	}
	//find end of var expansion
	for(int i=0; i<length; i++) {
		end++;
		if(line[i]==')') {
			break;
		}
	}
	//find word inside $(word)
	char var[BUFSIZ];
	int index=0; 
	for(int i=start+1; i<end-1; i++) {
		var[index]=line[i];
		index++;
	}
	//replace w/value
	char * variable=strdup(var);
	char * value=find_in_linkedlist(variable);
	char a[]=" ";
	value=realloc(value,sizeof(value[0])*strlen(value)+1);
	value=strcat(value, a);
	//get first part of string
	char str1[BUFSIZ]="";
	int index2=0;
	for(int i=0; i<start-1; i++) {
		str1[index2]=line[i];
		index2++;
	}

	
	//get string remaining after var
	char str2[BUFSIZ]="";
	int index3=0;

	for(int i=end+1; i<length; i++) {
		str2[index3]=line[i];
		index3++;
	}
	

	//put back together and then return char * to final string


	char *str_med=strcat(str1, value);

	char * str_final=strcat(str_med, str2);
	char * expanded=strdup(str_final);

	int final_length = strlen(expanded) +1;
	expanded = realloc(expanded, sizeof(expanded[0])*final_length);
	expanded[final_length] = '\0';

	return expanded;
}


			


//overall function repeats expansion for however many $'s there are
char * handle_expansions(char * line) {
	bool expand = false;
	int i = 0;
	while (line[i] != '\0') {
		if (line[i] == '$') {
			expand = true;
			break;
		}
		i++;
	}
	if (expand) {
		int counter = count(line);
		char **expanded = malloc(sizeof(char *));
		int exp = 0;
		expanded = realloc(expanded, (exp + 1) * sizeof(expanded[0]));
		expanded[exp] = expansion(line);
		exp++;


		for (int i = 0; i < counter - 1; i++) {
			expanded = realloc(expanded, (exp + 1) * sizeof(expanded[0]));
			expanded[exp] = expansion(expanded[i]);
			exp++;
		}

		return expanded[counter - 1];
	} else {
		return line;
	}
}




