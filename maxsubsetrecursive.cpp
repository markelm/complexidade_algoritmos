//FEI - CC5661 - Trabalho - Problema 3.4 - Recusao

#include <vector>
#include <iostream>

using namespace std;


int getSum(vector<int> v, int x){

	if (x == 0)
		return 1;
	if (x < 0)
		return 0;
      	if(v.size() == 0 && x != 0){
		return 0;
	}
	int size = v.size();
	int first = v[0];
	vector<int> v2(size - 1);
	for (int i = 1; i < size; i++){
		v2[i-1] = v[i];
	} 
	return getSum(v2, x - first) + getSum(v2, x);

}

int main(){
	vector<int> v{1,2,3,3,3};
	cout << getSum(v, 6) << endl;

	return 0;

}
