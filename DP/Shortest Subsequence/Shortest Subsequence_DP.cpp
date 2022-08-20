#include <bits/stdc++.h>

using namespace std;

int solve(string s, string v)
{

    int m = s.size();
    int n = v.size();

    vector<vector<int>> next(m + 1, vector<int>(n + 1));
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m; i++)
    {
        int prev = -1;
        for (int j = 0; j < n; j++)
        {
            if (s[i] == v[j])
            {
                prev = j;
            }

            next[i + 1][j + 1] = prev;
        }
    }
    

        for (int i = 0; i < n + 1; i++)
        {
            dp[0][i] = 1e9;
        }

        for (int i = 1; i < m + 1; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (next[i][j] == -1)
                    dp[i][j] = 1;
                else
                {
          dp[i][j] = min(dp[i-1][j], 1+ dp[i-1][next[i][j]]);
                }
            }
        }

        return dp[m][n];
}


                         
                         
                         
                         
                         
                         
                         
                         
                         
                         
                         
                         
                         
                         
                         
                       
