#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

    }
};
logo
学习
题库
讨论
竞赛
求职
商店
面试


单词搜索
提交记录
48 / 48 个通过测试用例
状态：通过
执行用时: 1128 ms
内存消耗: 143.6 MB
提交时间：几秒前
执行用时分布图表
执行消耗内存分布图表
邀请好友来挑战 单词搜索
提交的代码： 几秒前
语言： cpp

添加备注


class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool ans = false;
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        if(n*m<word.size())
            return false;
        bool a = true;
        for(int k = 0; k<word.length(); ++k)
        {
            bool flag = false;
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < m; ++j)
                {
                    if(word[k]==board[i][j])
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag)break;
            }
            a = a && flag;
            if(!a)
                break;
        }
        if(!a)return false;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <m; ++j)
            {
                if(word[0]==board[i][j])
                    dfs(board, word, i, j, 0);
                if(ans)
                    return ans;
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& board, string& word, int i, int j, int index)
    {
        if(ans) return ; 
        if(index==word.size()-1 && word[index]==board[i][j])
        {  
            ans=true;
            return ;
        }  
        if(word[index]!=board[i][j])
            return ;
        int n = board.size(), m = board[0].size();
        char tmp = board[i][j];
        board[i][j]='.';
        if(i-1>=0)
            dfs(board, word, i-1, j, index+1);
        if(i+1<n)
            dfs(board, word, i+1, j, index+1);
        if(j-1>=0)
            dfs(board, word, i, j-1, index+1);
        if(j+1<m)
            dfs(board, word, i, j+1, index+1);
        board[i][j]=tmp;
        return ;
    }
};