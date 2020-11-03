//FEI - CC5661 - Trabalho - Problema 3.4 - Programacao Dinamica

#include <vector>
#include <iostream>
using namespace std;

int subsets(vector<int> v, int x){
	int rows = v.size();
	vector<vector<int>> dp(rows, vector<int>(x+1));

	for (int i = 0 ; i < rows; i++)
		dp[i][0] = 1;

	for (int j = 0; j < (x + 1); j++){
		if(v[0] == j)
			dp[0][j] = 1;
		else
			dp[0][j] = 0;
	}

	
	for (int i = 1; i < rows; i++){
		for(int j = 1; j < (x + 1); j++){
			
			int include = (v[i] > j)? 0 : dp[i-1][j - v[i]];
			int exclude = dp[i-1][j];

			dp[i][j] = include + exclude;
			
		} 
	}
	return dp[rows-1][x];


}
int main(){
	vector<int> v{1, 2, 3, 3, 3};
	cout << subsets(v, 6) << endl;
	return 0;
}
