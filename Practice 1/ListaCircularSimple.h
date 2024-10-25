#ifndef LISTACIRCULARSIMPLE_H
#define LISTACIRCULARSIMPLE_H

#include <iostream>
#include "Nodo.h"

template <typename T>
class ListaCircularSimple {
private:
    Nodo<T>* cabeza;

public:
    ListaCircularSimple() : cabeza(nullptr) {}

    void agregar(T valor) {
        Nodo<T>* nodo = new Nodo<T>(valor);
        if (!cabeza) {
            cabeza = nodo;
            nodo->siguiente = cabeza;
        } else {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente != cabeza) {
                temp = temp->siguiente;
            }
            temp->siguiente = nodo;
            nodo->siguiente = cabeza;
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

    ~ListaCircularSimple() {
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

#endif  // LISTACIRCULARSIMPLE_H