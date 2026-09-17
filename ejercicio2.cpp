#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;
// template sacado del repositorio de github de la clase.
template <class K, class V>
class Hash
{
private:
    struct bucket
    {
        K clave;
        V valor;
        bucket *sig;
        bucket(K clave, V valor, bucket *sig) : clave(clave), valor(valor), sig(sig) {}
    };

    bucket **vec;
    int largoVec, cantidad, capacidad;
    float fc;
    int (*fHash)(K);

    bool esPrimo(int num)
    {
        if (num <= 1)
            return false;
        else if (num == 2)
            return true;
        else if (num % 2 == 0)
            return false;
        else
        {
            for (int i = 3; i <= num / 2; i += 2)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int primoSup(int num)
    {
        while (!esPrimo(++num))
            ;
        return num;
    }

public:
    Hash(int capacidad, int (*fHash)(K))
    {
        this->fHash = fHash;
        this->capacidad = capacidad;
        this->fc = 0.0;
        this->cantidad = 0;
        this->largoVec = primoSup(capacidad);
        this->vec = new bucket *[this->largoVec]();
    }

    bool EsVacia()
    {
        return cantidad == 0;
    }

    void Insertar(K clave, V valor)
    {
        int pos = abs(fHash(clave)) % largoVec;
        vec[pos] = new bucket(clave, valor, vec[pos]);
        cantidad++;
        fc = (float)cantidad / largoVec;
    }

    bool Existe(K clave)
    {
        int pos = abs(fHash(clave)) % largoVec, posInicial = pos;
        bucket *aux = vec[pos];
        while (aux != nullptr)
        {
            if (aux->clave == clave)
            {
                return true;
            }
            aux = aux->sig;
        }
        return false;
    }

    // Pre: Existe(clave)
    V Recuperar(K clave)
    {
        int pos = abs(fHash(clave)) % largoVec, posInicial = pos;
        bucket *aux = vec[pos];
        while (aux != nullptr)
        {
            if (aux->clave == clave)
            {
                return aux->valor;
            }
            aux = aux->sig;
        }
        // No deberia llegar aca si se cumple la precondicion.
        return V();
    }

    // Pre: Existe(clave)
    void Borrar(K clave)
    {
        int pos = abs(fHash(clave)) % largoVec, posInicial = pos;
        bucket *aux = vec[pos];
        bucket *anterior = nullptr;
        while (aux->clave != nullptr)
        {
            if (aux->clave == clave)
            {
                if (anterior->clave == nullptr)
                {
                }
                else
                {
                    anterior->sig = aux->sig;
                }
                delete aux;
                cantidad--;
                return;
                fc = (float)cantidad / largoVec;
            }
        }
    }
    void Mostrar()
    {
        for (int i = 0; i < largoVec; i++)
        {
            cout << i << ": ";
            bucket *aux = vec[i];

            if (aux == nullptr)
            {
              cout << "VACIO";
            }

            while (aux != nullptr)
            {
                cout << "("
                     << aux->clave
                     << ","
                     << aux->valor
                     << ")";
                if (aux->sig != nullptr)
                {
                 cout << " -> ";
                }
                aux = aux->sig;
            }
            cout << endl;
        }
    }
    
    ~Hash() {
        for (int i = 0; i < largoVec; i++)
        {
            bucket *aux = vec[i];
            while (aux != nullptr)
            {
                bucket *temp = aux;
                aux = aux->sig;
                delete temp;
            }
        }
        delete[] vec;
    }

    int funcionHash(int clave)
    {
        return clave;
    }
    
   
};

 int funcionHashString(string clave){
    int hash = 0;

    for (char c : clave)
    {
        hash = hash * 31 + c;
    }

    return abs(hash);
}

int main()
{
    int N;
    cin >> N;
    Hash<string, int>* palabras = new Hash<string, int>(N, funcionHashString);

    for (int i = 0; i < N; i++){
        string a;
        cin >> a;
    }

    return 0;
}

