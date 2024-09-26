# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 2: Cadenas y lenguajes
# Autor: Daniel Palenzuela Álvarez
# Archivo: Makefile
# Compilar: make
# Ejecutar: ./p02_strings filein.txt fileout.txt opcode (1 al 5)
# Ayuda: ./p02_strings --help
# Limpiar archivos generados: make clean

# Especificar el compilador y las opciones de compilación
CXX = g++
CXXFLAGS = -Wall -std=c++17  # Habilitar todas las advertencias y usar el estándar C++17

# Compilar todo el proyecto
all: p02_strings

# Regla para compilar el ejecutable a partir de los archivos objeto
p02_strings: main.o Strings.o
	$(CXX) $(CXXFLAGS) -o p02_strings main.o Strings.o

# Regla para compilar main.cc
main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

# Regla para compilar Strings.cc
Strings.o: Strings.cc
	$(CXX) $(CXXFLAGS) -c Strings.cc

# Regla para limpiar el directorio
clean:
	rm -f *.o p02_strings