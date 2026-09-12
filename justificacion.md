# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1

**Restricciones de la letra:**
- ALTA: O(log K) donde K = cantidad de piezas en la colección
- BUSCAR: O(log K) donde K = cantidad de piezas en la colección  
- RANGO: O(log K + R) donde K = cantidad de piezas en la colección, R = cantidad de elementos reportados

**Estructura de datos utilizada:** AVL (Árbol Binario de Búsqueda Balanceado)

**Justificación:**

- **ALTA (inserción):** Implementada con `Insertar()` que realiza inserción de ABB en O(log K) seguida de rotaciones balanceadas en O(1). Entonces es O(log K).

- **BUSCAR (búsqueda):** Implementada con `Existe()` que realiza búsqueda binaria en árbol balanceado, recorriendo a lo sumo la altura del árbol, que es O(log K).

- **RANGO (búsqueda por rango):** Implementada con `Rango()` que realiza el recorrido inorden. Realiza O(log K) comparaciones para alcanzar el primer elemento en el rango, luego reporta R elementos en O(R). Complejidad: O(log K + R).

## Ejercicio 2
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 3
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 4
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 5
- Sin restricciones de órdenes. / Justificación: ...

