#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("/Users/cat/myfile/github/cpp/text/file1.txt");

  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}
