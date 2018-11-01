#include <iostream>
#include <stdio.h>

using namespace std;
struct Node{
    int content;
    Node *next;
};

unsigned int findLength(Node **head);
void addNodeAtEnd(Node **head, int value);
void addNodeAtFirst(Node **head, int value);
void addNodeByIndex(Node **head, int value, int index);
void addNodeByValue(Node **head, int value, int findValue);

int searchNodeByValue(Node **head,int findValue);
int searchNodeByIndex(Node **head,int findIndex);

void deleteNodeAtFirst(Node **head);
void deleteNodeAtEnd(Node **head);




void deleteNodeByIndex(Node **head, int findIndex){
    if(findIndex!=0 && findIndex <=findLength(&*head)){
        Node *tempHead = *head;

        for(int i=1;i<=findIndex-1;i++){
            tempHead=tempHead->next;
        }
        Node *del = tempHead->next;
        delete del;
        tempHead->next=tempHead->next->next;
    }else {
        cout<<"Im toonii element listend bhgui"<<endl;
    }
}
void deleteNodeByValue(Node **head, int findValue){
    int searchIndex = searchNodeByValue(&*head,findValue);
    if(searchIndex>=0){
        deleteNodeByIndex(&*head,searchIndex);
    }else{
        cout<<"iim utgatai element oldsongui"<<endl;
    }
}


void displayAllNode(Node **head);










int main(){
    struct Node* el3= new Node;
    el3->content=333;
    el3->next=NULL;

    struct Node* el2= new Node;
    el2->content=456;
    el2->next=el3;

    struct Node* el= new Node;
    el->content=123;
    el->next=el2;
    struct Node* head=el;
    int index;

    //addByIndex(arrayList,1,88,length);

    char choose='0';

    do{
        cout<<"Songoltoo hiine uu"<<endl;
        cout<<"1. Add element"<<endl
            <<"2. Delete element"<<endl
            <<"3. Search element"<<endl
            <<"4. Display"<<endl
            <<"5. Exit"<<endl;
        cin>>choose;

        switch(choose){
            float value;
            case '1':
                do{
                    cout<<"Listend utga nemeh"<<endl
                        <<"1. Index-r nemeh"<<endl
                        <<"2. Utga guulsan elementiin ard nemeh"<<endl
                        <<"3. Listiin Ehend nemeh"<<endl
                        <<"4. Listiin tugsguld nemeh"<<endl
                        <<"0. Back"<<endl;
                    cin>>choose;
                    switch(choose){
                        case '1':
                            cout<<"Index-ig oruulna uu: ";
                            cin>>index;
                            cout<<"Nemeh utgaa oruulna uu: ";
                            cin>>value;
                            addNodeByIndex(&head,value,index);
                            break;

                        case '2':
                            cout<<"Ymar utgiin ard nemeh we?: ";
                            float findValue;
                            cin>>findValue;
                            cout<<"Nemeh utgaa oruulna uu: ";
                            cin>>value;
                            addNodeByValue(&head,value,findValue);
                            break;

                        case '3':
                            cout<<"Listiin ehend Nemeh utgaa oruulna uu: ";
                            cin>>value;
                            addNodeAtFirst(&head,value);
                            break;
                        case '4':
                            cout<<"Listiin tugsguld Nemeh utgaa oruulna uu: ";
                            cin>>value;
                            addNodeAtEnd(&head,value);
                            break;
                    }
                }while(choose!='0');
                choose='1';
                break;

            case '2':
                do{
                    cout<<"List-ees element ustgah"<<endl
                        <<"1. Index-r ustgah"<<endl
                        <<"2. Utgaar ustgah"<<endl
                        <<"3. Ehnii elementiig ustgah"<<endl
                        <<"4. Suuliin elementiig ustgah"<<endl
                        <<"0. Back"<<endl;
                    cin>>choose;

                    switch(choose){
                        case'1':
                                cout<<"Index ee oruulna uu->";
                                cin>>index;
                                deleteNodeByIndex(&head,index);
                                break;
                        case'2':
                                cout<<"Utgaa oruulna uu->";
                                cin>>value;
                                deleteNodeByValue(&head,value);
                                break;
                        case'3':
                                deleteNodeAtFirst(&head);
                                break;
                        case'4':
                                deleteNodeAtEnd(&head);
                                break;

                    }
                }while(choose!='0');choose='1';break;

            case '3':
                do{
                    cout<<"List-ees utga haih"<<endl
                        <<"1. Index-r haih"<<endl
                        <<"2. Utgaar haih"<<endl
                        <<"0. Back"<<endl;
                    cin>>choose;

                    switch(choose){
                        case'1':
                                cout<<"Index ee oruulna uu->";
                                cin>>index;
                                searchNodeByIndex(&head,index);
                                break;
                        case'2':
                                cout<<"Utgaa oruulna uu->";
                                cin>>index;
                                int foundIndex = searchNodeByValue(&head,index);
                                if(foundIndex>0){
                                    searchNodeByIndex(&head,foundIndex);
                                }else{
                                    cout<<index<<" gesen utga listent bhgui"<<endl;
                                }
                                break;
                    }
                }while(choose!='0');choose='1';break;
            case '4':
                cout<<"-->";
                displayAllNode(&head);
                cout<<endl;
                break;

        }

    }while(choose!='0');


}

