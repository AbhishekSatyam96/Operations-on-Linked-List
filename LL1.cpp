#include<iostream>				//By Abhishek satyam 11508206 PST
#include<fstream>
#include<stdlib.h>				//for clear the screen
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	Node()
	{
		data=0;
		next=NULL;
	}
};
class LinkedList{
	Node *head,*tail;
public:
	LinkedList()
	{
		head=NULL;
		tail=NULL;
	}
	void add_first(int value)
	{
		Node *temp=new Node;
		temp->data=value;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else
		{
			temp->next=head;
			head=temp;
		}
	}
	void sort()
	{
		Node *prev=new Node;
		Node *curr=new Node;
		Node *temp=new Node;
		curr=head;
		for(curr;curr!=NULL;prev=curr,curr=curr->next)
		{
				if(prev->data>curr->data)
				{
					temp->data=prev->data;
					prev->data=curr->data;
					curr->data=temp->data;
				}
		}
	}
	void add_last(int value)
	{
		Node *temp=new Node();
		temp->data=value;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}
	void add_pos(int pos,int value)
	{
		Node *prev=new Node;
		Node *curr=new Node;
		Node *temp=new Node;
		curr=head;
		for(int i=1;i<pos;i++)
		{
			prev=curr;
			curr=curr->next;
		}
		temp->data=value;
		prev->next=temp;
		temp->next=curr;
	}
	void del_first()
	{
		if(head==NULL)	cout<<"There is nothing to remove"<<endl;
		Node *temp=new Node;
		temp=head;
		head=head->next;
		cout<<"Deleted"<<endl;
		delete temp;
	}
	void del_last()
	{
		Node *curr=new Node;
		Node *prev=new Node;
		for(curr=head;curr->next!=NULL;prev=curr,curr=curr->next);
		tail=prev;
		prev->next=NULL;
		delete curr;
	}
	void del_pos(int pos)
	{	
		Node *prev=new Node;
		Node *curr=new Node;
		Node *temp=new Node;
		curr=head;
		for(int i=1;i<pos;i++)
		{
			prev=curr;
			curr=curr->next;
		}
		temp=curr;
		prev->next=curr->next;
		delete temp;
	}
	void del_value(int value)
	{
		int i=0;
		Node *ptr=new Node;
		for(ptr=head;ptr!=NULL;ptr=ptr->next)
		{
			i++;
			if(ptr->data==value)
			{
				del_pos(i);	break;
			}
		}
	}
	void display()
	{
		if(head==NULL)	cout<<"Linked list is empty";
		Node *ptr;
		cout<<"Displaying..."<<endl;
		for(ptr=head;ptr!=NULL;ptr=ptr->next)
			cout<<ptr->data<<"\t";
	}
	void store()
	{
		ofstream ofs;
		ofs.open("rar.txt");
		for(Node *ptr=head;ptr!=NULL;ptr=ptr->next)
		{
			ofs<<ptr->data<<"\t";
		}
	}
	void load()
	{
		ifstream ifs;
		char ch;
		ifs.open("rar.txt");
		ch=ifs.get();
		while(!ifs.eof())
		{
			cout<<ch;
			ch=ifs.get();
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	system("color 2E");
	int s;
	LinkedList ll;
	cout<<"--------------Welcome to the Linked List World-----------------"<<endl;
s:	cout<<"1 :For Adding value"<<endl;
	cout<<"2 :For Deleting value"<<endl;
	cout<<"3 :Display value"<<endl;
	cout<<"4 :Store value"<<endl;
	cout<<"5 :Load value from the file"<<endl;
	cout<<"6 :Sort the value"<<endl;
	cout<<"0 :Exit"<<endl;
	int choice,k,l,m,r;
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			cout<<"1 :Inserting value at end"<<endl;
			cout<<"2 :Inserting value at any specefic position"<<endl;
			cout<<"3 :Insert value at the first"<<endl;
			cout<<"4 :Back"<<endl;
			cin>>k;
			if(k==1)
			{	system("cls");
				cout<<"Give a value to insert at end=";	cin>>l;
				ll.add_last(l);
				cout<<l<<" is inserted succesfully in the list"<<endl;
			}
			else if(k==2)
			{	system("cls");
				cout<<"Which position you have to enter value?=";	cin>>m;
				cout<<"Enter the value you want to enter=";	cin>>r;
				ll.add_pos(m,r);
			}
			else if(k==3)
			{	system("cls");
				cout<<"Enter a value that you want to insert at begining=";	cin>>m;
				ll.add_first(m);
			}
			else if(k=4)	goto s;
			else
			{	system("cls");
				cout<<"Invalid choice"<<endl;
				goto s;
			}
			goto s;
		case 2:
			system("cls");
			cout<<"1 :Delete at first"<<endl;
			cout<<"2 :Delete at last"<<endl;
			cout<<"3 :Delete at specific position"<<endl;
			cout<<"4 :Delete a particular value"<<endl;
			cout<<"5 :Back"<<endl;
			int p,po,v;
			cin>>p;
			switch(p)
			{
				case 1:
					ll.del_first();	break;
				case 2:
					ll.del_last();	break;
				case 3:
					cout<<"Enter a position to  delete="<<endl;	cin>>po;
					ll.del_pos(po);	break;
				case 4:
					cout<<"Enter a value to delete="<<endl;	cin>>v;
					ll.del_value(v);	break;
				case 5:
					goto s;
				default:
					cout<<"Enter a valid choice"<<endl;
				goto s;
			}
		case 3:
			system("cls");
			ll.display();	
			cout<<endl;
			goto s;
		case 4:
			ll.store();	
			cout<<"Value stored in file"<<endl;
			goto s;
		case 5:
			ll.load();	cout<<endl;	goto s;
		case 6:
			ll.sort();
			cout<<"Values are sorted succesfully"<<endl;	goto s;
		case 0:
			exit(0);
		default:
			cout<<"Enter a valid choice"<<endl;
			goto s;
	}
}
