//#include"charStack.h"
#include"FStack.h"
#include"charToInt.h"
#include<string.h>
#include<ctype.h>
#include<math.h>
float evaltion(char postfix[])
{
    Fstack s;
    float total;
    int b=strlen(postfix);//number of characters in postfix
    initializeStack(&s,b);
    for(int i=0;i<b;i++)//loop 3la el postfix to start evaluation
    {
        if(isdigit(postfix[i]))//check if postfix is a digit
        {
            int j;
            for(j=0;!isdigit(postfix[j]);j++)//loop until postfix char
            {
                push(&s,postfix[j]);//push in stack char of interger only untill an simble shows up
            }

            float x,y,error;//checker use to check if there is any errors occures
            error1=pop(&s,&x);//pop from stack char of two interger before symbol
            checker2=pop(&s,&y);
            if(checker1==0&&checker2==0)
            {
                switch(postfix[j])
            {
                case '+':checker3=push(&s,chartoint(x)+chartoint(y));//push back the result to the stack to continue the evaluation process
                        break;
                case '-':checker3=push(&s,chartoint(x)-chartoint(y));
                        break;
                case '*':checker3=push(&s,chartoint(x)*chartoint(y));
                        break;
                case '/':checker3=push(&s,chartoint(y)/chartoint(x));
                        break;
                case '^':checker3=push(&s,pow(chartoint(x),chartoint(y)));
                        break;
            }
            if(checker3==0)
            {
                if(isEmpty)
                {
                    checker4=pop(&s,&total);
                    if(checker4==0)
                        return total;
                    else
                    printf("error %d",checker3);
                }
                else
                j=0;
                }
            else printf("error %d",checker4);
            
            }
            else
            printf("error %d & error %d occures",checker1,checker2);
            
        }
    }

}