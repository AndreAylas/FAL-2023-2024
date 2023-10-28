// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
using lli = long long int;


// función que resuelve el problema
lli sinunos(lli num, bool& b) {
    if (num <10) {
        b = num % 10 == 1;
        return num == 0 ? 1 : num;
    }
    else {
        lli n = num / 10;
        lli resto = num % 10;
        lli r = sinunos(n,b);
        if (b||r==0||r==1) {
            if (n >= 20 && !b) {
                r = r * 9 - 8;
            }
            else {
                r = r * 9;
            }
        }
        else {
            r =r*9-(9-resto);
        }
        b = b || resto == 1;
        return r;
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
    cout << sinunos(num,b) << "\n";

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