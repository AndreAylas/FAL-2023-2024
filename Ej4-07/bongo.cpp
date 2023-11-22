// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int bongo(const vector<int>& v, int ini, int fin,int b) {
    if (ini == fin) {
        return -1;
    }
    else {
        int m = (ini + fin)/2;
        if (v[m] == m + b)return v[m];
        else if (v[m] < m + b)
            return bongo(v, m+1, fin, b);
        else
            return bongo(v, ini, m, b);

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, b;
    cin >> n>>b;
    vector<int> v(n);
    for (auto& i : v)cin >> i;
    int sol = bongo(v, 0, n,b);
    // escribir sol
    if (sol != -1) {
        cout << sol;
    }
    else {
        cout << "NO";
    }
    cout << "\n";
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