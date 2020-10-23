//
// Created by barth on 20/10/2020.
//

#include "NaturalInteger.h"

NaturalInteger::NaturalInteger() {}

NaturalInteger::~NaturalInteger() {}

unsigned NaturalInteger::getValue() const {
    return this->value;
}

void NaturalInteger::setValue(const unsigned int &n) {
    this->value = n;
}

void NaturalInteger::setValue(const NaturalInteger &n) {
    this->value = n.getValue();
}

bool NaturalInteger::isEven() const {
    return (this->getValue() & 1) == 0;
}

std::vector<NaturalInteger> NaturalInteger::deconstructToOne(const unsigned &n,
                                                             std::vector<NaturalInteger> &v) {
    v.emplace_back(NaturalInteger(n));
    if (n == 1) return v;
    return deconstructToOne((NaturalInteger(n).isEven() ? (n >> 1) : ((n - 1) >> 1)), v);
}

NaturalInteger* NaturalInteger::minus(const NaturalInteger &n) {
    this->value -= n.getValue();
    return this;
}

NaturalInteger *NaturalInteger::minus(const unsigned int &n) {
    this->value -= n;
    return this;
}

NaturalInteger *NaturalInteger::plus(const NaturalInteger &n) {
    this->value += n.getValue();
    return this;
}

NaturalInteger *NaturalInteger::plus(const unsigned int &n) {
    this->value += n;
    return this;
}

NaturalInteger *NaturalInteger::divide(const NaturalInteger &n) {
    this->value /= n.getValue();
    return this;
}

NaturalInteger *NaturalInteger::divide(const unsigned int &n) {
    this->value /= n;
    return this;
}

NaturalInteger *NaturalInteger::multiply(const NaturalInteger &n) {
    this->value *= n.getValue();
    return this;
}

NaturalInteger *NaturalInteger::multiply(const unsigned int &n) {
    this->value *= n;
    return this;
}

