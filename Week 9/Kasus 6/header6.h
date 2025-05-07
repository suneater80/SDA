#ifndef Kasus6_H
#define Kasus6_H
#include <stdio.h>
#include "BOOLEAN.H"

typedef char infotype;
typedef struct data *address;
typedef struct data
{
    infotype info;
    address next;
}Edata;

typedef struct 
{
    address Head;
}List;

void createList(List L);

boolean listEmpty(List L);



#endif