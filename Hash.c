
/************************
	 *  Hash.c
	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Hash.h"
#include "Node.h"

#define PRIME_1 163
#define PRIME_2 151

/**
 * static Wrapper function for void (*_Node::print)(struct _Node *this, int i)
 * - Prints all fields of node along with its address in memory and the index of which it has been stored in the hashtable
 */
static void print_node(Node *node, int i)
{
    node->print(node, i);
}

/**
 * Creates hash code from a char *, prime number, and the size of the hash table.
 */
static int hash(const char *str, int prime, int size)
{
    long hash = 0;
    int i;
    const int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        hash += (long)pow(prime, len - (i + 1)) * str[i];
        hash = hash % size;
    }
    return (int)hash;
}

/**
 * Creates hash code by passing two different prime numbers into <int hash(const char * , int, int)
 */
static int hash_code(const char *str, const int num, const int attempt)
{
    int hash_a = hash(str, PRIME_1, num);
    int hash_b = hash(str, PRIME_2, num);
    return (hash_a + (attempt * (hash_b + 1))) % num;
}

/**
 * Deallocates all memory that of which was allocated at the hashtables creation.
 */
static void _destroy(Hash *this)
{
    if (NULL != this)
    {
        printf("\n  Deallocating Hash Table            %p\n\n", this);
        for (int i = 0; i < this->size; i++)
        {
            if (NULL != this->table[i])
            {
                print_node(this->table[i], i);
                this->table[i]->destroy(this->table[i]);
            }
        }
        printf("\n");
        free(this);
    }
}

/**
 * Performs a hash search for the given key
 */
static Node *_search(Hash *this, const char *key)
{
    int index = hash_code(key, this->size, 0);
    Node *item = this->table[index];
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

/**
 * Prints Hashtable
 */
static void _print_table(Hash *this)
{
    for (int i = 0; i < this->size; i++)
    {
        if (NULL != this->table[i])
            print_node(this->table[i], i);
    }
}

/**
 * Inserts a new node into hashtable.
 */
static void _insert(Hash *this, Node *item) /* insert data params */
{
    int index = hash_code(item->key, this->size, 0);
    Node *cur_item = this->table[index];
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
    this->print_table = _print_table;
    this->count = 0;
    printf("\n  Allocating Hash Table              %p\n\n", this);
    return this;
}
