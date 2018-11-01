
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
			<<"1. Enqueue"<<endl
			<<"2. Dequeue"<<endl
			<<"3. FRONT"<<endl
			<<"4. REAR"<<endl
			<<"5. Display all queue elements"<<endl
            <<"0. Exit"<<endl
			<<"-------------------"<<endl;
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Oruulah utga=>";
				int val;
				cin>>val;
				enqueue(&head,val);
				cout<<"Queue->";
				displayQueue(&head);
				break;
			case 2:
				//pop(Queue,top);
				if(!isEmpty(&head)){
					cout<<"DEQUQUE->"<<dequeue(&head)<<endl;
					displayQueue(&head);
				}else
					cout<<"Queue hooson bna"<<endl;
				break;
			case 3:
			    //!ASK
				//hooson ued sanah oin hog hewleed bna
				//cout<<TOP(Queue,top)<<endl;

				if(!isEmpty(&head))
					cout<<"FRONT->"<<front(&head)<<endl;
					else
					cout<<"Queue hooson bna"<<endl;
				break;
			case 4:
				if(!isEmpty(&head))
					cout<<"REAR->"<<rear(&head)<<endl;
					else
					cout<<"Queue hooson bna"<<endl;
				break;
			case 5:
                cout<<"->";
				displayQueue(&head);
				break;
		}
	}while(choice!=0);	

	return 0;
}