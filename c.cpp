#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class llist {
    private:
    Node *head, *tail;
    public:
    llist() {
        head = NULL;
        tail = NULL;
    }

    void add(int n) {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail = tmp->next;
            tail = tail->next;
        }
    }

    Node *delFirstNode() {
        if(head == NULL) {
            return NULL;
        }
        Node *tmp = head;
        head = tmp->next;
        delete tmp;
    }

    Node *delNthNode(int n) {
        Node *h = head;
        Node *p = NULL;

        if(n <= 1) {
            return NULL;
        }
        else {
            while(h->next != NULL && h->data != n) {
                p = h;
                h = h->next;
                if(h->data == n) {
                    p->next = h->next;
                }
            }
            delete h;
        }
    }

    void display() {
        Node *tmp = head;
        while(tmp != NULL) {
            cout << tmp->data <<"\n";
            tmp = tmp->next;
        }
        cout << "NULL";
    }
};

class Solution {
    public:
    void deleteNode(Node *node) {
        node->data = node->next->data;
        node->next = node->next->next;
    } 
};

int main() {
    llist a;
    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);
    a.delFirstNode();
    a.delNthNode(4);
    a.display();
}
