#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;

        if (head == NULL) {
            cout << "Linked List is Empty!" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void Search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Element not found!" << endl;
    }

    void Delete_node(int key) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == key) {
            Node* del = head;
            head = head->next;
            delete del;
            cout << "Node deleted successfully!" << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Node not found!" << endl;
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        cout << "Node deleted successfully!" << endl;
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        cout << "Linked List Reversed Successfully!" << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n===== LINKED LIST CRUD MENU =====\n";
        cout << "1. Append Node\n";
        cout << "2. Insert At Beginning\n";
        cout << "3. Display List\n";
        cout << "4. Search Node\n";
        cout << "5. Delete Node\n";
        cout << "6. Reverse List\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            list.append(value);
            break;

        case 2:
            cout << "Enter Value: ";
            cin >> value;
            list.insert_at_beginning(value);
            break;

        case 3:
            list.display();
            break;

        case 4:
            cout << "Enter Value To Search: ";
            cin >> value;
            list.Search(value);
            break;

        case 5:
            cout << "Enter Value To Delete: ";
            cin >> value;
            list.Delete_node(value);
            break;

        case 6:
            list.reverse();
            break;

        case 0:
            cout << "Program Ended!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
