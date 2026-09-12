#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

template <class K, class V>
class AVL
{
private:
    struct nodo
    {
        K clave;
        V valor;
        nodo *izq;
        nodo *der;
        int altura;

        nodo(K clave, V valor)
            : clave(clave), valor(valor),
              izq(nullptr), der(nullptr), altura(1) {}
    };

    nodo *raiz;
    int cantidad;

    int Altura(nodo *n)
    {
        if (!n)
            return 0;

        return n->altura;
    }

    int Balance(nodo *n)
    {
        if (!n)
            return 0;

        return Altura(n->izq) - Altura(n->der);
    }

    nodo *RotarDerecha(nodo *y)
    {

        nodo *x = y->izq;
        nodo *aux = x->der;

        // Rotación
        x->der = y;
        y->izq = aux;

        // Actualizar alturas
        y->altura = 1 + max(Altura(y->izq), Altura(y->der));
        x->altura = 1 + max(Altura(x->izq), Altura(x->der));

        return x;
    }

    nodo *RotarIzquierda(nodo *x)
    {

        nodo *y = x->der;
        nodo *aux = y->izq;

        // Rotación
        y->izq = x;
        x->der = aux;

        // Actualizar alturas
        x->altura = 1 + max(Altura(x->izq), Altura(x->der));
        y->altura = 1 + max(Altura(y->izq), Altura(y->der));

        return y;
    }

    nodo *Insertar(nodo *actual, K clave, V valor)
    {

        // Inserción normal de ABB
        if (!actual)
        {
            cantidad++;
            return new nodo(clave, valor);
        }

        if (clave < actual->clave)
        {

            actual->izq = Insertar(actual->izq, clave, valor);
        }
        else if (clave > actual->clave)
        {

            actual->der = Insertar(actual->der, clave, valor);
        }
        else
        {

            // La clave ya existe, no hago nada
            return actual;
        }

        // Actualizar altura
        actual->altura =
            1 + max(Altura(actual->izq), Altura(actual->der));

        // Obtener factor de balance
        int balance = Balance(actual);

        // Caso IZQUIERDA - IZQUIERDA
        if (balance > 1 && clave < actual->izq->clave)
        {
            return RotarDerecha(actual);
        }

        // Caso DERECHA - DERECHA
        if (balance < -1 && clave > actual->der->clave)
        {
            return RotarIzquierda(actual);
        }

        // Caso IZQUIERDA - DERECHA
        if (balance > 1 && clave > actual->izq->clave)
        {

            actual->izq = RotarIzquierda(actual->izq);

            return RotarDerecha(actual);
        }

        // Caso DERECHA - IZQUIERDA
        if (balance < -1 && clave < actual->der->clave)
        {

            actual->der = RotarDerecha(actual->der);

            return RotarIzquierda(actual);
        }

        return actual;
    }

    bool Existe(nodo *actual, K clave)
    {

        if (!actual)
            return false;

        if (clave == actual->clave)
            return true;

        if (clave < actual->clave)
            return Existe(actual->izq, clave);

        return Existe(actual->der, clave);
    }

    V Recuperar(nodo *actual, K clave)
    {

        if (clave == actual->clave)
            return actual->valor;

        if (clave < actual->clave)
            return Recuperar(actual->izq, clave);

        return Recuperar(actual->der, clave);
    }

    void Rango(nodo *actual, K desde, K hasta)
    {

        if (!actual)
            return;

        /*
         * Si la clave actual es mayor que desde,
         * puede haber elementos válidos a la izquierda.
         */
        if (actual->clave > desde)
        {
            Rango(actual->izq, desde, hasta);
        }

        /*
         * Si está dentro del intervalo,
         * la mostramos.
         */
        if (actual->clave >= desde &&
            actual->clave <= hasta)
        {

            cout << actual->clave << endl;
        }

        /*
         * Si la clave actual es menor que hasta,
         * puede haber elementos válidos a la derecha.
         */
        if (actual->clave < hasta)
        {
            Rango(actual->der, desde, hasta);
        }
    }

public:
    AVL()
    {
        raiz = nullptr;
        cantidad = 0;
    }

    bool EsVacia()
    {
        return cantidad == 0;
    }

    void Insertar(K clave, V valor)
    {
        raiz = Insertar(raiz, clave, valor);
    }

    bool Existe(K clave)
    {
        return Existe(raiz, clave);
    }

    // Pre: Existe(clave)
    V Recuperar(K clave)
    {
        return Recuperar(raiz, clave);
    }

    void Mostrar()
    {
        Mostrar(raiz);
    }

    void Rango(K desde, K hasta)
    {
        Rango(raiz, desde, hasta);
    }
};

int main(){

    int N;
    cin >> N;

    AVL<long long, long long> *avlMonedas = new AVL<long long, long long>();
    AVL<string, string> *avlPinturas = new AVL<string, string>();

    for (int i = 0; i < N; i++)
    {
        string operacion;
        char coleccion;

        cin >> operacion >> coleccion;

        if (operacion == "ALTA")
        {
            if (coleccion == 'M')
            {
                long long clave;
                cin >> clave;
                if (!avlMonedas->Existe(clave))
                {
                    avlMonedas->Insertar(clave, clave);
                }
            }
            else if (coleccion == 'P')
            {
                string clave;
                cin >> clave;
                if (!avlPinturas->Existe(clave))
                {
                    avlPinturas->Insertar(clave, clave);
                }
            }
        }
        else if (operacion == "BUSCAR")
        {
            if (coleccion == 'M')
            {
                long long clave;
                cin >> clave;
                if (avlMonedas->Existe(clave))
                {
                    cout << "si" << endl;
                }
                else
                {
                    cout << "no" << endl;
                }
            }
            else if (coleccion == 'P')
            {
                string clave;
                cin >> clave;
                if (avlPinturas->Existe(clave))
                {
                    cout << "si" << endl;
                }
                else
                {
                    cout << "no" << endl;
                }
            }
        }
        else if (operacion == "RANGO")
        {
            if (coleccion == 'M')
            {
                long long desde, hasta;
                cin >> desde >> hasta;
                avlMonedas->Rango(desde, hasta);
            }
            else if (coleccion == 'P')
            {
                string desde, hasta;
                cin >> desde >> hasta;
                avlPinturas->Rango(desde, hasta);
            }
        }
    }

    return 0;
}
