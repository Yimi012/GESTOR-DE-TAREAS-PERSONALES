// main.cpp
// Sistema simple de gestión de tareas (C++) - C++11 o superior

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

struct Tarea {
    string descripcion;
    bool completada;
};

void agregarTarea(vector<Tarea>& tareas) {
    string desc;
    cout << "Ingrese la descripcion de la tarea: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, desc);
    if (desc.empty()) {
        cout << "Descripcion vacia: tarea no agregada.\n";
        return;
    }
    tareas.push_back({desc, false});
    cout << "Tarea agregada correctamente.\n";
}

void listarTareas(const vector<Tarea>& tareas) {
    cout << "\n--- Lista de Tareas ---\n";
    if (tareas.empty()) {
        cout << "No hay tareas registradas.\n";
        return;
    }
    for (size_t i = 0; i < tareas.size(); ++i) {
        cout << i + 1 << ". " << tareas[i].descripcion
             << (tareas[i].completada ? " [Completada]" : " [Pendiente]") << '\n';
    }
}

void completarTarea(vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "No hay tareas para completar.\n";
        return;
    }
    cout << "Ingrese el numero de la tarea a completar: ";
    int index;
    if (!(cin >> index)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: debe ingresar un numero valido.\n";
        return;
    }
    if (index < 1 || static_cast<size_t>(index) > tareas.size()) {
        cout << "Error: numero fuera de rango.\n";
        return;
    }
    if (tareas[index - 1].completada) {
        cout << "La tarea ya esta marcada como completada.\n";
    } else {
        tareas[index - 1].completada = true;
        cout << "Tarea marcada como completada.\n";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void eliminarTarea(vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "No hay tareas para eliminar.\n";
        return;
    }
    cout << "Ingrese el numero de la tarea a eliminar: ";
    int index;
    if (!(cin >> index)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: debe ingresar un numero valido.\n";
        return;
    }
    if (index < 1 || static_cast<size_t>(index) > tareas.size()) {
        cout << "Error: numero fuera de rango.\n";
        return;
    }
    tareas.erase(tareas.begin() + (index - 1));
    cout << "Tarea eliminada correctamente.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mostrarMenu() {
    cout << "\n--- Menu ---\n";
    cout << "1. Agregar tarea\n";
    cout << "2. Listar tareas\n";
    cout << "3. Completar tarea\n";
    cout << "4. Eliminar tarea\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    vector<Tarea> tareas;
    int opcion = 0;

    do {
        mostrarMenu();
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Ingrese un numero entre 1 y 5.\n";
            continue;
        }

        switch (opcion) {
            case 1: agregarTarea(tareas); break;
            case 2: listarTareas(tareas); break;
            case 3: completarTarea(tareas); break;
            case 4: eliminarTarea(tareas); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida. Intente nuevamente.\n"; break;
        }
    } while (opcion != 5);

    return 0;
}
// Función de ejemplo: marcar tarea como hecha

