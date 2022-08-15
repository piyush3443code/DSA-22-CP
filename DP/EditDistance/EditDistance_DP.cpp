#include <iostream>
using namespace std;

int editDistance_DP(string s1,string s2){

    int m = s1.size();
    int n = s2.size();

            
    int output[m+1][n+1] = {-1};

  // filling the first row
   for(int i = 0;i<n+1;i++){
     output[0][i] = i;
     
   }

 //filling the second row
 for(int i = 0;i<m+1;i++){
       output[i][0] = i;
 }

 for(int i = 1;i<m+1;i++){
    for(int j = 1;j<n+1;j++){

        if(s1[m-i] == s2[n-j])
        output[i][j] = output[i-1][j-1];
        else
        {
              int c1 = output[i-1][j];
              int c2 = output[i][j-1];
              int c3 = output[i-1][j-1];

              output[i][j] = min(min(c1,c2),c3)+1;

        }
    }
 }

 return output[m][n];



}








int main() {
	string s = "abcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdf";
	string t = "afdiafdafdafdafddjhdfhfbwfbwhfbwdfvhfewvbwjebjwbdbcdvjdbvhewyfewhbcjkdbnvjbdhbqkbekwndvqkvq";

	cout << editDistance_DP(s, t) << endl;
	
    return 0;

}