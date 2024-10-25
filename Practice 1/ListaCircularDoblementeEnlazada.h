#ifndef LISTACIRCULARDOBLEMENTEENLAZADA_H
#define LISTACIRCULARDOBLEMENTEENLAZADA_H

#include <iostream>
#include "Nodo.h"

template <typename T>
class ListaCircularDoblementeEnlazada {
private:
    Nodo<T>* cabeza;

public:
    ListaCircularDoblementeEnlazada() : cabeza(nullptr) {}

    void agregar(T valor) {
        Nodo<T>* nodo = new Nodo<T>(valor);
        if (!cabeza) {
            cabeza = nodo;
            nodo->siguiente = cabeza;
            nodo->anterior = cabeza;
        } else {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente != cabeza && temp->valor.edad < valor.edad) {
                temp = temp->siguiente;
            }
            if (temp->valor.edad > valor.edad) {
                nodo->siguiente = temp;
                nodo->anterior = temp->anterior;
                temp->anterior->siguiente = nodo;
                temp->anterior = nodo;
            } else {
                nodo->siguiente = temp;
                nodo->anterior = temp;
                nodo->siguiente->anterior = nodo;
                temp = nodo;
            }
            cabeza = temp;
        }
    }

    void imprimir() {
        Nodo<T>* temp = cabeza;
        while (true) {
            std::cout << temp->valor << std::endl;
            temp = temp->siguiente;
            if (temp == cabeza) {
                break;
            }
        }
    }

    ~ListaCircularDoblementeEnlazada() {
        if (cabeza) {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente != cabeza) {
                Nodo<T>* siguiente = temp->siguiente;
                delete temp;
                temp = siguiente;
            }
            delete temp;
        }
    }
};

#endif  // LISTACIRCULARDOBLEMENTEENLAZADA_H