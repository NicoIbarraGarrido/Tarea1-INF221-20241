#include <bits/stdc++.h>
using namespace std;

// Función para generar dataset ordenado
vector<int> generar_ordenado(int tamano) {
    vector<int> dataset(tamano);
    for (int i = 0; i < tamano; ++i) {
        dataset[i] = i;  // Lista ordenada
    }
    return dataset;
}

// Función para generar dataset inverso (peor caso)
vector<int> generar_inverso(int tamano) {
    vector<int> dataset(tamano);
    for (int i = 0; i < tamano; ++i) {
        dataset[i] = tamano - i;  // Lista inversa
    }
    return dataset;
}

// Función para generar dataset aleatorio
vector<int> generar_aleatorio(int tamano) {
    vector<int> dataset(tamano);
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(0, tamano);
    
    for (int i = 0; i < tamano; ++i) {
        dataset[i] = dist(rng);  // Números aleatorios
    }
    return dataset;
}

// Función para generar dataset parcialmente ordenado (ej. 50% desordenado)
vector<int> generar_parcialmente_ordenado(int tamano, double porcentaje_desorden) {
    vector<int> dataset = generar_ordenado(tamano);  // Comienza con lista ordenada
    random_device rd;
    mt19937 rng(rd());
    int num_desordenar = static_cast<int>(tamano * porcentaje_desorden);  // Cantidad a desordenar
    
    for (int i = 0; i < num_desordenar; ++i) {
        int indice1 = rng() % tamano;
        int indice2 = rng() % tamano;
        swap(dataset[indice1], dataset[indice2]);  // Intercambia valores para desordenar
    }
    return dataset;
}

// Función para generar dataset con elementos repetidos
vector<int> generar_con_repetidos(int tamano, double porcentaje_repetidos) {
    int nuevo_tamano = static_cast<int>(tamano * (1.0 - porcentaje_repetidos));
    
    vector<int> dataset(tamano);
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(0, nuevo_tamano - 1);

    for (int i = 0; i < tamano; ++i) {
        dataset[i] = dist(rng);
    }
    return dataset;
}

// Función para guardar el dataset en un archivo .txt
void guardar_en_txt(const vector<int>& dataset, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    for (const int& num : dataset) {
        archivo << num << "\n";
    }
    archivo.close();
}

int main() {
    int tamano;
    int opcion;
    double porcentaje;
    
    cout << "Ingrese el tamaño del dataset (máximo 10,000,000): ";
    cin >> tamano;
    if (tamano < 1 || tamano > 10000000) {
        cout << "Tamaño fuera de rango. Intente de nuevo." << endl;
        return 1;
    }
    
    cout << "Seleccione el tipo de dataset a generar:" << endl;
    cout << "1. Ordenado\n2. Inverso\n3. Aleatorio\n4. Parcialmente Ordenado\n5. Con Repetidos" << endl;
    cin >> opcion;

    vector<int> dataset;
    string nombre_archivo;
    
    switch (opcion) {
        case 1:
            dataset = generar_ordenado(tamano);
            nombre_archivo = "ordenado(" + to_string(tamano) + ").txt";
            guardar_en_txt(dataset, nombre_archivo);
            cout << "Dataset ordenado generado y guardado como '" << nombre_archivo << "'" << endl;
            break;
        case 2:
            dataset = generar_inverso(tamano);
            nombre_archivo = "inverso(" + to_string(tamano) + ").txt";
            guardar_en_txt(dataset, nombre_archivo);
            cout << "Dataset inverso generado y guardado como '" << nombre_archivo << "'" << endl;
            break;
        case 3:
            dataset = generar_aleatorio(tamano);
            nombre_archivo = "aleatorio(" + to_string(tamano) + ").txt";
            guardar_en_txt(dataset, nombre_archivo);
            cout << "Dataset aleatorio generado y guardado como '" << nombre_archivo << "'" << endl;
            break;
        case 4:
            cout << "Ingrese el porcentaje de desorden (ej. 0.5 para 50% desordenado): ";
            cin >> porcentaje;
            dataset = generar_parcialmente_ordenado(tamano, porcentaje);
            nombre_archivo = "parcialmente_ordenado(" + to_string(tamano) + ").txt";
            guardar_en_txt(dataset, nombre_archivo);
            cout << "Dataset parcialmente ordenado generado y guardado como '" << nombre_archivo << "'" << endl;
            break;
        case 5:
            cout << "Ingrese el porcentaje de repetidos (ej. 0.5 para 50% repetidos): ";
            cin >> porcentaje;
            dataset = generar_con_repetidos(tamano, porcentaje);
            nombre_archivo = "con_repetidos(" + to_string(tamano) + ").txt";
            guardar_en_txt(dataset, nombre_archivo);
            cout << "Dataset con repetidos generado y guardado como '" << nombre_archivo << "'" << endl;
            break;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            return 1;
    }

    return 0;
}
