#include <complex>
#include <fstream>
#include <iostream>
#include <cmath>

#define SIZEX 1000
#define SIZEY SIZEX
#define DEPTH 254

#define LIMIT 100
#define SMALL 1
#define SCA 4
using namespace std;

int tab[SIZEX][SIZEY];

int main() {
	//float i, j;
	for (int ii = 0; ii < SIZEX; ii++) {
		for (int jj = 0; jj < SIZEY; jj++) {
			complex<float> p((float)(ii - SIZEX / 2)*SCA / SIZEX, (float)(jj - SIZEY / 2)*SCA / SIZEY);
			complex<float> z(0, 0);
			for (int kk = 0; kk < LIMIT; kk++) z = z*z + p;

			float len;
			if ((len = z.imag()*z.imag() + z.real()*z.real()) < SMALL) tab[jj][ii] = DEPTH;// / sqrt(len);
			else tab[jj][ii] = 0;// DEPTH / sqrt(len);
			//cout << ii << " " << jj << endl;
			//cout << z.real() << " " << z.imag() << endl;
		}
		if(ii%40==0)cout << ii/40 << "%\n";
	}

	fstream plik;
	plik.open("Mandelbrot_set.pgm", ios::out | ios::trunc);

	plik << "P2\n" << SIZEX << " " << SIZEY << " " << DEPTH << "\n";

	for (int ii = 0; ii < SIZEX; ii++) {
		for (int jj = 0; jj < SIZEY; jj++) {
			if (jj % 70 == 0)plik << "\n";
			plik << tab[ii][jj]<<" ";
		}
		plik << "\n";
	}

	plik.close();

	return 0;
}