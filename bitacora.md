# Bitácora — Obligatorio 1

**Integrantes:** Maximo Reyna (303814), Nombre Apellido (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## AAAA-MM-DD — Nombre
- Ejemplo: Leí la letra del ejercicio 1. Primera idea: ... pero la restricción de
  complejidad pide ..., así que ...

## 2026-12-9— En conjunto
- Implementamos el ejercicio 1 completo. Trabajamos por google meet y live share de vscode por apróximadamente 1 hora y media. Luego de leer la letra y entender el ejercicio, buscamos un template de AVL en las guías y dimos con el link de geeksforgeeks en las ppts de AVL, de ahí tomamos el template completo de un AVL de tipo Int y lo volvimos genérico guíandonos también por el ejemplo en un repositorio del profesor Francisco Bouza. 
Con esto pudimos realizar el ejercicio entero, pero a la hora de correrlo contra los tests dados, la mitad fallaba. No lograbamos encontrar el error, por lo que le consultamos a la IA (extensión Claude Code para vscode) y el problema resultó ser porque los tests utilizaban numeros de prueba muy grandes, mayores a los soportados por Int, por lo que lo correcto era cambiar el tipo de avl y variables a "long long". Con este cambio pasaron todos los casos de prueba y pusheamos el ejercicio al repo.



## 2026-29-9 — En conjunto 
- Implementamos el ejercicio 3 completo. 
Trabajamos por google meet y live share aproximadamente 2 horas. Primero estuvimos analizando la letra y entendiendo que pedía el ejercicio, encontramos un template de minHeap en el repositorio de la clase, luego de entenderlo bien le borramos el hash que tenía porque no lo precisabamos. 
A la hora de resolver el algoritmo no sabíamos como inicializar el heap y le preguntamos a claude code como podiamos hacerlo, ahí nos dijo que nos faltaba implementar compararLL ya que era de tipo long long, luego el ejercicio lo fuimos pensando en conjunto ya que teniamos todas las funciones necesarias.