// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
const int MAXIMO = 1000000;
// función que resuelve el problema
bool esValida(vector<int>& numCompras, int i) {
    return numCompras[i] < 3;
}
bool esSolucion(int k, int m) {
    return k == m - 1;
}
void supermercado(const vector<vector<int>>& price, vector<int>& sol, vector<int>& numCompras, int k, int n, int m, int& costeMejor, int& costeActual) {
    for (int i = 0; i < n; i++) {
        sol[k] = i;
        if (esValida(numCompras, i)) {
            numCompras[i]++;
            costeActual += price[i][k];
            if (esSolucion(k, m)) {
                costeMejor = min(costeMejor, costeActual);
            }
            else {
                supermercado(price, sol, numCompras, k + 1, n, m, costeMejor, costeActual);
            }
            numCompras[i]--;
            costeActual -= price[i][k];
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;//n supermercado y m producto
    cin >> n >> m;
    vector<vector<int>> price(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> price[i][j];
        }
    }
    vector<int>sol(m);//valores que asume de 0 a n-1
    vector<int>cantCompras(n);
    int costeMejor = MAXIMO, costeActual = 0;
    supermercado(price, sol, cantCompras, 0, n, m, costeMejor, costeActual);
    if (costeMejor == MAXIMO) {
        cout << "Sin solucion factible";
    }
    else {
        cout << costeMejor;
    }
    cout << "\n";
    // escribir sol


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