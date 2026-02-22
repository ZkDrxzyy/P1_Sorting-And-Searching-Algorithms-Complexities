# 🚀 Análisis Comparativo de Algoritmos: Ordenamiento y Búsqueda

---

## **Autores:** 
- González González Erick Emiliano
- De La Rosa Hernández Tania
<br></br>
Curso: Análisis y Diseño de Algoritmos
<br></br>
Fecha: Febrero 2026

---

## 📝 Introducción
Esta práctica tiene como objetivo evaluar empíricamente la **complejidad computacional** (Tiempo y Espacio) de seis algoritmos clásicos; 3 de ordenamiento y 3 de búsqueda. A través de pruebas con volúmenes de datos masivos (hasta $10,000,000$ de elementos), se busca contrastar la teoría asintótica con el rendimiento real en hardware promedio.

---

## 📚 Estructura del repositorio

```bash
Práctica1_Introducción_a_la_complejidad/
│
├── 📂 Ordenamiento/               # Implementaciones individuales en C++
│   ├── BubbleSort.cpp
│   ├── MergeSort.cpp
│   └── QuickSort.cpp
│
├── 📂 Busqueda/                   # Implementaciones individuales en Python
│   ├── BusquedaLineal.py
│   ├── BusquedaBinaria.py
│   └── BusquedaPorSalto.py
│
├── 📜 CódigoMaestroOrdenamiento.cpp     # Código maestro: ejecuta pruebas y genera CSV
├── 📜 CódigoMaestroBusqueda.py          # Código maestro: ejecuta pruebas y genera CSV
├── 📊 resultados_ordenamiento.csv  # Datos generados por C++
├── 📊 resultados_busqueda.csv      # Datos generados por Python
└── 📘 README.md                    # Documentación del proyecto
```

---

## 🛠️ Especificaciones del Entorno de Pruebas

Para garantizar la precisión de los resultados, se separaron las responsabilidades tecnológicas de la siguiente manera:

### 1. Desarrollo en C++ (Foco: Rendimiento)
* **Uso:** Implementación de algoritmos de ordenamiento.
* **Justificación:** La gestión manual de memoria y la velocidad de ejecución de un lenguaje compilado son críticas cuando se procesan estructuras de datos de $40\text{ MB}$ o más. Se utilizó la librería `<chrono>` para mediciones de alta precisión.

### 2. Desarrollo en Python (Foco: Análisis y Flexibilidad)
* **Uso:** Implementación de algoritmos de búsqueda.
* **Justificación:** Python permite una rápida manipulación de datos y la generación automatizada de reportes CSV. Se utilizó `time.perf_counter_ns()` para capturar diferencias de tiempo en escala de nanosegundos.

---

## 📈 Sección 1: Algoritmos de Ordenamiento (C++)

Se seleccionaron tres algoritmos con comportamientos contrastantes según la Notación Big O.

### 1.1. Tabla Comparativa de Tiempos (ms)

| Tamaño (N) | Bubble Sort ( $O(n^2)$ ) | Merge Sort ( $O(n \log n)$ ) | QuickSort ( $O(n \log n)$ ) |
|------------|-------------------------|----------------------------|---------------------------|
| 10         | 0                       | 0                          | 0                         |
| 100        | 0                       | 0                          | 0                         |
| 1,000      | 4                       | 0                          | 0                         |
| 10,000     | 357                     | 4                          | 1                         |
| 100,000    | **Inviable (INF)**      | 42                         | 24                        |
| 1,000,000  | **Inviable (INF)**      | 501                        | 195                       |
| 10,000,000 | **Inviable (INF)**      | 5395                       | 4540                      |



