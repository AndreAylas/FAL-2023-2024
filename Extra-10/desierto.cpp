// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
// función que resuelve el problema
int resolver(const vector<int>& datos,int ini,int fin,int personas) {
    if (ini == fin) {
        if (datos[ini] < (int(datos.size())-ini) * personas)
            return ini;
        else
            return - 1;
    }
        
    else {
        int m = (ini + fin) / 2;
        if (datos[m] >=(int(datos.size())-m) * personas) {
            return resolver(datos, m + 1, fin, personas);
        }
        else {//datos[m] >=(m+1)*personas
            return resolver(datos, ini, m, personas);

        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int dias, personas;
    cin >> dias >> personas;
    vector<int> estimacion(dias);
    for (auto& i : estimacion)cin >> i;
    int sol = resolver(estimacion, 0, dias-1, personas);
    if(sol!=-1)
        cout << sol << endl;
    else
        cout << "SIN RACIONAMIENTO \n";
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