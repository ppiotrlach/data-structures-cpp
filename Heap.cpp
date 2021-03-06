#include <iostream>
#include "Heap.h"

using namespace std;

void Heap::heapify(int parent)
{
    int heapSize = heap.getSize();
    int largestIndex = parent; // initializing parent as the largest number
    int leftChildIndex = leftChild(largestIndex);
    int rightChildIndex = rightChild(largestIndex);

    // if left child is larger than parent overwrite largestIndex
    if (leftChildIndex < heapSize && heap.getNumber(leftChildIndex) > heap.getNumber(largestIndex))
    {
        largestIndex = leftChildIndex;
    }

    // if right child is larger than largest overwrite largestIndex
    if (rightChildIndex < heapSize && heap.getNumber(rightChildIndex) > heap.getNumber(largestIndex))
    {
        largestIndex = rightChildIndex;
    }

    // if largest is not initial parent:
    if (largestIndex != parent)
    {
        // - swap numbers
        heap.swap(parent, largestIndex);

        // - recursively heapify substree of swapped child
        heapify(largestIndex);
    }
}

Heap::Heap()
{
}

int Heap::getSize()
{
    return heap.getSize();
}

int Heap::getRoot()
{
    return heap.getNumber(0);
}


void Heap::append(int n){ //makes more sense when loading a large amount of items into the heap, then we call doHeapify 
    heap.append(n);
}


void Heap::addAndHeapify(int n) //add number and restore the functional property of heap (only if we use this method, call doHeapify after using append )
{
    heap.append(n);

    int i = heap.getSize() - 1;
    while (i != 0 && heap.getNumber(parent(i)) < heap.getNumber(i))
    {
        heap.swap(parent(i), i);
        i = parent(i);
    }
}

void Heap::doHeapify()
{
    int youngestParent = parent(heap.getSize() - 1);

    for (int i = youngestParent; i >= 0; i--) //call function heapify from the youngest parent to root
    {
        heapify(i);
    }
}

void Heap::deleteMax() //delete the root (number on first position of array) and restore property of heap
{
    heap.deleteAt(0);
    doHeapify();
}

void Heap::print()
{
    // heap.print();
    cout << endl;

    int pow_of_two = 1;
    for (size_t i = 0; i < heap.getSize(); i++)
    {
        int buff = pow_of_two;
        while (i < heap.getSize())
        {
            cout << heap.getNumber(i) << " ";
            pow_of_two--;
            if (pow_of_two == 0)
                break;
            i++;
        }
        cout << endl;

        pow_of_two = buff;
        pow_of_two *= 2;
    }
    cout << endl;
}
