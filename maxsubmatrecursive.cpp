//FEi - CC5661 - Trabalho -Problema 3.1 - Recursivo 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int size = 0;
int maxSqrMat(vector<vector<int>> mat, int i, int j, int& size){
	int x = 0;
	//int rows = mat.size();
	//int cols = mat[0]size();
	bool last;
	if (i == mat.size() - 1 && j == mat[0].size() - 1 && mat[i][j] == 0)
		last = true;
	else
		last = false;
	if(i == 0 || j == 0){
		if(size < mat[i][j])
			size = mat[i][j];
		return mat[i][j];
	}
	else if(mat[i][j] == 1 || last == true){
		x = maxSqrMat(mat, i - 1, j, size) < maxSqrMat(mat, i, j - 1, size)? maxSqrMat(mat, i - 1, j, size) : maxSqrMat(mat, i, j - 1, size);
		x = (maxSqrMat(mat, i - 1, j - 1, size) < x)? maxSqrMat(mat, i - 1, j - 1, size) : x;
		
		x += 1;
		if(last == true)
			x = x-1;
	}

	size = x > size? x : size;
	return x;

}
int main(){
	vector<vector<int>> v{{0, 1, 0, 1, 0}, 
				{0, 1, 1, 1, 1}, 
				{0, 1, 0, 1, 0}, 
				{1, 0, 0, 0, 1}, 
				{1, 1, 1, 0, 1}, 
				{1, 1, 1, 1, 1},
				{1, 1, 0, 1, 1},
				{0, 1, 1, 1, 1},
				{1, 1, 1, 1, 0}};
	int i = v.size() - 1;
	int j = v[0].size() - 1;
	maxSqrMat(v, i, j, size );
	cout << size << endl;

	return 0;
}
