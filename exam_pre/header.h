#include <iostream>

using namespace std;
    int arr[] = {8,45,433,45,23,234,4354,35,4656,234,234,2,654};
    int length = sizeof(arr)/sizeof(*arr);

    void printAll(int *arr, int length){
        if(length==0)
            return;
 
        printAll(arr,length-1);
        //minus one cause array start from 0 but length 1
        cout<<arr[length-1]<<" ";
}