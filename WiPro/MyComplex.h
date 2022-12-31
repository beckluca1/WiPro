#pragma once
#pragma warning(disable:4996)

#include "WiPro.h"

class MyComplex
{
public:
	double real;
	double im;

	MyComplex()
	{
		real = 0;
		im = 0;
	}

	MyComplex(double inReal, double inIm)
	{
		real = inReal;
		im = inIm;
	}

	double norm()
	{
		return sqrt(pow(real, 2) + pow(im, 2));
	}

	MyComplex& operator+()
	{
		MyComplex out;
		out.real = real;
		out.im = im;

		return out;
	}

	MyComplex& operator-()
	{
		MyComplex out;
		out.real = -real;
		out.im = -im;

		return out;
	}

	MyComplex& operator+(MyComplex& rhs)
	{
		MyComplex out;
		out.real = real + rhs.real;
		out.im = im + rhs.im;

		return out;
	}

	MyComplex& operator+(const MyComplex& rhs)
	{
		MyComplex out;
		out.real = real + rhs.real;
		out.im = im + rhs.im;

		return out;
	}

	MyComplex& operator+(double& rhs)
	{
		MyComplex out;
		out.real = real + rhs;
		out.im = im;

		return out;
	}

	friend MyComplex& operator+(double& lhs, MyComplex& rhs)
	{
		MyComplex out;
		out.real = lhs + rhs.real;
		out.im = rhs.im;

		return out;
	}

	MyComplex& operator+(const double& rhs)
	{
		MyComplex out;
		out.real = real + rhs;
		out.im = im;

		return out;
	}

	friend MyComplex& operator+(const double& lhs, MyComplex& rhs)
	{
		MyComplex out;
		out.real = lhs + rhs.real;
		out.im = rhs.im;

		return out;
	}

	MyComplex& operator+=(MyComplex& rhs)
	{
		real += rhs.real;
		im += rhs.im;

		return *this;
	}

	MyComplex& operator+=(const MyComplex& rhs)
	{
		real += rhs.real;
		im += rhs.im;

		return *this;
	}

	MyComplex& operator+=(double& rhs)
	{
		real += rhs;

		return *this;
	}

	MyComplex& operator+=(const double& rhs)
	{
		real += rhs;

		return *this;
	}

	MyComplex& operator-(MyComplex& rhs)
	{
		MyComplex out;
		out.real = real - rhs.real;
		out.im = im - rhs.im;

		return out;
	}

	MyComplex& operator-(const MyComplex& rhs)
	{
		MyComplex out;
		out.real = real - rhs.real;
		out.im = im - rhs.im;

		return out;
	}

	MyComplex& operator-(double& rhs)
	{
		MyComplex out;
		out.real = real - rhs;
		out.im = im;

		return out;
	}

	friend MyComplex& operator-(double& lhs, MyComplex& rhs)
	{
		MyComplex out;
		out.real = lhs - rhs.real;
		out.im = -rhs.im;

		return out;
	}

	MyComplex& operator-(const double& rhs)
	{
		MyComplex out;
		out.real = real - rhs;
		out.im = im;

		return out;
	}

	friend MyComplex& operator-(const double& lhs, MyComplex& rhs)
	{
		MyComplex out;
		out.real = lhs - rhs.real;
		out.im = -rhs.im;

		return out;
	}

	MyComplex& operator-=(MyComplex& rhs)
	{
		real -= rhs.real;
		im -= rhs.im;

		return *this;
	}

	MyComplex& operator-=(const MyComplex& rhs)
	{
		real -= rhs.real;
		im -= rhs.im;

		return *this;
	}

	MyComplex& operator-=(double& rhs)
	{
		real -= rhs;

		return *this;
	}

	MyComplex& operator-=(const double& rhs)
	{
		real -= rhs;

		return *this;
	}

	MyComplex& operator*(MyComplex& rhs)
	{
		MyComplex out;
		out.real = real * rhs.real - im * rhs.im;
		out.im = real * rhs.im + im * rhs.real;

		return out;
	}

	MyComplex& operator*(const MyComplex& rhs)
	{
		MyComplex out;
		out.real = real * rhs.real - im * rhs.im;
		out.im = real * rhs.im + im * rhs.real;

		return out;
	}

	MyComplex& operator*(double& rhs)
	{
		MyComplex out;
		out.real = real * rhs;
		out.im = im * rhs;

		return out;
	}

	friend MyComplex& operator*(double& lhs, MyComplex& rhs)
	{
		MyComplex out;
		out.real = lhs * rhs.real;
		out.im = lhs * rhs.im;

		return out;
	}

	MyComplex& operator*(const double& rhs)
	{
		MyComplex out;
		out.real = real * rhs;
		out.im = im * rhs;

		return out;
	}

	friend MyComplex& operator*(const double& lhs, MyComplex& rhs)
	{
		MyComplex out;
		out.real = lhs * rhs.real;
		out.im = lhs * rhs.im;

		return out;
	}

	MyComplex& operator*=(MyComplex& rhs)
	{
		real = real * rhs.real - im * rhs.im;
		im = real * rhs.im + im * rhs.real;

		return *this;
	}

	MyComplex& operator*=(const MyComplex& rhs)
	{
		real = real * rhs.real - im * rhs.im;
		im = real * rhs.im + im * rhs.real;

		return *this;
	}

	MyComplex& operator*=(double& rhs)
	{
		real *= rhs;
		im *= rhs;

		return *this;
	}

	MyComplex& operator*=(const double& rhs)
	{
		real *= rhs;
		im *= rhs;

		return *this;
	}

	MyComplex& operator=(MyComplex& copy)
	{
		MyComplex out(copy.real, copy.im);
		return out;
	}

	MyComplex& operator=(const MyComplex& copy)
	{
		MyComplex out(copy.real, copy.im);
		return out;
	}

	friend ostream& operator<<(ostream& stream, MyComplex& num)
	{
		stream << num.real << ", " << num.im;
		return stream;
	}

	friend ostream& operator<<(ostream& stream, const MyComplex& num)
	{
		stream << num.real << ", " << num.im;
		return stream;
	}
};