#include <bits/stdc++.h>
using namespace std;
int categ(char t)
{
	if (t == '`')
		return -1;
	if (t >= '0' && t < '9')
		return 0;
	if (t == '+' || t == '-')
		return 1;
	if (t == '*' || t == '/')
		return 2;
	return 3;
}
string str(string s)
{
	stack<char> st;
	st.push('`');
	string fi = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (categ(s[i]) == 0)
		{
			fi.push_back('_');
			while (categ(s[i]) == 0)
			{
				fi.push_back(s[i++]);
			}
			i--;
			fi.push_back('_');
		}
		else if (categ(s[i]) == 1)
		{
			if (categ(st.top()) == 1 || categ(st.top()) == 2)
			{
				while (categ(st.top()) == 1 || categ(st.top()) == 2)
				{
					fi.push_back(st.top());
					st.pop();
				}
				st.push(s[i]);
			}
			else
				st.push(s[i]);
		}
		else if (categ(s[i]) == 2)
		{
			if (categ(st.top() <= 1 || st.top() == '('))
				st.push(s[i]);
			else if (categ(st.top()) == 2)
			{
				fi.push_back(st.top());
				st.pop();
				st.push(s[i]);
			}
			// else if(categ(st.top())==)
			// st.push(s[i]);
			// else
		}
		else if (s[i] == '(')
		{
			st.push('(');
		}
		else
		{
			while (st.top() != '(')
			{
				fi.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
	}
	while (st.size() != 1)
	{
		fi.push_back(st.top());
		st.pop();
	}
	return fi;
}
int main()
{
	// +-*/()
	// cout << "Enter the number of calcualation strings :";
	// int n;
	// cin >> n;
	// while (n--)
	// {
	string s;
	cin >> s;
	int num=0,a,b;
	s = str(s);
	// cout << s;
	stack<int> st;
	for(int i=0;i<s.length();i++)
	{
		if(categ(s[i])==0)
		{
			num=num*10+(s[i]-'0');
			continue;
		}
		
		else if(s[i]=='_')
		{
			if(num!=0)
			st.push(num);
			num=0;
		}else 
		{
			if(num!=0)
			st.push(num);
			a=st.top();
			st.pop();
			b=st.top();
			st.top()=(s[i]=='+')?(a+b):((s[i]=='-')?(b-a):((s[i]=='*')?(a*b):((s[i]=='/')?(b/a):0)));
		}

	}
	cout<<st.top();
	// }
	return 0;
}
