#include "poly_test.h"
#include <stdio.h>

Poly_Test::Poly_Test() {
    // compiler settings: follow the C++11 language standard
    s_msg = R"(
    /--------------------------------------------------/
    /-----------------Polynomial Lab-------------------/
    /--------------------------------------------------/
    -Please implement: a Copy Constructor to avoid shallow
     copy.
    -Total 15p: 14p(pdf) and 1p:(Destructor/Copy Constructor)

    -Select Test case:
    [1] Test add_term()
    [2] Test p_copy()
    [3] Test remove_term()
    [4] Test poly_val()
    [5] Test mul_term()
    [6] Test operator ==()
    [7] Test operator !=()
    [8] Test operator +()
    [9] Test operator -()
    [10] Test operator *()
    [11] Test operator /()
    [12] Test operator %()
    [13] Test integrate()
    [14] Test differentiate()
    your input:)";
}

void Poly_Test::add_term_test() {
    Polynomial p;
    cout << "#1[i] Testing add_term():";
    cout << "\nExpected Output: \n";
    cout << "30x^60 +60x^40 +30x^20";
    cout << "\nYour output: \n";
    p.add_term(30, 40);
    p.add_term(30, 60);
    p.add_term(30, 20);
    p.add_term(30, 40);
    p.print();

    cout << "\n\n#1[ii] Testing add_term():";
    cout << "\nExpected Output: \n";
    cout << "30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10";
    cout << "\nYour output: \n";
    p.add_term(30, 50);
    p.add_term(30, 30);
    p.add_term(30, 10);
    p.print();

    cout << "\n\n#1[iii] Testing add_term():";
    cout << "\nExpected Output: \n";
    cout << "30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10";
    cout << "\nYour output: \n";
    p.add_term(30, 100);
    p.add_term(-30, 100);
    p.print();
}

void Poly_Test::copy_test() {
    Polynomial p, p1;
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10
    p.add_term(30, 60);
    p.add_term(30, 50);
    p.add_term(60, 40);
    p.add_term(30, 30);
    p.add_term(30, 20);
    p.add_term(30, 10);

    // copy test
    cout << "#2 Testing p_copy():";
    cout << "\nExpected Output: \n";
    cout << "30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10";
    cout << "\nYour output: \n";
    p1 = p.p_copy();
    p1.print();
}

void Poly_Test::remove_term_test() {
    Polynomial p1;
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10
    p1.add_term(30, 60);
    p1.add_term(30, 50);
    p1.add_term(60, 40);
    p1.add_term(30, 30);
    p1.add_term(30, 20);
    p1.add_term(30, 10);

    cout << "#3 Testing remove_term():";
    cout << "\nExpected Output: \n";
    cout << "30x^50 +30x^30 +30x^20";
    cout << "\nYour output: \n";
    p1.remove_term(60);
    p1.remove_term(40);
    p1.remove_term(10);
    p1.print();
}

void Poly_Test::poly_val_test() {
    Polynomial p1;
    // 30x^50 +30x^30 +30x^20
    p1.add_term(30, 50);
    p1.add_term(30, 30);
    p1.add_term(30, 20);

    cout << "#4 Testing poly_val():";
    cout << "\nExpected Output: \n";
    cout << "258.518";
    cout << "\nYour output: \n";
    cout << p1.poly_val(1.03);
}

void Poly_Test::mul_term_test() {
    Polynomial p1, pm;
    // 30x^50 +30x^30 +30x^20
    p1.add_term(30, 50);
    p1.add_term(30, 30);
    p1.add_term(30, 20);
    cout << "#5 Testing mul_term():";
    cout << "\nExpected Output: \n";
    cout << "-30x^60-30x^40-30x^30";
    cout << "\nYour output: \n";
    pm = p1.mul_term(-1, 10);
    pm.print();
}

