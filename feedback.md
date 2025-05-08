**5/8/2025**
*  **feedback.md is for instructor use only. DO NOT change the feedback.md**; make a copy if needed
* class definition style & standards:  first, member vars  none per line and do not forget to initialize them;  second functions: separate group of functions  by a blank line; either matching setter/getter pairs or list all setters back to back and list all getters back to back; start with a default c’tor, followed by  copy c’tor (if any), then other c’tors in the order of increased number of arguments, d’tor- right after c’tor(s), overloaded functions- list them back to back in the order of increased number of arguments;  all accessor/getter functions should be const; all functions with more than one statement should be normal (defined externally, outside of the class and below main()), no inline functions with more than one statement; initialize all member variables to appropriate default values at the time of definition; all member variables must be private; classes must provide a strong exception guarantee; must have default c’tor; implement Rule of Three when necessary
* Class Fraction architecture/logic/design does not comply with the assignment -10
* no test runs -10
* class Fraction does not provide a strong exception guarantee -10
* missing FractionException class -10
*  function definition(s) above main() -10
* inline functions do not adhere to the best practices -5
* if a user enters a value of a wrong data type, the program goes into an infinite loop; should create a highly reusable function that takes an error message string as a parameter, clears the failed input and outputs the error message to be called in the default case of the menu switch -5
* multiple return statements in a non-recursive function; may result in unreachable return; use if/else, use a variable to store the results and return the variable; e.g. a function to check the length of a string, function to validate account number,  short validations can be done in the return statement; e.g.  return a<MIN_LENGTH; -5
*  op ==: convoluted, redundant logic; see below -5
```text
return numerator *rhs.denominator ==rhs.numerator * denominator;
```
* operator = should prevent self-assignment -2
```text
if(this!=&rhs)
{
setFraction(0, rhs.numerator, rhs.denomonator);
}

```
* operator << : convoluted, redundant logic; computes the same thing several times – unnecessary computational expence; see below -5
```text
string res;

int whole=numer/denom;
int tempNumer= numer%denom;

res+=((whole!=0)? (to_string(whole)+ " ") :"" ); 
res+=((tempNumer>0)? (to_string(tempNumer)+ "/"+to_string(denom)):"");

```
* file name(s) and/or file/folder structure/capitalization do not comply with posted instructions; folder- CSXXX_LN_FL (all caps, X – class catalog number, N- lab number, FL- your initials;  files:  all lower case, main() – main.cpp, input - “in_\*.txt”, output –“out_\*.txt”, error –“err_\*.txt”; do not include any other files or folders;  -2
* assignment's description/specifications/requirements  and best practices are not optional; does not comply with the assignment's
