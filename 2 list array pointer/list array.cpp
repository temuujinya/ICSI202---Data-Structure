#include<iostream>

using namespace std;

/*
array 0-с эхэлнэ.

*/

void addAtFirst(float (&arrayList)[50],float &value, int &length,int index);
void addAtEnd(float (&arrayList)[50],float &value, int &length);
void addByIndex(float (&arrayList)[50],int &index,float &value,int &length);
void addByValue(float (&arrayList)[50],float &findValue,float &newValue,int &length);


void deleteAtFirst(float (&arrayList)[50],int &length, int index);
void deleteAtEnd(float (&arrayList)[50],int &length);
void deleteByIndex(float (&arrayList)[50],int &index,int &length);
void deleteByValue(float (&arrayList)[50],float &findValue,int &length);

void searchByIndex(float (&arrayList)[50],int index,int &length);
// Утгаар хайж олоод олдсон index-г буцаана.
// Олдоогүй бол -1 буцаана.
int searchByValue(float (&arrayList)[50], float value, int &length);

//Бүх листийг хэвлэх
void display(float (&arrayList)[50], int &length);

int main(){

        float arrayList[50];
            arrayList[0]=9,
            arrayList[1]=156,
            arrayList[2]=998;

        int length=3,index;

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
                                addByIndex(arrayList,index,value,length);
                                break;

                            case '2':
                                cout<<"Ymar utgiin ard nemeh we?: ";
                                float findValue;
                                cin>>findValue;
                                cout<<"Nemeh utgaa oruulna uu: ";
                                cin>>value;
                                addByValue(arrayList,findValue,value,length);
                                break;

                            case '3':
                                cout<<"Listiin ehend Nemeh utgaa oruulna uu: ";
                                cin>>value;
                                addAtFirst(arrayList,value,length,0);
                                break;
                            case '4':
                                cout<<"Listiin tugsguld Nemeh utgaa oruulna uu: ";
                                cin>>value;
                                addAtEnd(arrayList,value,length);
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
                                    deleteByIndex(arrayList,index,length);
                                    break;
                            case'2':
                                    cout<<"Utgaa oruulna uu->";
                                    cin>>value;
                                    deleteByValue(arrayList,value,length);
                                    break;
                            case'3':
                                    deleteAtFirst(arrayList,length,0);
                                    break;
                            case'4':
                                    deleteAtEnd(arrayList, length);
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

                        /*
                        if(choose==1){
                            cout<<"Index ee oruulna uu->";
                            cin>>index;
                            searchByIndex(arrayList,index,length);
                            break;
                        }else if(choose==2){
                            cout<<"Utgaa oruulna uu->";
                            cin>>index;
                            cout<<searchByValue(arrayList,igmoblendex,length)<<endl;
                            break;
                        }
                        */
                        switch(choose){
                            case'1':
                                    cout<<"Index ee oruulna uu->";
                                    cin>>index;
                                    searchByIndex(arrayList,index,length);
                                    break;
                            case'2':
                                    cout<<"Utgaa oruulna uu->";
                                    cin>>index;
                                    float foundIndex = searchByValue(arrayList,index,length);
                                    if(foundIndex>=0){
                                        cout<<index<<" utga ni "<<foundIndex<<" index deer bna"<<endl;
                                    }else{
                                        cout<<index<<" gesen utga listent bhgui"<<endl;
                                    }
                                    break;
                        }
                    }while(choose!='0');choose='1';break;
                case '4':
                    cout<<"-->";
                    display(arrayList,length);
                    cout<<endl;
                    break;

            }

        }while(choose!='0');

}

void addAtFirst(float (&arrayList)[50],float &value, int &length,int index){
    addByIndex(arrayList,index,value,length);
}

void addAtEnd(float (&arrayList)[50],float &value, int &length){
    addByIndex(arrayList,length,value,length);
}

void addByIndex(float (&arrayList)[50],int &index,float &value,int &length){

    if(index<=length){
        for(int i=length-1;i>=index;i--){
            arrayList[i+1] = arrayList[i];
        }
        arrayList[index]=value;
        length++;
    }else{
        cout<< "List-n urtaas ih bna";
        }
}

void addByValue(float (&arrayList)[50],float &findValue,float &newValue,int &length){
    int tempIndex=searchByValue(arrayList, findValue, length);
    if(tempIndex!=-1){
        //++tempIndex -- утгийг илгээхээсэй өмнө 1-р нэмэгдүүлж байна
        //tempIndex++ хийхэд эхлээд өөрийн утгаа явуулаад 1-р нэмнэ ингэснээр алдаа гарна учир нь заалт(referene) учраас
        addByIndex(arrayList, ++tempIndex, newValue, length);
    }else{
        cout<<"Oruulsan utgatai element baihgui bna"<<endl;
    }
}

void deleteAtFirst(float (&arrayList)[50],int &length,int index){
    deleteByIndex(arrayList, index, length);
}

void deleteAtEnd(float (&arrayList)[50], int &length){
    deleteByIndex(arrayList,--length, length);
}

void deleteByIndex(float (&arrayList)[50],int &index,int &length){

    if(index<length){
        for(int i=index;i<length;i++){
            arrayList[i] = arrayList[i+1];
        }
        length--;
    }else{
        cout<< "List-n urtaas ih bna || listend iim index bhgui";
        }
}

void deleteByValue(float (&arrayList)[50],float &findValue,int &length){
    int tempIndex=searchByValue(arrayList, findValue, length);
    if(tempIndex!=-1){
        //++tempIndex -- утгийг илгээхээсэй өмнө 1-р нэмэгдүүлж байна
        //tempIndex++ хийхэд эхлээд өөрийн утгаа явуулаад 1-р нэмнэ ингэснээр алдаа гарна учир нь заалт(referene) учраас
        deleteByIndex(arrayList, tempIndex, length);
    }else{
        cout<<"Oruulsan utgatai element baihgui bna"<<endl;
    }
}

void searchByIndex(float (&arrayList)[50],int index,int &length){
    if(index<=length){
        cout<<index<<" index deer bga utga: "<<arrayList[index]<<endl;
    }else{
        cout<<"List-n urtaas ih bna - "<<index<<" indextei utga oldsongui"<<endl;
    }
}

int searchByValue(float (&arrayList)[50], float value, int &length){
    for(int i=0;i<length;i++){
        if(arrayList[i]==value)
            return i;
    }
    return -1;
}


void display(float (&arrayList)[50], int &length){
    for(int i=0;i<length;i++){
        cout<<arrayList[i]<<" ";
    }
}
