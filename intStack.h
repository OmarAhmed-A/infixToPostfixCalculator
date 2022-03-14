#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int* arr;
	int sp;
	int size;

	//Constructor (from C++)
	Stack()
	{
		arr = NULL;
		sp = -1;
		size = 0;
	}
};

bool initializeStack(Stack *s, int size)
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

int isEmpty(Stack* s)
{
	return s->sp == -1;
}

int push(Stack *s, int item)
{
	if (s->arr == NULL)
		return -1;	//Stack not initialized !
	if (s->sp + 1 == s->size)
		return -2;	//Stack overflow !

	s->sp = s->sp + 1;	//or s->sp++;
	s->arr[s->sp] = item;
	return 0;
}

int pop(Stack *s, int* item)
{
	if (s->arr == NULL)
		return -1;	//Stack not initialized !
	if (isEmpty(s))
		return -2;	//Stack underflow !

	*item = s->arr[s->sp];
	s->sp = s->sp - 1;	//s->sp--;
	return 0;
}


int peek(Stack* s, int *item)
{
    if (!isEmpty(s))
    *item = s->arr[s->sp];

    return 1;
}