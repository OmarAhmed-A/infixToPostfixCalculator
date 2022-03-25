#include"FStack.h"
#include"charToFloat.h"
#include<string.h>
#include<ctype.h>
#include<math.h>
float evaluation(char postfix[],float *total)
{
    Fstack s;
    *total=0;
    int i,h=0, b=strlen(postfix);//number of characters in postfix
    initializeStack(&s,b);
    for(i=0;i<b;i++)//loop 3la el postfix to start evaluation
    {
        if(isdigit(postfix[i]))
                push(&s,chartoFloat(postfix[i]));
        else if(postfix[i] == '-'||postfix[i] =='+'||postfix[i] == '/'||postfix[i] == '*'||postfix[i] == '^')
        {
            float x,y;
            pop(&s,&x);//first value
            pop(&s,&y);//second value
            float first_value=x,second_value=y;
            //printf("\n%f\n%f\n",first_value,second_value);
            switch(postfix[i])
            {
                case '+':push(&s,second_value + first_value);//push back the result to the stack to continue the evaluation process
                        break;
                case '-':push(&s,second_value - first_value);
                        break;
                case '*':push(&s,second_value* first_value); 
                        break;
                case '/':if(first_value==0)
                        {
                        h++;
                        }
                        else push(&s,second_value/first_value);
                        break;
                case '^':push(&s,pow(second_value,first_value));
                        break;
                }
        }
        else if(isspace(postfix[i]))
            break;
    }
    peek(&s,total);
    if(h == 0)
    return 0;
    else return -1;

}