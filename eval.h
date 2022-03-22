#include"charStack.h"
#include"intStack.h"
#include"charToInt.h"
#include<string.h>
#include<ctype.h>
#include<math.h>
float evaltion(char postfix[])
{
    Stack s;
    float total;
    int b=strlen(postfix);//number of characters in postfix
    initializeStack(&s,b);
    for(int i=0;i<b;i++)//loop ala el postfix to start evaluation
    {
        if(isdigit(postfix[i]))//check if postfix is a digit
        {
            int j;
            for(j=0;!isdigit(postfix[j]);j++)//loop until postfix char
            {
                push(&s,postfix[j]);//push in stack char of interger only untill an simble shows up
            }
            float x,y;
            pop(&s,&x);//pop in stack char of two interger before simble 
            pop(&s,&y);
            switch(postfix[j])
            {
                case '+':push(&s,chartoint(x)+chartoint(y));//push back the result to the stack to continue the evaluation process
                        break;
                case '-':push(&s,chartoint(x)-chartoint(y));
                        break;
                case '*':push(&s,chartoint(x)*chartoint(y));
                        break;
                case '/':push(&s,chartoint(x)/chartoint(y));
                        break;
                case '^':push(&s,pow(chartoint(x),chartoint(y)));
                        break;
            }
            
            if(isEmpty)
            {
                peek(&s,&total);
                return total;
            }
            else
            j=0;
            
        }
    }

}