#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stdio.h>
#include "string.h"
#include <assert.h>

#define MAX_NAME 25
#define MAX_TELE 12
#define MAX_ADDR 25
#define MAX_SEX 10
#define MAX 1000

typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char sex[MAX_SEX];
}PeoInfo;
typedef struct Contact
{
	PeoInfo date[MAX];
	int sz;
}Contact, *p;

void InintContact(Contact *p);
void AddContact(Contact *p);
void ShowContact(Contact *p);
void SearchContact(Contact *p);
void DelContact(Contact *p);
void EmptyContact(Contact *p);
void SortContact(Contact *p);
void ReverseContact(Contact *p);



#endif // __CONTACT_H__
