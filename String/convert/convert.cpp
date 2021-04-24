/**
 * @file convert.cpp
 * @author liuqi(you@domain.com)
 * @brief convert the string by the shape of z
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/**
 * Just by brute force
 * Do it by the meaning of question
 * And it is very slow and poor efficiency
 */ 
#include<iostream>
#include<string>
#include<vector>
#include<cmaath>
using namespace std;
class Solution {
public:
    enum status{down,oblique};
    bool isOrder(int i,int j , int _i , int _j)
    {
        return (i == _i || i == -1 );
    }
    void move(int &x,int&y,status &t,int originI,int OriginJ)
    {
        //向下移动
        if(t == down )
        {
            x++;
            if(isOrder(x,y,originI,OriginJ))
            {
                t = oblique;
                x-=2;
                y++;
            }
            return;
        }
        //Turn oblique
        if(t == oblique)
        {
            x--;y++;
            if(isOrder(x,y,originI,OriginJ))
            {
                x+=2;
                y--;
                t = down;
            }
            return;
        }
    }
    
    string convert(string s, int numRows) {
        if(numRows == 1){return s;}
        string result = s;
        int i = numRows;
        int j = s.size();
        char** matrix = new char* [i];
        for(int m = 0 ; m < i ; m++)
        {
            matrix[m] = new char [j];
        }
        for(int m = 0; m < i ;m++)
        for(int n = 0 ;n < j ;n++ )
        {
            matrix[m][n] = '0';
        }
        int x = 0, y = 0;
        int count = 0;
        status t = down;
        while(count < s.size())
        {
            matrix[x][y] = s[count++];
            move(x,y,t,i,j);
        }
        int tt = 0;
        for(int m = 0; m < i ;m++)
        for(int n = 0 ;n < j ;n++ )
        {
            if(matrix[m][n] != '0')
            {
                result[tt++] = matrix[m][n];
            }
        }
        return result;
    }
};

/*
 *Second solution
 *Cause the char in any line is still read by row
 *So we do not need to store it by subscript.
 *When I see the solution by leetcode,I consider I am a foolish
 */
class Solution
{
    public:
        string convert(string s,int numRows)
        {

            if(numRows == 1)return s;
            
            vector<string>rows(min(numRows,int(s.size()));
            int currRow = 0;
            bool goingDown = false;
            for(char c : s)
            {
                rows[currRow] += c;
                if(currRow == 0 || currRow == numRows - 1) goingDown = !goingDown;
                currRow += goingDown ? 1 : -1;
            }
            string result;
            for(string row : rows)
            {
                result += row;
            }
            return result;
        }
};
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};

int main()
{
    string a = "AB";
    int n = 1;
    Solution s;
    string t = s.convert(a,n);
    cout<<t;

}
