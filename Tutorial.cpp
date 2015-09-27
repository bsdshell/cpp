#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //C/C++ initialize array
    int array[] = {1, 2, 3};

    // now pointer pt points to array
    int* pt = array; 

    // print out the array
    for(int i=0; i<3; i++)
    {
        cout<<"["<<i<<"]="<<pt[i]<<endl;
    }

    // print out using the pointer
    for(int i=0; i<3; i++)
    {
        cout<<"["<<i<<"]="<<*(pt+i)<<endl;
    }

    // dynamically allocate memory in C
    int size = 3;
    int* pt1 = (int*)malloc(sizeof(int)*size);

    // dellocate memory in C
    free(pt1);

    // dynamically allocate memory in C++
    int *pt2 = new int[3];

    // dellocate memory in C++
    delete pt2;

    // allocate two dimension array in C
    int col = 5;
    int row = 3;
    int** ppt;
    
    // this is trick part
    ppt = (int**)malloc(sizeof(int*)*col);
    for(int j=0; j<col; j++)
    {
        ppt[j] = (int*)malloc(sizeof(int)*row);
    }

    int c = 0;
    for(int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            ppt[i][j] = c++;
        }
    }

    for(int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            cout<<"["<<i<<"]["<<j<<"]="<<ppt[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int j=0; j<col; j++)
    {
        free(ppt[j]);
    }
}