### 1.2. Análisis de Consumo de Memoria
* **Bubble Sort:** Complejidad espacial $O(1)$. Solo requiere el espacio del arreglo original.
* **QuickSort:** Complejidad espacial $O(\log n)$ debido a la profundidad de la pila de recursión.
* **Merge Sort:** Complejidad espacial $O(n)$. Es el más costoso, ya que requiere un arreglo auxiliar del mismo tamaño que el original para realizar la mezcla de sub-arreglos.
  * *Ejemplo:* Para $10^7$ enteros, Merge Sort utiliza $\approx 80\text{ MB}$ de RAM total.

### 1.3. Gráfico de Análisis

<p align="center">
<img width="818" height="482" alt="Imagen2" src="https://github.com/user-attachments/assets/9fcef2a9-c423-4617-931a-4bed0dd91ead" />
<br>
<em>Figura 1: Comparativa de tiempos en milisegundos. Nótese la divergencia exponencial del Bubble Sort frente a los métodos basados en partición.</em>
</p>

**Descripción Técnica:**
Este gráfico ilustra la evolución del tiempo de ejecución de los algoritmos **Bubble Sort**, **Merge Sort** y **QuickSort** conforme aumenta el tamaño del arreglo ($N$).

* **Comportamiento Cuadrático:** Se observa cómo la línea de **Bubble Sort ( $O(n^2)$ )** mantiene una pendiente pronunciada y constante en la escala logarítmica. Al escalar hacia los $10^7$ elementos, su tiempo se dispara a valores inviables (representados por la tendencia hacia los 350,000 ms, para fines prácticos del gráfico, sin embargo en un entorno real los tiempos se extienden a las horas e incluso días), confirmando su ineficiencia para el procesamiento de grandes volúmenes de datos.
* **Eficiencia Logarítmica:** Las curvas de **QuickSort** y **Merge Sort ( $O(n \log n)$ )** se mantienen significativamente por debajo de la curva de Bubble Sort. 
* **Optimización Práctica:** QuickSort demostró ser el más óptimo, logrando procesar los 10 millones de registros en aproximadamente **4,540 ms**, superando ligeramente a Merge Sort (**5,395 ms**) debido a su menor factor de constante y mejor aprovechamiento de la memoria caché.

---

## 🔍 Sección 2: Algoritmos de Búsqueda (Python)

Las pruebas se realizaron sobre arreglos previamente ordenados para permitir el funcionamiento de los métodos logarítmicos.

### 2.1. Tabla de Rendimiento (ns)
| Tamaño (N) | Lineal ( $O(n)$ ) | Salto/Jump ( $O(\sqrt{n})$ ) | Binaria ( $O(\log n)$ ) |
|------------|-------------------------|----------------------------|---------------------------|
| 10         | 2200                    | 5700                       | 2000                      |
| 100        | 3700                    | 1500                       | 1400                      |
| 1,000      | 27400                   | 1000                       | 1700                      |
| 10,000     | 262900                  | 1400                       | 2700                      |
| 100,000    | 2634000                 | 1400                       | 3100                      |
| 1,000,000  | 27295200                | 7300                       | 12200                     |
| 10,000,000 | 270264600               | 6300                       | 11400                     |

### 2.2. Análisis de Consumo de Memoria (Búsqueda)

A diferencia de los algoritmos de ordenamiento, que a menudo requieren duplicar datos o gestionar pilas de recursión, los algoritmos de búsqueda seleccionados se caracterizan por ser sumamente eficientes en el uso de memoria auxiliar (espacio extra requerido además de la estructura de datos original).

* **Búsqueda Lineal:** Complejidad espacial **$O(1)$**. El algoritmo opera de forma iterativa y solo requiere una variable de control (índice) para recorrer la lista. El consumo de memoria es constante e independiente del tamaño del arreglo ($N$).
* **Búsqueda por Salto (Jump Search):** Complejidad espacial **$O(1)$**. Requiere únicamente dos variables adicionales de tipo entero: una para definir el tamaño del bloque de salto ($\sqrt{n}$) y otra para rastrear la posición previa dentro del bloque.
* **Búsqueda Binaria:** Complejidad espacial **$O(1)$**. Al implementarse de forma iterativa (usando un ciclo `while`), solo reserva espacio para tres índices: `izq`, `der` y `medio`. Al no utilizar recursividad en esta implementación, no genera sobrecarga en la pila de llamadas (*stack memory*), manteniendo un consumo mínimo y fijo.

