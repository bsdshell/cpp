#!/bin/bash
echo "g++ -Wno-deprecated -std=c++11 -v -o Hello Hello.cpp -I/Users/cat/myfile/github/cpp/MyLib"  

g++ -Wno-deprecated -std=c++11 -v -o Hello Hello.cpp -I/Users/cat/myfile/github/cpp/MyLib  -framework GLUT -framework OpenGL 


