#include <iostream>
#include <vector>

//specify the std namespace, so that stl containers can be used without std:: prefix
using namespace std;

//few typedef to hide stl template syntax
typedef vector<int> IntVector;
typedef vector<int>::iterator IntVectorIter;

void printVector(IntVector& arr) {
  for(IntVectorIter iter = arr.begin(); iter != arr.end(); iter++) {
    cout << *iter << " ";
  }
}

void merge(IntVector& mnVector, IntVector& nVector) {
  int mSize = mnVector.size();
  int nSize = nVector.size();
  mnVector.resize(mSize + nSize);
  for(int i = mSize + nSize - 1; i >= 0; i--) {
    printVector(mnVector);
    cout << "---- ";
    printVector(nVector);
    cout << "---- " << mSize << " " << nSize; 
    cout << endl;
    if(nSize == 0 || (mSize != 0 && mnVector[mSize-1] >= nVector[nSize-1])) {
      mnVector[i] = mnVector[mSize-1];
      mSize--;
    }
    else {
      mnVector[i] = nVector[nSize-1];
      nSize--;
    }
  }
}

int main(int argc, char* argv[]) {
  int inputArr1[] = { 3, 5, 7, 9 };
  IntVector inVector1( inputArr1, inputArr1 + (sizeof(inputArr1)/sizeof(inputArr1[0])));
  int inputArr2[] = { 1, 2, 4, 8 };
  IntVector inVector2( inputArr2, inputArr2 + (sizeof(inputArr2)/sizeof(inputArr2[0])));
  merge(inVector1, inVector2);
  for(IntVectorIter iter = inVector1.begin(); iter != inVector1.end(); iter++) {
    cout << *iter << " ";
  }
  cout << endl;
  
}
