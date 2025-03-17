#include <iostream>

using namespace std;

class Node{
    public:
        int number;
        int exponent;
        Node* next;

        Node(int num, int expo){
            number = num;
            exponent = expo;
            next = nullptr;
        }
};

class Poly{
    private:
        Node* head;
    public:
        Poly(){
            head = nullptr;
        }

        void insert(int num, int expo){
            Node* newnode = new Node(num, expo);
            if(!head || head -> exponent > expo){
                newnode -> next = head;
                head = newnode;
            }else{
                Node* temp = head;
                while(temp -> next && temp -> next -> exponent > expo){
                    temp = temp -> next;
                }
                    if(temp -> next && temp -> next -> exponent == expo){
                        temp -> next -> number += num;
                    if(temp -> next -> number == 0){
                        Node* Delete = temp -> next;
                        temp -> next = temp -> next -> next;
                        delete Delete;
                    }
                    delete newnode;
                }else{
                    newnode -> next = temp -> next;
                    temp -> next = newnode;
                }
            }
        }
            Poly add(Poly& other){
                Poly result;
                Node* p1 = head;
                Node* p2 = other.head;
                while(p1 || p2){
                    if(p1 && (!p2 || p1 -> exponent > p2 -> exponent)){
                        result.insert(p1 -> number, p1 -> exponent);
                        p1 = p1 -> next;
                    }else if(p2 && (!p1 || p2 -> exponent > p1 -> exponent)){
                        result.insert(p2 -> number, p2 -> exponent);
                        p2 = p2 -> next;
                    }else{
                        int sumnum = p1 -> number + p2 -> number;
                        if(sumnum != 0){
                            result.insert(sumnum, p1 -> exponent);
                        }
                        p1 = p1 -> next;
                        p2 = p2 -> next;
                    }
                }
                return result;
            }

            Poly multi(Poly& other){
                Poly result;
                for(Node* p1 = head; p1; p1 = p1 -> next){
                    for(Node*p2 = other.head; p2; p2 = p2 -> next){
                        result.insert(p1 -> number * p2 -> number, p1 -> exponent + p2 -> exponent);
                    }
                }
                return result;
            }

            void Pprint(){
                if(!head){
                    cout << "0";
                    return;
                }
                Node* temp = head;
                while(temp){
                    if(temp != head && temp -> number > 0){
                        cout << "+";
                    }
                    cout << temp -> number << "x^" << temp -> exponent;
                    temp = temp -> next;
                }
                cout << endl;
            }
};

int main() {
    Poly p1, p2;
    p1.insert(3, 3);
    p1.insert(4, 2);
    p1.insert(2, 1);
    
    p2.insert(5, 2);
    p2.insert(1, 1);

    cout << "Polynomial 1: ";
    p1.Pprint();
    
    cout << "Polynomial 2: ";
    p2.Pprint();

    Poly sum1 = p1.add(p2);
    cout << "sum1 = ";
    sum1.Pprint();

    Poly sum2 = p1.multi(p2);
    cout << "sum2 = ";
    sum2.Pprint();

    return 0;
}