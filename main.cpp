#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include "NaturalInteger.h"

using namespace std;

void display (const vector<NaturalInteger> & v) {
    ofstream os ("fly_log.txt", ios_base::app);

    for (const NaturalInteger& n : v)
        os << n.getValue() << " ";
    os << endl;
    os.close();
}

void suiteDeSyracuse (NaturalInteger & n) {
    vector<NaturalInteger> v;
    NaturalInteger::deconstructToOne (n.getValue(), v);

    display(v);

    if (n.getValue() == 1) return;
    if (n.isEven()) suiteDeSyracuse(*(n.divide(2)));
    else suiteDeSyracuse(*(n.multiply(3)->plus(1)));
}

int main() {

    default_random_engine re (chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<unsigned> distribution {0, 8192};
    auto rd = distribution(re);

    NaturalInteger n (rd);
    cout << n.getValue () << endl;
    vector<NaturalInteger> v;
    NaturalInteger::deconstructToOne (n.getValue(), v);
    n.multiply(NaturalInteger(3))->plus(NaturalInteger(1));
    cout << n.getValue() << endl;

    display(v);

    suiteDeSyracuse(n);

    return 0;
}
