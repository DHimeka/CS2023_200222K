#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int largest = root; // Initialize largest as root
    int l = 2 * root + 1; // left = 2*root + 1
    int r = 2 * root + 2; // right = 2*root + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != root) {
        swap(arr[root], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   /// Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
void displaysortedArray(int arr[], int n)
{
    int output[n];
    for(int i = 0; i < n; i++){
        output[i] = arr[n-i-1];
    }    
    for(int i = 0; i < n; i++){
        cout << output[i] << " ";
        
        
    }
    cout << "\n";
}
  
// main program
int main()
{
    while(true){
    int count;
    cout << "Enter number of elements in array\n";
    cin >> count;
    cout << "Enter " << count << " numbers \n";
    int heap_arr[count];
    for(int i = 0; i < count; i++){
        cin >> heap_arr[i];
    }
  // int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   //cout<<"Input array"<<endl;
   //displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
    }
}