import time
import math
import csv

# 1. BÚSQUEDA LINEAL - O(n)
def busqueda_lineal(lista, objetivo):
    for i in range(len(lista)):
        if lista[i] == objetivo:
            return i
    return -1

# 2. BÚSQUEDA BINARIA - O(log n)
def busqueda_binaria(lista, objetivo):
    izq, der = 0, len(lista) - 1
    while izq <= der:
        medio = (izq + der) // 2
        if lista[medio] == objetivo:
            return medio
        elif lista[medio] < objetivo:
            izq = medio + 1
        else:
            der = medio - 1
    return -1

# 3. JUMP SEARCH (Búsqueda por saltos) - O(sqrt(n))
def busqueda_salto(lista, objetivo):
    n = len(lista)
    salto = int(math.sqrt(n))
    previo = 0
    while lista[min(salto, n)-1] < objetivo:
        previo = salto
        salto += int(math.sqrt(n))
        if previo >= n:
            return -1
    while lista[previo] < objetivo:
        previo += 1
        if previo == min(salto, n):
            return -1
    if lista[previo] == objetivo:
        return previo
    return -1

# --- SISTEMA DE PRUEBAS ---
tamanos = [10, 100, 1000, 10000, 100000, 1000000, 10000000]
resultados = []

print("Iniciando pruebas de búsqueda en Python...")

for n in tamanos:
    # Creamos una lista ordenada (necesaria para Binaria y Salto)
    lista = list(range(n))
    objetivo = -1  # Buscamos un valor que no existe para probar el peor caso

    # Medir Búsqueda Lineal
    inicio = time.perf_counter_ns()
    busqueda_lineal(lista, objetivo)
    fin = time.perf_counter_ns()
    t_lineal = fin - inicio

    # Medir Búsqueda Binaria
    inicio = time.perf_counter_ns()
    busqueda_binaria(lista, objetivo)
    fin = time.perf_counter_ns()
    t_binaria = fin - inicio

    # Medir Búsqueda por Salto
    inicio = time.perf_counter_ns()
    busqueda_salto(lista, objetivo)
    fin = time.perf_counter_ns()
    t_salto = fin - inicio

    resultados.append([n, t_lineal, t_binaria, t_salto])
    print(f"Tamaño {n} completado.")

# Guardar en CSV
with open('resultados_busqueda.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(['Elementos', 'Lineal(ns)', 'Binaria(ns)', 'Salto(ns)'])
    writer.writerows(resultados)

print("\n¡Listo! El archivo 'resultados_busqueda.csv' ha sido generado.")