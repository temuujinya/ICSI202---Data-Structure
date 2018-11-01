//Stack массиваар илэрхийлэх

/*
	POP - сүүлийн элементийг гаргах
	PUSH - элемент нэмэх
	TOP - сүүлийн элементийг хасахгүйгээр утгийг буцаах
	
*/

#include "functions.h"

bool isEmpty(Node **head){
	if(*head==NULL){
		return true;
	}
	return false;
}

 void push(Node **head, int &newData){
	

    if(!isEmpty(head)){
        Node *tempHead = *head;
        Node *newHead = new Node;
        newHead->content=newData;
        newHead->next=tempHead;
        *head = newHead;
    }else{
        Node *newHead = new Node;
        newHead->content=newData;
        newHead->next=NULL;
        *head=newHead;
    }
 } 

 void displayStack(Node **head){
     if(!isEmpty(head)){
        Node *tempHead = *head;
        while(tempHead!=NULL){
         cout<<tempHead->content<<" ";
         tempHead = tempHead->next;
        }
        cout<<endl;
     }
     else{
        cout<<"Stack hooson"<<endl;
        }
 }

int pop(Node **head){
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

int TOP(Node **head){
	if(!isEmpty(head)){
        Node *tempHead = *head;
		return tempHead->content;
	}else{
		cout<<"Stack hooson bna"<<endl;
	}
}

