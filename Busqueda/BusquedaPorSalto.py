import time
import math

def busqueda_salto(lista, objetivo):
    n = len(lista)
    salto = int(math.sqrt(n))
    previo = 0
    
    # Encontrar el bloque donde podría estar el objetivo
    while lista[min(salto, n)-1] < objetivo:
        previo = salto
        salto += int(math.sqrt(n))
        if previo >= n:
            return -1
            
    # Búsqueda lineal dentro del bloque identificado
    while lista[previo] < objetivo:
        previo += 1
        if previo == min(salto, n):
            return -1
            
    if lista[previo] == objetivo:
        return previo
    return -1

# Prueba rápida
n = 1000000
datos = list(range(n))
objetivo = -1

inicio = time.perf_counter_ns()
busqueda_salto(datos, objetivo)
fin = time.perf_counter_ns()

print(f"Búsqueda por Salto ({n} elementos): {(fin - inicio)} ns")