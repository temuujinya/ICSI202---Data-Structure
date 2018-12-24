#include <iostream>

using namespace std;

    void swap(int *oldIndex, int *newIndex){
        int *temp = oldIndex;
        oldIndex = newIndex;
        newIndex=temp;
    }


    void print(int *arr, int length){
        if(length==0)
            return;
 
        print(arr,length-1);
        //minus one cause array start from 0 but length 1
        cout<<arr[length-1]<<" ";
    }