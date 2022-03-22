//#include"charStack.h"
#include"intStack.h"
#include"charToInt.h"
#include<string.h>
#include<ctype.h>
#include<math.h>
float evaltion(char postfix[])
{
    Istack s;
    int total;
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
            int x,y,checker1,checker2,checker3,checker4;//checker use to check if there is any errors occures
            checker1=pop(&s,&x);//pop in stack char of two interger before simble 
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
                case '/':checker3=push(&s,chartoint(x)/chartoint(y));
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