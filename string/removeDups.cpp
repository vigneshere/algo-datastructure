#include <iostream>
#include <string>

using namespace std;

void removeDuplicates(string& str) {
  int numChars = 0;
  int length = str.size();
  for (int i = 0; i < length; i++) {
    bool found = false;
    for (int j = i+1; j < length; j++) {
      if(str[i] == str[j]) {
        found = true;
        break;
      }
    }
    if(!found) {
      str[numChars] = str[i];
      numChars++;
    }
  }
  str.resize(numChars);
  
}

int main(int argc, char* argv[]) {
  string s("i am too good");
  removeDuplicates(s);
  cout << s << endl;
}
