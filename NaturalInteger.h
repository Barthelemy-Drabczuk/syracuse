//
// Created by barth on 20/10/2020.
//

#ifndef SYRACUSE_NATURALINTEGER_H
#define SYRACUSE_NATURALINTEGER_H


#include <vector>

class NaturalInteger {

private:
    unsigned value {0} ;

public:
    explicit NaturalInteger (const unsigned & n) : value (n) {}
    NaturalInteger ();
    ~NaturalInteger();

    [[nodiscard]] unsigned getValue () const;
    void setValue (const unsigned & n);
    void setValue (const NaturalInteger & n);
    [[nodiscard]] bool isEven () const;
    NaturalInteger* minus (const NaturalInteger & n);
    NaturalInteger* minus (const unsigned & n);
    NaturalInteger* plus (const NaturalInteger & n);
    NaturalInteger* plus (const unsigned & n);
    NaturalInteger* divide (const  NaturalInteger & n);
    NaturalInteger* divide (const  unsigned & n);
    NaturalInteger* multiply (const NaturalInteger & n);
    NaturalInteger* multiply (const unsigned & n);

    static std::vector<NaturalInteger> deconstructToOne (const unsigned &n, std::vector<NaturalInteger> & v);

};



#endif //SYRACUSE_NATURALINTEGER_H

