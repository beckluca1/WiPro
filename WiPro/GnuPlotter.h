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
	vector<int> iterations;

	int width;
	int height;

	GnuData(string inFileName, int inWidth, int inHeight)
	{
		fileName = inFileName;
		width = inWidth;
		height = inHeight;

		xCoords = vector<double>(0);
		yCoords = vector<double>(0);
		iterations = vector<int>(0);
	}

	void addDataPoint(double inX, double inY, int inIteration)
	{
		xCoords.push_back(inX);
		yCoords.push_back(inY);
		iterations.push_back(inIteration);
	}

	void addDataPoint(MyComplex complex, int inIteration)
	{
		xCoords.push_back(complex.real);
		yCoords.push_back(complex.im);
		iterations.push_back(inIteration);
	}

	vector<vector<int>> sortData()
	{
		vector<vector<int>> indices;
		for (int i = 0; i < xCoords.size(); i++)
		{
			while (xCoords[i] >= indices.size())
			{
				indices.push_back(vector<int>());
			}

			indices[int(xCoords[i])].push_back(i);
		}

		return indices;
	}

	void createFile()
	{
		fp = fopen(fileName.c_str(), "w");

		if (!fp)
		{
			std::perror("File opening failed");
			return;
		}

		vector<vector<int>> indices = sortData();

		for (int i = 0; i < indices.size(); i++)
		{
			for (int j = 0; j < indices[i].size(); j++)
			{
				fprintf(fp, "%f %f %d\n", xCoords[indices[i][j]], yCoords[indices[i][j]], iterations[indices[i][j]]);
			}
			if (indices[i].size() != 0)
			{
				fprintf(fp, "\n");
			}
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

		string plot = "splot '" + data.fileName + "' u 1:2:3";
		const char* gnucommands[] = { "set title \"2D-Plot\"", "set pm3d map", plot.c_str()};

		gnupipe = _popen("gnuplot -persistent", "w");

		for (int i = 0; i < 3; i++)
		{
			fprintf(gnupipe, "%s\n", gnucommands[i]);
		}
	}
};