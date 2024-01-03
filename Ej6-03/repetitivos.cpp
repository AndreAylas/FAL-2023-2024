// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
struct tElemntos {
    int cantidad;
    int elem;
};
// función que resuelve el problema
int contarElems(const vector<int>& v, int elem, int ini, int fin) {
    int contar = 0;
    for (int i = ini; i <= fin; i++) {
        if (v[i] == elem) {
            contar++;
        }
    }
    return contar;
}
tElemntos resolver(const vector<int>& v, int ini, int fin) {
    if (ini == fin) {
        return { 1,v[ini] };
    }
    else {
        int m = (ini + fin) / 2;
        tElemntos elemIzq = resolver(v, ini, m);
        tElemntos elemDer = resolver(v, m + 1, fin);

        int contarIzq = contarElems(v, elemIzq.elem, ini, fin);
        int contarDer = contarElems(v, elemDer.elem, ini, fin);

        if (contarIzq > contarDer) {
            return { contarIzq, elemIzq.elem };
        }
        else {
            return { contarDer, elemDer.elem };
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v;
    int aux;
    cin >> aux;
    while (aux != 0) {
        v.push_back(aux);
        cin >> aux;
    }
    // escribir sol
    if (!v.empty()) {
        auto result = resolver(v, 0, v.size() - 1);
        if (result.cantidad > v.size() / 2) {
            cout << result.elem << "\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else {
        cout << "NO\n";
    }

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}