#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

int main(int argc, char **argv)
{
    Hash *table = CREATE_HASH(10);
    table->insert(table, "one", 1);
    table->insert(table, "two", 2);
    table->insert(table, "two", 2);
    table->destroy(table);
    return 0;
}
