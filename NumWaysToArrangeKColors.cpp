// C++ program to find number of ways to arrange 
// items under given constraint 
#include <bits/stdc++.h> 
using namespace std; 

// method returns number of ways with which items 
// can be arranged 
int waysToArrange(int N, int K, int k[]) 
{ 
	int C[N + 1][N + 1]; 
	int i, j; 

	// Calculate value of Binomial Coefficient in 
	// bottom up manner 
	for (i = 0; i <= N; i++) { 
		for (j = 0; j <= i; j++) { 

			// Base Cases 
			if (j == 0 || j == i) 
				C[i][j] = 1; 

			// Calculate value using previously 
			// stored values 
			else
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]); 
		} 
	} 

	// declare dp array to store result up to ith 
	// colored item 
	int dp[K]; 

	// variable to keep track of count of items 
	// considered till now 
	int count = 0; 

	dp[0] = 1; 

	// loop over all different colors 
	for (int i = 0; i < K; i++) { 

		// populate next value using current value 
		// and stated relation 
		dp[i + 1] = (dp[i] * C[count + k[i] - 1][k[i] - 1]); 
		count += k[i]; 
	} 

	// return value stored at last index 
	return dp[K]; 
} 

// Driver code to test above methods 
int main() 
{ 
	int N = 4; 
	int k[] = { 2, 2 }; 

	int K = sizeof(k) / sizeof(int); 
	cout << waysToArrange(N, K, k) << endl; 
	return 0; 
} 
