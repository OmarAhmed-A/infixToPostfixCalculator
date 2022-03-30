#include <stdio.h>
#include <stdlib.h>

struct Cstack
{
	char* arr;
	int sp;
	int size;

	//Constructor (from C++)
	Cstack()
	{
		arr = NULL;
		sp = -1;
		size = 0;
	}
};

bool initializeStack(Cstack *s, int size)
{
	if (s->arr != NULL) //In case previous malloc is called
		free(s->arr);
	s->arr = (char*)malloc(sizeof(char) * size);
	if (s->arr == NULL)
		return false;
	s->size = size;
	s->sp = -1;
	return true;
}

int isEmpty(Cstack* s)
{
	return s->sp == -1;
}


int push(Cstack *s, char item)
{
	if (s->arr == NULL)
		return -1;	//Cstack not initialized !
	if (s->sp + 1 == s->size)
		return -2;	//Cstack overflow !

	s->sp = s->sp + 1;	//or s->sp++;
	s->arr[s->sp] = item;
	return 0;
}

int pop(Cstack *s, char* item)
{
	if (s->arr == NULL)
		return -1;	//Cstack not initialized !
	if (isEmpty(s))
		return -2;	//Cstack underflow !

	*item = s->arr[s->sp];
	s->sp = s->sp - 1;	//s->sp--;
	return 0;
}

// int isEmpty(Cstack* s)
// {
// 	return s->sp == -1;
// }

int peek(Cstack* s, char *item)
{
    if (!isEmpty(s))
    *item = s->arr[s->sp];

    return 1;
}