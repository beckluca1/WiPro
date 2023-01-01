#pragma once //Mehrfacheinbindung verhindern
#pragma warning(disable:4996) //Unterdrücken von Warnungen bei Nutzung von fopen (statt fopen_s)


//Inkludieren der notwendigen Klassen
#include "JuliaCalculator.h"
#include "MyComplex.h"

#include <iostream>
#include <vector>

class GnuData
{
public:
	FILE* fp = NULL;
	string fileName;

	vector<vector<MyComplex>>* positions;
	vector<vector<int>>* iterations;

	GnuData(string inFileName)
	{
		fileName = inFileName;

		positions = NULL;
		iterations = NULL;
	}

	void setDataPoints(JuliaCalculator* calculator)
	{
		//Frägt die Referenz an, nicht das Objekt selbst --> Datensparen!
		positions = &calculator->positions; 
		iterations = &calculator->iterations;
	}

	//Erstellen der Datei mit allen Datenpunkten und deren Werte
	void createFile() 
	{
		//Automatisierte Erstellung der Datei
		fp = fopen(fileName.c_str(), "w"); 

		////Error bei Fehler bei Dateierstellung
		if (!fp) 
		{
			std::perror("File opening failed");
			return;
		}

		//Schreiben der Datenpunkte und ihrer Werte in die Datei
		for (int i = 0; i < positions->size(); i++)
		{
			for (int j = 0; j < (*positions)[i].size(); j++)
			{
				fprintf(fp, "%f %f %d\n", (*positions)[i][j].real, (*positions)[i][j].im, (*iterations)[i][j]);
			}

			fprintf(fp, "\n");
		}
	}
};

//Aufrufen der Gnuplot-Befehle und damit grafische Ausgabe
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