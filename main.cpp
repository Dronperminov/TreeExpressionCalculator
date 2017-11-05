#include <iostream>
#include <string>

#include "expression.h"

using namespace std;

int main() {
	cout << "Hello from expression!" << endl;
	cout << "Now you must enter an aripthmetic expression with variables, numbers, round brackets and set of operations ('+', '-', '/' and '*')" << endl;
	cout << "If you use variables, application will ask you about their values after read expression. You can set it as by yourself and as by random." << endl;
	cout << "Application will check expression after all complete values and will say, if expression will incorrect." << endl << endl;

	string answer;

	do {
		string e;

		cout << "Enter your expression: ";
		getline(cin, e);

		while (e.empty()) {
			cout << "Your expression is empty. Please, try again: ";
			getline(cin, e);		
		}

		Expression expression(e);

		if (!expression.correct())
			cout << "Your expression is incorrect." << endl << "Sorry, it`s not my problem. If you want try again with correct expression" << endl;
		else {
			Tree* tree = expression.createTree();

			cout << "Tree: ";
			expression.printTree(tree);
			cout << endl;

			try {
				cout << "Result: " << expression.calculate(&tree) << endl;
			}
			catch (const char* msg) {
				cout << endl << "Error: " << msg << endl;
			}
		}

		cout << endl << "Do you want to enter new expression? (y/n): ";
		getline(cin, answer);
	} while (answer == "y");
}