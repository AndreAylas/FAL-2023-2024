// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& valores, int vInicial, int ini, int fin) {
    int mitad = (ini + fin) / 2;

    // Caso base: cuando solo me quede un número
    if (ini == fin) {
        return (valores[ini] == vInicial) ? valores[ini] + 1 : valores[ini];
    }

    // Cuando me queden 2 números
    else if (ini + 1 == fin) {
        return (valores[fin] - valores[ini] == 1) ? valores[fin] + 1 : valores[ini] + 1;
    }

    else {
        // Si la diferencia de los valores es igual, en la mitad izquierda no falta ningún número
        if (mitad - ini == valores[mitad] - valores[ini]) {
            // Me muevo a la derecha
            return resolver(valores, vInicial, mitad, fin);
        }
        // Si no, falta en la mitad izquierda
        else {
            return resolver(valores, vInicial, ini, mitad);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n,idx;
    cin>>n>>idx;
    vector<int> v(n);
    for(auto&i:v)cin>>i;

    // escribir sol
    // Escribir solución
    cout << ((n == 0 || v[0] != idx) ? idx : resolver(v, idx, 0, n-1)) << "\n";
    
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