#ifndef NODE_H
#define NODE_H

/**
 * A node type to be inserted into a hashtable using Hash.h.
 * Should (int data) need to be changed to a different data type lines 20 and 22 will need to be changed in Node.h, as well as lines 30, and 33 in Node.c.
 */
typedef struct _Node
{
    /**
     * Deallocates all memory that of which was allocated at the Nodes creation.
     */
    void (*destroy)(struct _Node *this);

    /**
     * prints Nodes data, key, address.
     */
    void (*print)(struct _Node *this, int i);
    char *key;
    int data;
    int index;
} Node;
Node *CREATE_NODE(char *key, int data);

#endif /* NODE_H */
