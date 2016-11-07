//
//  Week2.hpp
//  CodePathChallenges
//
//  Created by Sebastian Hernandez on 11/6/16.
//  Copyright © 2016 Sebastian Hernandez. All rights reserved.
//

#ifndef Week2_hpp
#define Week2_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Week2{
public:
};

/*
 NOTE: This implementation of a LinkedList was specified by CodePath and does not represent
 how I would go about implementing such a data struture. For my implementation go to
 https://github.com/prcbass/Algs-Datastructs
*/

template<class T>
class LinkedListNode{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T>* setValuesFromArray(vector<T> listValues);
    
    T getValue();
    void setValue(T value);
    
    LinkedListNode<T> getNext();
    void setNext(LinkedListNode<T> nextNode);
    
    void printList();
};

template<class T>
LinkedListNode<T>* LinkedListNode<T>::setValuesFromArray(vector<T> listValues){
    LinkedListNode<T>* head = this;
    LinkedListNode<T>* currentNode = this;
    for(int i=0; i < listValues.size(); i++){
        currentNode->data = listValues[i];
        //cout << currentNode->data << ", ";
        
        LinkedListNode<T>* nextNode;
        currentNode->next = nextNode;
        currentNode = currentNode->next;
    }
    //cout << endl;
    
//    LinkedListNode<T>* firstNode;
//    while(firstNode != NULL){
//        //cout << firstNode->data << ", ";
//        firstNode = firstNode->next;
//    }
    //cout << endl;
    return head;
}

template<class T>
T LinkedListNode<T>::getValue(){
    return data;
}

template<class T>
void LinkedListNode<T>::setValue(T value){
    data = value;
}

template<class T>
LinkedListNode<T> LinkedListNode<T>::getNext(){
    return next;
}

template<class T>
void LinkedListNode<T>::setNext(LinkedListNode<T> nextNode){
    next = nextNode;
}

template<class T>
void LinkedListNode<T>::printList(){
    LinkedListNode<T> *currentNode = this;
    while(currentNode != NULL){
        cout << currentNode->data << " -> ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

#endif /* Week2_hpp */


/*
 using namespace std;
 
 class LinkedListNode{
 public:
 int val;
 LinkedListNode *next;
 
 LinkedListNode(int node_value) {
 val = node_value;
 next = NULL;
 }
 };
 
 LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val){
 if(head == NULL) {
 head = new LinkedListNode(val);
 tail = head;
 }
 else {
 LinkedListNode *node = new LinkedListNode(val);
 tail->next = node;
 tail = tail->next;
 }
 return tail;
 }
 
 
 
 */

