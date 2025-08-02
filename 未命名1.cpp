#include<iostream>
using namespace std;

class Person
{
public:
	
	Person(int a,int b,int c):m_A(a), m_B(b), m_C(c)
	{
		
	}
		
	int m_A;
	int m_B;
	int m_C;
};

void teat01()
{
	Person p(30,20,10);
}

int main()
{
	return 0;
}
