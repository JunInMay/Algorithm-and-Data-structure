#include <iostream>

using namespace std;

class Node {
private:
    Node* next;
    Node* before;
    int value;

public:
    Node(int v) : next(nullptr), before(nullptr), value(v) {}

    Node(int value, Node* before, Node* next) : value(value), next(next), before(before) {}

    void set_next(Node* next) {
        this->next = next;
    }

    void set_before(Node* before) {
        this->before = before;
    }

    Node* get_next() {
        return this->next;
    }

    Node* get_before() {
        return this->before;
    }

    int get_value() {
        return this->value;
    }
};

class LinkedList {
private:
    Node* first;
    int size;
public:
    LinkedList() : first(nullptr), size(0) {}

    int get_size() {
        return this->size;
    }

    int get(int idx) {
        Node* now = this->first;
        if (!(idx < this->size)) {
            cout << "잘못된 값을 참조하였습니다." << endl;
            return NULL;
        }
        for (int i = 0; i < idx; i++) {
            now = now->get_next();
        }

        return now->get_value();
    }

    Node* get_node(int idx) {
        if (!(idx < this->size)) {
            cout << "잘못된 값을 참조하였습니다." << endl;
            return NULL;
        }

        Node* now = this->first;
        for (int i = 0; i < idx; i++) {
            now = now->get_next();
        }

        return now;
    }

    void remove(int idx) {
        Node* now = get_node(idx);
        Node* before = now->get_before();
        Node* next = now->get_next();

        if (before != nullptr && next != nullptr) {
            before->set_next(next);
            next->set_before(before);
        }
        else if (before != nullptr && next == nullptr) {
            before->set_next(nullptr);
        }
        else if (before == nullptr && next != nullptr) {
            next->set_before(nullptr);
        }
        free(now);

        this->size--;
    }

    void add_last(int v) {
        if (this->first == nullptr) {
            this->first = new Node(v);
        }
        else {
            Node* now = this->first;
            Node* target = new Node(v);
            while (true) {
                if (now->get_next() == nullptr) {
                    target->set_before(now);
                    now->set_next(target);
                    break;
                }
                now = now->get_next();
            }
        }

        this->size++;
    }

    void add_first(int v) {
        Node* target = new Node(v);
        if (this->first == nullptr) {
            this->first = target;
        }
        else {
            Node* now = this->first;
            target->set_next(now);
            now->set_before(target);
            this->first = target;
        }

        this->size++;
    }
};


int main() {
    LinkedList li;

    li.add_last(1);
    li.add_last(2);
    li.add_last(3);
    li.add_last(4);

    cout << li.get(1) << '\n';
    li.remove(1);
    cout << li.get(1) << '\n';

    li.add_first(10);

    for (int i = 0; i < li.get_size(); i++) {
        cout << i << " : " << li.get(i) << '\n';
    }
}