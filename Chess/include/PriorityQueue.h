#pragma once
#include <stdexcept>

template <typename T, typename Comparator>
class PriorityQueue {
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& val);
    };

    Node* head;
    Comparator comp;

public:
    PriorityQueue();
    ~PriorityQueue();

    void push(const T& value);
    T poll();
    bool isEmpty() const;
};
