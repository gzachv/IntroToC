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

#include <iostream>
#include "ComplexNumber.h"

using namespace std;

/*
 * Complex Number implemented class
 *
 * A Complex Number object contains a real part and an imaginary part
 * Each part of a complex number is a double.
 */

// constructs a complex number object with default value of 0.0 for both parts
ComplexNumber::ComplexNumber(){
	real = 0.0;
	imag = 0.0;
}

// constructs a complex number object with given values of real and imag parts
ComplexNumber::ComplexNumber(double real_part, double imaginary_part){
	real = real_part;
	imag = imaginary_part;
}

// copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber & rhs):
							real(rhs.real),imag(rhs.imag)
{

}

// print complex number to the given out stream
void ComplexNumber::print(ostream & out) const {

	out << real;

	if(imag < 0){
		out << " - " << imag*(-1) << "i" << endl;
	}

	else{
		out << " + " << imag << "i" << endl;
	}
}

// Determines if a complex number is equal to another complex number, a complex
// number is equal to anther complex number is equal to another complex number
// if and only if both the real and the imag parts are equal.
bool ComplexNumber::equals(const ComplexNumber & rhs) const {
	if(real == rhs.real && imag == rhs.imag){
		return true;
	}
	return false;
}

// assignment operators:
// equal operator
const ComplexNumber & ComplexNumber::operator=(const ComplexNumber & rhs){
	real = rhs.real;
	imag = rhs.imag;
	return *this;
}

// plus equal operator, adds given complex number to complex number
const ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & rhs){
	real = real + rhs.real;
	imag = imag + rhs.imag;
	return *this;
}

// minus equal operator, subtracts given complex number to complex number
const ComplexNumber & ComplexNumber::operator-=(const ComplexNumber & rhs){
	real = real - (rhs.real);
	imag = imag - (rhs.imag);
	return *this;
}

// times equal operator, multiplies given complex number to complex number
const ComplexNumber & ComplexNumber::operator*=(const ComplexNumber & rhs){
	double tmp_real = real;
	tmp_real = (real*rhs.real) - (imag*rhs.imag);
	imag = (real*rhs.imag) + (imag*rhs.real);
	real = tmp_real;
	return *this;
}


// arithmetic operators:
ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber answer(lhs);
	answer+=rhs;
	return answer;
}

ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber answer(lhs);
	answer-=rhs;
	return answer;
}

ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber answer(lhs);
	answer*=rhs;
	return answer;
}


// relational operators:
// equal equal operator checks if the given complex numbers are equal
// complex numbers are equal if and only if both real and imag parts are equal
bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs){
	if(lhs.equals(rhs)){
		return true;
	}

	return false;
}

// not equal operator
bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs){
	if(lhs.equals(rhs)){
		return false;
	}

	return true;
}

// I/O operator output
ostream & operator<<(ostream & out, const ComplexNumber & n){
	n.print(out);
	return out;
}

// I/O operator input
istream & operator>>(istream & in, ComplexNumber & n){
	double r,i;
	char ch;

	in >> r;

	// consume white space
	in.get(ch);
	while(ch == ' ' || ch == '\n' || ch == '\t'){
		in.get(ch);
	}

	in >> i;

	if(ch == '-'){
		i = i*-1;
	}

	// consume white space
	in.get(ch);
	while(ch == ' ' || ch == '\n' || ch == '\t'){
		in.get(ch);
	}

	if(ch != 'i'){
		in.setstate(ios::failbit);
		return in;
	}

	n = ComplexNumber(r,i);
	return in;
}
