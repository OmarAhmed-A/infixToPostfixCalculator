// Made By Omar Ahmed
#include "charStack.h"
#include <string.h>
#include <ctype.h>

int checkBrackets(char *input)
{
    Cstack s;
    char b;
    int e;
    initializeStack(&s, strlen(input));
    for (int i = 0; i <= strlen(input); i++)
    {
        if (input[i] == '(')
            push(&s, '(');
        else if (input[i] == ')')
        {
            e = pop(&s, &b);
            if (e != 0)
                return 1; // not balanced
        }
    }

    if (!isEmpty(&s))
        return 1; // not balanced

    return 0; // bancled
}

int checkInput(char *input)
{
    checkBrackets(input);

    if (input[strlen(input)-1] == '^' ||input[strlen(input)-1] == '+' || input[strlen(input)-1] == '-' ||
        input[strlen(input)-1] == '*' || input[strlen(input)-1] == '/')
        return -1; // last char of input is operator // not allowed

    for (int i = 0; i < strlen(input); i++)
    {
        if(isalpha(input[i]))
        return -4; //letters are not allowed
        else if (isdigit(input[i]) && isdigit(input[i + 1]))
            return -2; // multidigit input num //not allowed
        else if ((input[i] == '^' || input[i] == '+' || input[i] == '/' || input[i] == '*' || input[i] == '-') 
            &&  (input[i+1] == '^' || input[i+1] == '+' || input[i+1] == '/' || input[i+1] == '*' || input[i+1] == '-'))
            return -3; // multiple operators in a row //not allowed
    }

    return 0; // all ok
