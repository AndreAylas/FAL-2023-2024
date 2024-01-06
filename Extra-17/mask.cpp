// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;
struct tSuministrador {
    int cantidad;
    int precio;

};
const int MAXIMO = 1e9;
class ord {
public:
    ord() {}
    bool operator() (const tSuministrador& a, const tSuministrador& b)const {
        return a.precio < b.precio;
    }
};
// función que resuelve el problema
void  comprasToSuministrador(int k, int n, int m, vector<int>& facultad, vector<tSuministrador>& suministrador, int& precioMejor, int& precioActual,int &mask) {
    for (int i = 0; i < n; i++) {
        if (facultad[i] > 0) {
            int stock = min(facultad[i], suministrador[k].cantidad);
            int cost = stock * suministrador[k].precio;
            //marcamos
            facultad[i] = facultad[i] - stock;
            precioActual += cost;
            if (k == m - 1) {
                precioMejor = min(precioMejor, precioActual);
            }
            else {

                comprasToSuministrador(k + 1, n, m, facultad, suministrador, precioMejor, precioActual,mask);
            }
            facultad[i] = facultad[i] + stock;
            precioActual -= cost;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;//n facultades y m suministradores
    cin >> n >> m;
    vector<int> facultad(n);
    for (auto& i : facultad)cin >> i;
    vector<int> stock(m);
    vector<int> price(m);
    int mask = 0;
    for (auto& i : stock) { cin >> i; mask += i; }
    for (auto& i : price)cin >> i;
    vector< tSuministrador> suministrador;
    for (int i = 0; i < m; i++) {
        suministrador.push_back({ stock[i],price[i] });
    }
    sort(suministrador.begin(), suministrador.end(), ord());
    int precioMejor = MAXIMO;
    int precioActual = 0;



    // escribir sol
    comprasToSuministrador(0, n, m, facultad, suministrador, precioMejor, precioActual,mask);
    if (precioMejor == MAXIMO) {
        cout << "NO\n";
    }
    else {
        cout << precioMejor << "\n";
    }

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