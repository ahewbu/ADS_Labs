#include <iostream>
#include <algorithm>
#include <string>


using namespace std;


class List {
    struct Node {
        int value;
        Node* next;
        Node(int _val) : value(_val), next(nullptr) {}
        Node() : value(0), next(nullptr) {}
    };

    Node* first;
    Node* last;
public:
    List() : first(nullptr), last(nullptr) {}
    List(const List& list) {
        first = nullptr;
        last = nullptr;
        if (list.first == NULL) {
            first = last = NULL;
            return;
        }
        Node* temp = list.first;
        while (temp != NULL) {
            Node* newNode = new Node(temp->value);

            if (first == NULL) {
                first = newNode;
                last = newNode;
            }
            else {
                last->next = newNode;
                last = newNode;
            }
            temp = temp->next;
        }
    }
    List(size_t count) {
        for (size_t i = 0; i < count; i++) {
            push_tail(rand() % 10);
        }
    }
    ~List() {
        remove_all();
    }

    bool is_empty() {
        return first == nullptr;
    }

    void push_front(int _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        p->next = first;
        first = p;
    }

    void push_tail(int _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void push_list_front(List& l) {
        List temp(l);
        Node* p = first;
        while (p) {
            temp.push_tail(p->value);
            p = p->next;
        }
        *this = temp;
    }

    void push_list_tail(List& l) {
        List temp(*this);
        Node* p = l.first;
        while (p) {
            temp.push_tail(p->value);
            p = p->next;
        }
        *this = temp;
    }