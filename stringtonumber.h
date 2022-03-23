#include "charToFloat.h"
#include<math.h>
float stringtofloat(char c[])
{
    float s=0;
    for(int i = 0; i <strlen(c);i++) 
        s+=(chartoFloat(c))*pow(10,i);
    return s;
    }
}