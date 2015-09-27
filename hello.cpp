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
    while ( *s++ = *t++ )
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

int main()
{
    std::cout<<"Hello World";
    
    char str[] = "123";
    char str1[] = "aaa";
    char *pt = str;
    char *pt1 = str1;
    char *mycopy = cp(str);
    printf("\n");
    printf("pt  =[%x]\n", pt);
    printf("pt1 =[%x]\n", pt1);

    char* tmp = pt;
    pt = pt1;
    pt1 = tmp; 

    printf("s pt  =[%x]\n", pt);
    printf("s pt1 =[%x]\n", pt1);

    int* npt1 = (int*)malloc(sizeof(int)*3);
    int* npt2 = (int*)malloc(sizeof(int)*3);


    std::cout<<"mycopy="<<mycopy<<std::endl;
}

