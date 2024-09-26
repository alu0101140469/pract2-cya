// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 23/09/2024
// Archivo: Strings.cc
// Descripción: Implementación de las clases para manipulación de cadenas y lenguajes

#include "Strings.h"
#include <algorithm>  // Para std::reverse

// Constructor: inicializa los atributos con los valores proporcionados
String::String(const std::string& str, const std::set<char>& alphabet)
    : str_(str), alphabet_(alphabet) {}

// Método que devuelve el alfabeto de la cadena
std::set<char> String::GetAlphabet() const {
    return alphabet_;
}

// Método que devuelve la longitud de la cadena
size_t String::Length() const {
    return str_.length();
}

// Método que devuelve la cadena inversa utilizando la función std::reverse
std::string String::Reverse() const {
    std::string rev = str_;  // Copia la cadena original
    std::reverse(rev.begin(), rev.end());  // Invierte la cadena
    return rev;  // Devuelve la cadena invertida
}

// Método que calcula y devuelve el conjunto de prefijos de la cadena
std::set<std::string> String::Prefixes() const {
    std::set<std::string> prefixes;
    prefixes.insert("&");
    // Se generan los prefijos añadiendo cada vez un símbolo más de la cadena
    for (size_t i = 1; i <= str_.length(); ++i) {
        prefixes.insert(str_.substr(0, i));
    }
    return prefixes;  // Devuelve el conjunto de prefijos
}

// Método que calcula y devuelve el conjunto de sufijos de la cadena
std::vector<std::string> String::Suffixes() const {
    std::vector<std::string> suffixes;
    suffixes.push_back("&");
    // Se generan los sufijos eliminando cada vez un símbolo más del principio
    for (size_t i = str_.length(); i > 0; --i) {
        suffixes.push_back(str_.substr(i - 1));
    }
    return suffixes;  // Devuelve el conjunto de sufijos
}

// MODIF: Método GetString


// Sobrecarga del operador de salida para imprimir la cadena
std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.str_;  // Imprime la cadena almacenada
    return os;
}