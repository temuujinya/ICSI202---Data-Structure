//Queue массиваар илэрхийлэх

/*
	enqueue - дараалалд элемент нэмнэ
	dequeue - дарааллаас элемент хасна
	front - эхний элементийг хасахгүйгээр утгийг буцаах
	read - сүүлийн элементийг хасахгүйгээр утгийг буцаах
	
*/
#include <iostream>
using namespace std;

bool isFull(int &max, int &length){
	if(max==length){
		return true;
	}
	return false;
}

bool isEmpty(int &length){
	if(length==-1){
		return true;
	}
	return false;
}

void enqueue(int *queue, int &max, int &length,int &newData){
	if(!isFull(max,length)){
		length+=1;
		queue[length]=newData;
	}else{
		cout<<"queue duursen bna"<<endl;
	}
} 

int dequeue(int *queue, int &length){
	if(!isEmpty(length)){
		int back = queue[0];
        //бүх элементийг нэг урагш шифтлэнэ
        for(int i=1;i<=length;i++){
            queue[i-1] = queue[i];
        }
		length-=1;
		return back;
	}else{
		exit;
	}
}

int front(int *queue){
	// if(!isEmpty(length)){
		return queue[0];
	// }else{
	// 	cout<<"queue hooson bna"<<endl;
	// }
}

int rear(int *queue, int &length){
	// if(!isEmpty(length)){
		return queue[length];
	// }else{
	// 	cout<<"queue hooson bna"<<endl;
	// }
}

void displayQueue(int *queue, int &length){
	if(!isEmpty(length)){
		//Сүүлд орсон нь түрүүлж гарах ёстой
		for(int i=0;i<=length;i++){
			cout<<queue[i]<<" ";
		}
		cout<<endl;
	}else{
		cout<<"queue hoooson"<<endl;
	}
}