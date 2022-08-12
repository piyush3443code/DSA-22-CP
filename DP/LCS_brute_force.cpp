#include <bits/stdc++.h>

using namespace std;

int longestLengthLCS(string s, string t)
{

    if (s.size() == 0 || t.size() == 0)
        return 0;

    if (s[0] == t[0])
        return longestLengthLCS(s.substr(1), t.substr(1)) + 1;
    else
    {

        int c1 = longestLengthLCS(s, t.substr(1));
        int c2 = longestLengthLCS(s.substr(1), t);
        return max(c1, c2);
    }
}

int main()
{

    string s, t;

    cin >> s >> t;

    int lcs = longestLengthLCS(s, t);

    cout << lcs;

    return 0;
}