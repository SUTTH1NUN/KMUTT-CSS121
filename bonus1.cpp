#include <iostream>
using namespace std;

struct Score {
    string name;
    int point;
};

class Node {
public:
    Score data;
    Node* next;
    Node* prev;
    
    Node(Score val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;
    
    bool isFull() const {
        return size > 10;
    }

    void removeLast() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        --size;
    }

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    void insert(const Score& val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = tail = newNode;
        } else if (newNode->data.point > head->data.point) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->data.point >= newNode->data.point) {
                temp = temp->next;
            }
            
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if (newNode->next) {
                newNode->next->prev = newNode;
            } else {
                tail = newNode;
            }
        }
        
        ++size;
        if (isFull()) removeLast();
    }
    
    void display() const {
        cout << "------------------------------" << endl;
        for (Node* temp = head; temp; temp = temp->next) {
            cout << temp->data.name << " " << temp->data.point << endl;
        }
    }
    
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList node;
    Score scores[11];
    
    for (int i = 0; i < 11; ++i) {
        cin >> scores[i].name >> scores[i].point;
        node.insert(scores[i]);
    }
    
    node.display();
    return 0;
}