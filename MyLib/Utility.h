#include <execinfo.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Vector3.h"
#include "DDLinkedList.h"

#define PAD "--------------------------------------------------------------------------------"
using namespace std;

void fl();
string fun_parent_parent();
void cut(char* pt);
void pp(const char* format, ...);

void begin(){
    int sz = 80;
    std::string pretty_fun = fun_parent_parent();
    int len = pretty_fun.length();
    printf ("[%s%.*s]\n", pretty_fun.c_str(), sz < len ? 0 : (int)(sz - len), PAD);
}

void begin(const char* name){
    int sz = 80;
    printf ("[%s%.*s]\n", name, (sz < strlen(name)) ? 0 : (int)(sz - strlen(name)), PAD);
}

void end(){
    fl();
}

void fl(){
    printf("[%s]\n", PAD);
}


void cut(char* pt){
    int k = strlen(pt) - 1;
    while(k >= 0 && pt[k] != 'v') k--;

    k >= 0 ? pt[k] = 0 : printf("Error: invalid string format.");
}

// get the name of parent function, get the name of caller function
string fun_parent(){
    void *array[10];
    size_t size;
    char **strings;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);

    cut(strings[1]);
    string str = std::string(strings[1] + 62);
    free(strings);
    return str; 
}

// get name of caller of caller function, get the name of parent of parent function
string fun_parent_parent(){
    void *array[10];
    size_t size;
    char **strings;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);

    cut(strings[2]);
    string str = std::string(strings[2] + 62);
    free (strings);
    return str; 
}

void pp(const char* format, ...){
    printf(format);
}

void pp(int n){
    printf("[%d]", n);
}

void pp(float n){
    printf("[%f]", n);
}

void print(Vector3 v){
    v.print();
}

void print(DDLinkedList<Vector3>* ddl){
    Node<Vector3>* curr = ddl->head;
    while(curr){
        curr->data.print();
        curr = curr->next;
    }
}

void printContext(GLfloat x, GLfloat y, GLfloat fl, GLfloat f2) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    char buffer1[50];
    char buffer2[50];
    sprintf(buffer1, "%f", fl);
    for (char* p = buffer1; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);

    glTranslatef(x + 30.0, 0.0, 0);
    sprintf(buffer2, "%f", f2);
    for (char* p = buffer2; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}

void printContext(GLfloat x, GLfloat y, GLfloat fl) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    char buffer[50];
    sprintf(buffer, "%f", fl);
    for (char* p = buffer; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}


