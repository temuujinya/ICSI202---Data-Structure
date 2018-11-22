#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void insert_element(string newWord, string *hashTable, int &length);
int search_element(string searchWord, string *hashTable, int &length);
void delete_element(string delWord, string *hashTable, int &length);
int hashTemuujin(string newWord, string *hashTable, int &length);

void fill_zero(string *hashTable, int &length);
void printHashTable(string *hashTable, int &length);
string emptySymbol = ".";

int main()
{
    int tableLen = 100;
    string words[tableLen]={"hi","abc"};

    string hashTable[tableLen];
    int total = 0;

    fill_zero(hashTable, tableLen);

    int n;
    do{
        cout<<"\n1. Insert\n2. Search\n3. Delete\n4. Print\n-2. Exit\n-> ";
        scanf("%d", &n);
        switch(n){
            case 1 : {
                    string aa;
                    cin>>aa;
                    insert_element(aa, hashTable, tableLen);
                }
                break;
            case 2:
                {
                    string aa;
                    cin>>aa;
                    int result = search_element(aa,hashTable, tableLen);
                    if(result>=0){
                        cout<<"oldloo hashTable->index: "<<result;
                    }else{
                        cout<<"not found"<<endl;
                    } break;
                 }
            case 3:{

                string aa;
                cin>>aa;
                delete_element(aa,hashTable, tableLen);
                break;
                }
            case 4: {
                printHashTable(hashTable, tableLen);
                break;
                }
            default: cout<<"\nzuw dugaar oruul\n";break;
        }

    } while (n != -2);

    // insert_element(newone, hashTable);
}


int hashTemuujin(string newWord, string *hashTable, int &length){
    int wordLength = newWord.length();
    int hashedIndex = 0;
    while(wordLength>=0){
        hashedIndex += char(newWord[wordLength]);
        wordLength--;
    }
    return hashedIndex %= length-1;
}
void insert_element(string newWord, string *hashTable, int &length)
{

    int hashedIndex= hashTemuujin(newWord, hashTable, length);
    cout<<" -hash index->"<<hashedIndex<<"\n";
    int s = 0;
    if(hashTable[hashedIndex].compare(emptySymbol)==0){
        hashTable[hashedIndex]=newWord;
    }else{
        if(hashedIndex<length){
            //TODO: eniig neg func bolgoh
            if(hashTable[hashedIndex].compare(newWord)!=0){
                for(int i=hashedIndex+1;i<length;i++){
                    if(hashTable[i].compare(emptySymbol)==0){
                        hashTable[i] = newWord;
                        s++;
                        break;
                    }
                }
                //Enen total baih hregtei umuu        
                if(s==0){
                    for(int i=0; i<length; i++){
                        if(hashTable[i].compare(emptySymbol)==0){
                            hashTable[i] = newWord;
                            break;
                        }
                    }
                }
            }    
        }

    }
}

/*
буцаах утга
    -1 олдоогүй
    0<= тоо олдсон индекс
*/
int search_element(string searchWord, string *hashTable, int &length){
    int hashedIndex = hashTemuujin(searchWord, hashTable, length);
    
    int status = 0;
    if(hashTable[hashedIndex].compare(".")==0){
        cout<<"\nIIm Element baihgiu"<<endl;
    }else{
        if(hashTable[hashedIndex].compare(searchWord)==0){
            return hashedIndex;   
        }
        for(int i=hashedIndex; i<length; i++){
            if(hashTable[i].compare(searchWord)==0){
                // cout<<"Oldloo index: "<<hashedIndex+1<<endl;
                status=1;
                return i;
            }
        }

        if(!status){
            for(int i=0; i<hashedIndex; i++){
                if(hashTable[i].compare(searchWord)==0){
                    // cout<<"Oldloo index: "<<hashedIndex+1<<endl;
                    return i;
                }   
            }
        }
    }

    return -1;
}


void delete_element(string delWord, string *hashTable, int &length){
    int hashedIndex = hashTemuujin(delWord, hashTable, length);
    int searchResult = search_element(delWord, hashTable, length);


    if(searchResult>=0){
        hashTable[searchResult] = emptySymbol;
        cout<<"Amjilttai ustsan"<<endl;
    }else{
        cout<<"baihgui element ustgah geed bna"<<endl;
    }

}


void fill_zero(string *hashTable, int &length)
{
    for (int i = 0; i < length; i++)
    {
        hashTable[i]=emptySymbol;
    }
}

void printHashTable(string *hashTable, int &length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<hashTable[i]<<" ";
    }
}