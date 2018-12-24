#include "header.h"

int main(){
    int arr[] = {8,45,433,45,23,234,4354,35,4656,234,234,2,654};
    int length = sizeof(arr)/sizeof(*arr);
    for(int i=0; i<length;i++){
        for(int j=0; j < length-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    print(arr,length);
}