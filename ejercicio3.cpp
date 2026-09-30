#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
template <class T>

class Heap
{
private:
    T *vec;
    int capacidad;
    int primeroLibre; // int ultimoOcupado
    int (*fComp)(T, T);

    void swap(int posA, int posB)
    {
        T auxA = vec[posA];
        T auxB = vec[posB];
        vec[posA] = auxB;
        vec[posB] = auxA;
    }

    int comparar(int posA, int posB)
    {
        return fComp(vec[posA], vec[posB]);
    }
    void flotar(int pos)
    {
        // CB1: estoy en raiz pos == 1 return
        if (pos == 1)
            return;
        // buscar posicion del padre
        int posPadre = pos / 2;
        // comparar lo que haya en la posPadre con lo que haya en pos
        // CB2: si el padre es menor o igual que el hijo return
        if (comparar(pos, posPadre) >= 0)
            return;
        swap(pos, posPadre);
        flotar(posPadre);
    }

    void hundir(int pos)
    {
        // CB1: estoy en hoja return
        if (pos * 2 >= primeroLibre)
            return;
        // buscar posicion del hijo menor
        int posHijoMenor = pos * 2;
        if (posHijoMenor + 1 < primeroLibre && comparar(posHijoMenor + 1, posHijoMenor) < 0)
        {
            posHijoMenor = posHijoMenor + 1; // el menor es el hijo derecho
        }
        // comparar lo que haya en la pos con lo que haya en posHijoMenor
        // CB2: si el hijo es mayor o igual que el padre return
        if (comparar(posHijoMenor, pos) >= 0)
            return;
        swap(pos, posHijoMenor);
        hundir(posHijoMenor);
    }

public:
    Heap(int unaCap, int (*fComp)(T, T))
    {
        primeroLibre = 1;
        capacidad = unaCap;
        vec = new T[capacidad + 1];
        this->fComp = fComp;
    }

    ~Heap()
    {
        // eliminar memoria
        delete[] vec;
    }

    void insertar(T elemento)
    {
        assert(primeroLibre <= capacidad);
        vec[primeroLibre] = elemento;
        primeroLibre++;
        flotar(primeroLibre - 1);
    }

    void eliminar()
    {
        assert(primeroLibre > 1);
        swap(1, primeroLibre - 1);
        primeroLibre--; // eliminar logicamente el ultimo elemento
        hundir(1);
    }


    bool estaVacio()
    {
        return primeroLibre == 1;
    }

    int cantidad()
    {
        return primeroLibre - 1;
    }

    T tope()
    {
        assert(primeroLibre > 1);
        return vec[1];
    }
};

int compararLL(long long a, long long b)
{
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}
int main()
{
    int N;
    cin >> N;

    long long costo = 0;

    Heap<long long> archivos(N, compararLL);
    
    for (int i = 0; i < N; i++)
    {
        long long tam;
        cin >> tam;
        archivos.insertar(tam);
    }
    
    while (archivos.cantidad() > 1)
    {
        long long a = archivos.tope();
        archivos.eliminar();
        long long b = archivos.tope();
        archivos.eliminar();

        costo += a + b;
        archivos.insertar(a + b);
    }

    cout << costo << "\n";

    return 0;
}