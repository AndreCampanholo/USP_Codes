#ifndef rat_h
    #define rat_h

    typedef struct rational RATIONAL;

    RATIONAL *create_rational(int num, int den);
    RATIONAL *add_rationals(RATIONAL *a, RATIONAL *b);
    RATIONAL *multiply_rationals(RATIONAL *a, RATIONAL *b);
    RATIONAL *add_rational_int(RATIONAL *a, int b);
    RATIONAL *multiply_rational_int(RATIONAL *a, int b);
    void delete_rational(RATIONAL *a);

#endif