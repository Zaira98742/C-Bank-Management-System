#ifndef DATATYPE_H
#define DATATYPE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct {
    char id[100];
    char name[100];
    char email[100];
    char phone[100];
    int age;
    int Status[20];
    int locked;
} User;
#endif
