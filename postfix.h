#include"charStack.h"
#include <string.h>
#include<ctype.h>

int Prec(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}


int Postfixconv(char* x,char* temp)
{
	int i, j = 0;
	


	Cstack stack;
    initializeStack(&stack,strlen(x));



	for (i = 0; i < strlen(x); ++i)
	{


		if (isdigit(x[i])) {
			temp[j++] = x[i];

		}


		else if (x[i] == '(')
			push(&stack, x[i]);


		else if (x[i] == ')')
		{
			char z;
         peek(&stack, &z);
			while (!isEmpty(&stack) && z != '(')
				 pop(&stack,&temp[j++]);
			//if (!isEmpty(stack) && peek(stack) != '(')
				//return -1;
			//else
				pop(&stack,&z);
		}
		else
		{
         char z;
         peek(&stack,&z);
			while (!isEmpty(&stack) &&Prec(x[i]) <= Prec(z))
				pop(&stack,&temp[j++]);
			push(&stack, x[i]);
		}

	}
   
	while (!isEmpty(&stack))
		pop(&stack,&temp[j++]);

	temp[j++] = '\0';
	return 0;
}

