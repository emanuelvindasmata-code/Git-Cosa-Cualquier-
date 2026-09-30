#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tarea {
    string descripcion;
    bool completada;
    string prioridad; 
};

void agregarTarea(vector<Tarea>& tareas);
void mostrarTareas(const vector<Tarea>& tareas);
void eliminarTarea(vector<Tarea>& tareas); 
void completarTarea(vector<Tarea>& tareas);

int main() {
    vector<Tarea> tareas;
    int opcion = 0;

    while (opcion != 5) {
        cout << "\nLISTA DE TAREAS\n\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Eliminar tarea\n";
        cout << "4. Marcar tarea como completada\n";
        cout << "5. Salir\n\n";
        cout << "Seleccione una opción: ";

        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarTarea(tareas);
                break;
            case 2:
                mostrarTareas(tareas);
                break;
            case 3:
                eliminarTarea(tareas);
                break;
            case 4:
                completarTarea(tareas);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}

void agregarTarea(vector<Tarea>& tareas) {
    Tarea nueva;
    
    cout << "Ingrese la tarea: ";
    getline(cin, nueva.descripcion);
    
    if (nueva.descripcion == "") {
        cout << "La tarea no puede estar vacia\n";
        return;
    }
    
    cout << "Ingrese la prioridad (Alta/Media/Baja): ";
    getline(cin, nueva.prioridad);
    
    nueva.completada = false;
    tareas.push_back(nueva);
    cout << "Tarea agregada correctamente.\n";
}

void mostrarTareas(const vector<Tarea>& tareas) {
    cout << "\nTAREAS\n";
    for (int i = 0; i < tareas.size(); i++){
        cout << i + 1 << ". ";
        
        if (tareas[i].completada == true){
            cout << "[Completada] ";
        } else {
            cout << "[Pendiente] ";
        }
        
        cout << "[" << tareas[i].prioridad << "] ";
        cout << tareas[i].descripcion << endl;
    }
}

void completarTarea(vector<Tarea>& tareas) {
    mostrarTareas(tareas);
    
    int numeroTarea;
    cout << "Seleccione la tarea: ";
    cin >> numeroTarea;
    
    if(numeroTarea < 1 || numeroTarea > tareas.size()){
        cout << "Opción no válida.\n";
        return;
    }
    
    tareas[numeroTarea - 1].completada = true;
    cout << "Tarea marcada como completada.\n";
}

void eliminarTarea(vector<Tarea>& tareas) {
    mostrarTareas(tareas);
    
    if (tareas.empty()) {
        return;
    }
    
    int numeroTarea;
    cout << "Seleccione la tarea que desea eliminar: ";
    cin >> numeroTarea;
    
    if(numeroTarea < 1 || numeroTarea > tareas.size()){
        cout << "Opción no válida.\n";
        return;
    }
    
    tareas.erase(tareas.begin() + numeroTarea - 1);
    cout << "Tarea eliminada correctamente.\n";
}
