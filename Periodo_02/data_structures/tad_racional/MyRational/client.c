#include <stdio.h>
#include "rational.h"
#include <stdlib.h>

int main() {
    int num1, den1, num2, den2, a, b;
    scanf("%d %d %d %d %d %d", &num1, &den1, &num2, &den2, &a, &b);

    RATIONAL *rat1 = create_rational(num1, den1);
    RATIONAL *rat2 = create_rational(num2, den2);

    add_rationals(rat1, rat2);
    multiply_rationals(rat1, rat2);
    add_rational_int(rat1, a);
    add_rational_int(rat1, b);
    add_rational_int(rat2, a);
    add_rational_int(rat2, b);
    multiply_rational_int(rat1, a);
    multiply_rational_int(rat1, b);
    multiply_rational_int(rat2, a);
    multiply_rational_int(rat2, b);

    delete_rational(rat1);
    delete_rational(rat2);

    return 0;
}