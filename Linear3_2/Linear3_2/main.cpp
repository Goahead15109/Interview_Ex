#include<iostream>
#include<string>

using namespace std;

bool Check(string equation)
{
	while (equation.find("()")!= string::npos ||
			equation.find("[]")!=string::npos ||
			equation.find("{}")!=string::npos)
	{
		equation.erase("()");
	}
}
int main()
{
	if (Check("[](})"))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}