#include<iostream>
#include<stdio.h>
#include<sstream>

using namespace std;

bool checkRowCol(vector<vector<char>> array2d)
{
    char prev = '#';
    for(int r=0; r<array2d.size(); r++)
    {
        vector<char> row = array2d.at(r);
        for(int c=0; c<row.size-1; c++)
        {
            if(prev != '#' && prev != row[c] && row[c] != row[c+1])    
                return false;
            prev = row[c];
        }

    }
        if(str[i] != str[i+1])
}
int main()
{
    string input_line;
    getline(cin, input_line);
    int numtest = atoi(input_line.to_str());
    while(cin)
    {
        getline(cin, input_line);
        vector<string> tokens;
        string buf;
        while(input_line>>buf)
            tokens.push_back(buf);
        int nRow = tokens.at(0);   
        int nCol = tokens.at(1);   
        int count = 0;
        vector<vector<char>> array2d;
        while(count < nRow)
        {
            getline(cin, input_line);
            vector<char> row;
            for(int i=0; i<input_line.length(); i++)
                row.push(input_line[i]);
            array2d.push(row);
            count++;
        }
        if(!checkRowCol(array2d))
            cout<<"NO";
    }
    cout<<"YES";
}

