#include <iostream>
#include <map>
using namespace std;

class Node {
  public:
    int data; //Data to store (could be int,string,object etc)
  Node * nextElement; //Pointer to next element

  Node() {
    //Constructor to initialize nextElement of newlyCreated Node
    nextElement = nullptr;
  }
};

class LinkedList {
  private:
    Node * head;
  public:

    LinkedList(){
    head = NULL;
    };
  Node * getHead(){
    return head;
    };
  bool isEmpty(){
    return head == nullptr;
    };
  bool printList(){
    Node *current = head;
    while(current->nextElement != nullptr){
        cout<<current->data<<"->";
        current = current->nextElement;
    }
    cout<<current->data<<"->null"<<endl;
    return true;
};
  void insertAtHead(int value){
    Node *newNode = new Node();
    newNode->data = value;
    if(isEmpty()){
    head = newNode;
    }
    else{
        newNode->nextElement = head;
        head = newNode;
    }
    };
    
  string elements(){
    Node * current = head;
    string result = "";
    while(current-> nextElement != nullptr){
        result += to_string(current->data) +"->";
        current = current->nextElement;
    }
    result += to_string(current-> data) + "->null";
    return result;
  };
  void insertAtTail(int value);
  bool search(int value){
        Node *temp = head;
    while(temp != nullptr){
        if(temp->data == value){
            return true;
    }
    temp = temp->nextElement;
    }
    return false;

  };
  bool deleteAtHead();
  bool Delete(int value);
  int length();
  string reverse();
  string removeDuplicates(){
     map<int, bool> visited;
     Node *prev = head;
     Node *curr = head -> nextElement;
     visited[prev ->data] = 1;
     while(curr != nullptr){
        if(visited[curr -> data ] == true){
            prev -> nextElement = curr -> nextElement;
            delete curr;
        }
        else{
            visited[curr -> data] = true;
            prev = prev -> nextElement;
            }
        curr = prev ->nextElement;
  }
  return elements();

  };
  
  string Union(LinkedList list1, LinkedList list2);
  string Intersection(LinkedList list1, LinkedList list2);
};


string LinkedList::Union(LinkedList list1, LinkedList list2) {
    Node * temp = list1.getHead();
    while (temp->nextElement != nullptr){
        temp = temp->nextElement;
        }
    temp->nextElement = list2.getHead();
    list1.removeDuplicates();
    return list1.elements();
}
string LinkedList::Intersection(LinkedList list1, LinkedList list2){
    LinkedList ans;
    Node *temp = list1.getHead();
    while(temp != nullptr){
        if(list2.search(temp->data)){
            ans.insertAtHead(temp->data);}
        temp = temp->nextElement;
    
        }
    return ans.elements();
}
int main(){
    LinkedList list, list1;
    list.insertAtHead(1);
    list.insertAtHead(5);
    list.insertAtHead(2);
    list1.insertAtHead(5);
    list1.insertAtHead(4);
    list1.insertAtHead(6);
    string check = list.Union(list , list1);
    cout << "Union" << endl;
    cout << check << endl;
    string result = list.Intersection(list , list1);
    cout << "Intersection" << endl;
    cout << result << endl;
    return 0;
}