#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

typedef vector<int> IntVector;
typedef vector<vector<int> > Int2DVector;

int convertCharToIndex(char ch) {
  if(ch >= 'A' && ch <= 'Z')
    return ch - 'A';
  if(ch >= 'a' && ch <= 'z')
    return ch - 'a';
  throw out_of_range("non alphabet found");
}

int populateCharacterIndex(const string& pattern, IntVector& charIndex) {
  charIndex.resize(26);
  for(int iter = 0;iter < 26; iter++) {
    charIndex[iter] = -1;
  }
  int uniqCharCount = 0;
  for(int pIter = 0; pIter < pattern.size(); pIter++) {
    int charOffSet = convertCharToIndex(pattern[pIter]);
    if(charIndex[charOffSet] == -1) {
      cout << pattern[pIter] << endl;
      charIndex[charOffSet] = uniqCharCount++;
    }
  }
  cout << uniqCharCount << endl;
  return uniqCharCount;
}

int getCharIndex(char ch, const IntVector& charIndex) {
  return charIndex[convertCharToIndex(ch)];
}

int populateFiniteAutomata(const string& pattern, IntVector& charIndex, Int2DVector& finiteAuto) {
  int size = populateCharacterIndex(pattern, charIndex);
  int lps = 0;
  for(int pIter = 0; pIter < pattern.size(); pIter++) {
    IntVector* nVector = new IntVector();
    if(pIter == 0) {
      nVector->insert(nVector->end(), size, 0);
    }
    else {
      *nVector = finiteAuto[lps];
    }
    int charOffSet = getCharIndex(pattern[pIter], charIndex);
    (*nVector)[charOffSet] = pIter+1;
    finiteAuto.push_back(*nVector);
    lps = (pIter) ? finiteAuto[lps][charOffSet] : 0;
  }

  for(int sIter = 0; sIter < pattern.size(); sIter++) {
    for(int cIter = 0; cIter < size; cIter++) {
      cout << finiteAuto[sIter][cIter] << " ";
    }
    cout << endl;
  } 
  return size;
}

int FiniteAutomataSearch(const string& text, const string& pattern) {
  IntVector charIndex; 
  Int2DVector finiteAuto;
  int size = populateFiniteAutomata(pattern, charIndex, finiteAuto);
  int state = 0;
  for(int tIter = 0; tIter < text.size(); tIter++) {
    int charOffSet = getCharIndex(text[tIter], charIndex); 
    state = finiteAuto[state][charOffSet];
    if(state == pattern.size()) {
      return (tIter - pattern.size());
    }
  }
  return -1;
}

int main(int argc, char* argv[]) {
  string text("stringabcabdabctobesearched");
  string pattern("abcabdabc");
  string pattern2("abcdabc");
  cout << FiniteAutomataSearch(text, pattern) << endl;
  cout << FiniteAutomataSearch(text, pattern2) << endl;
}
