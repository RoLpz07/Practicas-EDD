#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T dato;
    int prioridad;
    Nodo* siguiente;
};

template <typename T>
class ColaDePrioridad {
private:
    Nodo<T>* frente;

public:
    ColaDePrioridad() : frente(nullptr) {}

    ~ColaDePrioridad() {
        while (frente != nullptr) {
            Nodo<T>* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

    void insertar(T dato, int prioridad) {
        Nodo<T>* nuevoNodo = new Nodo<T>{dato, prioridad, nullptr};
        if (frente == nullptr || frente->prioridad > prioridad) {
            nuevoNodo->siguiente = frente;
            frente = nuevoNodo;
        } else {
            Nodo<T>* temp = frente;
            while (temp->siguiente != nullptr && temp->siguiente->prioridad <= prioridad) {
                temp = temp->siguiente;
            }
            nuevoNodo->siguiente = temp->siguiente;
            temp->siguiente = nuevoNodo;
        }
    }

    void eliminar() {
        if (frente == nullptr) {
            cout << "La cola está vacía" << endl;
            return;
        }
        Nodo<T>* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }

    T obtenerFrente() {
        if (frente == nullptr) {
            throw runtime_error("La cola está vacía");
        }
        return frente->dato;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaDePrioridad<int> cp;
    int n, dato, prioridad;

    cout << "Ingrese el número de elementos: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Ingrese el dato y la prioridad del elemento separados por un espacio (Dato Prioridad): ";
        cin >> dato >> prioridad;
        cp.insertar(dato, prioridad);
    }

    cout << "Elementos en la cola de prioridad: ";
    while (!cp.estaVacia()) {
        cout << cp.obtenerFrente() << " ";
        cp.eliminar();
    }
    cout << endl;

    return 0;
}