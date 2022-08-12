#include <bits/stdc++.h>

using namespace std;

int longestLengthLCS(string s, string t)
{
   // Base Case
    if (s.size() == 0 || t.size() == 0)
        return 0;
  
    
    // If the first characters are same then simply call recursion on remaining length of strings and return answer + 1 .
    if (s[0] == t[0])
        return longestLengthLCS(s.substr(1), t.substr(1)) + 1;
    else         
    {

        int c1 = longestLengthLCS(s, t.substr(1));        // Case 1: When we do not include the first character of string s. 
        int c2 = longestLengthLCS(s.substr(1), t);        // Case 2: When we do not include the first character of string t.
        // int c3 = longestLengthLCS(s.substr(1), t.substr(1));  // Case 3: When we do not include the first character of both string s as well as .
                                                                  // But this case is handled already in recursicve call when s[0]== t[0].
        return max(max(c1, c2),c3);
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
 
