#include <iostream>
using namespace std;

/**
 * This program defines a class called Complex that
 * calculates and correctly formats complex numbers,
 * using various member functions, and implements
 * overloaded operators in C++.
 *
 * @author     Sylva, Kaenaokalani
 * @assignment ICS 212 Assignment 21
 * @date 21 November 2023
 */

/**
 * Complex ADT (abstract data type).
 */
class Complex {
  // declare private double data members
private:
  double real;
  double imaginary;
  // declare default constructor
public:
  /**
   * Constructs a Complex object.
   */
  Complex(){
    real = 0;
    imaginary = 0;
  }

  /**
   * Overloads the >> to create Complex objects with cin >>.
   *
   * @param in A call to in.
   * @param complexParam A call to complexParam.
   * @return The input stream.
   */
  friend istream &operator>>(istream &in, Complex &complexParam){
    in >> complexParam.real >> complexParam.imaginary;
    return in;
  }

  /**
   * Overloads the << to create Complex objects with cout <<.
   *
   * @param out A call to out.
   * @param complexParam A call to complexParam.
   * @return The output stream.
   */
  friend ostream &operator<<(ostream &out, Complex &complexParam){
    out << complexParam.real << " + " << complexParam.imaginary << "i";
    return out;
  }
  
  /**
   * Allows a Complex object to be created with specific
   * real and imaginary parts.
   *
   * @param realParam The real parameter.
   * @param imaginaryParam The imaginary parameter.
   */
  Complex(double realParam, double imaginaryParam){
    real = realParam;
    imaginary = imaginaryParam;
  }

  /**
   * Copies the data members from copyComplex to this object.
   *
   * @param &copyComplex A call to copyComplex.
   *
   */
  Complex(const Complex &copyComplex){
    real = copyComplex.real;
    imaginary = copyComplex.imaginary;
  }

  /**
   * Destructor method.
   */
  ~Complex(){
    cout << "Destructor for: ";
    if(imaginary < 0){
      // if imaginary is negative, print correct format
      cout << "(" << real << " - " << imaginary * (-1) << "i)" << endl;
    } else {
      // if imaginary is positive, print correct format
      cout << "(" << real << " + " << imaginary << "i)" << endl;
    }
  }

  /**
   * Uses cout to print a complex number in the format
   * (a + bi) followed by a new line.
   */
  void print() const{
    cout << "(" << real;
    if(imaginary >= 0){
      // positive case, print "(a + bi)"
      cout << " + " << imaginary << "i)" << endl;
    } else {
      // negative case, print "(a - bi)"
      cout << " - " << imaginary * (-1) << "i)" << endl;
    }
  }
  
  /**
   * Set helper function.
   *
   * @param newReal The new real number.
   * @param newImaginary The new imaginary number.
   */
  void set(double newReal, double newImaginary){
    real = newReal;
    imaginary =newImaginary;
  }

  /** Accessor methods. */
  double getReal() const{
    return real;
  }

  double getImaginary() const{
    return imaginary;
  }

  /**
   * Add member function.
   *
   * @param &addComplex A call to addComplex.
   * @return The result of this object plus addComplex.
   */
  Complex add(const Complex &addComplex) const{
    // add the specified object to this object
    double newReal = real + addComplex.real;
    double newImaginary = imaginary + addComplex.imaginary;
    return Complex(newReal, newImaginary);
  }

  /**
   * Subtract member function.
   *
   * @param &subtractComplex A call to subtractComplex.
   * @return The result of this object minus subtractComplex.
   */
  Complex subtract(const Complex &subtractComplex) const{
    // subtract the specified object from this object
    double newReal = real - subtractComplex.real;
    double newImaginary = imaginary - subtractComplex.imaginary;
    return Complex(newReal, newImaginary);
  }