void Poly_Test::equality_test() {
    Polynomial p, p2;
    string res;
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10
    p.add_term(30, 60);
    p.add_term(30, 50);
    p.add_term(60, 40);
    p.add_term(30, 30);
    p.add_term(30, 20);
    p.add_term(30, 10);

    cout << "#6[i] Testing operator ==():";
    cout << "\nExpected Output: \n";
    cout << "true";
    cout << "\nYour output: \n";
    p2 = p.p_copy();
    res = (p2 == p) ? "true" : "false";
    cout << res;

    cout << "\n\n#6[ii] Testing operator ==():";
    cout << "\nExpected Output: \n";
    cout << "false";
    cout << "\nYour output: \n";
    p2.remove_term(10);
    //p2: 30x^60 +30x^50 +60x^40 +30x^30 +30x^20
    res = (p2 == p) ? "true" : "false";
    cout << res;
}

void Poly_Test::inequality_test() {
    Polynomial p, p2;
    string res;
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10
    p.add_term(30, 60);
    p.add_term(30, 50);
    p.add_term(60, 40);
    p.add_term(30, 30);
    p.add_term(30, 20);
    p.add_term(30, 10);
    p2 = p.p_copy();
    p2.remove_term(10);

    cout << "#7[i] Testing operator !=():";
    cout << "\nExpected Output: \n";
    cout << "true";
    cout << "\nYour output: \n";
    res = (p2 != p) ? "true" : "false";
    cout << res;

    cout << "\n\n#7[ii] Testing operator !=():";
    cout << "\nExpected Output: \n";
    cout << "false";
    cout << "\nYour output: \n";
    res = (p != p) ? "true" : "false";
    cout << res;
}

void Poly_Test::add_test() {
    Polynomial p, p1, ps, ps1;
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10
    p.add_term(30, 60);
    p.add_term(30, 50);
    p.add_term(60, 40);
    p.add_term(30, 30);
    p.add_term(30, 20);
    p.add_term(30, 10);
    // 30x^50 +30x^30 +30x^20
    p1.add_term(30, 50);
    p1.add_term(30, 30);
    p1.add_term(30, 20);

    cout << "#8 Testing operator +():";
    cout << "\nExpected Output: \n";
    cout << "30x^60 +60x^50 +60x^40 +60x^30 +60x^20 +30x^10";
    cout << "\nYour output: \n";
    ps = p1 + p,
            ps = p + p1;
    ps.print();
    ps1.print();
}

void Poly_Test::sub_test() {
    Polynomial p, p1, pdiff, pdiff1;
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10
    p.add_term(30, 60);
    p.add_term(30, 50);
    p.add_term(60, 40);
    p.add_term(30, 30);
    p.add_term(30, 20);
    p.add_term(30, 10);
    // 30x^50 +30x^30 +30x^20
    p1.add_term(30, 50);
    p1.add_term(30, 30);
    p1.add_term(30, 20);

    cout << "#9[i] Testing operator -():";
    cout << "\nExpected Output: \n";
    cout << "30x^60 +60x^40 +30x^10\n";
    cout << "-30x^60-60x^40-30x^10";
    cout << "\nYour output: \n";
    pdiff = p - p1;
    pdiff1 = p1 - p;
    pdiff.print();
    pdiff1.print();

    cout << "\n\n#9[ii] Testing operator -():";
    cout << "\nExpected Output: \n";
    cout << "";
    cout << "\nYour output: \n";
    pdiff = p - p;
    pdiff.print();
}

void Poly_Test::mul_test() {
    Polynomial p1, pm;
    // 30x^50 +30x^30 +30x^20
    p1.add_term(30, 50);
    p1.add_term(30, 30);
    p1.add_term(30, 20);
    cout << "#10 Testing operator *():";
    cout << "\nExpected Output: \n";
    cout << "900x^100 +1800x^80 +1800x^70 +900x^60 +1800x^50 +900x^40";
    cout << "\nYour output: \n";
    pm = p1 * p1;
    pm.print();
}


