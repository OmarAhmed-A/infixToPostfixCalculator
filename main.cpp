// Made By Omar Ahmed
#include <stdio.h>
#include <string.h>
#include "eval.h"
#include "checkInput.h"
#include "infixtopostfix.h"
int main()
{
    int e = 1;
    float total;
    char input[256];
    char postfix[256];
    system("cls");
    while (e != 0)
    {
        printf("\nplease enter infix equation using operators ^*/+- and ()");
        gets(input);
        e = checkInput(input);
        if (e != 0)
            printf("\ninput error (%d)", e);
    }
    infixtopostfix(input,postfix);
    e = evaluation(postfix, &total);
    printf("your answer is %.2f", total);

    return 0;
}