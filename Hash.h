#ifndef HASH_H
#define HASH_H

typedef struct _Node Node;

/**
 * A Hashtable
 * To change the stored data types, edit the nodes fields in Node.h
 * A hashtable instance can be declared as follows...
 *      Hash * hash_table = CREATE_HASH(int size)
 */
typedef struct _Hash
{
    /**
     * Deallocates all memory that of which was allocated at the hashtables creation.
     */
    void (*destroy)(struct _Hash *this);

    /**
     * Performs a hash search for the given key
     */
    Node *(*search)(struct _Hash *this, const char *key);

    /**
     * Prints Hashtable
     */
    void (*print_table)(struct _Hash *this);

    /**
     * Inserts a new node into hashtable.
     */
    void (*insert)(struct _Hash *this, Node *node);

    Node **table;
    int size;
    int count;

} Hash;
Hash *CREATE_HASH(int size);
#endif /* HASH_H */
