
#include "functions.h"



int main(){
    struct Node *s2 = new Node;
    s2->content=22;
    s2->next=NULL;
    struct Node *s1 = new Node;
    s1->content=11;
    s1->next=s2;
    // struct Node *head=s1;
    struct Node *head=NULL;


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
				push(&head,val);
				cout<<"stack->";
				displayStack(&head);
				break;
			case 2:
				//pop(stack,top);
				if(!isEmpty(&head)){
					cout<<"POP->"<<pop(&head)<<endl;
					displayStack(&head);
				}else
					cout<<"stack hooson bna"<<endl;
				break;
			case 3:
			    //!ASK
				//hooson ued sanah oin hog hewleed bna
				//cout<<TOP(stack,top)<<endl;

				if(!isEmpty(&head))
					cout<<"TOP->"<<TOP(&head)<<endl;
					else
					cout<<"stack hooson bna"<<endl;
				break;
			case 4:
                cout<<"->";
				displayStack(&head);
				break;
		}
	}while(choice!=0);	

	return 0;
}