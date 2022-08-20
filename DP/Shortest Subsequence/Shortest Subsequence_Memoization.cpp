#include <bits/stdc++.h>

int solve(string s, string v, int **output)
{
    // Write your code here

    int m = s.size();
    int n = v.size();

    if (s.size() == 0 || v.size() == 0)
    {

        return max(s.size(), v.size());
    }

    if (output[m][n] == -1)
    {

        int case1 = solve(s.substr(1), v, output);

        int i;
        for (i = 0; i < v.size(); i++)
        {

            if (v[i] == s[0])
                break;
        }
        int case2;

        if (i == v.size())
        {
            case2 = 1;
        }
        else
        {
            case2 = solve(s.substr(1), v.substr(i + 1), output) + 1;
        }

        output[m][n] = min(case1, case2);
    }

    return output[m][n];
}

int solve(string s, string v)
{

    int m = s.size();
    int n = v.size();

    int **output = new int *[m + 1];

    for (int i = 0; i < m + 1; i++)
    {

        output[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            output[i][j] = -1;
        }
    }

    return solve(s, v, output);
}
