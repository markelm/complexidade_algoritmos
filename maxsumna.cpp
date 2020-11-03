//FEI - CC5661 - Trabalho - Problema 3.3

#include <iostream>
#include <stdio.h>
using namespace std;

int getMax(int v[], int n){
	int include_prev = v[0] ;
	int exclude_prev= 0;
	int max_so_far;

	for(int i = 1; i < n; i++){
		max_so_far = (include_prev > exclude_prev)? include_prev : exclude_prev;

		include_prev = exclude_prev + v[i];
		exclude_prev = max_so_far; 
	}

	if(include_prev > exclude_prev)
		return include_prev;
	else
		return exclude_prev;

}

int main(){
	int  v[] = {1,2,9,4,5,0,4,11,6};

	int n = sizeof(v)/sizeof(v[0]);
	cout << getMax(v, n) << endl;

	return 0;

}
