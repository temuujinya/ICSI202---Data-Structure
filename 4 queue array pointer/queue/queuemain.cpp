
#include "functions.h"

int main(){
	int max=50;
	int queue[max],length=-1;
	
	

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
				enqueue(queue,max,length,val);
				cout<<"queue->";
				displayQueue(queue,length);
				break;
			case 2:
				//pop(queue,length);
				if(!isEmpty(length)){
					cout<<"DEQUEUE->"<<dequeue(queue,length)<<endl;
					displayQueue(queue, length);
				}else
					cout<<"queue hooson bna"<<endl;
				break;
			case 3:
			    //!ASK
				//hooson ued sanah oin hog hewleed bna
				//cout<<length(queue,length)<<endl;

				if(!isEmpty(length))
					cout<<"Front->"<<front(queue)<<endl;
					else
					cout<<"queue hooson bna"<<endl;
				break;
			case 4:

				if(!isEmpty(length))
					cout<<"Rear->"<<rear(queue,length)<<endl;
					else
					cout<<"queue hooson bna"<<endl;
				break;
			case 5:
				displayQueue(queue,length);
				break;
		}
	}while(choice!=0);	
	return 0;
}