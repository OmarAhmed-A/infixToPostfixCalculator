#include "charStack.h"
#include <string.h>

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

    if (!isEmpty)
        return 1; // not balanced

    return 0; // bancled
}


int checkInput(char *input)
{
    


}