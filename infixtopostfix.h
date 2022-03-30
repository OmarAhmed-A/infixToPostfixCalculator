#include"charStack.h"
#include<string.h>
#include <ctype.h>
#pragma once

int Prec(char mathchar)
{
	if(mathchar == '+'||mathchar =='-')
      return 1;
   else if(mathchar == '*'||mathchar=='/')
      return 2;
   else if(mathchar == '^')
      return 3;
   else return -1;
}

int infixtopostfix(char* x, char* temp)
{

	int i, j = 0;
	Cstack stack;
	initializeStack(&stack, strlen(x));

   for (i = 0; i < strlen(x); ++i)
	{
      char chr;

		if (isdigit(x[i])) {
			temp[j++] = x[i];

		}


		else if (x[i] == '(')
			push(&stack, x[i]);


		else if (x[i] == ')')
		{
			char bracket;
         peek(&stack, &chr);
			while (!isEmpty(&stack) && chr != '('){
				pop(&stack, &temp[j++]);
            peek(&stack, &chr);
         }

			pop(&stack, &bracket);
		}
		else
		{
         peek(&stack,&chr);
			while (!isEmpty(&stack) && Prec(x[i]) <= Prec(chr)){
				pop(&stack, &temp[j++]);
            peek(&stack, &chr);
         }
			push(&stack, x[i]);
		}

	}


	while (!isEmpty(&stack))
		pop(&stack, &temp[j++]);

	temp[j++] = '\0';
	return 0;
}

