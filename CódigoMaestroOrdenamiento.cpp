#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <fstream>  // Para crear el archivo de Excel (.csv)

using namespace std;
using namespace std::chrono;

// --- 1. BUBBLE SORT OPTIMIZADO ---
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// --- 2. MERGE SORT ---
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// --- 3. QUICKSORT ---
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// --- EJECUCIÓN Y GENERACIÓN DE CSV ---
int main() {
    vector<long> tamanos = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    
    // Crear archivo CSV
    ofstream archivo("resultados_ordenamiento.csv");
    archivo << "Elementos,Bubble(ms),Merge(ms),Quick(ms)\n";

    cout << fixed << setprecision(2);
    cout << "Iniciando pruebas... Los resultados se guardaran en 'resultados_ordenamiento.csv'" << endl;
    cout << setw(12) << "N" << setw(15) << "Bubble(ms)" << setw(15) << "Merge(ms)" << setw(15) << "Quick(ms)" << endl;

    for (long n : tamanos) {
        vector<int> base(n);
        for (long i = 0; i < n; i++) base[i] = rand() % 1000000;

        string bTime = "INF", mTime, qTime;

        // Prueba Bubble
        if (n <= 10000) {
            vector<int> datos = base;
            auto start = high_resolution_clock::now();
            bubbleSort(datos);
            auto end = high_resolution_clock::now();
            bTime = to_string(duration_cast<milliseconds>(end - start).count());
        }

        // Prueba Merge
        {
            vector<int> datos = base;
            auto start = high_resolution_clock::now();
            mergeSort(datos, 0, n - 1);
            auto end = high_resolution_clock::now();
            mTime = to_string(duration_cast<milliseconds>(end - start).count());
        }

        // Prueba Quick
        {
            vector<int> datos = base;
            auto start = high_resolution_clock::now();
            quickSort(datos, 0, n - 1);
            auto end = high_resolution_clock::now();
            qTime = to_string(duration_cast<milliseconds>(end - start).count());
        }

        // Imprimir en consola y guardar en archivo
        cout << setw(12) << n << setw(15) << bTime << setw(15) << mTime << setw(15) << qTime << endl;
        archivo << n << "," << bTime << "," << mTime << "," << qTime << "\n";
    }

    archivo.close();
    cout << "\nListo! Busca el archivo 'resultados_ordenamiento.csv' en la carpeta de tu proyecto." << endl;

    return 0;
}