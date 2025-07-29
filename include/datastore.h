#ifndef DATASTORE_H
#define DATASTORE_H
#include<stdbool.h>

void set_key(const char* key, const char* value);
char* get_key(const char* key);
bool delete_key(const char* key);
void free_store();
void save_data(const char *filename);
void load_data(const char *filename);

#endif

