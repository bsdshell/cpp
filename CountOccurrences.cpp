#include<iostream>
#include<vector>
#include "Aron.h"
#include<array>
#include<string>

using namespace std;

//[ file=countoccurrence.html title=""
// str: aaa
// pat: aa
int count_occurrences(string str, string pat) {
    int len = pat.length();
    int k = 0;
    int start = 0;
    int s = 0;
    int i = 0;
    int count = 0;

    while(i < str.length()) {
        if(str[i] == pat[k]) {
            if(k == 0)
                start = i;
            k++;
            if(k == len) {
                count++;
                k = 0;

                start = start + 1;
                i = start;
            } else {
                i++;
            }
        } else {
            // reset start
            start = start + 1;
            i = start;
        }

    }
    return count;
}
//]

// abcabd
// abd

int KMP(string str, string pat) {
    int len = pat.length();
    int* arr = new int[str.length()];
    for(int i=0; i<str.length(); i++)
        arr[i] = 0;

    int k = 0;
    int start = 0;
    int s = -1;
    int i = 0;
    int count = 0;
    while(i < str.length()) {

        if(str[i] == pat[0]) {
            arr[i] = 0;
            s = i;
        } else {
            if(i - 1 >= 0)
                arr[i] = arr[i] + 1;
                
        }

        if(str[i] == pat[k]) {
            k++;

            if(k == len) {
                return i;
            } else {
                i++;
            }
        } else {
            // reset start
            if(s >= 0) {
                i = s;
                k = i - s;
            } else {
                i = start + arr[i];
                k = 0;
            }
        }
    }

    //printArray(arr, str.length());
    delete[] arr;

    return count;
}


void test0() {
    begin(__PRETTY_FUNCTION__);
    int num = KMP("a", "a");
    printf("[%d]\n", num);
    end();
}
void test1() {
    begin(__PRETTY_FUNCTION__);
    int num = KMP("ba", "a");
    printf("[%d]\n", num);
    end();
}

void test2() {
    begin(__PRETTY_FUNCTION__);
    int num = KMP("ba", "ba");
    printf("[%d]\n", num);
    end();
}
void test3() {
    begin(__PRETTY_FUNCTION__);
    int num = KMP("abcabe", "abe");
    printf("[%d]\n", num);
    end();
}
void test4() {
    begin(__PRETTY_FUNCTION__);
    end();
}

void test10() {
    begin(__PRETTY_FUNCTION__);
    int num = count_occurrences("aaa", "aa");
    printf("[%d]\n", num);
    end();
}
int main() {
    test0();
    test1();
    test2();
    test3();
}

