// Made By Omar Ahmed
#include <stdio.h>
#include <stdlib.h>
#pragma once

struct Istack
{
	int* arr;
	int sp;
	int size;

	//Constructor (from C++)
	Istack()
	{
		arr = NULL;
		sp = -1;
		size = 0;
	}
};

bool initializeStack(Istack *s, int size)
{
	if (s->arr != NULL) //In case previous malloc is called
		free(s->arr);
	s->arr = (int*)malloc(sizeof(int) * size);
	if (s->arr == NULL)
		return false;
	s->size = size;
	s->sp = -1;
	return true;
}

int isEmpty(Istack* s)
{
	return s->sp == -1;
}

int push(Istack *s, int item)
{
	if (s->arr == NULL)
		return -1;	//Istack not initialized !
	if (s->sp + 1 == s->size)
		return -2;	//Istack overflow !

	s->sp = s->sp + 1;	//or s->sp++;
	s->arr[s->sp] = item;
	return 0;
}

int pop(Istack *s, int* item)
{
	if (s->arr == NULL)
		return -1;	//Istack not initialized !
	if (isEmpty(s))
		return -2;	//Istack underflow !

	*item = s->arr[s->sp];
	s->sp = s->sp - 1;	//s->sp--;
	return 0;
}


int peek(Istack* s, int *item)
{
    if (!isEmpty(s))
    *item = s->arr[s->sp];

    return 1;
}