#pragma warning(disable:4996)

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>

using namespace std;

class classStack {

private:
	stack<string> mystack;

	bool isOperator(string& opr) {
		if (opr.length() == 1) {
			string op = "+-/*";
			if (op.find(opr) != std::string::npos) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	bool isNumber(string& number) {
		if (number.length() > 0) {
			for (int i = 0; i < number.length(); i++) {
				if (!isdigit(number.at(i))) {
					return false;
				}
			}

			return true;
		} else {
			return false;
		}
	}

	void evaluate(stack<string>& stck) {
		string op = stck.top();
		stck.pop();
		string value1 = stck.top(); stck.pop();
		string value2 = stck.top(); stck.pop();
		double val1 = atoi(value1.c_str());
		double  val2 = atoi(value2.c_str());
		double result = 0;

		if (op.compare("+") == 0)
			result = val1 + val2;
		else if (op.compare("-") == 0)
			result = val2 - val1;
		else if (op.compare("*") == 0)
			result = val1 * val2;
		else if (op.compare("/") == 0)
			result = val2 / val1;

		char buffer[10];

		sprintf(buffer, "%lf", result);

		stck.push(string(buffer));
	}

public:
	void push(string& str) {

		string temp;
		if (mystack.size())
			top(temp);

		if (isOperator(str) && isNumber(temp)
			&& mystack.size() == 1) {
			cout << "\nEnter another value before";
			cout << " performing operation";
			return;
		} else {
			mystack.push(str);

			if (isOperator(str)) {
				evaluate(mystack);
			}
		}
	}

	void pop() {
		mystack.pop();
	}

	void top(string& str) {
		str = mystack.top();
	}

	/*
	void printAll(){
	string temp;

		while(mystack.size()>0){
			top(temp);
			cout<<" "<<temp;
			pop();
		}
	}
	*/

};

int main(int argc, char** argv) {

	classStack myStack;

	string input;

	cout << "\n Enter a number of Q to quit :";
	cin >> input;

	while (input.compare("Q") != 0 && input.compare("q") != 0) {
		myStack.push(input);
		cout << "\nEnter a number or Q to quit :";
		cin >> input;
	}

	string temp;
	myStack.top(temp);
	if (temp.length())
		cout << "\nThe value on the top of the stack is: "
		<< std::fixed << std::setprecision(2) << temp << endl;

	_getch();
	return 0;
}