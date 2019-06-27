#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

/*
** Simple Vector class implementation
** Includes overloads for +, -, +=, -=, and ==
*/
class Vector {
	public:
		Vector(int x, int y);
		Vector();
		~Vector();
		Vector(const Vector& f);
		Vector clamp(Vector min, Vector max);
		Vector operator=(const Vector& f);
		bool operator==(const Vector& f) const;
		Vector operator+(const Vector& v) const;
		Vector operator-(const Vector& v) const;
		Vector &operator+=(const Vector& v);
		Vector &operator-=(const Vector& v);

		int getX() const;
		int getY() const;

	private:
		int x;
		int y;
};

std::ostream &operator<<(std::ostream& os, const Vector& v);

#endif