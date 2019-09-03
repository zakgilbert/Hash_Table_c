
/************************
	 *  Hash.c
	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Hash.h"

#define PRIME_1 163
#define PRIME_2 151

static int hash(const char *letter, int prime, int size)
{
    long hash = 0;
    int i;
    const int len = strlen(letter);
    for (i = 0; i < len; i++)
    {
        hash += (long)pow(prime, len - (i + 1)) * letter[i];
        hash = hash % size;
    }
    return (int)hash;
}

static int hash_code(const char *letter, const int num, const int attempt)
{
    int hash_a = hash(letter, PRIME_1, num);
    int hash_b = hash(letter, PRIME_2, num);
    return (hash_a + (attempt * (hash_b + 1))) % num;
}

static void print_node(struct Node *node, int i)
{
    printf("%p    Data: %d     Key: %s    Index: %d\n", node, node->data, node->key, i);
}

static void _destroy(Hash *this)
{
    if (NULL != this)
    {
        printf("Deallocating Hash Table %p\n", this);
        for (int i = 0; i < this->size; i++)
        {
            if (NULL != this->table[i])
            {
                print_node(this->table[i], i);
                free(this->table[i]->key);
                free(this->table[i]);
            }
        }
        free(this);
    }
}

static struct Node *_search(Hash *this, const char *key)
{
    int index = hash_code(key, this->size, 0);
    struct Node *item = this->table[index];
    int i = 1;
    while (NULL != item)
    {
        if (strcmp(item->key, key) == 0)
            return item;
        index = hash_code(key, this->size, i);
        i++;
    }
    return NULL;
}

static struct Node *_create_node(const char *key, int data) /* insert data params */
{
    struct Node *item = malloc(sizeof(struct Node));
    item->key = malloc(strlen(key));
    item->key = strcpy(item->key, key);
    item->data = data;

    return item;
}

static void _print_table(Hash *this)
{
    for (int i = 0; i < this->size; i++)
    {
        if (NULL != this->table[i])
            print_node(this->table[i], i);
    }
}

static void _insert(Hash *this, const char *key, int data) /* insert data params */
{
    struct Node *item = this->create_node(key, data); /* insert data params */
    int index = hash_code(item->key, this->size, 0);
    struct Node *cur_item = this->table[index];
    int i = 1;
    while (NULL != cur_item)
    {
        index = hash_code(item->key, this->size, i);
        cur_item = this->table[index];
        i++;
    }
    this->table[index] = item;
    print_node(this->table[index], index);
    this->count++;
}

Hash *CREATE_HASH(int size)
{
    Hash *this = malloc(sizeof(*this));
    this->size = size;
    this->table = calloc(this->size, sizeof(struct Node *));
    this->insert = _insert;
    this->destroy = _destroy;
    this->search = _search;
    this->create_node = _create_node;
    this->print_table = _print_table;
    this->count = 0;
    printf("Allocating Hash Table %p\n", this);
    return this;
}
