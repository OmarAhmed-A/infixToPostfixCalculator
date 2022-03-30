// Made By Hassan Mekawi
#include"FStack.h"
#include"CharToFloat.h"
#include<string.h>
#include<ctype.h>
#include<math.h>
#pragma once

float evaluation(char postfix[],float *total)
{
    Fstack s;
    int h=0,b=strlen(postfix);//number of characters in postfix
    initializeStack(&s,b);
    for(int i=0;i<b;i++)//loop 3la el postfix to start evaluation
    {
        if(isdigit(postfix[i]))
            push(&s,charToFloat(postfix[i]));
        else if(postfix[i] == '-'||postfix[i] =='+'||postfix[i] == '/'||postfix[i] == '*'||postfix[i] == '^')//mesh hadakhal haga 3ar el mathimatical charters
        {
            float first_value,second_value;    
            pop(&s,&first_value);//first value
            pop(&s,&second_value);//second value
            if(postfix[i]=='+')
                push(&s,second_value + first_value);//push back the result to the stack to continue the evaluation process
            else if(postfix[i]=='-')
                push(&s,second_value - first_value);
            else if (postfix[i]=='*')
                push(&s,second_value * first_value); 
            else if(postfix[i]=='/')
                if(first_value==0)//make sure that first value isn't == 0
                    h++;//to return error for main 
                else 
                    push(&s,second_value / first_value);
            else if(postfix[i] == '^')
                push(&s,pow(second_value,first_value));
        }
        else if(isspace(postfix[i]))
            break;//if postfix comes with spaces like postfix[]]="2 2 /" will run without any problems
    }
    peek(&s,total);
    if(h == 0)//if math error will return -1
    return 0;//no errors produced
    else return -1;//math error produced
}