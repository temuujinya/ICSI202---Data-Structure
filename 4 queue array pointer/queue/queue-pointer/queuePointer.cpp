//Queue массиваар илэрхийлэх

/*
	enqueue - дараалалд элемент нэмнэ
	dequeue - дарааллаас элемент хасна
	front - эхний элементийг хасахгүйгээр утгийг буцаах
	read - сүүлийн элементийг хасахгүйгээр утгийг буцаах
	
*/
#include "functions.h"

bool isEmpty(Node **head){
	if(*head==NULL){
		return true;
	}
	return false;
}

 void enqueue(Node **head, int &newData){
	

    if(!isEmpty(head)){
        Node *tempHead = *head;
        Node *newNode = new Node;
        newNode->content=newData;
        newNode->next=NULL;

        while(tempHead->next!=NULL){
            tempHead=tempHead->next;
        }
        tempHead->next=newNode;
    }else{
        Node *newNode = new Node;
        newNode->content=newData;
        newNode->next=NULL;
        *head=newNode;
    }
 }

int dequeue(Node **head){
	if(!isEmpty(head)){
		Node *tempHead = *head;
        //хэрэглэгчид ямар утга поп хийгдсэнийг харуулах үүднээс
        int back = tempHead->content;
        tempHead=tempHead->next;
        delete *head;
        *head=tempHead;
		return back;
	}else{
		exit;
	}
}

int front(Node **head){
	if(!isEmpty(head)){
        Node *tempHead = *head;
		return tempHead->content;
	}else{
		cout<<"Queue hooson bna"<<endl;
	}
}

int rear(Node **head){
	if(!isEmpty(head)){
        Node *tempHead = *head;
        while(tempHead->next!=NULL){
            tempHead=tempHead->next;
        }
		return tempHead->content;
	}else{
		cout<<"Queue hooson bna"<<endl;
	}
}

 

 void displayQueue(Node **head){
     if(!isEmpty(head)){
        Node *tempHead = *head;
        while(tempHead!=NULL){
         cout<<tempHead->content<<" ";
         tempHead = tempHead->next;
        }
        cout<<endl;
     }
     else{
        cout<<"Queue hooson"<<endl;
        }
 }