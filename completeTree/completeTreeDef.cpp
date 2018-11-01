#include "completeTree.h"
int findRoot(int *tree){
    return tree[0]; 
}


void findLeafs(int *tree,int beginIndex,int n){
    if(2*beginIndex<n){
        findLeafs(tree,2*beginIndex+1,n);
        findLeafs(tree,2*beginIndex+2,n);
    }else{
        if(beginIndex<n){
            cout<<tree[beginIndex]<<",";
        }
    }
    
    // if(2*beginIndex>n){
    //     cout<<tree[(beginIndex-1)/2]<<",";
    //     return;
    // }

        
    // findLeafs(tree,2*beginIndex+1,n);
    // findLeafs(tree,2*beginIndex+2,n);


}

int findLevel(int *tree, int n){
    int totaln = 0;
    while(n>1){
        n/=2;
        totaln++;
    }
    return totaln;
}

int findHeight(int *tree, int n){
    return findLevel(tree,n)+1;
}

void findAncestors(int *tree,int pos,int n){
    if(pos/2-1<=0){
        if(pos==0)
            return;
        cout<<tree[0];
        return;
    }
    cout<<tree[(pos-1)/2]<<": ";
    findAncestors(tree,(pos-1)/2,n);
}
0
void findDescendant(int *tree, int pos, int n)
{
	if (pos*2<=n)
	{
		if (pos*2+1<= n)
			cout<<tree[pos*2+1]<< ", ";
		if (pos * 2 + 2 <= n)
			cout<<tree[pos*2+2]<<", ";

		findDescendant(tree, pos * 2 + 1, n);
		findDescendant(tree, pos * 2 + 2, n);
	}
}

void findSiblings(int *tree, int pos, int n)
{
	if (pos == 0)
		return;

	int parent_pos = (pos - 1) / 2;

	if (parent_pos * 2 + 1 <= n)
		cout << tree[parent_pos * 2 + 1] << ", ";
	if (parent_pos * 2 + 2 <= n)
		cout << tree[parent_pos * 2 + 2] << ", ";
}

void findParent(int *tree, int pos, int n)
{
	if (pos == 0)
		return;

	cout << tree[(pos - 1) / 2] << ", ";
}

void findChildren(int *tree, int pos, int n)
{
	if (pos * 2 + 1 <= n)
		cout << tree[pos * 2 + 1] << ", ";
	if (pos * 2 + 2 <= n)
		cout << tree[pos * 2 + 2] << ", ";
}


void postorder(int tree*,int pos,int n) 
{ 
    if (pos <n) {
    postorder(tree, pos * 2 + 1,n); 
    postorder(tree, pos * 2 + 2,n); 
    cout << tree[pos]; }
} 
  
void Inorder(int tree*,int pos,int n) 
{ 
    if (pos <n) {
    Inorder(tree, pos * 2 + 1,n);     
    cout << tree[pos]; 
    Inorder(tree, pos * 2 + 2,n); }
} 
  
void Preorder(int tree*,int pos,int n) 
{ 
    if (pos<n)   
{
    cout << tree[pos]; 
    Preorder(tree, pos * 2 + 1,n);  
    Preorder(tree, pos * 2 + 2,n); }
}  