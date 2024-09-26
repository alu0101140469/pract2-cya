// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 23/09/2024
// Archivo: Strings.h
// Descripción: Definición de clases para cadenas y lenguajes

#ifndef STRINGS_H  // Include guard para evitar múltiples inclusiones
#define STRINGS_H

#include <string>
#include <set>
#include <iostream>
#include <vector>

// Clase String: representa una cadena con su alfabeto asociado
class String {
public:
    // Constructor: inicializa la cadena y su alfabeto
    String(const std::string& str, const std::set<char>& alphabet);
    
    // Métodos públicos:
    // Devuelve el alfabeto asociado a la cadena
    std::set<char> GetAlphabet() const;
    
    // Devuelve la longitud de la cadena
    size_t Length() const;
    
    // Devuelve la cadena inversa
    std::string Reverse() const;
    
    // Devuelve el conjunto de prefijos de la cadena
    std::set<std::string> Prefixes() const;
    
    // Devuelve el conjunto de sufijos de la cadena
    std::vector<std::string> Suffixes() const;

    // MODIF: devuelve la union de todas las cadenas
    std::string GetString() const {
        return str_;
    }
    
    // Sobrecarga del operador de salida para mostrar la cadena
    friend std::ostream& operator<<(std::ostream& os, const String& str);
    
private:
    std::string str_;  // Almacena la cadena
    std::set<char> alphabet_;  // Almacena el alfabeto de la cadena
};

#endif