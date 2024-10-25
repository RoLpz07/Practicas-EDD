#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
public:
    std::string nombre;
    int edad;

    Persona(std::string nombre, int edad) : nombre(nombre), edad(edad) {}

    bool operator<(const Persona& otra) const {
        return edad < otra.edad;
    }

    bool operator==(const Persona& otra) const {
        return nombre == otra.nombre && edad == otra.edad;
    }

    friend std::ostream& operator<<(std::ostream& os, const Persona& persona) {
        os << "Nombre: " << persona.nombre << ", Edad: " << persona.edad;
        return os;
    }
};

#endif  // PERSONA_H