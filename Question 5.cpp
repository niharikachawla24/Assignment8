#include <iostream>
using namespace std;

int heapsize;
int Array[50];


void max_heapify(int Array[], int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= heapsize && Array[left] > Array[largest])
        largest = left;

    if (right <= heapsize && Array[right] > Array[largest])
        largest = right;

    if (largest != i) {
        int temp = Array[i];
        Array[i] = Array[largest];
        Array[largest] = temp;

        max_heapify(Array, largest);
    }
}

void build_max_heap(int Array[]) {
    for (int i = heapsize / 2; i >= 1; i--) {
        max_heapify(Array, i);
    }
}

int main() {
    cout << "Enter the size of the array: ";
    cin >> heapsize;

    cout << "Enter " << heapsize << " elements:\n";
    for (int i = 1; i <= heapsize; i++) {
        cin >> Array[i];
    }

    build_max_heap(Array);

    cout << "\nMax Heap: ";
    for (int i = 1; i <= heapsize; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;

    return 0;
}
