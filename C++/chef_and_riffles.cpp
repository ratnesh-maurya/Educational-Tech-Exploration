#include<iostream>
using namespace std; 
int main()
{
    int n;
    int d;
    cin>>n;
    int a[n];
    int b[n];
    int j=0;
    int i;
    for(i=0;i<n;i++){
      a[i]=i;
      cout<<a[i]<<endl;
    }
    
    
        for(i=0;i<n;i++)
        {
        if(i%2!=0){
        b[j]=a[i];
        j++;
        }
        }
        for(i=0;i<n;i++)
        {
            if(
                i%2==0)
            b[j]=a[i];
            j++;

        }


      /*  for(i=0;i<n;i++)
        {
            a[i]=b[i];
        }
        */
        
    
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }

    return 0;
}