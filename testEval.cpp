#include"eval.h"
int main ()
{
    char x[100]  = "20/";
    float total;
    if(evaluation(x,&total)==0)
    printf("=%.2f",total);//return 
    else
    printf("error ");

    return 0;
}