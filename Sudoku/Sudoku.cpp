// Sudoku.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "CSudoku.h"
#include <vector>

// =============================================================================
// ALUMNO =====================================================================
// =============================================================================

string NombreAlumno = "Camille";
string ApellidosAlumno = "Caudrillier";
string NIUAlumno = "1591320"; // NIU alumno

// =============================================================================
// SOLUCIONADOR DE SODOKU ======================================================
// =============================================================================

// Soluciona ===================================================================

bool CSudoku::Soluciona() {
	int count = 0;
	int i = 0;
	int j = 0;
	for (int k = 1; k <= m_Dim; k++) {
		while (Casella(i, j) != 0) {
			if (i != m_Dim - 1) {
				i++;
			}
			else if (i == m_Dim - 1 && j != m_Dim - 1) {
				j++;
			}
			else {
				break;
				break;
				return true;
			}
		}
		int box = (i - i % m_n) / m_n + j - j % m_n;
		if (m_DigitsFiles[i * m_Dim + k] == false && m_DigitsColumnes[j * m_Dim + k] == false && m_DigitsCuadrats[box * m_Dim + k] == false) {
			m_Taulell[i * m_Dim + j] = k;
			m_DigitsFiles[i * m_Dim + k] == true;
			m_DigitsColumnes[j * m_Dim + k] == true;
			m_DigitsCuadrats[box * m_Dim + k] == true;
			Soluciona();
		}
		m_Taulell[i * m_Dim + j] = 0;
		m_DigitsFiles[i * m_Dim + k] == false;
		m_DigitsColumnes[j * m_Dim + k] == false;
		m_DigitsCuadrats[box * m_Dim + k] == false;
		box = 0;
		i = 0;
		j = 0;
	}
	for (i = 0; i < m_Dim; i++) {
		for (j = 0; j < m_Dim; j++) {
			if (Casella(i, j) != 0) { count += 1; }
		}
	}
}


// =============================================================================
// main ========================================================================
// =============================================================================

int main(int argc, char *argv[])
{
	if (!CheckNIU(NIUAlumno.c_str())) {
		cout << "Indentificacio dels alumnes incorrecte" << endl;
		return 1;
	}
	cout << "Nom Alumne .....: " << NombreAlumno << endl;
	cout << "Cognoms Alumne .: " << ApellidosAlumno << endl;
	cout << "NIU Alumne .....: " << NIUAlumno << endl;
	if (argc != 3) {
		cout << "Uso: Sudoku FicheroSudoku FitxerSolucioSudoku" << endl;
		return 1;
	}
	CSudoku taulell;
	taulell.Load(argv[1]);
	cout << "SUDOKU:" << endl;
	cout << taulell;
	double t0 = Clock();
	// Solucionar 
	bool HiHaSolucio = taulell.Soluciona();
	double t1 = Clock();
	if (HiHaSolucio) {
		cout << "SOLUCIO:" << endl;
		cout << taulell;
		taulell.Save(argv[2]);
	}
	else {
		cout << "NO TE SOLUCIO" << endl;
	}
	cout << "TIEMPO DE EJECUCION: " << t1 - t0 << endl;
    return 0;
}