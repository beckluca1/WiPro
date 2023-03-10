#pragma once //Mehrfacheinbindung verhindern

#include <iostream>

using namespace std;

class MyComplex
{
public:

	//Variablen der Instanzen
	double real;
	double im;

	//Standartkonstuktor mit Standartwerten
	MyComplex()
	{
		real = 0;
		im = 0;
	}

	//Konstruktor mit Eingabem?glichkeit
	MyComplex(double inReal, double inIm)
	{
		real = inReal;
		im = inIm;
	}

	//Getter-Funktion (nicht wie gefordert benannt, da sonst die public variable h?tte umbenannt werden m?ssen)
	double realGetter() 
	{
		return real;
	}

	//Getter-Funktion (nicht wie gefordert benannt, da sonst die public variable h?tte umbenannt werden m?ssen)
	double imagGetter() 
	{
		return im;
	}


	//Berechnet die Norm der komplexen Zahl (Betrag, L?nge, ...)
	double norm()
	{
		return sqrt(pow(real, 2) + pow(im, 2));
	}

	//Berechnet komplexe Zahl^Exponent
	MyComplex power(int exponent)
	{
		MyComplex value = MyComplex(real, im);

		for (int i = 0; i < exponent - 1;i++)
		{
			value *= MyComplex(real, im);
		}

		return value;
	}

	//Definition allgemeiner mathematischer Zusammenh?nge//

	MyComplex operator+()
	{
		MyComplex out;
		out.real = real;
		out.im = im;

		return out;
	}

	MyComplex operator-()
	{
		MyComplex out;
		out.real = -real;
		out.im = -im;

		return out;
	}

	MyComplex operator+(MyComplex& rhs)
	{
		MyComplex out;
		out.real = real + rhs.real;
		out.im = im + rhs.im;

		return out;
	}

	MyComplex operator+(const MyComplex& rhs)
	{
		MyComplex out;
		out.real = real + rhs.real;
		out.im = im + rhs.im;

		return out;
	}

	MyComplex operator+(double& rhs)
	{
		MyComplex out;
		out.real = real + rhs;
		out.im = im;

		return out;
	}

	friend MyComplex operator+(double& lhs, MyComplex& rhs)
	{
		MyComplex out;
		out.real = lhs + rhs.real;
		out.im = rhs.im;

		return out;
	}

	MyComplex operator+(const double& rhs)
	{
		MyComplex out;
		out.real = real + rhs;
		out.im = im;

		return out;
	}

	friend MyComplex operator+(const double& lhs, MyComplex& rhs)
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

	MyComplex operator-(MyComplex& rhs)
	{
		MyComplex out;
		out.real = real - rhs.real;
		out.im = im - rhs.im;

		return out;
	}

	MyComplex operator-(const MyComplex& rhs)
	{
		MyComplex out;
		out.real = real - rhs.real;
		out.im = im - rhs.im;

		return out;
	}

	MyComplex operator-(double& rhs)
	{
		MyComplex out;
		out.real = real - rhs;
		out.im = im;

		return out;
	}

	friend MyComplex operator-(double& lhs, MyComplex& rhs)
	{
		MyComplex out;
		out.real = lhs - rhs.real;
		out.im = -rhs.im;

		return out;
	}

	MyComplex operator-(const double& rhs)
	{
		MyComplex out;
		out.real = real - rhs;
		out.im = im;

		return out;
	}

	friend MyComplex operator-(const double& lhs, MyComplex& rhs)
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

	MyComplex operator*(MyComplex& rhs)
	{
		MyComplex out;
		out.real = real * rhs.real - im * rhs.im;
		out.im = real * rhs.im + im * rhs.real;

		return out;
	}

	MyComplex operator*(const MyComplex& rhs)
	{
		MyComplex out;
		out.real = real * rhs.real - im * rhs.im;
		out.im = real * rhs.im + im * rhs.real;

		return out;
	}

	MyComplex operator*(double& rhs)
	{
		MyComplex out;
		out.real = real * rhs;
		out.im = im * rhs;

		return out;
	}

	friend MyComplex operator*(double& lhs, MyComplex& rhs)
	{
		MyComplex out;
		out.real = lhs * rhs.real;
		out.im = lhs * rhs.im;

		return out;
	}

	MyComplex operator*(const double& rhs)
	{
		MyComplex out;
		out.real = real * rhs;
		out.im = im * rhs;

		return out;
	}

	friend MyComplex operator*(const double& lhs, MyComplex& rhs)
	{
		MyComplex out;
		out.real = lhs * rhs.real;
		out.im = lhs * rhs.im;

		return out;
	}

	MyComplex& operator*=(MyComplex& rhs)
	{
		double tempReal = real;
		real = real * rhs.real - im * rhs.im;
		im = tempReal * rhs.im + im * rhs.real;

		return *this;
	}

	MyComplex& operator*=(const MyComplex& rhs)
	{
		double tempReal = real;
		real = real * rhs.real - im * rhs.im;
		im = tempReal * rhs.im + im * rhs.real;

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
		real = copy.real;
		im = copy.im;
		return *this;
	}

	MyComplex& operator=(const MyComplex& copy)
	{
		real = copy.real;
		im = copy.im;
		return *this;
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