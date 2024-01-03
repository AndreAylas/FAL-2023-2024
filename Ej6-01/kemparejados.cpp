// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
struct tEmparejados {
    int cantidad=0;
    int ini=0;
    int fin = 0;
};

tEmparejados kemparejados(const vector<int>& v, const int k) {
    tEmparejados e;
    while (e.ini < v.size() && e.fin < v.size()) {
        if (v[e.fin] - v[e.ini] < k) {
            e.fin++;
        }
        else if (v[e.fin] - v[e.ini] > k) {
            e.ini++;
        }
        else {
            e.ini++;
            e.fin++;
            e.cantidad++;
        }
    }
    return e;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta


bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n;
    if (n==-1)
        return false;
    cin >> k;
    vector<int>v(n);
    for (auto& i : v)cin >> i;


    auto sol = kemparejados(v, k);
    // escribir sol
    cout << sol.cantidad << "\n";


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}