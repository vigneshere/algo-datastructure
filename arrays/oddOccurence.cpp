#include <iostream>
#include <vector>

//specify the std namespace, so that stl containers can be used without std:: prefix
using namespace std;

//few typedef to hide stl template syntax
typedef vector<int> IntVector;
typedef vector<int>::const_iterator IntVectorConstIter;

// inputArr - const referece to integer vector
//    - const so guarantee that vector is not modified inside the function
//    - reference to make sure that additional copy is not created
// Return val - integer which has odd occurence
// LOGIC: 
// -  XOR of similar elements would result in 0
// -  XOR of element x with 0 would result in x
int integerWithOddOccurence(const IntVector& inputArr) {

  //intialize the iterator to begin of array
  IntVectorConstIter iter = inputArr.begin();
  
  //assign first element to num and increment iterator
  int num = *iter++;
  
  //iterate over rest of the elements in array 
  //perform XOR of current number with num integer
  for(;iter != inputArr.end(); iter++) {
    num = num ^ *iter;
  }
  return num;
}

int main(int argc, char* argv[]) {
  int inputArr[] = { 1, 1, 2, 2, 3, 4, 4, 5, 5, 3, 6, 7, 6 };
  IntVector inVector( inputArr, inputArr + (sizeof(inputArr)/sizeof(inputArr[0])));
  cout << integerWithOddOccurence(inVector) << endl;
}
