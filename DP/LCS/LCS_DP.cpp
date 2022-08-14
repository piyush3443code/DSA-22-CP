#include <iostream>

using namespace std;

int lcs_dp(string s, string t)
{

    int m = s.size();
    int n = t.size();

    int **output = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        output[i] = new int[n + 1];
    }
     

    // Fill the 1st row which has no dependency.
    for (int i = 0; i < n + 1; i++)
    {
        output[0][i] = 0;
    }

    // Fill the 2nd column which has no dependency
    for (int i = 0; i < m + 1; i++)
    {
        output[i][0] = 0;
    }


    // Now we can start filling the rest cells because now their dependencies have been filled with values.
    for (int i = 1; i < m + 1; i++)    // Note  here i and j signifies the respective lengths of string s and t... 
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[m - i] == t[n - j])        // if 1st character  matches.
            {
                output[i][j] = output[i - 1][j - 1] + 1;
            }
            else
            {

                output[i][j] = max(max(output[i - 1][j - 1], output[i - 1][j]), output[i][j - 1]);
            }
        }
    }

    // Finally answer gets filled in the last cell of the output array.
    return output[m][n];
}

int main()
{

    string s, t;
    cin >> s >> t;

    cout << lcs_dp(s, t);

    return 0;
}