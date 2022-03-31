#include "polynomial.h"

Polynomial::Polynomial(Node* h) : head(h)  {}

Polynomial::Polynomial(const Polynomial& p)
{}

Polynomial::~Polynomial()
{}

void Polynomial::print() const
{}

void Polynomial::add_term(const double& c, const int& e)
{}

Polynomial Polynomial::p_copy() const
{}

void Polynomial::remove_term(const int& e)
{}

double Polynomial::poly_val(const double& x) const
{}

Polynomial Polynomial::mul_term(const double& c, const int& e) const
{}

bool Polynomial::operator==(const Polynomial& p) const
{}

bool Polynomial::operator!=(const Polynomial& p) const
{}

Polynomial Polynomial::operator + (const Polynomial& p) const
{}

Polynomial Polynomial::operator - (const Polynomial& p) const
{}

Polynomial Polynomial::operator * (const Polynomial& p) const // complexity
{}

Polynomial Polynomial::operator / (const Polynomial& divisor) const
{}

Polynomial Polynomial::operator % (const Polynomial& divisor) const
{}

Polynomial Polynomial::differentiate () const
{}

Polynomial Polynomial::integrate () const
{}

