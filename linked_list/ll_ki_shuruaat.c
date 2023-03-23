// linked list ki shuruaat

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    char data;
    struct list *link;
} list;

int main()
{
    list item1, item2, item3;
    item1.data = 'a';
    item2.data = 'b';
    item3.data = 'c';
    item1.link = item2.link = item3.link = NULL;
    return 0;
}
