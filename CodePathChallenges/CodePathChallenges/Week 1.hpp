//
//  Week 1.hpp
//  CodePathChallenges
//
//  Created by Sebastian Hernandez on 11/6/16.
//  Copyright © 2016 Sebastian Hernandez. All rights reserved.
//

#ifndef Week_1_hpp
#define Week_1_hpp

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Week1
{
public:
    int challenge1(vector<int>& arr);
    void challenge2();
    void challenge3();
    void challenge4();
    void challenge5();
    void challenge6();
    
private:
    char toLower(char c);
    bool isPalindrome(string str);
};


/*
 This problem is concerned with deleting repeated elements from a sorted array.
 
 Write a program which takes as input a sorted int[] and updates it such that:
 
 all duplicates have been removed and
 all remaining valid elements have been shifted left to fill the emptied indices
 all remaining empty indices have values set to 0
 the function returns the number of remaining valid elements (the array size minus the number of removed elements)
 For example, given an input array with the values {2,3,5,5,7,11,11,11,11,13}, after the function completes, the values in the array should be {2,3,5,7,11,13,0,0,0}, and the function should return 6.
 
 Hint: There is an O(n) time and O(1) space solution.
 */

int Week1::challenge1(vector<int>& arr){
    int countDups = 0;
    int j = 0;
    int i = 1;
    
    if(arr.size() <= 1){
        return arr.size();
    }
    
    while(i < arr.size()){
        if(arr[i] == arr[j]){
            countDups++;
            i++;
        }
        else{
            j++;
            arr[j] = arr[i]; //remove duplicate by moving non-duplicate elements to position of first instance of duplicate
            i++;
        }
    }
    
    int leftOverDupsIndex = arr.size() - countDups;
    
    for(int i=leftOverDupsIndex; i < arr.size(); i++){
        arr[i] = 0;
    }
    
    return leftOverDupsIndex;
};


/*
 A prime number (or a prime) is an integer greater than 1 that has no positive divisors other than 1 and itself.
 
 Write a program which takes as input an int value n and returns an array of int containing all unique primes <= n.
 
 Example: if the value of n is 8, the function should return: {2,3,5,7}
 
 Hint: One well-known algorithm for doing this is over 2,000 years old, but it's not the most efficient.
 
 Remember, you are not allowed to use any primality testing functions.
 */

void Week1::challenge2(){
    //implement Sieve of Erastothenes
    
    int n = 50;
    vector<int> primesToReturn;
    bool primes[n+1];
    memset(primes, true, sizeof(primes));
    
    //primes to enumerate
    for(int i = 2; i*i <= n; i++){
        if(primes[i] == true){
            
            //go through multipes of prime
            for(int j = 2*i; j <= n; j+=i){
                primes[j] = false;
            }
            
        }
    }
    
    //create array of primes
    for(int i=2; i < sizeof(primes)/sizeof(primes[0]); i++){
        if(primes[i]){
            primesToReturn.push_back(i);
        }
    }
    
    //print primes
    for(int num: primesToReturn){
        cout << num << ", ";
    }
};

/*
 A matrix is a two-dimensional array of r rows, each with c columns, such that the total number of elements in the matrix is r * c.
 
 The spiral order of such a matrix is the list of all its elements starting at index (0, 0) and proceeding in clockwise order from the outermost values to innermost values.
 
 Write a program that takes an int[][] matrix as its input and returns an int[] of all the input's values in spiral order.
 
 Example: Given the following matrix:
 
 int[][] matrix = {
 { 1, 2, 3 },
 { 4, 5, 6 },
 { 7, 8, 9 }
 };
 Your program should return {1,2,3,6,9,8,7,4,5}
 */

