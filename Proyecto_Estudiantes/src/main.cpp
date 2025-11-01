#include "../include/Estudiante.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<Estudiante> estudiantes;

    estudiantes.push_back(Estudiante("Juan Diego", 101, 1, 4.2, 80));
    estudiantes.push_back(Estudiante("Maria Camila", 102, 2, 3.9, 90));
    estudiantes.push_back(Estudiante("Luisa Ramirez", 103, 1, 4.5, 100));

    estudiantes[0].registrarNota(4.8, 3);
    estudiantes[1].registrarNota(3.5, 4);
    estudiantes[2].registrarNota(4.2, 2);

    cout << "=== Resumen de estudiantes ===\n";
    for (const auto& e : estudiantes) {
        cout << e.obtenerResumen() << endl;
    }

    float promedioGeneral = 0;
    for (const auto& e : estudiantes)
        promedioGeneral += e.cumpleRequisitosGrado(90) ? e.cumpleRequisitosGrado(90) : 0;
    promedioGeneral /= estudiantes.size();
    cout << "\nPromedio general del grupo: " << promedioGeneral << endl;

    ofstream reporte("reporte_estudiantes.txt");
    if (reporte.is_open()) {
        reporte << "Reporte Académico\n";
        for (const auto& e : estudiantes) {
            reporte << e.obtenerResumen() << endl;
        }
        reporte.close();
        cout << "\nReporte generado: reporte_estudiantes.txt\n";
    } else {
        cout << "Error al generar el reporte.\n";
    }
    return 0;
}