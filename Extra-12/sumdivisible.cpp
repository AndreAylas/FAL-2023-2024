// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct tSol {
    int sum;
    int n;//tmaaño
    bool esdiv;
};
// función que resuelve el problema
tSol resolver(const int& datos) {
    if (datos < 10) {
        return { datos,1,true };
    }
    else {
        int res = datos % 10;
        tSol s = resolver(datos / 10);
        s.n++;
        if ((res + s.sum) %s.n == 0) {
            s.esdiv =s.esdiv && true;
        }
        else { s.esdiv =s.esdiv && false; }
        return { s.sum + res,s.n,s.esdiv };
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (num==0)
        return false;

    tSol sol = resolver(num);

    // escribir sol
    if (sol.esdiv)
        cout << "SI";
    else
        cout << "NO";
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