#include<iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


void Gauss(double**macierz, double*X, int n)
{
	double m = 0, s = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{

			if (macierz[i][i] == 0) return;
			m = -macierz[j][i] / macierz[i][i];
			for (int k = i + 1; k <= n; k++)
			{
				macierz[j][k] += m * macierz[i][k];
				//cout << macierz[j][k] << "d ";
			}
			//cout << endl;
		}
	}
	
	cout << endl;
	cout << "ROZWIAZANIA: " << endl;
	cout << endl;

	for (int i = n - 1; i >= 0; i--)
	{
		s = macierz[i][n];
		for (int j = n - 1; j >= i + 1; j--)
			s -= macierz[i][j] * X[j];
		if (macierz[i][i] == 0) return;
		X[i] = s / macierz[i][i];
	}
	for (int i = 0; i < n; i++)
		cout << X[i] << "  ";
	cout << endl;

	cout << endl;
};


int main() {
	double**macierz = new double*[4];
	for (int i = 0; i < 4; i++)
		macierz[i] = new double[5];
	fstream plik;

	plik.open("plik.txt", ios::in);
	if (plik.good() == true)
	{

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++) {
				plik >> macierz[i][j];

			}

	}
	plik.close();

	cout << "WCZYTANA MACIERZ: " << endl;
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << macierz[i][j] << "\t";
		} cout << endl;

	}
	cout << endl;
	cout << "***************************************" << endl;
	cout << endl;

	double*tab = new double[4];
	Gauss(macierz, tab, 4);

	system("pause");
	return 0;
}