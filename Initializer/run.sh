#!/bin/bash
echo "run initializer"

g++ -Wno-deprecated -std=c++11 -g -v -o initializer initializer.cpp -I/Users/cat/myfile/github/cpp/MyLib -framework GLUT -framework OpenGL 

