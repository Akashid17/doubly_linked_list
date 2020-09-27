///////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :    DoublyLL
//  Input :         -
//  Output :        -
//  Description :   Class is of Doubly Linear Linkedlist
//  Author :        Akash Ankush Kashid
//  Date :          27 Sep 2020
//
///////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

typedef struct DLL
{
    int data;
    struct DLL *next;
    struct DLL *prev;
} DLNODE, *DPNODE;

class DoublyLL
{
private:
    DPNODE Head;
    int size;

public:
    DoublyLL();
    ~DoublyLL();
    void InsertFirst(int);
    void InsertLast(int);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int, int);
    void DeleteAtPos(int);
    void Display();
    void DisplayX();
    int Count();
};

DoublyLL::DoublyLL()
{
    Head = NULL;
    size = 0;
}
DoublyLL::~DoublyLL()
{
}

void DoublyLL::Display()
{
    DPNODE temp = Head;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |";
        temp = temp->next;
    }
    cout << "\n";
}

void DoublyLL::DisplayX()
{
    DPNODE temp = Head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |";
        temp = temp->prev;
    }
    cout << "\n";
}

int DoublyLL::Count()
{
    return size;
}

void DoublyLL::InsertFirst(int iNo)
{
    DPNODE newn = new DLNODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    size++;
}

void DoublyLL::InsertLast(int iNo)
{
    DPNODE newn = new DLNODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        DPNODE temp = Head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    size++;
}

void DoublyLL::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    if (Head->next == NULL)
    {
        delete (Head);
        Head = NULL;
    }
    else
    {
        Head = Head->next;
        delete (Head->prev);
        Head->prev = NULL;
    }
    size--;
}

void DoublyLL::DeleteLast()
{
    if (Head == NULL)
    {
        return;
    }
    if (Head->next == NULL)
    {
        delete (Head);
        Head = NULL;
    }
    else
    {
        DPNODE temp = Head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
    size--;
}

void DoublyLL::InsertAtPos(int iNo, int iPos)
{
    if (Head == NULL)
    {
        return;
    }
    if ((iPos < 1) || (iPos > size + 1))
    {
        return;
    }
    else if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == size + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        DPNODE newn = new DLNODE;
        DPNODE temp = Head;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iPos++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        size++;
    }
}

void DoublyLL::DeleteAtPos(int iPos)
{
    if (Head == NULL)
    {
        return;
    }
    if ((iPos < 1) || (iPos > size))
    {
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == size)
    {
        DeleteLast();
    }
    else
    {
        DPNODE temp = Head;

        for (int iCnt = 1; iCnt < iPos - 1; iPos++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;

        size--;
    }
}

int main()
{

    int iChoice = 1;
    int iValue = 0, iPlace = 0;

    DoublyLL dobj;

    for (int iCnt = 1; iCnt <= 10; iCnt++)
    {
        iValue = iCnt * 10;
        dobj.InsertLast(iValue);
    }
    dobj.Display();

    while (iChoice)
    {
        cout << "Enter Your Choice\n";
        cout << "1: To InsertFirst\n";
        cout << "2: To InsertLast\n";
        cout << "3: To InsertAtPos\n";
        cout << "4: To DeleteFirst\n";
        cout << "5: To DeleteLast\n";
        cout << "6: To DeleteAtPos\n";
        cout << "7: To Display Likedlist\n";
        cout << "8: To Display In Reverse Order\n";
        cout << "9: To See To Count of Element\n";
        cout << "0: To Exit\n";

        cin >> iChoice;

        switch (iChoice)
        {

            case 1:
                cout << "Enter Number to Insert\n";
                cin >> iValue;
                dobj.InsertFirst(iValue);
                dobj.Display();
                break;

            case 2:
                cout << "Enter Number to Insert\n";
                cin >> iValue;
                dobj.InsertLast(iValue);
                dobj.Display();
                break;

            case 3:
                cout << "Enter Number to Insert\n";
                cin >> iValue;
                cout << "Enter Position to Insert Number\n";
                cin >> iPlace;
                dobj.InsertAtPos(iValue, iPlace);
                dobj.Display();
                break;

            case 4:
                dobj.DeleteFirst();
                dobj.Display();
                break;

            case 5:
                dobj.DeleteLast();
                dobj.Display();
                break;

            case 6:
                cout << "Enter Position to Delete Number\n";
                cin >> iPlace;
                dobj.DeleteAtPos(iPlace);
                dobj.Display();
                break;

            case 7:
                cout << "All Element : \n";
                dobj.Display();
                break;

            case 8:
                cout << "All Elements in Reverse order\n";
                dobj.DisplayX();
                break;

            case 9:
                cout << "Count of Element is : " << dobj.Count() << "\n";
                break;

            case 0:
                cout << "Thank You For Using Application\n";
                break;

            default:
                cout << "Wrong Choice\n";
            break;
        }
    }

    return 0;
}
