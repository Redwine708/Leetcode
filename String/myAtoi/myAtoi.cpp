/**
 * @file myAtoi.cpp
 * @author your name (you@domain.com)
 * @brief  use automation way to solve the string problem,
 *         When there is many cases,we use automation
 * @version 0.1
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
 *deterministic finite automaton, DFA
 */
#include<unordered_map>
#include<string>
using namespace std;
class Automation
{
    string state = "start";
    unordered_map< string, vector<string> >table = {
        {"start", {"start","signed","in_number","end"} },
        {"signed",{"end","end","in_number","end"} },
        {"in_number",{"end","end","in_number","end"} },
        {"end",{"end","end","end","end"} }
    };

    int get_col(char c)
    {
        if(isspace(c))return 0;
        if(c == '+' || c == '-')return 1;
        if(isdigit(c))return 2;
        return 3;
    }

    public:
        int sign = 1;
        long long ans = 0;
        void get (char c)
        {
            state = table[state][get_col(c)];
            if(state=="in_number")
            {
                ans = ans*10 + c - '0';
                ans = sign == 1 ? min(ans,(long long)INT_MAX) : min(ans , -(long long) INT_MIN);

            }
            else if( state == "signed")
            {
                sign = c == '+' ? 1 : -1;    
            }
        }
};

class Solution
{
    public:
        int myAtoi(string str)
        {
            Automation automation;
            for(char c : str)
            {
                automation.get(c);
            }
            return automation.ans * automation.sign;
        }
};