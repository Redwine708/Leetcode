/*
 *Problem28
 */
#include<string>
#include<iostream>
using namespace std;
class Solution{
    public:
int* getNext(string x)
{
    int * next = new int[x.size()];
    next[0] = -1;
    int j = -1;
    for(int i = 1 ; i < x.size() ; i++)
    {
        while(j!= -1 &&x[i] != x[j + 1])
        {
            j = next[j];
        }
        if(x[i] == x[j+1])j++;
        next[i] = j;
    }
    return next;
}
int strStr(string A , string B)
{
    if(A == "" && B=="")return 0;
    if(A == "" && B !="")return -1;
    if(A != "" && B == "")return 0;
    int* next = getNext(B);
    int j = -1;
    for(int i = 0 ; i < A.size() ; i++)
    {
        while(j!=-1&&A[i]!=B[j+1])
        {
            j = next[j];
        }
        if(A[i] == B[j+1])j++;
        if(j == B.size()-1 ) {return i-B.size() + 1;}
    }
    delete []next;
    return -1;
}
};
int main()
{
    Solution t;
    cout<<t.strStr("","");
}