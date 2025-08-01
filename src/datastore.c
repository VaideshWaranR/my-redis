#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../include/datastore.h"
#include "../include/uthash.h"

typedef struct {
    char *key;            // key
    char *value;          // value
    UT_hash_handle hh;    // makes this structure hashable
} KVPair;

static KVPair *store = NULL;

void set_key(const char *key, const char *value) {
    KVPair *entry = NULL;
    HASH_FIND_STR(store, key, entry);

    if (entry == NULL) {
        entry = (KVPair *)malloc(sizeof(KVPair));
        entry->key = strdup(key);
        entry->value = strdup(value);
        HASH_ADD_KEYPTR(hh, store, entry->key, strlen(entry->key), entry);
    } else {
        free(entry->value);
        entry->value = strdup(value);
    }
}

char *get_key(const char *key) {
    KVPair *entry = NULL;
    HASH_FIND_STR(store, key, entry);
    return entry ? entry->value : NULL;
}

bool delete_key(const char *key) {
    KVPair *entry = NULL;
    HASH_FIND_STR(store, key, entry);
    if (entry != NULL) {
        HASH_DEL(store, entry);
        free(entry->key);
        free(entry->value);
        free(entry);
	return true;
    }
    return false;
}

void save_data(const char *filename){
    FILE *fp = fopen(filename, "w");
    if (!fp) return;

    KVPair *s, *tmp;
    HASH_ITER(hh, store, s, tmp) {
        fprintf(fp, "%s %s\n", s->key, s->value);
    }
    fclose(fp);
}
void load_data(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    char key[256], value[1024];
    while (fscanf(fp, "%s %s\n", key, value) != EOF) {
        set_key(key, value);
    }
    fclose(fp);
}

void free_store() {
    KVPair *entry, *tmp;
    HASH_ITER(hh, store, entry, tmp) {
        HASH_DEL(store, entry);
        free(entry->key);
        free(entry->value);
        free(entry);
    }
}
bool key_exist(const char *key){
	KVPair *found;
        HASH_FIND_STR(store, key, found); 
        return found != NULL;
}
