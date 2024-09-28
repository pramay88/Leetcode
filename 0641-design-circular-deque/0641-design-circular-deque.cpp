class MyCircularDeque {
    int front, back;
    int size, capacity;
    int *arr;
public:
    MyCircularDeque(int k) {
        arr = new int[k];
        front = 0;
        back = k-1;
        capacity = k;
        size = 0;
    }
    bool insertFront(int value) {
        if (size == capacity) {
            return false;
        }
        arr[front] = value;
        front = (front + 1) % capacity;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (size == capacity) {
            return false;
        }
        arr[back] = value;
        back = (back - 1 + capacity) % capacity;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        back = (back + 1) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if (size == 0) {
            return -1;
        }
        return arr[(front - 1 + capacity) % capacity];
    }
    
    int getRear() {
        if (size == 0) {
            return -1;
        }
        return arr[(back + 1) % capacity];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
    ~MyCircularDeque() {
        delete[] arr;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */