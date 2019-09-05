#include<iostream>
#include<math.h>
#include <cstdlib> 
using namespace std;
class SortingAlgorithms{
    int b[100];
    int n;
    void swap(int c,int d){
        int temp;
        temp=*(b+c);
        *(b+c)=*(b+d);
        *(b+d)=temp;
    }
    void swap(int *a,int *b){
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }
    void insert(int start){
        int pos=start;
        while(pos>0 && b[pos]<b[pos-1]){
            swap(pos,pos-1);
            pos=pos-1;
        }
    }
    
    void merge(int a[],int l,int m,int r){
        int n1=m-l+1;
        int n2=r-m;
        int L[n1],R[n2];
        int i=0,j=0,k=l;
        for(i=0;i<n1;i++){
            L[i]=a[l+i];
        }
        for(i=0;i<n2;i++){
            R[i]=a[m+1+i];
        }
        i=0;j=0;k=l;
        while(i<n1 && j<n2){
            if(L[i]<R[j]){
                a[k]=L[i];
                i++;
            }
            else{
                a[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            a[k]=L[i];
            i++;
            k++;
        }
        while(j<n2){
            a[k]=R[j];
            j++;
            k++;
        }
    }
    int partition (int low, int high) 
    { 
        int pivot = b[high];   
        int i = (low - 1);  
    
        for (int j = low; j <= high- 1; j++) 
        { 
            
            if (b[j] < pivot) 
            { 
                i++;    
                swap(&b[i], &b[j]); 
            } 
        } 
        swap(&b[i + 1], &b[high]); 
        return (i + 1); 
    } 
    //partiton by choosing random pivot
    int partition_r(int low, int high) 
    { 
        srand(time(NULL)); 
        int random = low + rand() % (high - low); 
        // Swap A[random] with A[high] 
        swap(&b[random], &b[high]); 
        return partition(low, high); 
    } 
    void heapify(int n,int i) 
    { 
        int largest = i; 
        int l = 2*i + 1; 
        int r = 2*i + 2; 
    
        
        if (l < n && b[l] > b[largest]) 
            largest = l; 
    
        
        if (r < n && b[r] > b[largest]) 
            largest = r; 
    
       
        if (largest != i) 
        { 
            swap(&b[i], &b[largest]);  
            heapify(n,largest); 
        } 
    } 
    public:
    SortingAlgorithms(int a[],int size){
        n=size;
        for(int i=0;i<n;i++){
             b[i]=a[i];
        }
        
    }
    void getter(){
        cout<<"The Array is:"<<endl;
        for(int i=0;i<n;i++){
            cout<<b[i]<<endl;
        }
    }
    void insertionSort(){
        int pos;
        int nextpos;
        for(pos=1;pos<n;pos++){
            nextpos=pos;
            while(nextpos>0 && b[nextpos]<b[nextpos-1]){
                    swap(nextpos,nextpos-1);
                    nextpos=nextpos-1;
            }
        }
    }
    void insertionSortRecursive(int start){
            if(start>=n)
                return;
            insert(start);
            insertionSortRecursive(start+1);
            return;
    }
    void mergeSort(int l,int r){
        if(l<r){
            int mid=l+(r-l)/2;
            mergeSort(l,mid);
            mergeSort(mid+1,r);
            merge(b,l,mid,r);
        }
    }    
    void quickSort(int low,int high)//high=size-1 
    { 
        if (low < high) 
        { 
            int pi = partition_r(low, high); 
            quickSort(low, pi - 1); 
            quickSort(pi + 1, high); 
        } 
    } 
    void heapSort() 
    { 
        // Build heap (rearrange array) 
        for (int i = n / 2 - 1; i >= 0; i--) 
            heapify(n,i); 
        // One by one extract an element from heap 
        for (int i=n-1; i>=0; i--) 
        { 
            // Move current root to end 
            swap(&b[0],&b[i]); 
    
            // call max heapify  
            heapify(i,0); 
        } 
    } 
};
int main(){
    cout<<"enter the size of the array:"<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"enter the array:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    SortingAlgorithms p1=SortingAlgorithms(arr,size);
    p1.quickSort(0,size-1);
    p1.getter();
    cout<<endl;
    //cout<<time(NULL);
    // p1.getter();   
}
