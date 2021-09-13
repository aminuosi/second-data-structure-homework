#include<iostream>
using namespace std;
//#define MAXSIZE 100

struct Node 
{
	char data;
	Node* next;
};

class SqStack 
{
private:
	Node* temp;
	Node* top;
	//int stacksize;
public:
	void Init();
	int push(char a);
	int pop(char& a);
	int IsEmpty();
	void Destroy();
	void Judgment(char m[], int n);
	char GetTop();
};

void SqStack::Init() 
{
	temp = new Node;
	if (!temp) exit(-1);
	temp = NULL;
	top = temp;
	//stacksize = MAXSIZE;
}

int SqStack::push(char a) 
{
	top = new Node;
	top->data = a;
	top->next = temp;
	temp = top;
	return 1;
}

int SqStack::pop(char& a) 
{
	if (top == NULL) return false;
	a = top->data;
	temp = top;
	top = top->next;
	delete temp;
	temp = top;
	return 1;
}

int SqStack::IsEmpty() 
{
	if (top == NULL)
	{
		cout << "������������" << endl;
		return 1;
	}
	else
	{
		cout << "��������������" << endl;
		return 0;
	}
}

//void SqStack::Destroy() 
//{
//	if (top->next == NULL) exit(-1);
//	while (top->next != NULL) 
//	{
//		temp = top;
//		top = top->next;
//		delete temp;
//	}
//}

void SqStack::Judgment(char m[], int n) 
{
	SqStack sq;
	sq.Init();
	char a;
	int f = 0;

	if (n % 2 != 0)
	{
		cout << "�����ϲ�������" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (m[i] == 'i' || m[i] == 'I')
			{
				push(m[i]);
			}
			if (m[i] == 'o' || m[i] == 'O')
			{
				a = GetTop();
				if (a == 'i' || a == 'I')
				{
					pop(a);
				}
				else
				{
					cout << "�����ϲ�������" << endl;
					f++;
					break;
				}
			}
		}
		if (f == 0) { IsEmpty(); }
	}
	//Destroy();
}


char SqStack::GetTop() 
{
	if (top != NULL)
		return top->data;
}


int main()
{
	char m[6] = { 'i','i','i','o','o','o' };
	SqStack sq;
	sq.Judgment(m, 6);
}