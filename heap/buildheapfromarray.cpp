#include <iostream> 
using namespace std;
int n;
void heapify(int arr[], int i) 
{ 
	int smallest = i; // node which will be heapified 
	int l = 2 * i + 1; // left child 
	int r = 2 * i + 2; // right child 
	// Check if left child is smaller than its parent 
	if (l < n && arr[l] < arr[smallest]) smallest = l; 
	// Check if right child is smaller than smallest 
	if (r < n && arr[r] < arr[smallest]) smallest = r; 
	// If smallest is not parent 
	if (smallest != i) { 
		swap(arr[i], arr[smallest]); 
		heapify(arr, smallest); 
	} 
} 

// Function to build a Max-Heap from the given array 
void buildHeap(int arr[]) 
{
// Perform level order traversal from last non-leaf node and heapify each node 
	for (int i = n; i >= 0; i--) heapify(arr, i);
} 
int main() 
{ 
	int arr[] = { 1, 5, 6, 8, 9, 7, 3}; 
	n = sizeof(arr) / sizeof(arr[0]);
	cout << "Before: "<<endl; 
	for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
	cout << '\n'; 
	buildHeap(arr); 
    cout << "After: " << '\n';
	for (int i = 0; i < n; ++i) cout << arr[i] << ' '; 
	return 0; 
} 
