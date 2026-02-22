#include <iostream>
#include <vector>
#include <algorithm> // Necesaria para std::swap
#include <chrono>    // Necesaria para medir el tiempo
#include <random>    // Para generar números aleatorios

using namespace std;
using namespace std::chrono;

// Función de Ordenamiento Bubble Sort Optimizado
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
        // Si en toda una vuelta no hubo intercambios, ya está ordenado
        if (!swapped) break;
    }
}

int main() {
    // Tamaños que pide tu práctica (ajustados para Bubble Sort)
    // NOTA: No incluimos 10^6 o 10^7 aquí porque Bubble Sort tardaría horas.
    vector<int> tamanos = {10, 100, 1000, 10000}; 

    for (int n : tamanos) {
        // 1. Crear arreglo con números aleatorios
        vector<int> datos(n);
        for(int i = 0; i < n; i++) {
            datos[i] = rand() % 10000; 
        }

        // 2. Medir tiempo de inicio
        auto inicio = high_resolution_clock::now();

        // 3. Ejecutar algoritmo
        bubbleSort(datos);

        // 4. Medir tiempo de fin
        auto fin = high_resolution_clock::now();

        // 5. Calcular duración en milisegundos
        auto duracion = duration_cast<milliseconds>(fin - inicio);

        cout << "Elementos: " << n << " | Tiempo: " << duracion.count() << " ms" << endl;
    }

    return 0;
}