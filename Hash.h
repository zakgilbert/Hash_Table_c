#ifndef HASH_H
#define HASH_H

struct Node
{
    char *key;
    int data;
};

typedef struct _Hash
{
    void (*destroy)(struct _Hash *this);

    void (*insert)(struct _Hash *this, const char *key, int data); /* insert data params */

    struct Node *(*search)(struct _Hash *this, const char *key);

    struct Node *(*create_node)(const char *key, int data); /* insert data params */

    void (*print_table)(struct _Hash *this);

    struct Node **table;
    int size;
    int count;

} Hash;
Hash *CREATE_HASH(int size);
#endif /* HASH_H */
