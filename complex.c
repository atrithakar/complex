#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "complex.h"

Complex complex_create(double real, double imaginary) {
    Complex c;
    c.real = real;
    c.imaginary = imaginary;
    return c;
}

Complex complex_add(Complex a, Complex b) {
    return complex_create(a.real + b.real, a.imaginary + b.imaginary);
}

Complex complex_sub(Complex a, Complex b) {
    return complex_create(a.real - b.real, a.imaginary - b.imaginary);
}

Complex complex_mul(Complex a, Complex b) {
    return complex_create(
        a.real * b.real - a.imaginary * b.imaginary,
        a.real * b.imaginary + a.imaginary * b.real
    );
}

Complex complex_div(Complex a, Complex b) {
    double denom = b.real * b.real + b.imaginary * b.imaginary;
    if (denom == 0) {
        fprintf(stderr, "Division by zero in complex_div\n");
        exit(EXIT_FAILURE);
    }
    return complex_create(
        (a.real * b.real + a.imaginary * b.imaginary) / denom,
        (a.imaginary * b.real - a.real * b.imaginary) / denom
    );
}

void complex_print(Complex c) {
    printf("%.2f %c %.2fi\n", c.real, (c.imaginary >= 0 ? '+' : '-'), fabs(c.imaginary));
}
