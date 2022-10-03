
void sort012(int *arr, int n)
{
   int l = 0, h = n-1, m = 0;
    
   while(m <= h) {
       switch(arr[m]) {
           case 0:
               swap(arr[m], arr[l]);
               m++; l++;
               break;
           case 1:
               m++;
               break;
           case 2:
               swap(arr[m], arr[h]);
               h--;
               break;
       }   
   }

}