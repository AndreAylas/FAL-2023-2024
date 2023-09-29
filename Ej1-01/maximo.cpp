// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<sstream>
using namespace std;


// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
/*
N=numero de vueltas
v=supuesto vector
P={forall w:0<w<N:v[w]!=0}
func contar(int v[],int N) dev r;
Q={maximo=max u:0<=u<N:v[u] and r=#i:0<=i<N:v[i]=maximo }
*/

void resuelveCaso() {
    // leer los datos de la entrada
    //string line;
    //cin.ignore();
    //getline(cin, line);
    // cin.ignore();
    //stringstream ss(line); 
    int num;
    cin >> num;
    int maximo = num;
    int contar = 1;
    cin>>num;
    //coste O(N)
    while (num!=0) {
        if (maximo >= num) {
            if (maximo == num) {
                contar++;
            }
        }
        else {
            maximo = num;
            contar = 1;
        }
        cin >> num;
    }
    // escribir sol
    cout << maximo << " " << contar << "\n";
    
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