#ifndef _FUNC_H_
#define _FUNC_H_

#include "stdio.h"
#include "malloc.h"
#include "string.h"

struct CNode
{
	int data;
	CNode * next;
};

int reverseNumber(int);
char * findPref(char **s, int);
void reverseList(CNode*);
int * findSumElements(int b[], int, int);

#endif  //  _FUNC_H_