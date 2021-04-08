//
//  main.cpp
//  BinaryHeapBasedPriorityQueue
//
//  Created by HAO LI on 4/7/21.
//

#include <iostream>

using namespace std;

int data[50];
int size = -1;

int leftChild(int i){
    return i * 2 + 1;
}

int rightChild(int i){
    return leftChild(i) + 1;
}

int parent(int i){
    return (i - 1) / 2;
}

void swapUp(int i){
    while(i > 0 && data[i] > data[parent(i)]){
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

void swapDown(int i){
    int maxIndex = i;
    int leftIndex = leftChild(i);
    if(leftIndex <= size && data[leftIndex] > data[maxIndex]){
        maxIndex = leftIndex;
    }
    
    int rightIndex = rightChild(i);
    if(rightIndex <= size && data[rightIndex] > data[maxIndex]){
        maxIndex = rightIndex;
    }
    
    if(i != maxIndex){
        swap(data[i], data[maxIndex]);
        swapDown(maxIndex);
    }
}

void insert(int p){
    size += 1;
    data[size] = p;
    swapUp(size);
    
}

int getMax(){
    if(size >= 0)
        return data[0];
    return NULL;
}

int popMax(){
    
    int root = data[0];
    data[0] = data[size];
    size -= 1;
    swapDown(0);
    return root;
}

void remove_element(int i){
    data[i] = getMax() + 1;
    swapUp(i);
    popMax();
    
}

void changePriority(int idx, int p){
    int oldP = data[idx];
    data[idx] = p;
    if(p > oldP){
        swapUp(idx);
    }
    else{
        swapDown(idx);
    }
}

int main(int argc, const char * argv[]) {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);
    
    for(int i = 0; i <= size; i++){
        cout << data[i] << " ";
    }
    cout << "\n";
    
    cout << "Popping max: " << popMax() << endl;
    
    cout << "Remove 4th item" << endl;
    remove_element(4);
    
    for(int i = 0; i <= size; i++){
        cout << data[i] << " ";
    }
    
    cout << "Changing priority: " <<endl;
    changePriority(4, 100);
    
    for(int i = 0; i <= size; i++){
        cout << data[i] << " ";
    }
    
    cout << "\n";
    
    cout << "-------------\n";
    
    while(size >= 0){
        cout << popMax()<< endl;
    }
    
}
