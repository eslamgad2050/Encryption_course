#ifndef POLY_TEST_H
#define POLY_TEST_H
#include "polynomial.h"

// ASCII of ctrl+c
const int ETX = '0';

class Poly_Test{
private:
	string s_msg;
public:
	Poly_Test();
    // [1] Testing add_term()
    void add_term_test();
    // [2] Testing p_copy()
    void copy_test();
    // [3] Testing remove_term()
    void remove_term_test();
    // [4] Testing poly_val()
    void poly_val_test();
    // [5] Testing mul_term()
    void mul_term_test();
    // [6] Testing operator ==()
    void equality_test();
    // [7] Testing operator !=()
    void inequality_test();
    // [8] Testing operator +()
    void add_test();
    // [9] Testing operator -()
    void sub_test();
    // [10] Test operator *()
    void mul_test();
    // [11] Test operator /()
    void div_test();
    // [12] Test operator %()
    void rem_test();
    // [13] Test integrate()
    void integ_test();
    // [14] Test differentiate()
    void deriv_test();
	// Helper functions
	/* Proceed to next test? */
	void proceed();
    void display_s_msg();
};

#endif
