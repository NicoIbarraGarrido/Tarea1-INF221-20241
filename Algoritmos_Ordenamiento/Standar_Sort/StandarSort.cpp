#include <bits/stdc++.h>
using namespace std;

int main() {
    string filename;
    cout << "Ingrese el nombre del archivo de texto: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile) {
        cerr << "No se pudo abrir el archivo " << filename << endl;
        return 1;
    }

    vector<int> data;
    int number;
    while (infile >> number) {
        data.push_back(number);
    }
    infile.close();

    int tamano = data.size();

    // Empezamos a medir el tiempo de ordenamiento del algoritmo
    auto start = chrono::high_resolution_clock::now();
    sort(data.begin(), data.end()); // Función de la biblioteca para ordernar un vector.
    auto end = chrono::high_resolution_clock::now();

    // Calculamos el tiempo que demoró
    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo de ordenamiento: " << elapsed.count() << " segundos." << endl;

    ofstream outfile("Resultado.txt");
    if (!outfile) {
        cerr << "No se pudo crear el archivo resultado.txt" << endl;
        return 1;
    }
    for (int num : data) {
        outfile << num << endl;
    }
    outfile.close();

    cout << "Sea a crear un nuevo archivo: Resultados.txt con el DataSet ordenado." << endl;

    return 0;
}