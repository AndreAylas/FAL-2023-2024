// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct tSol {
    int contar;
    int producto;
};
// función que resuelve el problema
tSol resolver(int n) {
    
    if (n < 10) {
        int producto = 1;
        if (n == 1)return { 1,1 };
        else return { 0,n };
    }
    else {
        int resto = n % 10;
        int num = n / 10;
        tSol s = resolver(num);
        if (s.producto % 10 == resto) {
            s.contar++;
            
        }
        s.producto = s.producto * resto;
        return s;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0 ) {
        cout << "0\n";
    }
    else {
        cout<<resolver(n).contar<<"\n";
    }
    // escribir sol


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