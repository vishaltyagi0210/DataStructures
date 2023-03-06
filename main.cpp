#include"List.cpp"

int main()
{
    SLL<char> a;
    a.insertatEnd('a');
    a.insertatEnd('v');
    a.insertatEnd('g');
    a.insertAtBeg('n');
    a.insertAfter(a.search('g'),'b');
    a.insertatEnd('c');
    a.show();
}