void addNodeByIndex(Node **head, int value, int index){
    if(*head==NULL){
        Node *newNode = new Node;
        newNode->content=value;
        newNode->next=NULL;
        *head=newNode;
    }
    else
    if(index<=findLength(&*head)){
        Node *tempHead = *head;
        Node *newNode = new Node;
        newNode->content=value;

        for(int i=1;i<index;i++){
            tempHead= tempHead->next;
        }
        newNode->next = tempHead;

        tempHead = *head;
        for(int i=1;i<index-1;i++){
            tempHead= tempHead->next;
        }
        tempHead->next = newNode;

    }else{
    cout<<"List-n urtaas ih index oruulsan bna"<<endl;}
}

void addNodeByValue(Node **head, int value, int findValue){
    int searchIndex = searchNodeByValue(&*head,findValue);
    if(searchIndex>=0){
        int location=0;
        cout<<"Tus elementiing haana oruulah we? urd=0, hoino=1"<<endl;
        cin>>location;
        addNodeByIndex(&*head,value,searchIndex+location);
    }else{
        cout<<"iim utgatai element oldsongui"<<endl;
    }
}



void addNodeAtFirst(Node **head, int value){
    struct Node *newNode = new Node;
    newNode->content=value;
    newNode->next=NULL;
    if(*head == NULL){
        *head=newNode;
        return;
    }

    struct Node *tempHead = *head;
    newNode->next=*head;
    *head=newNode;
}

void addNodeAtEnd(Node **head, int value){
    struct Node *newNode = new Node;
    struct Node *tempHead = *head;
    newNode->content=value;
    newNode->next=NULL;

    if(*head == NULL){
        *head=newNode;
        return;
    }
    while(tempHead->next != NULL){
        tempHead = tempHead->next;
    }
    tempHead->next=newNode;
}



int searchNodeByIndex(Node **head,int findIndex){
    if(findIndex!=0 && findIndex <=findLength(&*head)){
        Node *tempHead = *head;

        for(int i=1;i<findIndex;i++){
            tempHead=tempHead->next;
        }
        return tempHead->content;
    }else {
        return -1;
    }

}


int searchNodeByValue(Node **head,int findValue){
    Node *tempHead = *head;
    unsigned int count=0;
    while(tempHead!=NULL){
        count++;
        if(tempHead->content==findValue){
            return count;
        }
        tempHead=tempHead->next;
    }
    return -1;
}


void deleteNodeAtFirst(Node **head){
    Node *temp = *head;
   *head = temp->next;
   delete temp;
}

void deleteNodeAtEnd(Node **head){
    Node *tempHead = *head;

    while(tempHead->next!=NULL){
        if(tempHead->next->next==NULL){
            delete tempHead->next;
            tempHead->next=NULL;
        }else{
        tempHead=tempHead->next;}
    }
}



void displayAllNode(Node **head){
    struct Node *tempHead = *head;
    if(*head == NULL){
        cout<<"List hooson bna"<<endl;
        return;
    }
    while(tempHead!=NULL){
        cout<<tempHead->content<<" ";
        tempHead=tempHead->next;
    }
    cout<<endl;
}

unsigned int findLength(Node **head){
    unsigned int total=0;
    Node *tempHead = *head;

    while(tempHead!=NULL){
        ++total;
        tempHead = tempHead->next;
    }
    return total;
}
