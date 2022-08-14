#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2)
{
    // Write your code here

    // Base Case... 

    if (s1.size() == 0)
    {
        return s2.size(); // No of operations needed in this case will be equal to length of the s2 string.
    }
    if (s2.size() == 0)
    {
        return s1.size(); // No of operations needed in this case will be equal to length of the s1 string.
    }

    //

    if (s1[0] == s2[0]) // If in the given strings the first character matches then simply do a recursive call for the
                        // remaining portion of two strings...
    {
        int c1 = editDistance(s1.substr(1), s2.substr(1));

        return c1;
    }
    else
    {
        // Insert s1[0] in starting of s2, and then do a recursive call for lenght(s1)- 1 and length(s2).

        int c2 = editDistance(s1.substr(1), s2);

        // Delete the char s2[0] and do a recursive call for length(s1),  and  length(s2)-1;

        int c3 = editDistance(s1, s2.substr(1));

        // Repalce the s2[0] character with s1[0] and do a recursive call for length(s1)-1 and length(s2)-1;

        int c4 = editDistance(s1.substr(1), s2.substr(1));

        return min(min(c2, c3), c4) + 1; // return the minimum of all possible recursive calls and add +1 because we
                                         // performed a operation already before making the recursive calls.
    }
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);

    return 0;
}
