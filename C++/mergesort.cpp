#include<iostream>
using namespace std;
void merge(int *arr , int s , int e){
    int mid = (s+e)/2;
     int len1= mid - s + 1;
     int len2= e-mid;

     int *first =  new int[len1];
     int *second = new int[len2];

     //copy values
     int mainArrayindex = s ;
     for(int i=0;i<len1; i++){
        first[i] =arr [mainArrayindex++];
     }
     mainArrayindex = mid+1;
     for (int i = 0; i < len2; i++)
     {
        second[i] = arr[mainArrayindex++];
     }

     //merge two sorted arrays
     int index1 = 0;
     int index2 = 0;
     mainArrayindex = s;
     while (index1 < len1 && index2 < len2){

        if(first[index1] < second[index2]){
            arr[mainArrayindex++] = first[index1++];
        }
        else{
            arr[mainArrayindex++] =second[index2++];
        }
     }
    while(index1< len1){
        arr[mainArrayindex++] = first[index1++];
    }
    while (index2 <len2) {
        arr[mainArrayindex++] = second[index2++];
    }
    delete []first;
    delete []second;
}
void merge_sort(int *arr , int s , int e){
     //base case
     if(s >= e){
     return;
    }
     int mid = (s+e)/2;
    //to sort the left side
    merge_sort(arr , s , mid);
    
    //to sort right side
    merge_sort(arr , mid+1 , e);

    //merge two arrays
    merge(arr, s ,e);
}

int main()
{
    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15 ;
    merge_sort(arr,0,n-1);
    
    for(int i =0 ; i<n ; i++)
    {
       cout<< arr[i]<<" ";
    }cout<<endl;
return 0;
}