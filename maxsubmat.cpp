//FEI - CC5661 - Trabalho - Problema 3.1

#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#define row 5
#define col 5
using namespace std;
int maxsqr(vector<vector<int>>& mat){
	int rows = mat.size();
	int cols = mat[0].size();
	if (rows == 0 || cols == 0)
		return 0;
	vector<vector<int>> dp(rows, vector<int>(cols) );
	int dp_max = 0;
	for (int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if (i == 0 || j == 0)
				dp[i][j] = mat[i][j];
			else{
				if(mat[i][j] == 1){
					dp[i][j] = (dp[i-1][j] < dp[i][j-1])? dp[i-1][j] : dp[i][j-1];
					dp[i][j] = (dp[i-1][j-1] < dp[i][j])? dp[i-1][j-1] : dp[i][j];
					dp[i][j] += 1;
				}
				else
					dp[i][j] == 0;
				
				dp_max = (dp[i][j] > dp_max)? dp[i][j] : dp_max;
				
			}
		}
	
	}
	return dp_max;
}

int main(){
	vector<vector<int>> v{{0, 1, 1, 1, 0}, 
				{0, 0, 0, 1, 1}, 
				{0, 1, 0, 1, 1}, 
				{1, 0, 0, 0, 1}, 
				{1, 1, 1, 1, 0}, 
				{1, 1, 1, 1, 1},
				{1, 1, 1, 1, 1},
				{1, 1, 0, 1, 1},
				{1, 1, 0, 0, 1}};
	cout << maxsqr(v) << endl;

	return 0;
}
