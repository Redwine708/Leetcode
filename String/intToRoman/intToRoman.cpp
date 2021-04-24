/**
 * @file intToRoman.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
 * Solution
 * 1.我们建立int 对 string 的 映射 存储 所有 数值和对应的字符串
 * 2. 用数组存储 所有的除数
 * 3. 用string 存储结构 ， 利用+=重载来得出结果
 */
#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    unordered_map< int , string>table;
    string intToRoman(int num) {
        const int divisor [] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        table[1000] = "M";table[900] = "CM";table[500] = "D";table[400] = "CD";
        table[100] = "C";table[90] = "XC";table[50] = "L";table[40] = "XL";
        table[10] = "X";table[9] = "IX";table[5] = "V";table[4] = "IV";
        table[1] = "I";
        int temp = 0;
        int i = 0;
        string result;
        while(num)
        {
            int temp = num / divisor[i];
            num =num - temp * divisor[i];
            for(int t = 0; t < temp ; t++)
            {
                result += table[ divisor[i] ];
            }
            i++;
        }
        return result;
    }
};
//秒啊
class Solution {
public:
    string intToRoman(int num) {
        string strs[]= {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        for (int i = 0; num > 0 && i < 13; i++) {
            //内层
            while (nums[i] <= num) {
                ans += strs[i];
                num -= nums[i];
            }
        }
        return ans;
    }
};