void Poly_Test::div_test() {
    Polynomial p, p1, p2, pdiv;
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10
    p.add_term(30, 60);
    p.add_term(30, 50);
    p.add_term(60, 40);
    p.add_term(30, 30);
    p.add_term(30, 20);
    p.add_term(30, 10);
    // 30x^50 +30x^30 +30x^20
    p1.add_term(30, 50);
    p1.add_term(30, 30);
    p1.add_term(30, 20);
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20
    p2.add_term(30, 60);
    p2.add_term(30, 50);
    p2.add_term(60, 40);
    p2.add_term(30, 30);
    p2.add_term(30, 20);

    cout << "#11[i] Testing operator /():\n";
    p.print();
    p1.print();
    cout << "Expected Output: \n";
    cout << "x^10 +1";
    cout << "\nYour output: \n";
    pdiv = p / p1;
    pdiv.print();

    cout << "\n\n#11[ii] Testing operator /():\n";
    p.print();
    p2.print();
    cout << "Expected Output: \n";
    cout << "1";
    cout << "\nYour output: \n";
    pdiv = p / p2;
    pdiv.print();
}

void Poly_Test::rem_test() {
    Polynomial p, p1, p2, prem;
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10
    p.add_term(30, 60);
    p.add_term(30, 50);
    p.add_term(60, 40);
    p.add_term(30, 30);
    p.add_term(30, 20);
    p.add_term(30, 10);
    // 30x^50 +30x^30 +30x^20
    p1.add_term(30, 50);
    p1.add_term(30, 30);
    p1.add_term(30, 20);
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20
    p2.add_term(30, 60);
    p2.add_term(30, 50);
    p2.add_term(60, 40);
    p2.add_term(30, 30);
    p2.add_term(30, 20);

    cout << "#12[i] Testing operator %():\n";
    p.print();
    p1.print();
    cout << "Expected Output: \n";
    cout << "30x^40-30x^30 +30x^10";
    cout << "\nYour output: \n";
    prem = p % p1;
    prem.print();

    cout << "\n\n#12[ii] Testing operator %():\n";
    p.print();
    p2.print();
    cout << "Expected Output: \n";
    cout << "30x^10";
    cout << "\nYour output: \n";
    prem = p % p2;
    prem.print();
}

void Poly_Test::integ_test() {
    Polynomial p, pi;
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10
    p.add_term(30, 60);
    p.add_term(30, 50);
    p.add_term(60, 40);
    p.add_term(30, 30);
    p.add_term(30, 20);
    p.add_term(30, 10);
    cout << "#13 Testing integrate():";
    cout << "\nExpected Output: \n";
    cout << "0.491803x^61 +0.588235x^51 +1.46341x^41 +0.967742x^31 +1.42857x^21 +2.72727x^11";
    cout << "\nYour output: \n";
    pi = p.integrate();
    pi.print();
}

void Poly_Test::deriv_test() {
    Polynomial p, pd;
    // 30x^60 +30x^50 +60x^40 +30x^30 +30x^20 +30x^10
    p.add_term(30, 60);
    p.add_term(30, 50);
    p.add_term(60, 40);
    p.add_term(30, 30);
    p.add_term(30, 20);
    p.add_term(30, 10);
    cout << "#14 Testing differentiate():";
    cout << "\nExpected Output: \n";
    cout << "1800x^59 +1500x^49 +2400x^39 +900x^29 +600x^19 +300x^9";
    cout << "\nYour output: \n";
    pd = p.differentiate();
    pd.print();
}

/* Helper functions */
void Poly_Test::Poly_Test::proceed() {
    char input_cmd = 0;
    cout << "\nNext Test (press ctrl+c to exit)?";
    cin >> input_cmd;
    if (input_cmd == ETX)
        exit(0);
    system("clear");
}

void Poly_Test::display_s_msg() {
    cout << s_msg;
}
