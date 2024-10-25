#include <iostream>
#include "ListaCircularSimple.h"
#include "ListaCircularDoblementeEnlazada.h"
#include "Persona.h"

int main() {
    // Crear personas
    Persona persona1("Juan", 25);
    Persona persona2("Maria", 30);
    Persona persona3("Pedro", 20);

    // Crear listas circulares simples y doblemente enlazadas
    ListaCircularSimple<Persona> listaDesordenada;
    ListaCircularDoblementeEnlazada<Persona> listaOrdenada;

    // Agregar personas a las listas
    listaDesordenada.agregar(persona1);
    listaDesordenada.agregar(persona2);
    listaDesordenada.agregar(persona3);

    listaOrdenada.agregar(persona1);
    listaOrdenada.agregar(persona2);
    listaOrdenada.agregar(persona3);

    // Imprimir las listas
    std::cout << "Lista desordenada:" << std::endl;
    listaDesordenada.imprimir();

    std::cout << std::endl << "Lista ordenada:" << std::endl;
    listaOrdenada.imprimir();

    return 0;
}