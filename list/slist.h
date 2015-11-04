#include <iostream>

using namespace std;

// Structure for linked list node
template <class T>
struct node {
  T data;
  node<T>* next;

  node() {
   next = NULL;
  }
  node(T t) {
    data = t;
    next = NULL;
  }
};

template <class T, class Node>
class SList {

 Node* head;
 int length;

 public:

  SList() {
    head = NULL;
    length = 0;
  }

  void push_front(T data) {
    Node* nNode = new Node(data);
    nNode->next = head;
    head = nNode;
    length++;
  }

  void push_back(T data) {
    Node* nNode = new Node(data);
    if( head == NULL) {
      head = nNode;
      length++;
      return;
    } 
    Node *cNode = head;
    while(cNode->next != NULL) {
      cNode = cNode->next;
    }
    cNode->next = nNode;
    length++;
  }

  void insert(T data) {
    push_back(data);
  }

  void deleteNode(Node* dNode) {
    Node* nextNode = dNode->next;
    dNode->data = nextNode->data;
    dNode->next = nextNode->next;
    delete nextNode;
    length--;
  }

  int size() {
    return length;
  }

  void deleteList() {
   Node* cNode = head;
   Node* nNode;
    while(cNode) {
      nNode = cNode->next;
      delete cNode;
      cNode = nNode;
    }
    head = NULL;
    length = 0;
  }

  void reverseList() {
    if(head == NULL || head->next == NULL) {
      return;
    }
    Node* curNode = head;
    Node* nextNode = NULL;
    Node* prevNode = NULL;
    while(curNode) {
      nextNode = curNode->next;
      curNode->next = prevNode;
      prevNode = curNode;
      curNode = nextNode;
    }
    head = prevNode;
  }

  void reverseRecurse() {
    if(!head || !head->next) {
      return;
    }
    Node* tmpNode = head;
    reverseRecurseUtil(head);
    tmpNode->next = NULL;
  }

  void reverseRecurseUtil(Node* node) {
    if(!node->next) {
      head = node;
      return;
    }
    reverseRecurseUtil(node->next);
    node->next->next = node;
  }
    
  //void removeDuplicates();
  //void pairWiseSwap();
  //void makeLastFirst();
  //void makeLoop();
  //bool detectLoop();
  //bool palidrome();

  void printList() {
   Node* cNode = head;
    while(cNode) {
      cout<<cNode->data<< "--> ";
      cNode = cNode->next;
    }
    cout<< "NULL" << endl;
  }
  
  ~SList() {
    deleteList();
  }
};
