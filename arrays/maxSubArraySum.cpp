#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> IntVector;
typedef vector<int>::const_iterator IntVectorIter;

int MaxSubArraySum(const IntVector& inputArr, int& sPos, int& ePos) {
  sPos = ePos = 0;
  IntVectorIter inputArrIter = inputArr.begin();
  int maxSum = *inputArrIter, curSum = *inputArrIter++;
  int resPos = 0;
  for(; inputArrIter != inputArr.end(); inputArrIter++) {
    curSum += *inputArrIter;
    if (curSum > maxSum) {
      maxSum = curSum;
      sPos = resPos;
      ePos = inputArrIter - inputArr.begin();
    }
    if (curSum < 0) {
      resPos = inputArrIter - inputArr.begin() + 1;
      curSum = 0;
    }
  }
  return maxSum;
}

int main(int argc, char *argv[]) {
  int inArr[] = { 2, 4, -7, 3, -4, 8, -6, 9, 5 };
  IntVector inputArr(inArr, inArr + sizeof(inArr)/sizeof(inArr[0]));
  int sPos, ePos;
  cout << MaxSubArraySum(inputArr, sPos, ePos) << endl; 
  for(int i = sPos; i <= ePos; i++) {
    cout << inputArr[i] << " ";
  }
  cout << endl;
  return -1;
}
