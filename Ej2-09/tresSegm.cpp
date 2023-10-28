// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int>& v) {
    int cont = 1, lMax = 1, lAct = 1;
        for (int i = 0;i < v.size() - 1;i++) {
            if (v[i] < v[i + 1]) {
                cont++;
                lAct++;
            }
            else {
                lAct++;
                cont = 1;
            }
            if (cont == 3) {
                lAct = 2;
                cont--;
            }
            if (lMax <= lAct) lMax = lAct;
        }
        if (lMax <= lAct) lMax = lAct;
    return lMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v)cin >> i;
    int l = 0;

    // escribir sol
    int sol;
    if (v.size() < 3) sol = v.size();

    else sol = resolver(v);

    cout << sol << endl;

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
