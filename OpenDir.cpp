#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<string.h>
#include<fstream>
#include<dirent.h>

using namespace std;
void listFile();

int main(){
    listFile();
    return 0;
}

void listFile(){
        DIR *pDIR;
        struct dirent *entry;
        if( pDIR=opendir("/Users/cat/myfile/screenshots") ){
                while(entry = readdir(pDIR)){
                        //if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
                        cout << entry->d_name << "\n";
                        int result = rename(entry->d_name, newName);
                        if(result){
                        }
                }
                closedir(pDIR);
        }
}


