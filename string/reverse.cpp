#include <iostream>

using namespace std;

void swap(char& ch1, char& ch2) {
  char temp = ch1;
  ch1 = ch2;
  ch2 = temp;
}

char* reverse(char* str) {
  if (!str) {
    return NULL;
  }
  int length = strlen(str);
  for(int i = 0; i < length/2; i++) {
    swap(str[i], str[length-i-1]);
  }
  return str;
}

int main(int argc, char* argv[]) {
  char str[] = "testiing";
  cout << reverse(str) << endl;
  return 1;
}
