// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

// función que resuelve el problema
int galactica(vector<int>&v,int ini,int fin) {
    if (ini + 1 == fin)
        return 0;
    else {
        int m = (ini + fin) / 2;
        int ladoIzq = galactica(v, ini, m);
        int ladoDer = galactica(v, m, fin);
        int i = ini,j=m;
        int tiempo = ladoDer + ladoIzq;
        while (i < m && j < fin) {
            if (v[i] < v[j])i++;
            else {
                tiempo += m- i;
                j++;
            }
        }
        inplace_merge(v.begin() + i, v.begin() + m, v.begin() + fin);
        return tiempo;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int> v(n);
    for (auto& i : v)cin >> i;
    int sol = galactica(v,0,n);

    // escribir sol
    cout << sol << "\n";

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