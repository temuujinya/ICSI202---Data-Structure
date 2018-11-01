
#include "functions.h"
#include <iostream>
using namespace std;

int main(){
	int max=50;
	int stack[max],top=-1;
	
	//push(stack,max,top,a);

	// cout<<pop(stack,top)<<endl;
	

	unsigned int choice=0;
	do{
		cout<<"------------------"<<endl
			<<"Select your choice"<<endl
			<<"1. Push stack"<<endl
			<<"2. Pop stack"<<endl
			<<"3. TOP stack"<<endl
			<<"4. Display all stack elements"<<endl
           		<<"0. Exit"<<endl
			<<"-------------------"<<endl;
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Oruulah utga=>";
				int val;
				cin>>val;
				push(stack,max,top,val);
				cout<<"stack->";
				displayStack(stack,top);
				break;
			case 2:
				//pop(stack,top);
				if(!isEmpty(top)){
					cout<<"POP->"<<pop(stack,top)<<endl;
					displayStack(stack, top);
				}else
					cout<<"stack hooson bna"<<endl;
				break;
			case 3:
			    //!ASK
				//hooson ued sanah oin hog hewleed bna
				//cout<<TOP(stack,top)<<endl;

				if(!isEmpty(top))
					cout<<"TOP->"<<TOP(stack,top)<<endl;
					else
					cout<<"stack hooson bna"<<endl;
				break;
			case 4:
				displayStack(stack,top);
				break;
		}
	}while(choice!=0);	
	return 0;
}