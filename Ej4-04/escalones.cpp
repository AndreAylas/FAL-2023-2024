// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include <algorithm>
using namespace std;


// función que resuelve el problema

int resolver(const vector<int>& v, int ini, int fin) {
    if (ini == fin)
        return 1;

    int m = (ini + fin) / 2;
    int izq = resolver(v, ini, m);
    int der = resolver(v, m + 1, fin);

    // Verificar si hay un escalón entre las dos mitades
    int largo = 0;
    if (v[m] == v[m + 1]) {
        int izqLargo = 0;
        int derLargo = 0;

        // Verificar longitud del escalón en la mitad izquierda
        for (int i = m; i >= ini && v[i] == v[m]; --i) {
            ++izqLargo;
        }

        // Verificar longitud del escalón en la mitad derecha
        for (int i = m + 1; i <= fin && v[i] == v[m + 1]; ++i) {
            ++derLargo;
        }

        largo = izqLargo + derLargo;
    }

    // Devolver la longitud máxima entre izquierda, derecha y escalón consecutivo
    return max({ izq, der, largo });
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n==0)
        return false;
    vector<int> v(n);
    for (auto& i : v)cin >> i;
    int s = resolver(v,0,v.size()-1);
    // escribir sol
    cout << s << "\n";


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
