// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<limits.h>
using namespace std;


bool esCompatible(int k, int i, const vector<int>& G, const vector<int>& P, vector<int>& personas) {
    return personas[i]+P[k]<=G[i];
}

int poda(const int restantes, const int minimo) {
    return minimo * restantes;
}

void imprimirSol(const vector<int>& sol) {
    for (int i : sol) {
        cout << i << " ";
   }
    cout << "\n";
}

// función que resuelve el problema
void solucion(vector<int>const&L,vector<int>const&G,vector<int>const&S,vector<int>const& P,int&Minsueldo,int&sueldoparcial,int r,int k,vector<int>&sol,int&restante,const int minimo,vector<int>&personas,int ciudades) {
    for (int i = 0;i < L.size();i++) {//probamos a asignar la patrulla a una ciudad
        sol[k] = i;
        sueldoparcial += P[k] * S[i];
        restante -= P[k];
        if (esCompatible(k, i, G, P, personas)) {
            if (personas[i] < L[i] && (personas[i] + P[k] >= L[i])) {
                ciudades++;
            }
            personas[i] += P[k];
            if (k == P.size() - 1) {
                if (ciudades == L.size()) {
                    //  imprimirSol(sol);
                    Minsueldo = min(Minsueldo, sueldoparcial);
                }
            }
            else {
                if (poda(restante, minimo) + sueldoparcial < Minsueldo) {
                    solucion(L, G, S, P, Minsueldo, sueldoparcial, r, k + 1, sol, restante, minimo, personas, ciudades);
                }
            }
            //desmarcamos
            personas[i] -= P[k];
            if (personas[i] < L[i] && (personas[i] + P[k] >= L[i])) {
                ciudades--;
            }
        }
        sueldoparcial -= P[k] * S[i];
        restante += P[k];
       
    }
//probando a no asignar la patrulla
    sol[k] = -1;
    //marcamos
    sueldoparcial += P[k] * r;
    restante -= P[k];
    if (k == P.size() - 1) {
        if (ciudades == L.size()) {
            // imprimirSol(sol);
            Minsueldo = min(Minsueldo, sueldoparcial);
        }
    }
    else {
        if (poda(restante, minimo) + sueldoparcial < Minsueldo) {
            solucion(L, G, S, P, Minsueldo, sueldoparcial, r, k + 1, sol, restante, minimo, personas, ciudades);
        }
    }
    //desmarcamos
    sueldoparcial -= P[k] * r;
    restante += P[k];

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int m, n, r;
    cin >> n >> m >> r;
    vector<int> L(n);
    vector<int>G(n);
    vector<int> S(n);

    for (auto& i : L)cin >> i;
    for (auto& j : G)cin >> j;
    for (auto& k : S)cin >> k;
    vector<int>P(m);
    for (auto& l : P)cin >> l;
    int Minsueldo = INT_MAX;
    int k = 0,sueldoParcial=0;
    int restantes = 0;//numero de personas
    for (auto& i : P) {
        restantes += i;
    }
    int minimo = r;
    for (auto& j : S) {
        minimo = min(minimo, j);
    }
    vector<int>sol(m);
    vector<int>personas(n,0);
    int ciudades = 0;
    solucion(L, G, S,P, Minsueldo, sueldoParcial, r, k, sol,restantes,minimo,personas,ciudades);
    // escribir sol
    if (Minsueldo < INT_MAX) {
        cout << Minsueldo;
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