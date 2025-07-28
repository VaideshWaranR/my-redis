#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/command_handler.h"
//#include "datastore.h"

#define MAX_TOKENS 3

char* handle_command(char *input) {
    input[strcspn(input, "\r\n")] = 0;

    char *tokens[MAX_TOKENS];
    int token_count = 0;
    char *token = strtok(input, " ");

    while (token && token_count < MAX_TOKENS) {
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }

    if (token_count == 0) return strdup("ERROR: Empty command\n");

    if (strcmp(tokens[0], "set") == 0) {
        if (token_count != 3) return strdup("ERROR: Usage: SET key value\n");
        //set_key(tokens[1], tokens[2]);
        return strdup("OK\n");

    } else if (strcmp(tokens[0], "get") == 0) {
        if (token_count != 2) return strdup("ERROR: Usage: GET key\n");
        const char *value = "value retrived"; 
	//get_key(tokens[1]);
        if (value)
            return strdup(value);
        else
            return strdup("(nil)\n");

    } else if (strcmp(tokens[0], "del") == 0) {
        if (token_count != 2) return strdup("ERROR: Usage: DEL key\n");
        if (1==1)
	       //	delete_key(tokens[1]))
            return strdup("Deleted\n");
        else
            return strdup("Not Found\n");

    } else {
        return strdup("ERROR: Unknown command\n");
    }
}

