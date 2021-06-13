#include<iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int preNum = getValue(s[0]);
        int num = 0;
        int sum = preNum;
        for(int i = 1;i<s.size();i++){
           num =getValue(s[i]); 
           //if the next one is bigger than the former
            if(num>preNum){
                //notice: should decline twice cause we have add preNum once before
                sum +=  num - preNum -preNum; 
            }else{
                sum += num;
            }

            preNum = num;
        }
        return sum;

    }
public:
    int getValue(char c){
        
        switch (c){
        case 'I':   return 1;
        case 'V':   return 5;
        case 'X':   return 10;
        case 'L':   return 50;
        case 'C':   return 100;
        case 'D':   return 500;
        case 'M':   return 1000;
        default:    return 0;
        }
    }
};