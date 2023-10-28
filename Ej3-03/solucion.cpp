// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
using namespace std;

struct tSol {
    bool esInteresante;
    int sumaIzq;
};
// función que resuelve el problema
tSol resolver(int n,int &sumaDer) {
    if (n < 10) {
        bool b = n != 0 ? true : false;
        b = b && (sumaDer % n == 0);
        return{b,n };
    }
    else{
        int rest = n % 10;
        int num = n / 10;
        sumaDer = sumaDer + rest;
        tSol s = resolver(num, sumaDer);
        sumaDer = sumaDer - rest;
        if (sumaDer % rest == 0 && s.sumaIzq%rest==0) {
            s.esInteresante = s.esInteresante && true;
        }
        else {
            s.esInteresante = s.esInteresante && false;
        }
        s.sumaIzq += rest;
        return s;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    int suma = 0;
    tSol sol = resolver(n,suma);
    // escribir sol
    if (sol.esInteresante)cout << "SI\n";
    else cout << "NO\n";
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