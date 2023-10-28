// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
using lli = long long int;

struct tnum{
    lli valor;
    bool tieneuno;
};

// función que resuelve el problema
tnum sinunos(lli n) {
    if (n <10) {
        if (n == 0) return {1, false};
        else {
            if (n == 1) return { n, true };
            else return { n, false };
        }
    }
    else {
        tnum s = sinunos(n / 10);
        s.valor = s.valor * 9;
        if (s.tieneuno) return s;
        else {
            if (n % 10 > 1) s.valor -= 9 - n % 10;
            else s.valor -= 8;
            if (n % 10 == 1) s.tieneuno = true;
            return s;
        }
     
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli num;
    cin >> num;
    if (!std::cin)
        return false;
    bool b = false;
    cout << sinunos(num).valor << "\n";

    // escribir sol


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