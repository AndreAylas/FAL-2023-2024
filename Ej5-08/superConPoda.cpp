// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
using Matriz = vector<vector<int>>;
const int Max = 1000000;
// función que resuelve el problema
void resolver(const int& mSuper,const int& nProd,int k,const Matriz& v,vector<int>& contarProd,const vector<int> & cost_prod, int &coste_mejor,int &  coste_Actual,bool &b) {
    for (int i = 0;i < mSuper;i++) {
        if (contarProd[i] < 3) {//marcaje
            coste_Actual+= v[i][k];
            contarProd[i]++;
            if (k == nProd - 1) {
                coste_mejor = min(coste_mejor, coste_Actual);
                b = true;
            }
            else {
                //poda
                if (coste_Actual+ cost_prod[k + 1] < coste_mejor) {
                    resolver(mSuper, nProd, k + 1, v, contarProd, cost_prod, coste_mejor, coste_Actual, b);
                }
            }
            coste_Actual-= v[i][k];
            contarProd[i]--;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nProd, mSuper;
    cin >> mSuper >> nProd;
    Matriz v(mSuper, vector<int>(nProd));
    vector<int> cost_prod(nProd, Max);
    for (int i = 0;i < mSuper;++i) {
        for (int j = 0;j < nProd;++j) {
            cin >> v[i][j];
            cost_prod[j] = min(cost_prod[j], v[i][j]);
        }
    }
    vector<int> contarProd(mSuper, 0);
    for (int k = nProd - 1;k > 0;k--) {
        cost_prod[k - 1] += cost_prod[k];
    }
    int coste_mejor = Max;
    int coste_Actual= 0;
    bool b = false;
    resolver(mSuper,nProd,0,v, contarProd,cost_prod,coste_mejor,coste_Actual,b);
    // escribir sol
    if (b)cout << coste_mejor << "\n";
    else cout << "Sin solucion factible\n";
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