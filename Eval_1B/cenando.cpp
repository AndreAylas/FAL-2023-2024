// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<tuple>
using namespace std;

// función que resuelve el problema
tuple<int, int, int> resolver(const vector<int>& v, int n) {//primero la suma segundo el indice y tercero contar longitud;
    tuple<int, int, int> s;
    s = { 0,0,0 };
    int suma = 0;
    int idx = 0;
    int cont = 0;
    for (int i = 0; i < n; i++) {
        suma += v[i];
        if (suma > 0) {
            if (get<0>(s) < suma) {
                idx = i - cont;
                cont++;
                s = { suma,idx,cont};
            }
            else if (get<0>(s) == suma) {
                cont++;
                if (get<2>(s) > cont) {
                    get<2>(s) = cont;
                    get<1>(s) = i-cont+1;
                }

            }
            else {
                cont++;
            }
        }
        else {

            suma = 0;
            cont = 0;
        }
    }
    
    return s;
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

    auto result = resolver(v, n);

    // escribir sol
    cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << "\n";

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