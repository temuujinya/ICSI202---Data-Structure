//Stack массиваар илэрхийлэх

/*
	POP - сүүлийн элементийг гаргах
	PUSH - элемент нэмэх
	TOP - сүүлийн элементийг хасахгүйгээр утгийг буцаах
	
*/
#include <iostream>
using namespace std;

bool isFull(int &max, int &top){
	if(max==top){
		return true;
	}
	return false;
}

bool isEmpty(int &top){
	if(top==-1){
		return true;
	}
	return false;
}

void push(int *stack, int &max, int &top,int &newData){
	if(!isFull(max,top)){
		top+=1;
		stack[top]=newData;
	}else{
		cout<<"Stack duursen bna"<<endl;
	}
} 

int pop(int *stack, int &top){
	if(!isEmpty(top)){
		int back = stack[top];
		top-=1;
		return back;
	}else{
		exit;
	}
}

int TOP(int *stack, int &top){
	// if(!isEmpty(top)){
		return stack[top];
	// }else{
	// 	cout<<"Stack hooson bna"<<endl;
	// }
}

void displayStack(int *stack, int &top){
	if(!isEmpty(top)){
		//Сүүлд орсон нь түрүүлж гарах ёстой
		for(int i=top;i>=0;i--){
			cout<<stack[i]<<" ";
		}
		cout<<endl;
	}else{
		cout<<"Stack hoooson"<<endl;
	}
}