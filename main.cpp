//Matteo Podesta
//Lab #8

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

int FractionCount = 0;

void printFractionCount() {
	cout << "Current amount of Fraction classes in memory is: " << FractionCount << endl;
}

class Fraction {
public:
	Fraction();
	Fraction(Fraction& Fraction);
	Fraction(int wholeInput);
	Fraction(int numeratorInput, int denominatorInput);
	Fraction(int numeratorInput, int denominatorInput, int wholeInput);
	~Fraction();

	void setNumerator(int input) { numerator = input; }
	void setDenominator(int input) { denominator = input; }

	void setFraction(int numeratorInput, int denominatorInput, int wholeInput);
	void setFraction(int NumeratorInput, int DenominatorInput);
	void setFraction(int NumeratorInput);

	void catchFunction(int Numerator, int Nenominator, int Whole);

	bool operator==(Fraction const &otherFraction) {

		if ((numerator == otherFraction.numerator) && (denominator == otherFraction.denominator) && (whole == otherFraction.whole)) {

			return true;

		}
		else if ((((denominator * whole) + numerator) == otherFraction.numerator) && (denominator == otherFraction.denominator)) {

			return true;

		}
		else if ((((otherFraction.denominator * otherFraction.whole) + otherFraction.numerator) == numerator) && (denominator == otherFraction.denominator)) {

			return true;

		}
		else {

			return false;
		
		}

	}

	Fraction& operator=(Fraction& fractionObject) {

		numerator = fractionObject.numerator;
		denominator = fractionObject.denominator;
		whole = fractionObject.whole;

		return fractionObject;
	}
	
	friend ostream& operator<<(ostream& output, const Fraction& fractionObject) {

		output << fractionObject.whole << " " << fractionObject.numerator << "/" << fractionObject.denominator;

		if (fractionObject.whole > 0) {

			output << " = " << (fractionObject.denominator * fractionObject.whole) + fractionObject.numerator << "/" << fractionObject.denominator;

		}

		if (fractionObject.numerator > fractionObject.denominator && (fractionObject.numerator % fractionObject.denominator) > 0) {

			output << " = " << (fractionObject.numerator / fractionObject.denominator) << " " << (fractionObject.numerator % fractionObject.denominator) << "/" << fractionObject.denominator;

		}

		if (fractionObject.denominator == 1) {

			output << " = " << fractionObject.numerator;

		}

		return output;

	}
	friend istream& operator>>(istream& input, Fraction& fractionObject) {

		fractionObject.catchFunction(fractionObject.numerator, fractionObject.denominator, fractionObject.whole);
		
		input >> fractionObject.whole >> fractionObject.numerator >> fractionObject.denominator;
		return input;

	}

	string printFraction();
	string toString();

private:
	const int DEFAULT_NUMERATOR = 1;
	const int DEFAULT_DENOMINATOR = 1;
	const int DEFAULT_WHOLE = 0;

	int numerator = DEFAULT_NUMERATOR;
	int denominator = DEFAULT_DENOMINATOR;
	int whole = DEFAULT_WHOLE;
};

enum {
	IF_EQUALS = 1,
	EQUALS,
	INPUT,
	OUTPUT,
	QUIT
};

int main() {

	int input = 0;

	
	while (input != QUIT) {

		cout << "\nMenu:\n"
			"1. If equals (==) demo\n"
			"2. Equals (=) demo\n"
			"3. Input (>>) demo\n"
			"4. Output (<<) demo\n"
			"5. Quit\n"
			"Input: ";
		cin >> input;

		switch (input) {
		case IF_EQUALS:
		{

			Fraction cow(1, 5, 2);
			Fraction gambling(11, 5, 0);

			if (cow == gambling) {

				cout << cow.toString() << " and " << gambling.toString() << " are equal\n";

			}

		}
		break;
		case EQUALS:
		{

			Fraction sillies(1, 100, 12);
			Fraction gaming;

			gaming = sillies;

			cout << sillies.toString() << endl << gaming.toString() << endl;

		}
		break;
		case INPUT:
		{
			Fraction gaming;
			cin >> gaming;
			cout << gaming;
		}
		break;
		case OUTPUT:
		{

			Fraction gaming;
			Fraction ball(5, 1, 0);
			Fraction books(3, 6, 3);
			cout << gaming << endl << ball << endl << books << endl;

		}
		break;
		case QUIT:
			break;
		}
	}
}

Fraction::Fraction() {
	FractionCount++;
	setFraction(DEFAULT_NUMERATOR, DEFAULT_DENOMINATOR, whole);
}
Fraction::~Fraction() {
	numerator = 0;
	denominator = 1;
	FractionCount--;
}
Fraction::Fraction(int NumeratorInput) {
	FractionCount++;
	setFraction(NumeratorInput, denominator, whole);
}
Fraction::Fraction(int NumeratorInput, int DenominatorInput) {
	FractionCount++;
	setFraction(NumeratorInput, DenominatorInput, whole);
}
Fraction::Fraction(int NumeratorInput, int DenominatorInput, int WholeInput) {
	FractionCount++;
	setFraction(NumeratorInput, DenominatorInput, WholeInput);
}
Fraction::Fraction(Fraction& Fraction) {
	FractionCount++;
	Fraction.numerator = numerator;
	Fraction.denominator = denominator;
	Fraction.whole = whole;
}

string Fraction::printFraction() {

	ostringstream text;
	text << numerator << "/" << denominator;
	return text.str();

}
string Fraction::toString() {

	ostringstream text;
	text << whole << " " << numerator << "/" << denominator;
	return text.str();

}

void Fraction::catchFunction(int Numerator, int Denominator, int Whole) {
	if (Numerator < 0) {
		cout << "Error: numerator is set to " << Numerator << endl;
		throw Numerator;
	}
	if (Denominator < 0) {
		cout << "Error: denominator is set to " << Denominator << endl;
		throw Denominator;
	}
	if (Whole < 0) {
		cout << "Error: whole is set to " << Whole << endl;
		throw Whole;
	}

	if (Numerator == 0) {
		cout << "Error: numerator is set to " << Numerator << endl;
		throw Numerator;
	}
	else if (Denominator == 0) {
		cout << "Error: denominator is set to " << Denominator << endl;
		throw Denominator;
	}

	if (Numerator > Denominator) {
		if (Whole > 0) {
			cout << "Error: Improper Fraction formatting\n";
			throw Whole;
		}
	}
}
void Fraction::setFraction(int numeratorInput, int denominatorInput, int wholeInput) {

	numerator = numeratorInput;
	denominator = denominatorInput;
	whole = wholeInput;
	try {
		catchFunction(numeratorInput, denominatorInput, wholeInput);
	}
	catch (...) {
		cout << "The Fraction " << toString() << " is Invalid\n";
	}

}
void Fraction::setFraction(int NumeratorInput, int DenominatorInput) {
	setFraction(NumeratorInput, DenominatorInput, whole);
}
void Fraction::setFraction(int NumeratorInput) {
	setFraction(NumeratorInput, denominator, whole);
}