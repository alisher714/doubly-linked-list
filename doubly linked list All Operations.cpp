#include<iostream>
#include<conio.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;
Node *tail = NULL;

void insertAtStart(int val)
{
    Node *newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev =NULL;

    if(head==NULL && tail ==NULL)
    {
        tail = head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
        newnode->prev = NULL;
    }
}

void insertAtEnd(int val)
{
    Node *newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev =NULL;

    if(head==NULL && tail ==NULL)
    {
        tail = head = newnode;
    }
    else
    {
        newnode->next = NULL;
        newnode->prev = tail;
		tail->next = newnode;	
        tail = newnode;
        
    }
}

void insertAtSpecPos(int pos, int val)
{
    Node *newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev =NULL;

    if(head==NULL && tail ==NULL)
    {
        tail = head = newnode;
    }
    else
    {
    	Node *temp = head;
        for(int i=1; i<pos-1; i++)
        {
        	temp = temp->next;
		}
		temp->next->prev=newnode;
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next= newnode;
		
		
		
        
    }
}

void print()
{
    Node *temp = head;
    if(head == NULL)
    {
        cout<<"List is Empty..\n";
    }
    else
    {
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

}

void DelFromStart()
{
    if(head==NULL && tail ==NULL)
    {
        cout<<"list is empty";
    }
    else
    {
    	Node *temp = head;
    	head=head->next;
    	delete(temp);
    }
}

void DelFromEnd()
{
    if(head==NULL && tail ==NULL)
    {
        cout<<"list is empty";
    }
    else
    {
    	Node *temp = tail;
    	tail=tail->prev;
    	tail->next=NULL;
    	delete(temp);
    }
}

void DelFromSpecPos(int pos)
{
    if(head==NULL && tail ==NULL)
    {
        cout<<"list is empty";
    }
    else
    {
    	Node *temp = head;
    	Node *temp1 = new Node;
    	for(int i=1; i<pos-1; i++)
    	{
    		temp = temp->next;
		}
		temp1 = temp->next;
		temp->next = temp->next->next;
		temp->next->prev=temp;
    	delete(temp1);
    }
}

void search(int elem)
{
	int count=1;
	if (head == NULL)
	{
		cout << "list is empty\n";
	}
	else
	{
		Node *temp = head;
		while(temp->data != elem)
		{
			temp = temp->next;
			count++;
		}
		cout<<elem<<"is found at "<<count;
	}
}


int main()
{
	int choice, val, pos;
do_:
	cout << "1. insert at beginning\n";
	cout << "2. insert at ending\n";
	cout << "3. insert at a specific postion\n";
	cout << "4. display list\n";
	cout << "5. delete from end\n";
	cout << "6. delete from start\n";
	cout << "7. delete from specific position\n";
	cout << "8. search element\n";
	cout << "9. exit \n";
	cout << "ENTER YOUR CHOICE : \n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "enter value : ";
		cin >> val;
		insertAtStart(val);
		system("cls");
		break;

	case 2:
		cout << "enter value : ";
		cin >> val;
		insertAtEnd(val);
		system("cls");
		break;

	case 3:
		cout << "enter value : ";
		cin >> val;
		cout << "enter position : ";
		cin >> pos;
		insertAtSpecPos(pos,val);
		system("cls");
		break;

	case 4:
		print();
		getch();
		system("cls");
		break;

	case 5:
		DelFromEnd();
		system("cls");
		break;

	case 6:
		DelFromStart();
		system("cls");
		break;

	case 7:
		int del;
		cout << "enter position to be deleted : ";
		cin >> del;
		DelFromSpecPos(del);
		system("cls");
		break;

	case 8:
		int val;
		cout << "enter element to be search : ";
		cin >> val;
		search(val);
		getch();
		system("cls");
		break;

	case 9:
		exit(0);
		break;

	default:
		cout << "\nINVALID INPUT";
		break;
	}
	goto do_;
  return 0;
}
