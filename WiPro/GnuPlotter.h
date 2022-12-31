#pragma once
#pragma warning(disable:4996)

#include "WiPro.h"

class GnuData
{
public:
	FILE* fp = NULL;
	string fileName;

	vector<double> xCoords;
	vector<double> yCoords;

	GnuData(string inFileName)
	{
		fileName = inFileName;

		xCoords = vector<double>(0);
		yCoords = vector<double>(0);
	}

	void addDataPoint(double inX, double inY)
	{
		xCoords.push_back(inX);
		yCoords.push_back(inY);
	}

	void addDataPoint(MyComplex complex)
	{
		xCoords.push_back(complex.real);
		yCoords.push_back(complex.im);
	}

	void createFile()
	{
		fp = fopen(fileName.c_str(), "w");

		if (!fp)
		{
			std::perror("File opening failed");
			return;
		}

		for (int i = 0; i < xCoords.size(); i++)
		{
			fprintf(fp, "%f %f\n", xCoords[i], yCoords[i]);
		}
	}
};

class GnuPlotter
{
public:
	static void plotData(GnuData data)
	{
		data.createFile();

		FILE* gnupipe = NULL;

		string plot = "plot '" + data.fileName + "'";
		const char* gnucommands[] = { "set title \"Demos\"", plot.c_str()};

		gnupipe = _popen("gnuplot -persistent", "w");

		for (int i = 0; i < 2; i++)
		{
			fprintf(gnupipe, "%s\n", gnucommands[i]);
		}
	}
};