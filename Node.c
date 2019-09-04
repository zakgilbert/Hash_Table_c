
/**
*  Node.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

/**
 * Deallocates all memory that of which was allocated at the Nodes creation.
 */
static void _destroy(Node *this)
{
    if (NULL != this)
    {
        if (NULL != this->key)
            free(this->key);

        free(this);
    }
}

/**
 * prints Nodes data, key, address.
 */
static void _print(Node *node, int i)
{
    printf("Data: %d     Key: %s    Index: %d     %p\n", node->data, node->key, i, node);
}

Node *CREATE_NODE(const char *key, int data)
{
    Node *this = malloc(sizeof(*this));
    this->destroy = _destroy;
    this->print = _print;
    this->key = malloc(sizeof(strlen(key)));
    this->key = strcpy(this->key, key);
    this->data = data;

    return this;
}
