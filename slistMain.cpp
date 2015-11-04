#include "slist.h"

typedef SList<int, node<int> > IntList;
int main()
{
    IntList iList; 
    for (int i=5; i>0; i--) {
        if ( i%2 ) {
          iList.push_back(i);
        }
        else {
          iList.push_front(i);
        }
        iList.printList();
    }
    iList.reverseRecurse();
    iList.printList();
    iList.reverseList();
    iList.printList();
}
