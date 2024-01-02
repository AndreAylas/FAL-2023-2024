// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

struct tCasino {
    int gananciaMax;
    int ini;
    int fin;
    tCasino() :gananciaMax(0), ini(0), fin(-1) {}
};
// función que resuelve el problema
tCasino resolver(const vector<int>&v,const int s) {
    tCasino ca;
    int idx = 0, ganaciaActual = 0;
    for (int i = 0; i < v.size(); i++) {
        ganaciaActual += v[i];
        if (ganaciaActual > ca.gananciaMax) {
            ca.gananciaMax = ganaciaActual;
            ca.ini = idx;
            ca.fin = i;
        }
        if (ganaciaActual < 0) {
            ganaciaActual = 0;
            idx = i + 1;
        }
    }
    if (ca.gananciaMax >= s) {
        return ca;
    }
    else {
        tCasino c;
        return c;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto& i : v)cin >> i;

    auto sol = resolver(v,s);
    // escribir sol
    if (sol.gananciaMax == 0) {
        cout << "NO COMPENSA\n";
    }
    else {
        cout << sol.gananciaMax << " " << sol.ini << " " << sol.fin << "\n";
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