#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "Node.h"

int main(int argc, char **argv)
{
    Hash *table = CREATE_HASH(10);
    table->insert(table, CREATE_NODE("one", 1));
    table->insert(table, CREATE_NODE("two", 2));
    table->insert(table, CREATE_NODE("three", 3));
    table->insert(table, CREATE_NODE("four", 4));
    table->delete (table, "two");
    table->delete (table, "fjsdlf");
    table->print_table(table);
    table->destroy(table);
    table->print_table(table);
    return 0;
}
