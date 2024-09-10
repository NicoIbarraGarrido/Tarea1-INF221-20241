#include <bits/stdc++.h>
using namespace std;

// Algoritmo BubbleSort
// Fuente: https://www.geeksforgeeks.org/bubble-sort-in-cpp/
void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

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

    // Empezamos a medir el tiempo de ordenamiento del algoritmo
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(data);
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