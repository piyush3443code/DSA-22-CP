#include <bits/stdc++.h>

using namespace std;



int knapsack(int *weight, int *values, int n, int maxWeight) {
	// Base case
	if(n == 0 || maxWeight == 0) {
		return 0;
	}

	if(weight[0] > maxWeight) {
		return knapsack(weight + 1, values + 1, n - 1, maxWeight);
	}

	// Recursive calls
	int x = knapsack(weight + 1, values + 1, n - 1, maxWeight - weight[0]) + values[0];
	int y = knapsack(weight + 1, values + 1, n - 1, maxWeight);

	return max(x, y);
}

//int knapsack(int w[], int v[], int w_count, int w_max)
//{
//
//    if (w_max <= 0)
//        return 0;
//    if (w[0] == w[w_count - 1])
//    {
//        if (w[0] <= w_max)
//            return v[0];
//        else
//            return 0;
//    }
//
//    int ans = -1;
//
//    if (w[0] <= w_max)
//    {
//
//        int val1 = knapsack(w + 1, v + 1, w_count - 1, w_max - w[0]) + v[0];
//
//        int val2 = knapsack(w + 1, v + 1, w_count - 1, w_max);
//
//        ans = max(val1, val2);
//    }
//    else
//    {
//        int val3 = knapsack(w + 1, v + 1, w_count - 1, w_max);
//        ans = val3;
//    }
//
//    return ans;
//}

int main()
{

    int w_count;
    int w_max;

    cin >> w_count;

    int weight[w_count];
    int value[w_count];

    for (int i = 0; i < w_count; i++)
    {

        cin >> weight[i];
    }

    for (int i = 0; i < w_count; i++)
    {

        cin >> value[i];
    }

    cin >> w_max;

    // vector<int> output;

    int max_val = knapsack(weight, value, w_count, w_max);

    cout << max_val;

    return 0;
}
