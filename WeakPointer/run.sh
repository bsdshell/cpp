#!/bin/bash
echo "run"

g++ -Wno-deprecated -std=c++11 -g -v -o weak_pointer weak_pointer.cpp -I/Users/cat/myfile/github/cpp/MyLib -framework GLUT -framework OpenGL 

