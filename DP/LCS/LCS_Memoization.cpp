#include <iostream>

using namespace std;

int lcs_mem(string s, string t, int **output)
{

    int m = s.size();
    int n = t.size();

    int ans;

    // Base Case
    if (s.size() == 0 || t.size() == 0)
        return 0;

    // Check if ans already exists
    if (output[m][n] != -1)
        ans = output[m][n];

    // else calculate and store it into output 2-D array for future use.

    if (s[0] == t[0])
        ans = lcs_mem(s.substr(1), t.substr(1), output) + 1;
    else
    {

        int c1 = lcs_mem(s.substr(1), t, output);
        int c2 = lcs_mem(s, t.substr(1), output);

        ans = max(c1, c2);
    }

    // Save the calculation.
    output[m][n] = ans;

    return ans;
}

int lcs_mem(string s, string t)
{

    int m = s.size();
    int n = t.size();
    
    // We create an output array of size m+1, n+1 because the recursive calls go from m,n to either of the length becoming 
    // zero, and the length may be same or differnet so  m-0+1 = m+1 and n-0+1 = n+1;

    // Each field output[i][j] = lenght of the LCS of (string s of length i and t of length of j).. 
    int **output = new int *[m + 1];

   for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			output[i][j] = -1;
		}
	}
    int length = lcs_mem(s, t, output);

    return length;
}


int main(){



    string s,t;
    cin>>s>>t;

    cout<<lcs_mem(s,t);

    return 0;
}
