#include <iostream>
using namespace std;

int heap[50];
int heapSize = 0;

void max_heapify(int A[], int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left <= heapSize && A[left] > A[largest])
        largest = left;
    if (right <= heapSize && A[right] > A[largest])
        largest = right;
    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        max_heapify(A, largest);
    }
}

void heap_increase_key(int A[], int i, int key) {
    if (key < A[i]) {
        cout << "New key is smaller than current key!\n";
        return;
    }
    A[i] = key;
    while (i > 1 && A[i / 2] < A[i]) {
        int temp = A[i];
        A[i] = A[i / 2];
        A[i / 2] = temp;
        i = i / 2;
    }
}

void max_heap_insert(int A[], int key) {
    heapSize++;
    A[heapSize] = -9999;
    heap_increase_key(A, heapSize, key);
}

int heap_extract_max(int A[]) {
    if (heapSize < 1) {
        cout << "Heap underflow!\n";
        return -1;
    }
    int max = A[1];
    A[1] = A[heapSize];
    heapSize--;
    max_heapify(A, 1);
    return max;
}

int heap_maximum(int A[]) {
    if (heapSize < 1) {
        cout << "Heap is empty!\n";
        return -1;
    }
    return A[1];
}

void display() {
    if (heapSize == 0) {
        cout << "Heap is empty!\n";
        return;
    }
    cout << "Heap elements: ";
    for (int i = 1; i <= heapSize; i++) {
        cout << heap[i] << " ";
    }
    cout << "\n";
}

int main() {
    int input;
    while (1) {
        cout << "Press:\n 1 to insert into heap\n 2 to display heap\n 3 to find maximum\n 4 to extract maximum\n 5 to increase key\n 6 to exit\n";
        cin >> input;
        cout << "\n";
        switch (input) {
            case 1: {
                int num;
                cout << "Enter value to insert: ";
                cin >> num;
                max_heap_insert(heap, num);
                break;
            }
            case 2:
                display();
                break;
            case 3:
                cout << "Maximum element: " << heap_maximum(heap) << "\n";
                break;
            case 4:
                cout << "Extracted max: " << heap_extract_max(heap) << "\n";
                break;
            case 5: {
                int pos, key;
                cout << "Enter index and new key: ";
                cin >> pos >> key;
                heap_increase_key(heap, pos, key);
                break;
            }
        }
        if (input == 6)
            break;
    }
    return 0;
}
