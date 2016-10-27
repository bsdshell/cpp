#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
void fun(){
    printf("this is fun name");
}

void cut(char* pt){
    int k = strlen(pt) - 1;
    while(k >= 0 && pt[k] != 'v') k--;

    k >= 0 ? pt[k] = 0 : printf("Error: invalid string format.");
}

// gf https://www.gnu.org/software/libc/manual/html_node/Backtraces.html
// get name of caller function name
string fun_parent(){
    void *array[10];
    size_t size;
    char **strings;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);

    cut(strings[1]);
    string str = std::string(strings[1] + 63);
    free (strings);
    return str; 
}

// get name of caller of caller function
string fun_parent_parent(){
    void *array[10];
    size_t size;
    char **strings;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);

    cut(strings[2]);
    string str = std::string(strings[2] + 63);
    free (strings);
    return str; 
}


/* Obtain a backtrace and print it to stdout. */
void print_trace (void) {
    void *array[10];
    size_t size;
    char **strings;
    size_t i;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);

    printf ("Obtained %zd stack frames.\n", size);

//0   backtrack                           0x000000010c1f0e47 _Z11print_tracev + 39
//=>1   backtrack                           0x000000010c1f0ef9 _Z14dummy_functionv + 9
//=>2   backtrack                           0x000000010c1f0f14 main + 20
//=>3   libdyld.dylib                       0x00007fff91d3d5ad start + 1
//=>4   ???                                 0x0000000000000001 0x0 + 1

    for (i = 0; i < size; i++){
        printf ("=>%zd %s\n", i, strings[i]);
        cut(strings[i]);
        printf ("=>%zd, %s\n", i, (strings[i] + 63));
    }

    free (strings);
}


void myfun(void){
    string str = fun_parent_parent();
    cout<<"parent_parent="<<str<<endl;
}

void dummy_function (void) {
    string str = fun_parent();
    cout<<"parent="<<str<<endl;
    myfun();
}

int
main (void) {
    dummy_function ();
    return 0;
}
