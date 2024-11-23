#include <iostream>
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;
    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

template <typename T>
class Pila {
private:
    Nodo<T>* cima;
public:
    Pila() : cima(nullptr) {}

    void push(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        nuevoNodo->siguiente = cima;
        cima = nuevoNodo;
    }

    void pop() {
        if (cima != nullptr) {
            Nodo<T>* nodoAEliminar = cima;
            cima = cima->siguiente;
            delete nodoAEliminar;
        }
    }

    T top() {
        if (cima != nullptr) {
            return cima->dato;
        }
        throw runtime_error("Pila vacía");
    }

    bool empty() {
        return cima == nullptr;
    }
};

template <typename T>
void insertarEnFondo(Pila<T>& pila, T valor) {
    if (pila.empty()) {
        pila.push(valor);
    } else {
        T temp = pila.top();
        pila.pop();
        insertarEnFondo(pila, valor);
        pila.push(temp);
    }
}


void leerValores(Pila<int>& pila) {
    int n, valor;
    cout << "Ingrese el número de elementos: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> valor;
        pila.push(valor);
    }
}

void imprimirPila(Pila<int> pila) {
    Pila<int> auxPila; 
    while (!pila.empty()) {
        auxPila.push(pila.top());
        pila.pop();
    }
    while (!auxPila.empty()) {
        cout << auxPila.top() << " ";
        auxPila.pop();
    }
    cout << endl;
}

int main() {
    Pila<int> pila;
    leerValores(pila);

    cout << "Pila invertida: ";
    imprimirPila(pila);

    return 0;
}