#include "Vector.hpp"

Vector::Vector()
{
	this->x = 0;
	this->y = 0;
}

Vector::Vector(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector::Vector(const Vector& vector)
{
	this->x = vector.x;
	this->y = vector.y;
}

Vector::~Vector()
{
}

Vector Vector::operator=(const Vector& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	return *this;
}

Vector &Vector::operator+=(const Vector& v)
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}

Vector &Vector::operator-=(const Vector& v)
{
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

Vector Vector::operator-(const Vector& v) const
{
	return Vector(this->x - v.x, this->y - v.y);
}

Vector Vector::operator+(const Vector& v) const
{
	return Vector(this->x + v.x, this->y + v.y);
}

bool Vector::operator==(const Vector& v) const
{
	if (this->x == v.x && this->y == v.y)
		return true;
	else
		return false;
}

Vector Vector::clamp(Vector min, Vector max)
{
	if (this->x < min.x)
		this->x = min.x;
	if (this->x > max.x)
		this->x = max.x;
	if (this->y < min.y)
		this->y = min.y;
	if (this->y > max.y)
		this->y = max.y;
	return *this;
}

int Vector::getX() const
{
	return x;
}

int Vector::getY() const
{
	return y;
}

std::ostream &operator<<(std::ostream& os, const Vector& v)
{
	os << v.getX() << ", " << v.getY();
	return os;
}
