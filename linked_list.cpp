#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

typedef struct node //construct a list
{
	string name;
	int age;
	struct node* next;
}student;
void display(student* );
student* create_list(int n);
int main()
{
int n =5;
student* a = create_list(n);
display(a);


return 0;
}

student* create_list(int n)
{
	student* head = new student; //store head in stack so that it can exist during the entire procedure
	student* pre = head;
	for (int i = 0; i < n; i++ )
	{
	
	student*p = new student;
	cout<<"please input name and age: "<<endl;
	cin>>p->name;
	cin>>p->age;
	pre->next = p;
	pre = p;
	p->next =NULL;
	}
	return head;		
}

void display(student* head)
{	
	student*p = head->next;
	while(p!=NULL)
	{
		cout<<p->name<<", "<<p->age<<endl;
		p = p->next;
	}
}
