// Ejercicio 2 - El taller de imprenta

#include <string>
#include <iostream>
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
    int largoVec;
    int cantidad;
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
            for (int i = 3; i * i <= num; i += 2)
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
        this->cantidad = 0;
        this->largoVec = primoSup(capacidad);
        this->vec = new bucket *[this->largoVec]();
    }

    // Suma 1 al valor de la clave. Si la clave no estaba, la agrega con valor 1.
    // Devuelve el valor que quedo.
    int Incrementar(K clave)
    {
        int pos = fHash(clave) % largoVec;
        bucket *aux = vec[pos];
        while (aux != nullptr)
        {
            if (aux->clave == clave)
            {
                aux->valor = aux->valor + 1;
                return aux->valor;
            }
            aux = aux->sig;
        }
        vec[pos] = new bucket(clave, 1, vec[pos]);
        cantidad++;
        return 1;
    }

    bool Existe(K clave)
    {
        int pos = fHash(clave) % largoVec;
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
        int pos = fHash(clave) % largoVec;
        bucket *aux = vec[pos];
        while (aux != nullptr)
        {
            if (aux->clave == clave)
            {
                return aux->valor;
            }
            aux = aux->sig;
        }
        // Si se cumple la precondicion nunca se llega aca.
        return V();
    }

    int Cantidad()
    {
        return cantidad;
    }

    ~Hash()
    {
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
};

// Devuelve la clave del cajon de una palabra: cuantos tipos necesita de cada
// una de las 26 letras, guardado como un string de largo 26.
// Dos palabras van al mismo cajon si y solo si les da la misma clave.
string firma(string palabra)
{
    int conteo[26];
    for (int i = 0; i < 26; i++)
    {
        conteo[i] = 0;
    }

    int largo = palabra.length();
    for (int i = 0; i < largo; i++)
    {
        conteo[palabra[i] - 'a']++;
    }

    string clave = "";
    for (int i = 0; i < 26; i++)
    {
        // Una palabra tiene a lo sumo 20 letras, asi que el conteo entra en un char.
        char tipos = '0' + conteo[i];
        clave += tipos;
    }

    return clave;
}

// Hash de la clave del cajon. El resto de la division mantiene el numero
// chico y siempre positivo.
int funcionHashString(string clave)
{
    long long hash = 0;

    int largo = clave.length();
    for (int i = 0; i < largo; i++)
    {
        hash = (hash * 31 + clave[i]) % 1000000007;
    }

    return hash;
}

int main()
{
    int N;
    cin >> N;

    // Hay a lo sumo N cajones distintos, uno por palabra registrada.
    // Pidiendo lugar para 2 * N el factor de carga nunca pasa de 0.5
    // y no hace falta agrandar la tabla en ningun momento.
    Hash<string, int> palabras(2 * N, funcionHashString);

    // Se van actualizando a medida que se registra, sin recorrer nada al final.
    int cajonesDistintos = 0;
    int maxCajon = 0;

    for (int i = 0; i < N; i++)
    {
        string palabra;
        cin >> palabra;

        int enElCajon = palabras.Incrementar(firma(palabra));

        if (enElCajon == 1)
        {
            cajonesDistintos++;
        }
        if (enElCajon > maxCajon)
        {
            maxCajon = enElCajon;
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        string consulta;
        cin >> consulta;

        // Consultar no registra: solo se busca, no se agrega nada.
        string clave = firma(consulta);

        if (palabras.Existe(clave))
        {
            cout << palabras.Recuperar(clave) << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }

    cout << cajonesDistintos << " " << maxCajon << "\n";

    return 0;
}
