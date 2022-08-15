#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}

int maxMoneyLooted(int *arr, int n)
{

    
    int dp[n+1] ;           
    dp[0] = arr[0];
    
    dp[1] = max(arr[0],arr[1]);
    
    for(int i = 2;i<n;i++){
        
        dp[i] = max(arr[i]+dp[i-2],dp[i-1]);      // it's just common sense while applying Dynamic Programming.
    }
    
    return dp[n-1];
}
