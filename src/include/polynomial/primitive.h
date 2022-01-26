#ifndef __POLYNOMIAL_PRIMITIVE_H__
#define __POLYNOMIAL_PRIMITIVE_H__
#include <vector>
#include <iostream>
#include <string>

namespace seqtools {

class Poly;

std::ostream & operator<<(std::ostream &, const Poly &);
std::istream & operator>>(std::istream &, Poly &);

class Poly {
// types
public:
	using coef_vector = std::vector<int>;
	using size_t = coef_vector::size_type;
	using poly_vector = std::vector<Poly>;

// variables
private:
	coef_vector				coef;
	static poly_vector		irreducible;

// methods
private:
	inline void refresh();
	bool isPrimitive_step2() const;
	static void generateIrreducible(const size_t);

public:
	// constructors
	Poly();
	Poly(const Poly &);
	Poly(const std::string &);

	// overloaded operators
	Poly & operator = (const Poly &);
	bool operator == (const Poly &) const;
	Poly operator + (const Poly &) const;
	Poly operator - (const Poly &) const;
	Poly operator * (const Poly &) const;
	Poly operator / (const Poly &) const;
	Poly operator % (const Poly &) const;	

	// others	
	bool isZero() const;
	bool isOne() const;
	bool isPrimitive() const;	
	bool isIrreducible() const;
	Poly inverse (const Poly &) const;
	static void listPrimitive(const size_t);
	static std::vector<std::vector<int>> getPrimitive(const size_t);

	friend std::ostream & operator<<(std::ostream &, const Poly &);
    friend std::istream & operator>>(std::istream &, Poly &);
};



}

#endif