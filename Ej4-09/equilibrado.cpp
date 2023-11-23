// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
using matriz = vector<vector<int>>;

// función que resuelve el problema
struct tSol {
    int cont1;
    bool esEq;
};

tSol resolver(const matriz& m, int row_ini, int row_fin, int colum_ini, int colum_fin) {
    if (row_ini == row_fin && colum_ini == colum_fin) {
        if (m[row_ini][colum_ini] == 1) {
            return { 1,true };
        }
        else {
            return{ 0,true };
        }
    }
    else {
        int row_m = (row_ini + row_fin) / 2;
        int colum_m = (colum_ini + colum_fin) / 2;
        tSol zona1 = resolver(m, row_ini, row_m, colum_ini, colum_m);
        tSol zona2 = resolver(m, row_m + 1, row_fin, colum_ini, colum_m);
        tSol zona3 = resolver(m, row_ini, row_m, colum_m + 1, colum_fin);
        tSol zona4 = resolver(m, row_m + 1, row_fin, colum_m + 1, colum_fin);
        int total = (colum_fin - colum_ini + 1) * (row_fin - row_ini + 1);
        bool b = (zona1.cont1 + zona2.cont1 + zona3.cont1 + zona4.cont1 >= total / 4) && (zona1.cont1 + zona2.cont1 + zona3.cont1 + zona4.cont1 <= 3 * total/ 4);
        b = b && zona1.esEq && zona2.esEq && zona3.esEq && zona4.esEq;
        return{ zona1.cont1 + zona2.cont1 + zona3.cont1 + zona4.cont1 ,b };

    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    matriz m;
    m.clear();
    m.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    tSol sol = resolver(m,0,n-1,0,n-1);
    // escribir sol
    if (sol.esEq) {
        cout << "SI";
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
    std::ifstream in("datos.in");
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