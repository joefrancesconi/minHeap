/*
 * Name: Joe Francesconi
 * Date Submitted: 4/19/2022
 * Assignment Name: Min-Heap Implementation
 */

#include "minHeap.h"

//parameterized constructor that takes a vector
//to build the heap from bottom up w/o insert
minHeap::minHeap(std::vector<int> data)
{
    heap.resize(0);
    for (int i = 0; i < data.size(); i++)
        heap.push_back(data[i]);
    for (int i = heap.size() - 1; i >= 0; i--)
        siftDown(i);
}

//insert that maintains heap property
void minHeap::insert(int value)
{
    //inserts at the end
    heap.push_back(value);
    //sets position of value
    int pos = heap.size() - 1;
    //moves the value upwards to the right place
    siftUp(pos);
}
//remove that maintains heap property
int minHeap::removeMin()
{
    if (heap.size() == 0)
        return -1;
    
    //first element is the min in a minHeap
    //swap first element and last to be able to pop
    int temp = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap[heap.size() - 1] = temp;
    heap.pop_back();

    //move everything back down
    siftDown(0);

    //returns minimum value of original heap (ie. heap[0])
    return temp;
}
//helper functions
void minHeap::siftUp(int pos)
{
    //p for parent and c for child
    int p = (pos - 1) / 2;
    int c = pos;
    int temp = 0;

    while(c != 0 && heap[p] > heap[c])
    {
        //swap
        temp = heap[p];
        heap[p] = heap[c];
        heap[c] = temp;

        c = p;
        //new parent
        p = (p - 1) / 2;
    }
}

void minHeap::siftDown(int pos)
{
    //p for parent, cL for left child, and cR for right child
    int p = pos;
    int cL = 2 * p + 1;
    int cR = 2 * p + 2;

    int swap = -1;

    if (cL < heap.size() && heap[cL] < heap[p])
        swap = cL;
    if (cR < heap.size() && heap[cR] < heap[p])
    {
        if (swap == -1)
            swap = cR;
        else if (heap[cR] < heap[cL])
            swap = cR;
    }

    if (swap == -1)
        return;
    int temp = heap[p];
    heap[p] = heap[swap];
    heap[swap] = temp;

    //recursive call to sift down
    siftDown(swap);
}