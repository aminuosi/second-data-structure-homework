#include<iostream>
//#include<stack>
using namespace std;
#define MAXSIZE 100

struct Node
{
	char data;
};

class SqStack {
public:
	Node* base;
	Node* top;
	int stacksize;

	void Init(SqStack& s);
	int push(SqStack& s, char a);
	int pop(SqStack& s, char& a);
	int IsEmpty(SqStack s);
	void Destroy(SqStack& s);
	void Judgment(char m[], int n);
	char GetTop(SqStack& s);
};

void SqStack::Init(SqStack& s) 
{
	s.base = new Node;
	if (!s.base) exit(-1);
	s.top = s.base;
	s.stacksize = MAXSIZE;
}

int SqStack::push(SqStack& s, char a) 
{
	s.top->data = a;
	s.top = s.top++;
	return 1;
}

int SqStack::pop(SqStack& s, char& a)
{
	if (s.top == s.base) { return 0; }
	s.top--;
	a = s.top->data;
}

int SqStack::IsEmpty(SqStack s) 
{
	if (s.top == s.base) 
	{ 
		cout << "操作符合流程" << endl;
		return 1; 
	}
	else
	{ 
		cout << "操作不符合流程" << endl;
		return 0; 
	}
}

void SqStack::Destroy(SqStack& s) 
{
	if(s.base)
	    delete s.base;
}

 char SqStack::GetTop(SqStack& s) 
{
	if (s.top != s.base)
		return (s.top - 1)->data;
}

void SqStack::Judgment(char m[], int n) 
{
	SqStack sq;
	sq.Init(sq);
	char a;
	int f = 0;
	
	if(n%2 != 0)
	{
		cout << "不符合操作流程" << endl;
	}
	else 
	{
		for (int i = 0; i < n; i++) 
		{
			if (m[i] == 'i' || m[i] == 'I') 
			{
				push(sq, m[i]);
			}
			if (m[i] == 'o' || m[i] == 'O') 
			{
				a = GetTop(sq);
				if (a == 'i' || a == 'I') 
				{
					pop(sq, a);
				}
				else 
				{
					cout << "不符合操作流程" << endl;
					f++;
					break;
				}
			}
		}
		if (f == 0) { IsEmpty(sq); }
	}
	Destroy(sq);
}


int main() 
{
	char m[6] = { 'i','i','i','o','o','o' };
	SqStack sq;
	sq.Judgment(m, 6);
}