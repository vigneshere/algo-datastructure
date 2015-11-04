#include <iostream>
#include <string>

using namespace std;
typedef string::iterator StringIter;
bool isUniqueChars(string& str) {
  
  bool found[256];
  memset(found, false, sizeof found);
  for(StringIter iter = str.begin(); iter != str.end(); iter++) {
    if (found[*iter]) {
       return false;
    }
    found[*iter] = true;
  }
  return true;
}

int main(int argc, char* argv[]) {
  string s("testing");
  cout << isUniqueChars(s) << endl;
  string s2("tesing");
  cout << isUniqueChars(s2) << endl;
  return 1;
}
