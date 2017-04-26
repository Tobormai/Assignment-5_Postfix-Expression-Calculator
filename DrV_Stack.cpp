#include <iostream>
#include <string>
#include "ArrayStack.h"
#include <sstream>
#include<stack>


using namespace std;

// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string expression);

// Function to perform an operation and return output. 
int PerformOperation(char operation, int operand1, int operand2);

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C);

// Function to verify whether a character is numeric digit. 
bool IsNumericDigit(char C);

int main()
{
	string expression;
	string loop;

	do
	{
		cout << "POSTFIX CALCULATOR" << endl;
		cout << "Enter Postfix Expression: ";
		getline(cin, expression);
		int result = EvaluatePostfix(expression);
		cout << "Result = " << result << "\n";

//empty stack


		cout << "More expressions: " << endl;
		cin >> loop;

	} while (loop != "n" || "N");
	if (loop == "y" || "Y")
		cout << "Expression: " << expression << endl;
		return 0;
	system("pause");
}

// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string expression)
{
	// Declaring a Stack from Standard template library in C++. 
	ArrayStack<int> S;

	for (size_t i = 0; i < expression.length(); i++)
	{
		// Scanning each character from left. 
		// If character is a space ignore. 
		if (expression[i] == ' ') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if (IsOperator(expression[i]))
		{
			// Pop two operands. 
			int operand2 = S.peek(); S.pop();
			int operand1 = S.peek(); S.pop();
			// Perform operation
			int result = PerformOperation(expression[i], operand1, operand2);
			//Push back result of operation on stack. 
			S.push(result);
		}
		else if (IsNumericDigit(expression[i]))
		{
			// Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit. 
			int operand = 0;
			while (i<expression.length() && IsNumericDigit(expression[i]))
			{
				// For a number with more than one digits, as we are scanning from left to right. 
				// Everytime , we get a digit towards right, we can multiply current total in operand by 10 
				// and add the new digit. 
				operand = expression[i] - '0'; //convert character to integer
				cout << "Operand value: " << operand << endl;
				i++;
			}
			i--;
			// Push operand on stack. 
			S.push(operand);
		}
		/*else if (IsNumericDigit == 0 || IsOperator == 0)
		{
			cout << "Invalid character encountered." << endl;
			cout << "Enter another expression (Y/N)" << endl;
			cin >> expression;
		}*/
	}
	// If expression is in correct format, Stack will finally have one element. This will be the output. 
	return S.peek();
	
	// clean up after evaluation completed
	while (!S.isEmpty())
	{
		S.pop();
	}

	
}

// Function to verify whether a character is numeric digit. 
bool IsNumericDigit(char C)
{
	if (C >= '0' && C <= '9') return true;
	return false;
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

// Function to perform an operation and return output. 
int PerformOperation(char operation, int operand1, int operand2)
{
	if (operation == '+') return operand1 + operand2;
	else if (operation == '-') return operand1 - operand2;
	else if (operation == '*') return operand1 * operand2;
	else if (operation == '/') return operand1 / operand2;

	else cout << "Unexpected Error \n";

	return -1;
}

