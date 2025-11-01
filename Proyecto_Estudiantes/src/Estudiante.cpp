#include "../include/Estudiante.h"
#include <sstream>

/**
 * @brief Constructor que inicializa todos los atributos
 */
Estudiante::Estudiante(string nombre, int id, int programa, float promedio, int creditosAprobados)
    : nombre(nombre), id(id), programa(programa), promedio(promedio), creditosAprobados(creditosAprobados) {}

/**
 * @brief Registra una nueva nota y actualiza el promedio ponderado
 */
void Estudiante::registrarNota(float nota, int creditos) {
    float totalAnterior = promedio * creditosAprobados;
    creditosAprobados += creditos;
    promedio = (totalAnterior + nota * creditos) / creditosAprobados;
}

/**
 * @brief Agrega créditos aprobados adicionales
 */
void Estudiante::agregarCreditos(int creditos) {
    creditosAprobados += creditos;
}

/**
 * @brief Retorna una descripción general del estudiante
 */
string Estudiante::obtenerResumen() const {
    ostringstream resumen;
    resumen << "Nombre: " << nombre
            << " | ID: " << id
            << " | Programa: " << programa
            << " | Promedio: " << promedio
            << " | Créditos aprobados: " << creditosAprobados;
    return resumen.str();
}

/**
 * @brief Verifica si el estudiante cumple los requisitos de grado
 */
bool Estudiante::cumpleRequisitosGrado(int creditosRequeridos) const {
    return creditosAprobados >= creditosRequeridos;
}