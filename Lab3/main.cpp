#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int denominator); 
      Rational(int numerator, int denominator); 
      Rational add(const Rational &B) const; 
      Rational subtract(const Rational &B) const; 
      Rational multiply(const Rational &B) const; 
      Rational divide(const Rational &B) const;
      void simplify();
      void display() const;
   private:
      int gcd(int A, int B) const;
};

// Implement Rational class member functions here
Rational::Rational(int initnumerator, int initdenominator)
{
   //2 input constructor
   numerator = initnumerator;
   denominator = initdenominator;
}

Rational::Rational(int initnumerator)
{
   //denominator only constructor
   numerator = initnumerator;
   denominator = 1;
}

Rational::Rational()
{
   //no input constructor
   numerator = 0;
   denominator = 1;
}

Rational Rational::add(const Rational &B) const
{
   //(a/b) + (c/d) = (ad + bc) / (b*d)
   Rational result;

   result.numerator = ((numerator * B.denominator) + (denominator * B.numerator));
   result.denominator = denominator * B.denominator;

   return result;
} 

Rational Rational::subtract(const Rational &B) const
{
   //(a/b) - (c/d) = (ad - bc) / (b*d)
   Rational result;

   result.numerator = ((numerator * B.denominator) - (B.numerator * denominator));
   result.denominator = denominator * B.denominator;

   return result;
} 

Rational Rational::multiply(const Rational &B) const 
{
   //(a/b) * (c/d) = (ac) / (bd)
   Rational result;

   result.numerator = numerator * B.numerator;
   result.denominator = denominator * B.denominator;

   return result;
}

Rational Rational::divide(const Rational &B) const
{
   //(a/b) / (c/d) = (ad) / (cb)
   Rational result;

   result.numerator = numerator * B.denominator;
   result.denominator = B.numerator * denominator;

   return result;
}

int Rational::gcd(int A, int B) const
{
   while (B != 0)
   {
      int temp = B;
      B = A % B;
      A = temp;
   }

   return A;
}

void Rational::simplify()
{
   int gcdenom = gcd(numerator, denominator);
   numerator = numerator / gcdenom;
   denominator = denominator / gcdenom;

}

void Rational::display() const
{
   cout << numerator << " / " << denominator;
}



// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

