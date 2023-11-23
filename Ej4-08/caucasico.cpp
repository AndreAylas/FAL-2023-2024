// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
struct tSol {
    int suma;
    bool escaucasico;
};

tSol resolver(const vector<int>& v, int ini, int fin) {
    if (ini == fin) {
        if (v[ini] % 2 == 0)
            return { 1,true };
        else
            return{ 0,true };
    }
    else {
        int m = (ini + fin) / 2;
        tSol izq = resolver(v, ini, m);
        tSol der = resolver(v, m + 1, fin);
        bool b = izq.escaucasico && der.escaucasico && (abs(izq.suma - der.suma) <= 2);

        return { izq.suma + der.suma,b };

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n==0)
        return false;
    vector<int>v(n);
    for (auto& i : v)cin >> i;
    tSol sol = resolver(v,0,n-1);

    // escribir sol
    if (sol.escaucasico) {
        cout << "SI";
    }
    else {
        cout << "NO";
    }
    cout << "\n";
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
