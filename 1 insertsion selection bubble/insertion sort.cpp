#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
		cout<<endl;
	
	for(int i=1;i<n;i++){
		
		int temp = a[i];
		int pos= i;
		while(pos>0 && a[pos-1]>temp){
			a[pos]= a[pos-1];
			pos -= 1;
		}
		
		a[pos]=temp;	
		
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}	
		cout<<endl;
	}
	
}







//#include <iostream>
//
//using namespace std;
//
//int main(){
//	int n;
//	cin>>n;
//	int a[n];
//	
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
//	
//	for(int i=0;i<n;i++){
//		int temp = a[i];
//		int j = i;
//		
//		for(;j>0 && temp <a[j-1];j--){
//			
//				a[j] = a[i-1];
//			
//		}
//		a[j]=temp;
//		
//	}
//	
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}	
//}
