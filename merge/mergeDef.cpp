#include "merge.h"
void Merge(int *A,int *L,int leftTotal,int *R,int rightTotal) {
	int i,j,k;

	i = 0; j = 0; k =0;

	while(i<leftTotal && j< rightTotal) {
		if(L[i]  < R[j])
            A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftTotal) A[k++] = L[i++];
	while(j < rightTotal) A[k++] = R[j++];
}

void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return;

	mid = n/2;

	L = new int (mid*sizeof(int));
	R = new int ((n- mid)*sizeof(int));

	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];

	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(A,L,mid,R,n-mid);
        delete [] L;
        delete [] R;
}
