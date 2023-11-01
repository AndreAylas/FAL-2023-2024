// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
const int MAX = 1e7;
// función que resuelve el problema

struct tSol {
    int suma;
    bool esImPar;
};

tSol resolver(int num,int minimo,int&maximo) {
    if (num < 10) {
        maximo = max(maximo, num);
        
        return{ num*3+minimo,false };
    }
    else {
        int resto = num % 10;
        int n = num / 10;
 
        tSol s = resolver(n, min(minimo, resto), maximo);
        if (s.esImPar) {
            s.suma = s.suma + resto * 3 + minimo;
            s.esImPar = !s.esImPar;
        }
        else {
            s.suma = s.suma + resto * 2 + maximo;
            s.esImPar = !s.esImPar;
        }
        maximo = max(maximo, resto);
        return s;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    int minimo, maximo;
    minimo = MAX,maximo=0;
    tSol s = resolver(num,minimo,maximo);
    // escribir sol
    cout << s.suma << "\n";

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