  /**
   * Multiply member function.
   *
   * @param &multiplyComplex A call to multiplyComplex.
   * @return The result of this object multiplied by multiplyComplex.
   */
  Complex multiply(const Complex &multiplyComplex) const{
    // multiply this object by the specified object
    double newReal = real * multiplyComplex.real - imaginary * multiplyComplex.imaginary;
    double newImaginary = imaginary * multiplyComplex.real + real * multiplyComplex.imaginary;
    return Complex(newReal, newImaginary);
  }

  /**
   * Divide member function.
   *
   * @param &divideComplex A call to divideComplex.
   * @return The result of this object divided by divideComplex.
   */
  Complex divide(const Complex &divideComplex) const{
    // divide this object by the specified object
    // denominator variable to save some time
    double denominator = divideComplex.real * divideComplex.real + divideComplex.imaginary * divideComplex.imaginary;
    double newReal = (real * divideComplex.real + imaginary * divideComplex.imaginary) / denominator;
    double newImaginary = (imaginary * divideComplex.real - real * divideComplex.imaginary) / denominator;
    return Complex(newReal, newImaginary);
  }
  // new code
  /*
  friend Complex operator+(const Complex &complex1, const Complex &complex2){
    return Complex(real + complex1, imaginary + complex2);
  }

  friend Complex operator-(const Complex &subtractComplex) const{
    return Complex(real - subtractComplex.real, imaginary - subtractComplex.imaginary);
  }

  friend Complex operator*(const Complex &multiplyComplex) const{
    return Complex(real * multiplyComplex.real - imaginary * multiplyComplex.imaginary, real * multiplyComplex.imaginary + imaginary * multiplyComplex.real);
  }

  friend Complex operator/(const Complex &divideComplex) const{
    double denominator = divideComplex.real * divideComplex.real + divideComplex.imaginary * divideComplex.imaginary;
    return Complex((real * divideComplex.real + imaginary * divideComplex.imaginary) / denominator, (imaginary * divideComplex.real - real * divideComplex.imaginary) / denominator);
  }

  friend bool operator==(const Complex &complex1, const Complex &complex2){
    return (complex1 == complex2);
  }

  friend bool operator!=(const Complex &complex1, const Complex &complex2){
    return !(complex1 == complex2);
  }
  */
};

int main() {

  // Used to store the two Complex objects from user input.
  Complex complex1;
  Complex complex2;
  // A blank Complex object used to store the results of the Complex arithmetic.
  Complex complex3;

  // Get 2 Complex objects from the user.
  cout << "Enter a Complex number in the form 'a+bi': ";
  cin >> complex1;
  cout << "Enter another Complex number in the form 'a+bi': ";
  cin >> complex2;
  
  cout << endl;
  
  // Test the + overloaded operator.
  cout << "Test the + operator:" << endl;
  complex3 = complex1 + complex2;
  cout << complex1 << " + " << complex2 << " = " << complex3 << endl;

  cout << "\n";
  
  // Test the - overloaded operator.
  cout << "Test the - operator:" << endl;
  complex3 = complex1 - complex2;
  cout << complex1 << " - " << complex2 << " = " << complex3 << endl;

  cout << "\n";
  
  // Test the * overloaded operator.
  cout << "Test the * operator:" << endl;
  complex3 = complex1 * complex2;
  cout << complex1 << " * " << complex2 << " = " << complex3 << endl;

  cout << "\n";

  // Test the / overloaded operator.
  cout << "Test the / operator:" << endl;
  complex3 = complex1 / complex2;
  cout << complex1 << " / " << complex2 << " = " << complex3 << endl;

  cout << "\n";
  
  // Test the == overloaded operator.
  cout << "Test the == operator:" << endl;
  // Turn on boolalpha to actually print true or false instead of 1 or 0.
  cout << complex1 << " == " << complex2 << " = " << boolalpha << (complex1 == complex2) << endl;

  cout << "\n";
  
  // Test the != overloaded operator.
  cout << "Test the != operator:" << endl;
  cout << complex1 << " != " << complex2 << " = " << (complex1 != complex2) << endl;

  cout << "\n";
  
  return 0;
  
}
