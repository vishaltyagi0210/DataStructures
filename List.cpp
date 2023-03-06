#include<iostream>
using namespace std;

template<typename X>
struct node
{
    node* next;
    X item;
};

template<typename X>
class SLL
{
    private:
        node<X>* start;
    public: 
        SLL();
        void insertatEnd(X data);
        void insertAtBeg(X data);
        node<X>* search(X data);
        void insertAfter(node<X>* , X data);
        
        bool isEmpty();
        void show();
};

template<typename X>
SLL<X>::SLL()
{
    start = nullptr;
}

template<typename X>
void SLL<X>::insertatEnd(X data)
{
    node<X>* n = new node<X>;
    n->item = data;
    if(isEmpty())
    {
        n->next = start;
        start = n;
        return;
    }
    node<X>* temp = start;
    while(temp->next != nullptr)
        temp = temp->next;
    n->next = temp->next;
    temp->next = n;
}

template<typename X>
void SLL<X>::insertAtBeg(X data)
{
    node<X>* n = new node<X>;
    n->item = data;
    n->next = start;
    start = n;
}

template<typename X>
void SLL<X>::show()
{
    node<X>* temp = start;
    while(temp)
    {
        cout<<"--|"<<temp->item<<"|--";
        temp=temp->next;
    }
    cout<<endl;
}

template<typename X>
node<X>* SLL<X>::search(X data)
{
    node<X>* temp = start;
    while(temp)
    {
        if(temp->item == data)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

template<typename X>
void SLL<X>::insertAfter(node<X>* ptr , X data)
{
    if(ptr)
    {
        node<X>* n = new node<X>();
        n->item = data;
        n->next = ptr->next;
        ptr->next = n;
    }
}

template<typename X>bool SLL<X>::isEmpty()
{
    return start==nullptr;
}
