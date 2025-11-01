/**
 * @file Estudiante.h
 * @brief Definición de la clase Estudiante.
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
using namespace std;

/**
 * @class Estudiante
 * @brief Representa a un estudiante con su información académica básica.
 */
class Estudiante {
private:
    string nombre;
    int id;
    int programa;
    float promedio;
    int creditosAprobados;

public:
    /**
     * @brief Constructor que inicializa todos los atributos del estudiante
     * @param nombre Nombre del estudiante
     * @param id Identificador del estudiante
     * @param programa Código del programa académico
     * @param promedio Promedio ponderado inicial
     * @param creditosAprobados Créditos aprobados al momento de crear el objeto
     */
    Estudiante(string nombre, int id, int programa, float promedio, int creditosAprobados);

    /**
     * @brief Registra una nueva nota y actualiza el promedio ponderado
     * @param nota Nota obtenida
     * @param creditos Créditos correspondientes a la asignatura
     */
    void registrarNota(float nota, int creditos);

    /**
     * @brief Incrementa el número total de créditos aprobados
     * @param creditos Créditos adicionales aprobados
     */
    void agregarCreditos(int creditos);

    /**
     * @brief Devuelve una descripción general del estudiante
     * @return Cadena con el resumen del estudiante (nombre, id, programa, promedio, créditos aprobados)
     */
    string obtenerResumen() const;

    /**
     * @brief Verifica si el estudiante cumple con los requisitos de grado
     * @param creditosRequeridos Número de créditos necesarios para graduarse
     * @return true si cumple los créditos requeridos, false en caso contrario
     */
    bool cumpleRequisitosGrado(int creditosRequeridos) const;
};
#endif // ESTUDIANTE_H