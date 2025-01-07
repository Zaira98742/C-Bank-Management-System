#ifndef FUNCTION_H
#define FUNCTION_H
#include "dataType.h"
extern User users[100];
extern int numUsers;
int isValidID(char *id);
int isValidEmail(char *email);
int isValidPhoneNumber(char *phone);
int isInfoExists(char *id, char *email, char *phone, char *name);
void displayMenu();
void displayUsers();
void searchUserById();
void searchUserByName();
void addUser();
void toggleUserLock();
int compareUsers(void *a,void *b);
void sortUsersByName(int sortOrder);
#endif
