#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> IntVector;

// function to populate long prefix suffix vector
void PopulateLPS(const string& pattern, IntVector& lps) {

  // lps vector should hold values for each character in pattern
  lps.resize(pattern.size() + 1);

  // first character don't have any lps
  lps[0] = 0;

  // iterator for going over pattern
  int pIter = 1;

  // len of the lps
  int pLen = 0;

  while(pIter < pattern.size()) {

    // got a match, update lps
    if( pattern[pIter] == pattern[pLen] ) {
      lps[pIter] = pLen + 1;
      pIter++;
      pLen++;
    }
    else {
      if(pLen == 0) {
        // no match, move to the next character
        lps[pIter ] = 0;
        pIter++;
      }
      else {
        // tricky, lps is used inside lps :)
        // no match, go back to previous lps and check from there
        // pIter is not incremented, since we need to check for same character again 
        pLen = lps[pLen-1];
      }
    }
  }
}

int KMPSearch(const string& text, const string& pattern) {
 IntVector lps;
 PopulateLPS(pattern, lps);
 int tIter = 0, pIter = 0;
 while(tIter < text.size()) {
   // character matched
   if(text[tIter] == pattern[pIter]) {
     // patern matched
     if(pIter == pattern.size() - 1) {
       return (tIter - pIter);
     }
     tIter++; pIter++;
   }
   else {
     // No match
     if(pIter != 0) {
       // go back to previous lps and check from there
       pIter = lps[pIter-1];
     }
     else {
       // move to the next characer in the text
       tIter++;
     }
   }
 }
 return -1;
}

int main(int argc, char* argv[]) {
  string text("I am the string to be searched");
  string pattern("search");
  cout << KMPSearch(text, pattern) << endl;  
  string pattern2("no match");
  cout << KMPSearch(text, pattern2) << endl;  
}
