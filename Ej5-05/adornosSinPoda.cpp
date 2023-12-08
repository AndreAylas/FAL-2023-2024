// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
using object = pair<int, int>;


// función que resuelve el problema

bool esSolucion(int k, int n) {
    return k == n - 1;
}
bool esCompletable(int k, int n) {
    return k < n - 1;
}
bool esValida(int& budge_actual,int& budget) {
    return budge_actual <= budget;
}
void VA(const vector<object>& v, int budget, int n, int k, int& supAct, int& supMax,int &budge_actual) {
    //opcion 1 no se coje el objecto
    if (esSolucion(k, n))
        supMax = max(supAct, supMax);
    else if (esCompletable(k, n)) {
        VA(v, budget,n, k + 1, supAct, supMax,budge_actual);
    }
    //si es seleccionable
    budge_actual += v[k].first;
    supAct += v[k].second;
    if (esValida(budge_actual,budget) ){
        if (esSolucion(k, n)) {
            supMax = max(supAct, supMax);
        }
        else if (esCompletable(k, n)) {
            VA(v, budget, n, k + 1, supAct, supMax, budge_actual);
        }
    }
    budge_actual -= v[k].first;
    supAct -= v[k].second;
}

int calcular(int n, const vector<object>& comprar, int budget) {
    int k = 0;
    int budge_actual = 0;
    int supAct = 0, supMax = 0;
    VA(comprar, budget, n, k, supAct, supMax,budge_actual);
    return supMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    int budget; cin >> budget;
    vector<object> comprar(n);//primer valor es el cost y el segundo superficie
    for (auto& o : comprar)cin >> o.first >> o.second;
   
    int sol = calcular(n, comprar, budget);
    cout << sol << "\n";

    // escribir sol


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