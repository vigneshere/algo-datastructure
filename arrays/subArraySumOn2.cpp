#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> IntVector;
typedef vector<int>::iterator IntVectorIter;

// inputArray - input parameter - vector of integers
// sum - input parameter - integer
//sPos - Output parameter  with starting postion
//ePos - Output parameter with ending position
bool getSumArrayLocation(vector<int>& inputArr, double expSum, int& sPos, int& ePos) {
  // function returns starting and ending position as -1 if sum is not found
  sPos = ePos = -1;

  vector<int>::iterator inputArrIter1, inputArrIter2;

  for(inputArrIter1 = inputArr.begin(); inputArrIter1 != inputArr.end(); inputArrIter1++) {
    double curSum = 0;
    for(inputArrIter2 = inputArrIter1; inputArrIter2 != inputArr.end(); inputArrIter2++) {
      curSum += *inputArrIter2;
      cout<< "Sum " << curSum << endl;
      if (curSum == expSum) {
        sPos = inputArrIter1 - inputArr.begin();
        ePos = inputArrIter2 - inputArr.begin();
        return true;
      }
    }
  }

  return false;
}

int main(int argc, char* argv[]) {

  static const int arr[] = {6,2,7,9,2,5,3,6};
  vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
  int sPos = 0, ePos = 0;
  if(getSumArrayLocation(vec, 9, sPos, ePos)) {
    for(int i = sPos; i <= ePos; i++) {
      cout << vec[i] << " ";
    }
    cout<<endl;
    return 0;
  }
  cout<< "No match found" << endl;
  return -1;
}
