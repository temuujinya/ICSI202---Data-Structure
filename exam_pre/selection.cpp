#include<iostream>

using namespace std;

void swap(int *arr,int oldIndex, int newIndex);
void print(int *arr,int length);


int main(){
    int arr[] = {8,45,433,45,23,234,4354,35,4656,234,234,2,654};
    int lengthOfArray = sizeof(arr)/sizeof(*arr);
    for(int i=0; i<lengthOfArray;i++){
        int min = i;
        for(int j=i+1;j<=lengthOfArray;j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        swap(arr, i,min);
        // cout<<arr[min]<<"bolon "<<arr[i]<<endl;
    }

    print(arr, lengthOfArray);
}

void swap(int *arr, int oldIndex, int newIndex){
    int temp = arr[oldIndex];
    arr[oldIndex] = arr[newIndex];
    arr[newIndex]=temp;
}

void print(int *arr, int length){
    
    // TODO: recursive bolgood uz
    if(length<=0){
        return;
    }
    print(arr,length-1);
    cout<<arr[length-1]<<" ";
    
    // int index=0;
    // while(index<length){
    //     cout<<arr[index]<<" ";
    //     index++;
    // }
}