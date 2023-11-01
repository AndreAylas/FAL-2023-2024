// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;


// función que resuelve el problema
int num_combi(int i, int j, vector<vector<int>>&C) {
    if (j == 0 || j == i) return 1;
    else if (C[i][j] != -1) return C[i][j];
    else {
        C[i][j] = num_combi(i - 1, j - 1, C) + num_combi(i - 1, j, C);
        return C[i][j];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    cin >> a >> b;
    if (!std::cin)
        return false;

    // escribir sol
    vector<vector<int>>C(a + 1, vector<int>(b + 1, -1));
    cout<< num_combi(a,b,C)<<"\n";



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