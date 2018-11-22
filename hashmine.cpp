#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void insert_element(string newWord, string *hashTable, int &length, int &total);
int search_element(string searchWord, string *hashTable, int &length);
void delete_element();
int hashTemuujin(string newWord, string *hashTable, int &total);

void fill_zero(string *hashTable, int &total);
void printHashTable(string *hashTable, int &total);
string emptySymbol = ".";

int main()
{
    int tableLen = 100;
    string words[tableLen]={"hi","abc"};

    string hashTable[tableLen];
    int total = 0;

    fill_zero(hashTable, tableLen);
    printHashTable(hashTable, tableLen);

    // printf("%d", char('1'));

    // int newone;
    // scanf("%d", &newone);
    int n;
    do{
        scanf("%d", &n);
        string aa;
        cin>>aa;
        switch(n){
            case 1 : 
                insert_element(aa, hashTable, tableLen, total);
                printHashTable(hashTable, tableLen);
                break;
            case 2:
                int result = search_element(aa,hashTable, tableLen);
                if(result>=0){
                    cout<<"oldloo hashTable->index: "<<result;
                }else{
                    cout<<"not found"<<endl;
                }
                break;
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
void insert_element(string newWord, string *hashTable, int &length, int &total)
{

    int hashedIndex= hashTemuujin(newWord, hashTable, length);
    cout<<"\n"<<hashedIndex<<"\n";
    int s = total;
    if(hashTable[hashedIndex].compare(emptySymbol)==0){
        hashTable[hashedIndex]=newWord;
    }else{
        if(hashedIndex<length){
            //TODO: eniig neg func bolgoh
            if(hashTable[hashedIndex].compare(newWord)!=0){
                for(int i=hashedIndex+1;i<length;i++){
                    if(hashTable[i].compare(emptySymbol)==0){
                        hashTable[i] = newWord;
                        total++;
                        break;
                    }
                }
                //Enen total baih hregtei umuu        
                if(s==total){
                    for(int i=0; i<length; i++){
                        if(hashTable[i].compare(emptySymbol)==0){
                            hashTable[i] = newWord;
                            total++;
                            break;
                        }
                    }
                }
            }    
        }

    }
}

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
                    status=1;
                    return i;
                }   
            }
        }
    }

    return -1;
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