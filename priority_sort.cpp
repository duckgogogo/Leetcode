//
//  main.cpp
//  priority_queue
//
//  Created by Shan He on 12/8/16.
//  Copyright © 2016 Shan He. All rights reserved.
//

#include <iostream>

using namespace std;

class priorityQueue
{
private:
    int currentSize;
    int *array;
    int maxSize;
    
    void doubleSpace()
    {
        int *tmp = array;
        maxSize *= 2;
        array = new int[maxSize];
        for(int i = 0;i<currentSize;++i){
            array[i] = tmp[i];
        }
        delete [] tmp;
    }
    void buildHeap()
    {
        // start from the non leaf node with the biggest number
        for(int i = currentSize/2; i > 0; i--)
        {
            percolateDown(i);
        }
    }
    void percolateDown(int hole)
    {
        int child;
        int tmp = array[hole];
        for(;hole*2 <= currentSize;hole = child)
        {
            child = hole*2;
            if(child != currentSize && array[child + 1] < array[child])
                child++;
            if(array[child]<tmp)
                array[hole] = array[child];
            else break;
        }
        array[hole] = tmp;
    }
public:
    priorityQueue(int capacity = 100)
    {
        array = new int[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    priorityQueue(const int *items,int size):maxSize(size+10), currentSize(size)
    {
        array = new int[maxSize];
        for(int i = 0; i < size; i ++)
        {
            array[i+1] = items[i];
        }
        buildHeap();
    }
    ~priorityQueue(){delete [] array;}
    bool isEmpty() const
    {
        return currentSize == 0;
    }
    void enQueue(const int &x)
    {
        if(currentSize == maxSize - 1) doubleSpace();
        int hole  = ++currentSize;
        for(;hole > 1&&x<array[hole/2];hole/=2)
        {
            array[hole] = array[hole/2];
            array[hole/2] = x;
        }
    }
    int deQueue()
    {
        int minItem;
        minItem = array[1];
        array[1] = array[currentSize--];
        percolateDown(1);
        return minItem;
    }
    int getHead(){return array[1];}
};


int main() {
    
    return 0;
}
