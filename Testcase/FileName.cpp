#include <iostream>
#include <string>
#include <stack>
using namespace std;

int Uutien(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}

int TinhToan(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}

int evaluate(string s) {
	int i;

	stack <int> rs;


	stack <char> ops;

	for (i = 0; i < s.length(); i++) {

		if (isdigit(s[i])) {
			int val = 0;
			while (i < s.length() && isdigit(s[i]))
			{
				val = (val * 10) + (s[i] - '0');
				i++;
			}
			rs.push(val);
			i--;
		}
		else if (s[i] == ' ') continue;
		else if (s[i] == '(') {
			ops.push(s[i]);
		}
		else if (s[i] == ')')
		{
			while (!ops.empty() && ops.top() != '(')
			{
				int val2 = rs.top();
				rs.pop();

				int val1 = rs.top();
				rs.pop();

				char op = ops.top();
				ops.pop();

				rs.push(TinhToan(val1, val2, op));
			}
			if (!ops.empty())
				ops.pop();
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			while (!ops.empty() && Uutien(ops.top()) >= Uutien(s[i])) {
				int val2 = rs.top();
				rs.pop();

				int val1 = rs.top();
				rs.pop();

				char op = ops.top();
				ops.pop();

				rs.push(TinhToan(val1, val2, op));
			}

			ops.push(s[i]);
		}
		else {
			ops.push(s[i]);
		}
	}

	while (!ops.empty()) {
		int val2 = rs.top();
		rs.pop();

		int val1 = rs.top();
		rs.pop();

		char op = ops.top();
		ops.pop();

		rs.push(TinhToan(val1, val2, op));
	}

	return rs.top();
}

int main() {
	string s;
	getline(cin, s);
	int rs = evaluate(s);
	cout << rs;


	return 0;
}