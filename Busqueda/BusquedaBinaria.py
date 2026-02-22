import time

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

# Prueba rápida
n = 1000000
datos = list(range(n)) # Lista ya ordenada
objetivo = -1

inicio = time.perf_counter_ns()
busqueda_binaria(datos, objetivo)
fin = time.perf_counter_ns()

print(f"Búsqueda Binaria ({n} elementos): {(fin - inicio)} ns")