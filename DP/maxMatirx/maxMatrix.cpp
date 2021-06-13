#include<iostream>
#include<algorithm>
using namespace std;

struct matrix
{
    int a,b;
    matrix()
    {
        a = 0;
        b = 0;
    }
};

bool cmp(const matrix& a,const matrix& b)
{
    if(a.a!= b.a)return a.a < b.a;
    else return a.b < b.b;
}
int main()
{
    int T = 0;
    cin>>T;
    while(T--)
    {
        int x = 0 ;
        cin>>x;
        int a, b;
        //Let dp[i] represent the maximum number of rectangles 
        //that can be obtained at the end of rectangle i
        int* dp = new int[x];
        matrix* matri = new matrix[x];
        for(int i = 0 ; i < x ; i ++)
        {
            cin>>matri[i].a>>matri[i].b;
            if(matri[i].a > matri[i].b)
            {
                swap(matri[i].a,matri[i].b);
            }
        }
        int ans = 0;
        sort(matri,matri + x, cmp);
        for(int i = 0 ; i < x ; i ++)
        {
            dp[i] = 1;
            for(int j = 0 ; j < i ; j ++)
            {
                if(matri[j].b < matri[i].b && matri[i].a > matri[j].a)
                {
                    dp[i] = max(dp[i], dp[j] + 1 );
                }
            }
            ans = max(ans , dp[i]);
        }
        cout<<ans<<endl;
        

    }
}