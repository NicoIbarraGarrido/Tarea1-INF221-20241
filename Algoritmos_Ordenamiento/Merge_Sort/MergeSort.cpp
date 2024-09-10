#include <bits/stdc++.h>
using namespace std;

// Algoritmo MergeSort
// Fuente: https://www.geeksforgeeks.org/merge-sort/
void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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
    mergeSort(data, 0, tamano-1);
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