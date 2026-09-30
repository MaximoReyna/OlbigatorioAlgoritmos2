# Declaración de autoría — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): declarar para cada ejercicio
> las fuentes utilizadas: código discutido o desarrollado en clase, recursos web (con URL)
> y uso de herramientas de IA generativa (herramienta, consulta y uso dado, según los
> lineamientos de Uso de IA de la letra). Si no se usaron fuentes externas, indicarlo
> explícitamente. Los fragmentos de terceros o generados por IA deben además señalarse
> con comentarios en el código fuente. La omisión de fuentes puede considerarse plagio.

## Ejercicio 1
- Buscamos en las ppts la implementación de AVL: https://avl.uruguayan.ninja/7

- Utilizamos geeksforgeeks para implementar el AVL: https://www.geeksforgeeks.org/dsa/insertion-in-an-avl-tree/ y también el repositorio del profesor Federico Bouza: https://github.com/BouzORT/EDA2-2026s2-N4AID/blob/main/Hash/hash.cpp

- Utilizamos inteligencia artificial (claude code en vscode vía extensión) para detectar un error que hacía fallar varias pruebas, se encontró que el error era porque las pruebas utilizaban valores no soportados por int y que la solución era cambiarlos por long long. Prompt: "porque está mal nuestro código? corre los comandos para saber cuales pruebas pasan y cuales no y dime porque no funciona lo que está mal"

## Ejercicio 2
- 

## Ejercicio 3
- Tomamos la representación de un heap en el repo de la clase y lo convertimos a un heap binario sin hash. Link: https://github.com/BouzORT/EDA2-2026s2-N4AID/blob/main/Heap/heap.cpp

- Al comenzar tuvimos dificultades para incializar el heap, consultamos a la IA (claude code) y nos dió la pista de implementar la función de compararLL, adjunto prompt y respuesta:

"Analiza lo implementado en el ejercicio 3, es un heap binario. Necesito una pista sobre como implementar el Heap, hay algo hecho de prueba con el heap ornitorrinco, pero no logro hacer que funcione"

"Pista. El heap no sabe qué guarda: la T puede ser un long long, un string o un Ornitorrinco*. Entonces tampoco puede saber cuál de dos elementos va más arriba. Esa decisión se la tenés que dar de afuera, en forma de una función que reciba dos elementos y diga cuál va primero.

Lo que tenés que definir es el contrato: qué devuelve esa función. La convención de siempre, la misma de strcmp, es un int con tres casos:

negativo si el primero va antes que el segundo,
cero si da lo mismo,
positivo si el primero va después.
Fijate que digo "va antes", no "es menor". Ahí está lo interesante: min-heap o max-heap no es una propiedad de la clase, es una propiedad de esa función. La misma clase Heap, con una función que invierte el signo, te da un max-heap sin tocar una línea. Para este ejercicio querés que el más chico quede arriba, así que "va antes" es "es más chico".

Una trampa para cuando la escribas: con números enteros da tentación devolver la resta, a - b, porque el signo sale justo. Anda bien con int chicos y se rompe con long long, porque la resta no entra en el int que devolvés y podés terminar con el signo invertido. Tres if no tienen ese problema."

- El resto del código fue pensado y desarrollado solo por el equipo, en conjunto.

## Ejercicio 4
- Implementación íntegramente propia, sin fuentes externas.

## Ejercicio 5
- Implementación íntegramente propia, sin fuentes externas.

