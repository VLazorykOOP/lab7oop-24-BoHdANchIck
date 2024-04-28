#include <iostream>
using namespace std;

template <class T, int capacity>
class CircularQueue {
private:
    T* arr; 
    int front; 
    int rear; 
    int currentSize; 

public:
    CircularQueue() {
        arr = new T[capacity];
        front = rear = -1;
        currentSize = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == capacity;
    }

    void enqueue(T element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue more elements.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = element;
        currentSize++;
    }

  
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity; 
        }
        currentSize--;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No elements to peek.\n";
            exit(1);
        }
        return arr[front];
    }
};

int main() {
    CircularQueue<int, 5> queue;

    queue.enqueue(11);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.enqueue(6);

    cout << "Front element after dequeue and enqueue: " << queue.peek() << endl;

    return 0;
}
