#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "Node.h"

int main(int argc, char **argv)
{
    Hash *table = CREATE_HASH(10);
    table->print_table(table);
    Node *one = CREATE_NODE("one", 1);
    Node *two = CREATE_NODE("two", 2);
    Node *three = CREATE_NODE("three", 3);
    Node *four = CREATE_NODE("four", 4);
    table->insert(table, one);
    table->insert(table, two);
    table->insert(table, three);
    table->insert(table, four);
    table->destroy(table);
    table->print_table(table);
    return 0;
}
