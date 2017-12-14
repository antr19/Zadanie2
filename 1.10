#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_element
{
    char name[100];
    char number [20];
    struct list_element* next;
    struct list_element* prev;
} list_element;

list_element* create_list_element(char x [100], char y[20])
{
    list_element* p = malloc(sizeof(list_element));
    strcpy(p->name,x);
    strcpy(p->number,y);
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insert_into_list(list_element* a, list_element* b)
{
    list_element* c = a->next;
    a->next = b;
    b->prev = a;
    b->next = c;
    if(c != NULL)
        c->prev = b;
}

void print_list (list_element* a)
{
    while (a!=NULL)
    {
        printf("%s %s\n",a->name,a->number);
        a = a->next;
    }

}

void delete_list(list_element* a)
{
    list_element* b;
    while (a != NULL)
    {
        b=a->next;
        free(a);
        a=b;
    }

}


void Insert (list_element* a,char name[100],char number[20])
{
    int k = 0;
    list_element* b;
    b=a;
    while (b != NULL)
    {
        if (strcmp(b->name,name) == 0)
        {
            printf("Changed. Old value = %s\n",b->number);
            strcpy(b->number,number);
            k=1;
        }
        b = b->next;
    }
    if (k == 0)
    {
        insert_into_list(a,create_list_element(name,number));
    }

}

void Find (list_element* a,char name[100])
{
    int k = 0;
    list_element* b;
    b=a;

    while (b != NULL)
    {
        if (strcmp(b->name,name) == 0)
        {
            printf("%s\n",b->number);
            k=1;
        }
        b=b->next;
    }
    if (k == 0)
    {
        printf("NO");
    }
}

int main()
{

    char name[100];
    char number[20];
    char s[1];

    list_element* l;
    l=create_list_element(" "," ");

    scanf("%s",&s);
    while (s[0] != 'E')
    {

        if (s[0] == 'I')
        {

            scanf("%s",name);
            scanf("%s",number);
            Insert(l, name, number);
        }
        else if (s[0] == 'F')
        {
            scanf("%s",name);
            Find(l, name);
        }
        scanf("%c",s[0]);
    }

    delete_list(l);
    return 0;
}
