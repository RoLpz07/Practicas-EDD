#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
    T valor;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(T valor) : valor(valor), siguiente(nullptr), anterior(nullptr) {}
};

#endif  // NODO_H