#include <iostream>
using namespace std;

//root олох функц
int findRoot(int *tree);
// leaf олох функц
// цааш задрахгүй шинжтэй
void findLeafs(int *tree,int beginIndex,int n);

// level(түвшин) - рүүтээс тухайн ноде хүртлэх зай
int findLevel(int *tree, int n);

// height - өндөр (level+1)
int findHeight(int *tree, int n);
//Ancestor(өвөг) - өөрөөс нь нөөд хүртэлх бүх нөөд
void findAncestors(int *tree,int pos,int n);
//Descenden -үр удам - өөрөөс нь гарсан бүх навч
void findDescendant(int *tree, int pos, int n);
//sibling (ах дүү) - эцгин олооп зэргэлдээ байгаа нөөд
void findSiblings(int *tree, int pos, int n);
//subtree /тухайн модны нөөдүүдээр үүсгэж болох/
void findParent(int *tree, int pos, int n);
void findChildren(int *tree, int pos, int n);

//