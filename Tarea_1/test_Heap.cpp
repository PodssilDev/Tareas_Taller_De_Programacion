#include "Heap.h"
#include <stdlib.h>
#include <time.h>

/*
Test para probar la HEAP, se prueban las siguientes funciones publicas:
Heap
isEmpty
insert
pull
peek
getSize
print
*/
int main() {
    int n=20;
    srand(time(NULL));
    Heap h(n);
    cout << "Heap size: " << h.getSize() <<endl; // TEST GETSIZE
    // inserting random numbers
    for(int i = 0; i < n; i++) {
        int val=rand()%n;
        Node *node = new Node(i, i, val, NULL);
        cout<<"inserting "<<val<<endl;
        h.insert(node); // TEST INSERT
        delete node;
    }

    // printing heap
    cout << "The Heap" <<endl;
    h.print(); // TEST PRINT
    cout << "Peek: " << h.peek()<< endl; // TEST PEEK
    // extraccting all element from heap, shoud all appears in order
    cout << "Ordered number:" << endl;
    for(int i=0;i<n; i++){
        Node *node = h.pull(); // TEST PULL
        cout<<"pulling "<<node->getValue()<<endl;
    }
    if(h.isEmpty()){ // TEST ISEMPTY
        cout << "Heap is empty!";
    }

    cout << "\n";
    return 0;
 }
 