#include <bits/stdc++.h>
using namespace std;

// Algoritmo QuickSort
// Fuente: https://github.com/codigo404/Cpp-Data-structures-and-algorithms/blob/main/sortingAlgorithms/quickSort/quicksort.cpp
void swap(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int k = high;

    for (int i = high; i > low; i--) {
        if (arr[i] > pivot) {
            swap(arr[i], arr[k--]);
        }
    }

    swap(arr[low], arr[k]);
    return k;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int idx = partition(arr, low, high); 
        quickSort(arr, low, idx - 1);  
        quickSort(arr, idx + 1, high);  
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

    int tamano = data.size();

    // Empezamos a medir el tiempo de ordenamiento del algoritmo
    auto start = chrono::high_resolution_clock::now();
    quickSort(data, 0, tamano-1);
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