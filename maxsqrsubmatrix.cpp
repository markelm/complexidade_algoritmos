// C++ program to find maximum K such that K x K 
// is a submatrix with equal elements. 
#include<bits/stdc++.h> 
#define Row 6 
#define Col 6 
using namespace std; 
  
// Returns size of the largest square sub-matrix 
// with all same elements. 
int largestKSubmatrix(int a[][Col]) 
{ 
    int dp[Row][Col]; 
    memset(dp, sizeof(dp), 0); 
  
    int result = 0; 
    for (int i = 0 ; i < Row ; i++) 
    { 
        for (int j = 0 ; j < Col ; j++) 
        { 
            // If elements is at top row or first 
            // column, it wont form a  square 
            // matrix's bottom-right 
            if (i == 0 || j == 0) 
                dp[i][j] = 1; 
  
            else
            { 
                // Check if adjacent elements are equal 
                if (a[i][j] == a[i-1][j] && 
                    a[i][j] == a[i][j-1] && 
                    a[i][j] == a[i-1][j-1] ) 
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), 
                                      dp[i-1][j-1] ) + 1; 
  
                // If not equal, then it will form a 1x1 
                // submatrix 
                else dp[i][j] = 1; 
            } 
  
            // Update result at each (i,j) 
            result = max(result, dp[i][j]); 
        } 
    } 
  
    return result; 
} 
  
// Driven Program 
int main() 
{ 
    int a[Row][Col] = { 2, 2, 3, 3, 4, 4, 
                        5, 5, 7, 7, 7, 4, 
                        1, 2, 7, 7, 7, 4, 
                        4, 4, 7, 7, 7, 4, 
                        5, 5, 5, 1, 2, 7, 
                        8, 7, 9, 4, 4, 4 
                      }; 
  
    cout << largestKSubmatrix(a) << endl; 
  
    return 0; 
} 
