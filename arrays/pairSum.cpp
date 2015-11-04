#include <iostream>
#include <vector>
#include <unordered_map>

//specify the std namespace, so that stl containers can be used without std:: prefix
using namespace std;

//few typedef to hide stl template syntax
typedef vector<int> IntVector;
typedef vector<int>::const_iterator IntVectorConstIter;

typedef unordered_map<int, bool> IntBoolHashMap;

bool pairSum(const IntVector& inputArr, int sum, int& num1, int& num2) {
   IntBoolHashMap hMap;
   int num;
   for(IntVectorConstIter iter = inputArr.begin(); iter != inputArr.end(); iter++) {
     num = sum - *iter;
     if (hMap.find(num) != hMap.end()) {
        num1 = *iter;
        num2 = num;
        return true;
     }
     hMap[*iter] = true;
   }
   return false;
}

int main(int argc, char* argv[]) {
  int inputArr[] = { 1, 1, 2, 2, 3, 4, 4, 5, 5, 3, 6, 7, 6 };
  IntVector inVector( inputArr, inputArr + (sizeof(inputArr)/sizeof(inputArr[0])));
  int num1, num2;
  cout << pairSum(inVector, 14, num1, num2) << endl;
  cout << pairSum(inVector, 13, num1, num2) << " ";
  cout << num1 << " " << num2 << endl;
}
