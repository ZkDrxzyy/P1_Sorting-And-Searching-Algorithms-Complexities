#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Función para dividir el arreglo (Partición)
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

// Función recursiva
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Ejemplo con 100,000 elementos (puedes subirlo a 10^7)
    int n = 100000;
    vector<int> datos(n);
    for(int i=0; i<n; i++) datos[i] = rand() % 10000;

    auto inicio = high_resolution_clock::now();
    quickSort(datos, 0, n - 1);
    auto fin = high_resolution_clock::now();

    auto duracion = duration_cast<milliseconds>(fin - inicio);
    cout << "QuickSort con " << n << " elementos tardo: " << duracion.count() << " ms" << endl;

    return 0;
}