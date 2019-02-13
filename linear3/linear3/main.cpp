#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool Check(string equation)
{
	stack<char> s;
	for (int i = 0; i < equation.size(); ++i) {
		char ch = equation[i];
		switch (ch)
		{
		case '(':
			s.push(')');	//输入与ch匹配的字符
			break;
		case '[':
			s.push(']');
			break;
		case '{':
			s.push('}');
			break;
		default:
			if (s.empty() || s.top() != ch)	//方便利用与ch相等判断匹配
				return false;
			s.pop();
			break;
		}
	}
	return s.size() == 0;
}
int main()
{
	if (Check("[](})"))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}