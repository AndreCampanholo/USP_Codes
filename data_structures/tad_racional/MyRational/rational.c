#include "rational.h"
#include <stdio.h>
#include <stdlib.h>

struct rational {
    int num;
    int den;
};

RATIONAL *create_rational(int numerator, int denominator) {
    RATIONAL *rat = (RATIONAL *)calloc(1, sizeof(RATIONAL));
    rat->num = numerator;
    rat->den = denominator;
    printf("New rational: %d/%d\n", rat->num, rat->den);
    return rat;
}

RATIONAL *add_rationals(RATIONAL *a, RATIONAL *b) {
    RATIONAL *rat = (RATIONAL *)calloc(1, sizeof(RATIONAL));
    rat->num = a->num * b->den + b->num * a->den;
    rat->den = (*a).den * (*b).den;
    printf("New rational: %d/%d\n", rat->num, rat->den);
    return rat;
}

RATIONAL* multiply_rationals(RATIONAL *a, RATIONAL* b) {
    RATIONAL *rat = (RATIONAL *)calloc(1, sizeof(RATIONAL));
    rat->num = a->num * b->num;
    rat->den = a->den * b->den;
    printf("New rational: %d/%d\n", rat->num, rat->den);
    return rat;   
}

RATIONAL *add_rational_int(RATIONAL *a, int b) {
    RATIONAL *rat = (RATIONAL *)calloc(1, sizeof(RATIONAL));
    rat->num = b * a->den;
    rat->den = a->den;
    rat->num = a->num + rat->num;
    printf("New rational: %d/%d\n", rat->num, rat->den);
    return rat;
}

RATIONAL *multiply_rational_int(RATIONAL *a, int b) {
    RATIONAL *rat = (RATIONAL *)calloc(1, sizeof(RATIONAL));
    rat->num = a->num * b;
    rat->den = a->den;
    printf("New rational: %d/%d\n", rat->num, rat->den);
    return rat;
}

void delete_rational(RATIONAL *a) {
    free(a);
    a = NULL;
}