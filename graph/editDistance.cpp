#include <iostream>
#include <string>

using namespace std;

const int DELETE_COST = 1;
const int INSERT_COST = 1;
const int REPLACE_COST = 5;

int editDistance(const string& str1, const string& str2) {
  int eDist[2][str2.size()+1];
  int curRow = 0, previousRow = 0;
  for(int i = 0; i <= str1.size(); i++ ) {
    for(int j = 0; j <= str2.size(); j++) {
      // base case str1 & str2 are empty, nothing to be done
      // case str1 is empty, str1 can be converted to str2 by doing str2.size() inserts
      curRow = i%2;
      if(i == 0) {
        eDist[curRow][j] = j;
      }
      // case str2 is empty, str1 can be converted to str2 by doing str1.size() deletes
      else if(j == 0) {
        eDist[curRow][j] = i;
      }
    
      else {
        previousRow = (i-1)%2;

        // replace cost
        int rCost = eDist[previousRow][j-1] + ((str1[i-1] == str2[j-1]) ? 0 : REPLACE_COST);
        int dCost = eDist[curRow][j-1] + DELETE_COST;
        int iCost = eDist[previousRow][j] + INSERT_COST;
        eDist[curRow][j] = min(min(rCost, eCost), dCost);
        cout << i << " " << j << " " << curRow << " " << previousRow << " " << rCost << " " << eCost << " " << dCost << " " << eDist[curRow][j] << endl;
      }
    }
  }
  cout << eDist[curRow][str2.size()] << endl;
  return eDist[curRow][str2.size()];
}

// Driver program
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDistance(str1, str2) << endl;
    return 0;
}
