// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 23/09/2024
// Archivo: main.cc
// Descripción: Programa cliente para operar con cadenas y lenguajes

#include "Strings.h"
#include <fstream>  // Para manejar archivos
#include <iostream>
#include <sstream>  // Para manejo de cadenas
#include <vector>  // Para utilizar std::vector

// Función para leer el archivo de entrada y extraer las cadenas y alfabetos
std::vector<String> ReadInputFile(const std::string& filename) {
    std::ifstream file(filename);  // Abrir archivo de entrada
    std::vector<String> strings;   // Vector para almacenar los objetos String
    std::string line;

    // Leer línea por línea el archivo
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string str, alphabet_chars;
        // Leer la cadena y el alfabeto en la línea actual
        iss >> str >> alphabet_chars;

        // Convertir los caracteres del alfabeto en un conjunto (set)
        std::set<char> alphabet(alphabet_chars.begin(), alphabet_chars.end());
        // Añadir la cadena al vector de cadenas
        strings.emplace_back(str, alphabet);
    }

    return strings;  // Devuelve todas las cadenas y alfabetos leídos
}

// Función para escribir el resultado en el archivo de salida
void WriteOutputFile(const std::string& filename, const std::vector<std::string>& results) {
    std::ofstream file(filename);  // Abrir archivo de salida
    // Escribir cada resultado en una nueva línea
    for (const auto& result : results) {
        file << result << std::endl;
    }
}

// Función que muestra la ayuda del programa
void ShowHelp() {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n";
    std::cout << "Códigos de las operaciones:\n";
    std::cout << "1: Mostrar alfabeto\n";
    std::cout << "2: Mostrar longitud de la cadena\n";
    std::cout << "3: Invertir la cadena\n";
    std::cout << "4: Mostrar prefijos\n";
    std::cout << "5: Mostrar sufijos\n";
}

int main(int argc, char* argv[]) {
    // Verificar el número de argumentos
    if (argc != 4) {
        ShowHelp();
        return 1;
    }

    // Obtener los parámetros de línea de comandos
    std::string input_file = argv[1];
    std::string output_file = argv[2];
    int opcode = std::stoi(argv[3]);

    // Leer las cadenas desde el archivo de entrada
    auto strings = ReadInputFile(input_file);
    std::vector<std::string> results;

    // Procesar cada cadena en función del código de operación (opcode)
    for (const auto& string : strings) {
        switch (opcode) {
            case 1: {  // Mostrar el alfabeto de la cadena
                std::ostringstream oss;
                oss << "{";
                for (const auto& ch : string.GetAlphabet()) {
                    oss << ch << ", ";
                }
                oss.seekp(-2, std::ios_base::end);  // Eliminar la última coma
                oss << "}";
                results.push_back(oss.str());
                break;
            }
            case 2:  // Mostrar la longitud de la cadena
                results.push_back(std::to_string(string.Length()));
                break;
            case 3:  // Invertir la cadena
                results.push_back(string.Reverse());
                break;
            case 4: {  // Mostrar prefijos de la cadena
                std::ostringstream oss;
                oss << "{";
                for (const auto& prefix : string.Prefixes()) {
                    oss << prefix << ", ";
                }
                oss.seekp(-2, std::ios_base::end);  // Eliminar la última coma
                oss << "}";
                results.push_back(oss.str());
                break;
            }
            case 5: {  // Mostrar sufijos de la cadena
                std::ostringstream oss;
                oss << "{";
                bool first = true;  // Para controlar la inserción de la coma
                for (const auto& suffix : string.Suffixes()) {
                    if (!first) {
                        oss << " , ";
                    }
                    oss << suffix;
                    first = false;
                }
                oss << " }";  // Cerrar la lista
                results.push_back(oss.str());
                break;
            }
            default:
                ShowHelp();  // Mostrar ayuda si el opcode es inválido
                return 1;
        }
    }

    // Escribir los resultados en el archivo de salida
    WriteOutputFile(output_file, results);
    return 0;
}