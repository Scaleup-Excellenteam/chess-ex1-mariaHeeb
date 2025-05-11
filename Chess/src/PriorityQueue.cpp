#include "PriorityQueue.h"

// Node constructor
template <typename T, typename Comparator>
PriorityQueue<T, Comparator>::Node::Node(const T& val) : value(val), next(nullptr) {}

// Constructor
template <typename T, typename Comparator>
PriorityQueue<T, Comparator>::PriorityQueue() : head(nullptr) {}

// Destructor
template <typename T, typename Comparator>
PriorityQueue<T, Comparator>::~PriorityQueue() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Push method
template <typename T, typename Comparator>
void PriorityQueue<T, Comparator>::push(const T& value) {
    Node* newNode = new Node(value);

    if (!head || comp(value, head->value) > 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next && comp(value, current->next->value) <= 0) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Poll method
template <typename T, typename Comparator>
T PriorityQueue<T, Comparator>::poll() {
    if (!head) {
        throw std::runtime_error("Polling from empty PriorityQueue");
    }

    Node* temp = head;
    T val = head->value;
    head = head->next;
    delete temp;
    return val;
}

// isEmpty method
template <typename T, typename Comparator>
bool PriorityQueue<T, Comparator>::isEmpty() const {
    return head == nullptr;
}

// Explicit template instantiation if required
// template class PriorityQueue<int, IntComparator>;
