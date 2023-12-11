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

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }

    void pop_head() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void pop_tail() {
        if (is_empty()) return;
        if (first == last) {
            pop_head();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void delete_node(int _val) {
        if (is_empty()) return;
        if (first->value == _val && first->next == NULL) {
            pop_head();
            return;
        }
        else if (first->value == last->value && first->value == _val) {
            pop_head();
            pop_head();
            return;
        }
        else if (last->value == _val && first->next == last) {
            pop_tail();
            return;
        }
        removeDuplicates(_val);
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->value != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }
    void remove_all() {
        if (is_empty()) return;
        while (!is_empty()) {
            pop_head();
        }
        last = nullptr;
    }

    void removeDuplicates(int val)
    {
        struct Node* ptr1, * ptr2, * dup;
        ptr1 = first;
        while (ptr1 != NULL && ptr1->next != NULL) {
            ptr2 = ptr1;
            while (ptr2->next != NULL) {
                if (ptr1->value == ptr2->next->value && ptr2->next->value == val) {
                    dup = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete (dup);
                }
                else
                    ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }

    string get_number() {
        string str;
        Node* p = first;
        while (p) {
            str = str + to_string(p->value);
            p = p->next;
        }
        return str;
    }

    Node* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }

    List& operator=(List& l) {
        List temp(l);
        swap(temp.first, first);
        swap(temp.last, last);
        return *this;
    }

    friend std::ostream& operator << (std::ostream& out, const List& list)
    {
        Node* p = list.first;
        while (p) {
            out << p->value;
            p = p->next;
        }
        return out;
    }
};