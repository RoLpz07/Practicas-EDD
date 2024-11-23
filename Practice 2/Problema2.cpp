#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T dato) : dato(dato), siguiente(nullptr) {}
};

template <typename T>
class Cola {
private:
    Nodo<T>* frente;
    Nodo<T>* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    void push(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        if (final != nullptr) {
            final->siguiente = nuevoNodo;
        }
        final = nuevoNodo;
        if (frente == nullptr) {
            frente = nuevoNodo;
        }
    }

    void pop() {
        if (frente != nullptr) {
            Nodo<T>* temp = frente;
            frente = frente->siguiente;
            if (frente == nullptr) {
                final = nullptr;
            }
            delete temp;
        }
    }

    T front() {
        if (frente != nullptr) {
            return frente->dato;
        }
        throw out_of_range("La cola está vacía");
    }

    bool empty() {
        return frente == nullptr;
    }
};

struct Persona {
    char prioridad;
    string nombre;

    Persona(char p, string n) : prioridad(p), nombre(n) {}
};

void procesarCola(Cola<Persona>& cola) {
    map<char, vector<Persona>> prioridadMap;

    while (!cola.empty()) {
        Persona persona = cola.front();
        cola.pop();
        prioridadMap[persona.prioridad].push_back(persona);
    }

    for (char prioridad : {'A', 'B', 'C', 'D'}) {
        for (const Persona& persona : prioridadMap[prioridad]) {
            cout << "Procesando: " << persona.nombre << " con prioridad " << persona.prioridad << endl;
        }
    }
}

int main() {
    Cola<Persona> cola;
    int n;
    cout << "Ingrese el número de personas: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string nombre;
        char prioridad;
        cout << "Ingrese el nombre de la persona: ";
        cin >> nombre;
        cout << "Ingrese la prioridad de la persona (A, B, C, D): ";
        cin >> prioridad;
        cola.push(Persona(prioridad, nombre));
    }

    procesarCola(cola);

    return 0;
}