#include "eval.h"
#include "checkInput.h"
#include <string.h>

int main()
{
    int e = 1;
    float total;
    char input[256];
    char postfix[256];
    system("cls");
    while (e != 0)
    {
        printf("\nplease enter infix equation using operators */+- and ()");
        gets_s(input);
        e = checkInput(input);
        if (e != 0)
            printf("\ninput error (%d)", e);
    }
    // infixToPostfix(input,postfix); not yet implemented
    e = evaluation(postfix, &total);
    printf_s("your answer is %f", total);

    return 0;
}