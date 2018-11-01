#include "completeTree.h"

int main(){
    int a[] = {1,23,43,5,6,34,3,65,7,8,54,75};
    int n=12;
    cout<<findRoot(a)<<endl;
    findLeafs(a,0,n);
    cout<<findLevel(a,2)<<endl;
    cout<<findHeight(a,2)<<endl;
    cout<<"Ancestors: ";
    findAncestors(a,5,n);
    cout<<"descedant: ";
    findDescendant(a,5,n);
    cout<<"siblings: ";
    findSiblings(a,5,n);
    cout<<"parent: ";
    findParent(a,5,n);
    cout<<"children: ";
    findChildren(a,5,n);
}