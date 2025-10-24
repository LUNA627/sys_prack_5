
#include <iostream>
#include <locale>
#include <unordered_set>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

   
    void push_back(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    
    void push_front(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }



    void pop_front() {
        if (head == nullptr) {
            cout << "Нет элемента для удаления" << endl;
            return;
        }


        Node* current = head;
        Node* next = current->next;
        delete current;
        head = next;

        if (head == nullptr) {
            tail = nullptr;
        }
        else {
            head->prev = nullptr;
        }
     }


    void pop_back() {
        if (tail == nullptr) {
         
            cout << "Нет элемента для удаления" << endl;
            return;
        }

        Node* current = tail;
        Node* prev = current->prev;
        delete current;
        tail = prev;
        
        if (tail == nullptr) {
            head = nullptr;
        }
        else {
            tail->next = nullptr;
        }
        
    }

    void display() {
        Node* current = head;

        if (current == nullptr) {
            cout << "Список пуст" << endl;
            return;
        }

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }



    void sort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        bool swapped;

        Node* end = nullptr;

        do {
            swapped = false;
            Node* current = head;

            while (current->next != end) {
                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
            end = current;
        } while (swapped);
    }



    void remove_duplicates() {
        
        if (head == nullptr) {
            return;
        }

        Node* current = head;
        while (current != nullptr) {

            Node* runNode = current;
            while (runNode->next != nullptr) {
                if (runNode->next->data == current->data) {
                    Node* deleteNode = runNode->next;
                    runNode->next = deleteNode->next;

                    if (deleteNode->next != nullptr) {
                        deleteNode->next->prev = runNode;
                    }
                    else {
                        tail = runNode;
                    }
                    delete deleteNode;
                }
                else {
                    runNode = runNode->next;
                }
            }

            current = current->next;
        }

       

    }

};



int main()
{
    setlocale(LC_ALL, "Russian");
    DoublyLinkedList list;
    int choise;
    int value;

   

    while (true) {
        cout << "\n===== МЕНЮ =====" << endl;
        cout << "1) Добавить элемент в начало" << endl;
        cout << "2) Добавить элемент в конец" << endl;
        cout << "3) Удалить элемент с начала" << endl;
        cout << "4) Удалить элемент с конца" << endl;
        cout << "5) Отобразить список" << endl;
        cout << "6) Сортировать список" << endl;
        cout << "7) Удалить дибликаты" << endl;
        cout << "8) Выйти" << endl;
       
        cout << "Введите пункт: " << endl;
        cin >> choise;



        switch (choise) {
            case 1:
                cout << "Введите значение: ";
                cin >> value;
                list.push_front(value);
                cout << "Элемент добавлен в начало" << endl;
                break;

            case 2:
                cout << "Введите значение: ";
                cin >> value;
                list.push_back(value);
                cout << "Элемент добавлен в конец" << endl;
                break;

            case 3:
                list.pop_front();
                cout << "Элемент удален с начала" << endl;
                break;

            case 4:
                list.pop_back();
                cout << "Элемент удален с конца" << endl;
                break;

            case 5:
                cout << "\n----- СПИСОК -----" << endl;
                list.display();
                break;
    
            case 6:
                cout << "\n----- ОТСОРТИРОВАННЫЙ СПИСОК -----" << endl;
                list.sort();
                list.display();
                break;
            
            case 7:
                list.remove_duplicates();
                cout << "Дубликаты удалены" << endl;
                cout << "\n----- СПИСОК -----" << endl;
                list.display();
                break;

            case 8:
                cout << "\n----- ВЫХОД -----" << endl;
                return 0;

            default:
                cout << "Неверный пункт" << endl;
                break;
        }
    }

    return 0;
}

