#include "polynomial.h"

Polynomial::Polynomial(Node *h) : head(h) {}

Polynomial::Polynomial(const Polynomial &p) {
    head = p.head == nullptr ? nullptr : new Node(p.head->exp, p.head->coef);
    Node *current = p.head == nullptr ? nullptr : p.head->next, *new_current = head;
    while (current != nullptr) {
        Node *temp_node = new Node(current->exp, current->coef);
        new_current->next = temp_node;
        new_current = new_current->next;
        current = current->next;
    }
}

Polynomial::~Polynomial() {
    /* Node *del = head == nullptr ? nullptr : head->next, *undelete;
     while (del != nullptr) {
         undelete = del->next;
         delete del;
         del = undelete;
     }*/
}

void Polynomial::print() const {
    Node *x = head;
    bool first = true;
    while (x != nullptr) {
        if (first) {
            first = false;
            string s = x->exp == 0 ? "" : "x^" + to_string(x->exp);
            cout << '\n' << x->coef << s;
            x = x->next;
        } else {
            string sign = x->coef > 0 ? "+" : "";
            string s = x->exp == 0 ? "" : "x^" + to_string(x->exp);

            cout << sign << x->coef << s;
            x = x->next;
        }
    }
}

void Polynomial::add_term(const double &c, const int &e) {
    if (head == nullptr) {
        Node *node = new Node(e, c, nullptr);
        head = node;
    } else {
        if (c == 0) { return; }
        Node *current = head, *previous = head;
        while (current != nullptr && current->exp > e) {
            previous = current;
            current = current->next;
        }
        if (current != nullptr && current->exp == e) {
            current->coef += c;
            if (current->coef == 0) {
                remove_term(e);
            }
        } else if (current != nullptr && current == head) {
            Node *x = new Node(e, c, current);
            head = x;
        } else if (current == nullptr) {
            Node *x = new Node(e, c, nullptr);
            previous->next = x;
        } else {
            Node *x = new Node(e, c, previous->next);
            previous->next = x;
        }
    }
}

Polynomial Polynomial::p_copy() const {
    Polynomial *result = new Polynomial(*this);
    return *result;
}

void Polynomial::remove_term(const int &e) {
    Node *current = head, *previous = head;
    while (current != nullptr && current->exp != e) {
        previous = current;
        current = current->next;
    }
    if (current != nullptr && current != head) {
        previous->next = current->next;
        delete current;
    } else if (current == head) {
        head = head->next;
        delete current;
    }
}

double Polynomial::poly_val(const double &x) const {
    double result = 0;
    Node *node = head;
    while (node != nullptr) {
        result += node->coef * pow(x, node->exp);
        node = node->next;
    }
    return result;
}

Polynomial Polynomial::mul_term(const double &c, const int &e) const {
    Polynomial *result = new Polynomial;
    if (head == nullptr)return NULL;
    result->head = new Node(head->exp + e, head->coef * c);
    Node *current = head->next, *new_current = result->head;

    while (current != nullptr) {
        Node *temp_node = new Node(current->exp + e, current->coef * c);
        new_current->next = temp_node;
        new_current = new_current->next;
        current = current->next;
    }
    return *result;
}

bool Polynomial::operator==(const Polynomial &p) const {
    Node *x = p.head, *y = head;
    while (x != nullptr && y != nullptr) {
        if (x->coef != y->coef || x->exp != y->exp) {
            return false;
        }
        x = x->next;
        y = y->next;
    }
    return x == y && x == nullptr;
}

bool Polynomial::operator!=(const Polynomial &p) const { return !(*this == p); }

Polynomial Polynomial::operator+(const Polynomial &p) const {
    auto *result = new Polynomial;
    Node *current = head;
    while (current != nullptr) {
        result->add_term(current->coef, current->exp);
        current = current->next;
    }
    current = p.head;
    while (current != nullptr) {
        result->add_term(current->coef, current->exp);
        current = current->next;
    }
    return *result;
}

Polynomial Polynomial::operator-(const Polynomial &p) const {
    return *this + p.mul_term(-1, 0);
}

Polynomial Polynomial::operator*(const Polynomial &p) const // complexity
{
    Polynomial result;
    Node *current = head;
    while (current != nullptr) {
        result = result + p.mul_term(current->coef, current->exp);
        current = current->next;
    }
    return result;
}

Polynomial Polynomial::operator/(const Polynomial &divisor) const {
    Polynomial result, reminder = *this;
    if (head == nullptr || divisor.head == nullptr)return nullptr;
    if (head->exp < divisor.head->exp) { return nullptr; }
    Node *current = head;
    while (current != nullptr && divisor.head->exp <= current->exp) {
        double coef = current->coef / divisor.head->coef;
        int exp = current->exp - divisor.head->exp;
        result.add_term(coef, exp);
        reminder = (reminder - divisor.mul_term(coef, exp));
        current = reminder.head;
    }
    return result;
}

Polynomial Polynomial::operator%(const Polynomial &divisor) const {

    Polynomial result, reminder = *this;
    if (head == nullptr || divisor.head == nullptr)return nullptr;
    if (head->exp < divisor.head->exp) { return nullptr; }
    Node *current = head;
    while (current != nullptr && divisor.head->exp <= current->exp) {
        double coef = current->coef / divisor.head->coef;
        int exp = current->exp - divisor.head->exp;
        result.add_term(coef, exp);
        reminder = (reminder - divisor.mul_term(coef, exp));
        current = reminder.head;
    }
    return reminder;
}

Polynomial Polynomial::differentiate() const {
    if (head == nullptr || head->exp == 0) { return nullptr; }
    Node *h = new Node(head->exp - 1, head->exp * head->coef);
    Polynomial *result = new Polynomial(h);
    Node *current = head->next, *result_current = result->head;
    while (current != nullptr && current->exp > 0) {
        result_current->next = new Node(current->exp - 1, current->exp * current->coef);
        result_current = result_current->next;
        current = current->next;
    }
    return *result;
}

Polynomial Polynomial::integrate() const {
    if (head == nullptr) { return nullptr; }
    Node *h = new Node(head->exp + 1, head->coef / (head->exp + 1));
    Polynomial *result = new Polynomial(h);
    Node *current = head->next, *result_current = result->head;
    while (current != nullptr) {
        result_current->next = new Node(current->exp + 1, current->coef / (current->exp + 1));
        result_current = result_current->next;
        current = current->next;
    }
    return *result;
}