void Week1::challenge3(){
    vector<vector<int>> matrix = {{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}};
    
    int k = 0; //row start index
    int m = matrix.size(); //row end
    int l = 0; //column start index
    int n = matrix[0].size(); //column end
    int i; //iterator var for use in all loops
    int j = 0; //iterator var for spiral nums arr to return
    
    int spiralNums[m*n];
    
    
    while(k < m && l < n){
        for(i = l; i < n; i++){
            spiralNums[j] = matrix[k][i];
            j++;
        }
        k++;
        
        for(i=k; i < m; i++){
            spiralNums[j] = matrix[i][n-1];
            j++;
        }
        n--;
        
        if(k < m){
            for(i=n-1; i >= l; i--){
                spiralNums[j] = matrix[m-1][i];
                j++;
            }
            m--;
        }
        
        if(l < n){
            for(i=m-1; i >= k; i--){
                spiralNums[j] = matrix[i][l];
                j++;
            }
            l++;
        }
    }
    
    for(int index = 0; index < matrix.size() * matrix[0].size(); index++){
        cout << spiralNums[index] << ", ";
    }
};

/*
 A palindrome is a word, phrase, or sequence of characters that reads the same backward as forward, e.g., madam or nurses run.
 
 Write a program which takes a String as input and returns a boolean value which is true if the input is a palindrome and false if it is not, considering only alphanumeric characters and ignoring case.
 
 Example:
 
 "A man, a plan, a canal: Panama" is a palindrome and should return true
 "race a car" is not a palindrome and should return false
 */

void Week1::challenge4(){
    string input = "A man, a plan, a canal: Panama";
    //string input = "race a car";
    string str = input; //in-case we don't want to modify originala canal: Panama";
    
    //convert all upper to lower
    for(int i=0; i < input.length(); i++) {
        str.at(i) = toLower(str.at(i));
    }
        int i = 0;
        int j = str.length() - 1;
    
    while(i<j){
        if(str.at(i) < 'a' || str.at(i) > 'z'){
            i++;
            continue;
        }
        if(str.at(j) < 'a' || str.at(j) > 'z'){
            j--;
            continue;
        }
        
        if(str.at(i) != str.at(j)){
            cout << "false" << endl;
            return;
        }
        else{
            i++;
            j--;
        }
    }
        cout << "true" << endl;   
};

char Week1::toLower(char c){
    if(c >= 'A' && c <= 'Z'){
        return c - ('A' - 'a');
    }
    return c;
}

/*
 Write a program which takes a String as input and returns a String which is the longest palindromic substring in the input, given the following assumptions about the input string:
 
 its maximum length is 1000
 it contains one unique, longest palindromic substring
 Examples:
 
 "abdbabbdba" should return "abdba"
 "abdbbbbdba" should return "abdbbbbdba"
 */

void Week1::challenge5(){
    
    string str = "abdbaabdedba";
    string currLongPal = "";
    
    for(int i=0; i<str.length(); i++){
        for(int j=i+1; j < str.length()+1; j++){
            string curr = str.substr(i, j-i);
            
            if(isPalindrome(curr) && curr.length() > currLongPal.length()){
                currLongPal = curr;
            }
        }
    }
    
    
    cout << currLongPal << endl;
}

bool Week1::isPalindrome(string str){
    for(int i=0; i < str.length()/2; i++){
        if(str.at(i) != str.at(str.length() - 1 - i)){
            return false;
        }
    }
    return true;
}

/*
 Write a program which takes a String[] as input and returns a String which is the longest common prefix, or an empty string if there is none.
 
 Examples:
 
 {"bceefgh", "bcfghijk", "bcefgh"} should return "bc"
 {"abcdefgh", "aefghijk", "abcefgh"} should return "a"
 {"", "aefghijk", "abcefgh"} should return ""
 */

void Week1::challenge6(){
    vector<string> input = {"bcdeefgh", "bcdefghijk", "bcdefgh"};
    
    string longestPref = "";
    bool startSame = true;
    
    int minStringLength = 0;
    
    for(string s: input){
        if(s.length() > minStringLength){
            minStringLength = s.length();
        }
    }
    
    for(int i=1; i < minStringLength; i++){
        string subStrToCheck;
        for(int j=0; j < input.size()-1; j++){
            
            subStrToCheck = input[j].substr(0, i);
            if(subStrToCheck != input[j+1].substr(0,i)){
                startSame = false;
            }
        }
        
        if(startSame && subStrToCheck.length() > longestPref.length()){
            longestPref = subStrToCheck;
            cout << "NEW: " << longestPref << endl;
        }
        else{
            cout << "UNCHANGED: " << longestPref << endl;
        }
    }
}

#endif /* Week_1_hpp */
