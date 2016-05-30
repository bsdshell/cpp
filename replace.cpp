#include <iostream>
#include <string>
#include <regex>
#include <iterator>

using namespace std;
int main () {
  //[ file=cppregex.html title =""]
  std::string str("there is a subsequence in the string\n");
  std::regex pattern("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

  // using string/c-string (3) version:
  std::cout << std::regex_replace (str, pattern,"sub-$2");

  // using range/c-string (6) version:
  std::string result;
  std::regex_replace (std::back_inserter(result), str.begin(), str.end(), pattern, "$2");
  std::cout << result;

  // with flags:
  std::cout << std::regex_replace (str, pattern, "$1 and $2", std::regex_constants::format_no_copy);
  std::cout << std::endl;

  // cpp regex, cpp regular expression replace space to underscore
  std::string fileName ("screen cool dog.png\n");
  std::regex reg(" ");
  std::string resultFileName;
  std::regex_replace(std::back_inserter(resultFileName), fileName.begin(), fileName.end(), reg, "_");
  std::cout <<"fileName->"<<resultFileName<<endl;
  //]

    
  return 0;
}
