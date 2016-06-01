#!/bin/bash

    IFS=$'\n' # if file name has whitespace 
    git add .  
    git commit -am "$1"  
    git push origin master
    

    

