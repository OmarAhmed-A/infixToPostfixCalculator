// Made By Omar Ahmed
#include "eval.h"
#include "checkInput.h"
#include"postfix.h"
#include <string.h>

int main()
{
    int e = 1;
    float total;
    char input[256];
    char postfix[256], infix[256];
    system("cls");
    while (e != 0)
    {
        printf("\nplease enter infix equation using operators */+- and ()");
        gets_s(input);
        e = checkInput(input);
        if (e != 0)
            printf("\ninput error (%d)", e);
    }
    e = Postfixconv(infix,postfix);
    e = evaluation(postfix, &total);
    printf("your answer is %f", total);

    return 0;
}