> **Nota Técnica sobre el entorno (Python):** > Es fundamental distinguir entre la complejidad del *algoritmo* y el costo de la *estructura de datos*. Aunque los algoritmos son $O(1)$, una lista de $10^7$ enteros en Python consume significativamente más memoria que un `vector<int>` en C++. Esto se debe al "overhead" de los objetos en Python (cada entero es un objeto con metadatos), elevando el consumo base a un rango de **$80\text{ MB} - 160\text{ MB}$** en sistemas de 64 bits.

### 2.3. Gráfico de Análisis

<p align="center">
<img width="818" height="499" alt="Imagen1" src="https://github.com/user-attachments/assets/999604c0-e552-48ef-9f79-eaecb7bce242" />
<br>
<em>Figura 2: Comparativa de tiempos en milisegundos. Nótese la divergencia exponencial de la Busqueda Lineal frente a los otros métodos.</em>
</p>

**Descripción Técnica:**
El gráfico compara el tiempo de respuesta de los métodos de búsqueda sobre arreglos ordenados de hasta $10^7$ elementos, utilizando nanosegundos (ns) como unidad de medida.

* **Búsqueda Lineal ( $O(n)$ ):** Representada por la línea azul superior, muestra un crecimiento lineal perfecto. Al requerir la inspección de cada elemento en el peor de los casos, el tiempo aumenta en proporción directa al tamaño del arreglo, alcanzando los **270,264,600 ns** en la prueba máxima.
* **Búsqueda Binaria ( $O(\log n)$ ):** Situada en la parte inferior (línea naranja), demuestra una eficiencia asintótica superior. A pesar de aumentar el tamaño del arreglo un millón de veces, el tiempo de búsqueda apenas varía, manteniéndose en una escala de microsegundos, lo que valida su complejidad logarítmica.
* **Búsqueda por Salto ( $O(\sqrt{n})$ ):** La línea verde muestra un rendimiento intermedio. Es notablemente más eficiente que la búsqueda lineal pero menos optimizada que la binaria, sirviendo como un balance técnico que confirma su posición teórica entre $O(n)$ y $O(\log n)$.

---

## 🧠 Conclusiones

### A. La Barrera del Rendimiento Cuadrático
Los resultados muestran que el **Bubble Sort** experimenta un crecimiento explosivo. Al pasar de $10^4$ a $10^5$ elementos, el tiempo de procesamiento se multiplica por 100, validando la naturaleza de $n^2$. En aplicaciones industriales o de Big Data, este algoritmo es estrictamente teórico.

### B. QuickSort vs. Merge Sort
Aunque ambos comparten una complejidad promedio de $O(n \log n)$, **QuickSort** superó consistentemente a Merge Sort en tiempo. Esto se debe a que QuickSort tiene un factor de constante menor y no requiere la sobrecarga de memoria que implica crear copias de sub-arreglos en cada división.

### C. Eficiencia de Búsqueda
La **Búsqueda Binaria** es el ejemplo máximo de optimización. Mientras que la Búsqueda Lineal debe inspeccionar $10,000,000$ de elementos en el peor caso, la Búsqueda Binaria localiza el objetivo en un máximo de **24 comparaciones**, lo que reduce el tiempo de ejecución a una fracción casi imperceptible de segundo.

---

## 🛠️ Instrucciones de Ejecución
1. Clona el repositorio con: `git clone https://github.com/ZkDrxzyy/P1_Sorting-And-Searching-Algorithms-Complexities`
2. Compila los archivos de C++ usando `g++`.
3. Ejecuta los scripts de Python con `python3`.
