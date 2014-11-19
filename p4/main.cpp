/*******************************************************************************
Author:        Gustavo Zach Vargas
CS Login:      gustavo

Pair Partner:  <name of your pair programming partner (if applicable)>
CS Login:      <your partner's login name>

Credits:       <name of anyone (other than your pair programming partner) who
                helped you write your program>

Course:         CS 368, Fall 2013
Assignment:     Programming Assignment 4
 *******************************************************************************/

#include "ComplexNumber.h"; TODO

using namespace std;

int main(){

	ComplexNumber z1 = ComplexNumber(4.2,8.3);
	ComplexNumber z2 = ComplexNumber(3.1,-9.2);
	ComplexNumber tmp;

	cout << "Enter a complex number C1: " << endl;
	cin >> z1;
	if(cin.fail() && !cin.bad()){
		cin.clear();
		string skip;
		getline(cin,skip);
		cout << "Invalid input: "<< skip << endl;
		cout << " Please enter complex number as a+bi"<<endl;
	}

	cout << "Enter a complex number C2: " << endl;
	//cin >> z2;

	//TODO NOT working
	//Check input operator

	cout << "For C1 = ";
	z1.print();

	cout << "and C2 = ";
	z2.print();

	// check + operator
	cout << endl << "C1 + C2 = ";
	(z1 + z2).print();

	// check - operator
	cout << "C1 - C2 = ";
	(z1 - z2).print();

	// check * operator
	cout << "C1 * C2 = ";
	(z1 * z2).print();

	// check == operator
	if(z1 == z2){
		cout << "C1 == C2 is true" << endl;
	}
	else{
		cout << "C1 == C2 is false" << endl;
	}

	// check != operator
	if(z1 != z2){
		cout << "C1 != C2 is true" << endl;
	}
	else{
		cout << "C1 != C2 is false" << endl;
	}

	cout << "After C1 += C2, C1 = ";
	tmp = z1;
	(z1+=z2).print();
	z1 = tmp;

	cout << "After C1 -= C2, C1 = ";
	(z1-=z2).print();
	z1 = tmp;

	cout << "After C1 *= C2, C1 = ";
	(z1*=z2).print();
	z1 = tmp;

	return 0;
}
