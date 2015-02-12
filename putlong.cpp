#include<iostream>

char * cp(char *a)
{
    char *f;
    f = (char *)malloc((strlen(a) + 1)*sizeof(char));
    char* ret = f;
    while (*a != 0)
    {
        *f = *a;
        f++;
        a++;
    }  
    *f = '\0';
    return ret;
}

char *copy1( char *s, char *t )
{
    while ( (*s++ = *t++) )
    {
        ;
    }
    return s;
}

char* copy2(char *s, char* t)
{
   while(*s)
   {
       *t = *s;
       t++;
       s++;
   }
   *t = '\0';
   return t;
} 

//print decimal in order 
//123->1, 2, 3
void putlong(unsigned num)
{
    if(num >= 10)
        putlong(num/10);
    putchar('0'+num%10);
}

void revputlong(unsigned num)
{
    putchar('0' + num%10);
    if(num >= 10)
        revputlong(num/10);
}

int main()
{
    std::cout<<"Hello World";
    
    char str[] = "123";
    char str1[] = "aaa";
    char *pt = str;
    char *pt1 = str1;
    char *mycopy = cp(str);
    std::cout<<std::endl;
    putlong(123);
    std::cout<<std::endl;
    revputlong(0);
    std::cout<<std::endl;
    revputlong(456);
    std::cout<<std::endl;
    //char *mycopy = copy1(str, str1);
    //std::cout<<"mycopy="<<mycopy<<std::endl;
}

