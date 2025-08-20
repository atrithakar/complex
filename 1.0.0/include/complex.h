#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
    double real;
    double imaginary;
} Complex;

// Constructors
Complex complex_create(double real, double imaginary);

// Operations
Complex complex_add(Complex a, Complex b);
Complex complex_sub(Complex a, Complex b);
Complex complex_mul(Complex a, Complex b);
Complex complex_div(Complex a, Complex b);

// Utility
void complex_print(Complex c);

#endif // COMPLEX_H
