#include "polynomial.h"
#include "poly_test.h"


int main() {
    Polynomial p;
    Poly_Test pt;
    int test_num = -1;
    // start message
    pt.display_s_msg();
    // default value of test_num: -1
    cin >> test_num;
    system("clear");
    switch (test_num) {
        // [1] Testing add_term()
        case 1:
            pt.add_term_test();
            // Proceed to next test?
            pt.proceed();
            cout << "Skipped over";
            // [2] Testing p_copy()
        case 2:
            pt.copy_test();
            // Proceed to next test?
            pt.proceed();

            // [3] Testing remove_term()
        case 3:
            pt.remove_term_test();
            // Proceed to next test?
            pt.proceed();

            // [4] Testing poly_val()
        case 4:
            pt.poly_val_test();
            // Proceed to next test?
            pt.proceed();

            // [5] Testing mul_term()
        case 5:
            pt.mul_term_test();
            // Proceed to next test?
            pt.proceed();

            // [6] Testing operator ==()
        case 6:
            pt.equality_test();
            // Proceed to next test?
            pt.proceed();

            // [7] Testing operator !=()
        case 7:
            pt.inequality_test();
            // Proceed to next test?
            pt.proceed();

            // [8] Testing operator +()
        case 8:
            pt.add_test();
            // Proceed to next test?
            pt.proceed();

            // [9] Testing operator -()
        case 9:
            pt.sub_test();
            // Proceed to next test?
            pt.proceed();

            // [10] Test operator *()
        case 10:
            pt.mul_test();
            // Proceed to next test?
            pt.proceed();

            // [11] Test operator /()
        case 11:
            pt.div_test();
            // Proceed to next test?
            pt.proceed();

            // [12] Test operator %()
        case 12:
            pt.rem_test();
            // Proceed to next test?
            pt.proceed();

            // [13] Test integrate()
        case 13:
            pt.integ_test();
            // Proceed to next test?`
            pt.proceed();

            // [14] Test differentiate()
        case 14:
            pt.deriv_test();

        default:
            break;
    }
    return 0;
}

