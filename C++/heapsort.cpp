 #include<iostream>

 using namespace std;
 
void heapify(int a[],int n,int i) //n is no of elements
{ //i is a variable  a is array
    int max=i;
    int l=(2*i);
    int r=(2*i)+1;
if(l<n && a[i]<a[l]){
    max=l;
}
if(r<n && a[i]<a[r]){
    max=r;
}
if(max != i)//after above process max and i is 
//updated
{
    swap(a[i] , a[max]);
    heapify(a,n,max);
}
}

void heapsort(int a[],int n){
    //for building heapt
    for(int i=n/2 -1 ; i>=0 ; i--){
      heapify(a,n,i);
    }
    //for deleting the elements of heap
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver code
int main()
{
    int arr[] = { 1, 17, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapsort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}