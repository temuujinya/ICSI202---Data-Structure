#include "merge.h"



int main() {

	int A[] = {2,3,1,9,10,88,15,12,77,17,11};
	int i,niit=11;

	//niit = sizeof(A)/sizeof(A[0]);
	MergeSort(A,niit);

	for(i = 0;i < niit;i++) cout<<A[i]<<" ";
	return 0;
}
