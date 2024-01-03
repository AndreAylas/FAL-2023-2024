// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema

bool cTramos(const vector<int>& v, int c) {
    int cant =0;
    int ini = 0;
    for (int i = 0; i < v.size(); i++) {
        
        cant += v[i];
        while (cant > c) {
            cant -= v[ini];
            ++ini;
        }
        if (cant == c) {
            return true;
        }
    }
    return false;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, c;
    cin >> n;
    if (n==-1)
        return false;
    vector<int> v(n);
    for (auto& i : v)cin >> i;
    cin >> c;
    bool sol = cTramos(v,c);

    // escribir sol
    if (sol) {
        cout << "SI";
    }
    else{
        cout << "NO";
    }
    cout << "\n";
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
