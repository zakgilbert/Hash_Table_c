
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
        this->print(this, this->index);
        printf("%*s\n", 10, "Delete");
        free(this);
    }
}

/**
 * prints Nodes data, key, address.
 */
static void _print(Node *node, int i)
{
    printf("%p     Data: %*d     Key: %*s    Index: %*d", node, 2, node->data, 10, node->key, 2, i);
}

Node *CREATE_NODE(char *key, int data)
{
    Node *this = malloc(sizeof(*this));
    this->destroy = _destroy;
    this->print = _print;
    this->key = key;
    this->data = data;

    return this;
}
