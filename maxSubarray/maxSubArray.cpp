#include<vector>
#include<iostream>
#include<ctime>
using namespace std;
class Solution
{
    public:
        int maxSubArray(vector<int>& dp)
        {
            int res = dp[0];
            for(int i = 1 ; i < dp.size() ; i ++)
            {
                if(dp[ i-1 ] >= 0) dp[i] = dp[i - 1] + dp[i];
                if(res < dp[i]) res = dp[i];
            }
            return res;
        }
};


int main()
{
    srand(time(NULL));
    vector<int> vec(10);
    cout<<"Random vector: ";
    for(int i = 0 ; i < 10 ; i ++)
    {
        vec[i] = rand() % 10;
        cout<<vec[i]<<" ";
    }
    Solution t;
    int res = t.maxSubArray(vec);
    cout<<endl<<"Result "<<res;

}