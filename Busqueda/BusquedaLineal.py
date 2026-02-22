import time

def busqueda_lineal(lista, objetivo):
    for i in range(len(lista)):
        if lista[i] == objetivo:
            return i
    return -1

# Prueba rápida
n = 1000000
datos = list(range(n))
objetivo = -1 # Peor caso: no está en la lista

inicio = time.perf_counter_ns()
busqueda_lineal(datos, objetivo)
fin = time.perf_counter_ns()

print(f"Búsqueda Lineal ({n} elementos): {(fin - inicio)} ns")