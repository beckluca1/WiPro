#pragma once //Vermeiden von Mehrfacheinbindung

#include "MyComplex.h"  //Einbinden der Klasse für komplexe Zahlen

class JuliaCalculator
{
public:

	//Werte aus JuliaTabelle
	MyComplex minValue;
	MyComplex maxValue;
	int realStep;
	int imStep;
	int exponent;
	int maxIteration;
	double maxRadius;
	MyComplex constant;

	//Datenpunkte für Diagramm
	vector<vector<int>> iterations;
	vector<vector<MyComplex>> positions;

	//Standartkonstruktor mit Standartwerten
	JuliaCalculator()
	{
		minValue = MyComplex(0,0);
		maxValue = MyComplex(1,1);
		realStep = 100;
		imStep = 100;
		exponent = 2;
		maxIteration = 1000;
		maxRadius = 100;
		constant = MyComplex(0, 0);
	}

	//Konstruktor für Endanwendung
	JuliaCalculator(MyComplex inMinValue, MyComplex inMaxValue, int inRealStep, int inImStep, int inExponent, int inMaxIteration, double inMaxRadius, MyComplex inConstant)
	{
		minValue = inMinValue;
		maxValue = inMaxValue;
		realStep = inRealStep;
		imStep = inImStep;
		exponent = inExponent;
		maxIteration = inMaxIteration;
		maxRadius = inMaxRadius;
		constant = inConstant;
	}

	//Berechnen der Folge
	int iterateDataPoint(MyComplex value, MyComplex newConstant)
	{
		MyComplex currentValue = value;
		for (int i = 0; i < maxIteration; i++)
		{
			currentValue = currentValue.power(exponent) + newConstant;

			if (currentValue.norm() > maxRadius)
				return i + 1;
		}

		return maxIteration;
	}

	//Rechnet iterativ für alle Datenpunkte die Folgen aus --> Aufgabe 2) 
	void calculateFixedConstant()
	{
		iterations = vector<vector<int>>();
		positions = vector<vector<MyComplex>>();

		for (int i = 0; i <= imStep; i++)
		{
			cout << i << " / " << imStep << endl;

			iterations.push_back(vector<int>(0));
			positions.push_back(vector<MyComplex>(0));

			for (int j = 0; j <= realStep; j++)
			{
				double factorReal = double(j) / double(realStep);
				double factorIm = double(i) / double(imStep);

				double real = minValue.real + (maxValue.real - minValue.real) * factorReal;
				double im = minValue.im + (maxValue.im - minValue.im) * factorIm;
				MyComplex value(real, im);

				int iteration = iterateDataPoint(value, constant);

				iterations[i].push_back(iteration);
				positions[i].push_back(value);
			}
		}
	}

	//
	void calculateFixedStart()
	{
		iterations = vector<vector<int>>();
		positions = vector<vector<MyComplex>>();

		for (int i = 0; i <= imStep; i++)
		{
			cout << i << " / " << imStep << endl;

			iterations.push_back(vector<int>(0));
			positions.push_back(vector<MyComplex>(0));

			for (int j = 0; j <= realStep; j++)
			{
				double factorReal = double(j) / double(realStep);
				double factorIm = double(i) / double(imStep);

				double real = minValue.real + (maxValue.real - minValue.real) * factorReal;
				double im = minValue.im + (maxValue.im - minValue.im) * factorIm;
				MyComplex newConstant(real, im);

				int iteration = iterateDataPoint(MyComplex(0,0), newConstant);

				iterations[i].push_back(iteration);
				positions[i].push_back(newConstant);
			}
		}
	}
};