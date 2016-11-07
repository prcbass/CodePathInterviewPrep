//
//  main.cpp
//  CodePathChallenges
//
//  Created by Sebastian Hernandez on 11/6/16.
//  Copyright © 2016 Sebastian Hernandez. All rights reserved.
//

#include <iostream>
#include "Week1.hpp"
#include "Week2.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    /*
    Week1 week;
    
    vector<int> arr {2,3,3,3,5,5,7,11,11,13,14,14,14,15,16,17};
    
    int num = week.challenge1(arr);
    
    //print array at end
    for(int i: arr){
        cout << i << ", ";
    }
    cout << endl;
    
    cout << "Num valid elements: " <<  num << endl;
     */
    
    vector<int> arr {1, 4, 5, 7, 8, 2};
    LinkedListNode<int>* head;
    head = head->setValuesFromArray(arr);
    head->printList();
    
    
    return 0;
}
