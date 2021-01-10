#include <iostream>
using namespace std;
#include "PQType.h"

int main() {
    int N, M;
    int** orderList = nullptr;
    
    cin >> N >> M;
    orderList = new int* [M];
    for(int i = 0; i < M; i++){
        orderList[i] = new int[2];
        cin >> orderList[i][0] >> orderList[i][1];
    }
    
    // Input
    PQType<int> pqueue;
    for(int i = 0; i < N; i++){
        pqueue.Enqueue(N-i, i+1);// (priority, question number)
    }

    // Ordering
    // TODO1 : write PQ.Ordering function 
    pqueue.Ordering(orderList, M);
    
    // Print
	int priority = N;
    while (!pqueue.IsEmpty()) {
        int tempItem;
        pqueue.Dequeue(tempItem, N);
        cout << tempItem << ' ';
		N--;
    }
    return 0;
}
