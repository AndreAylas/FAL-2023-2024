// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;
using matriz = vector<vector<int>>;
struct tCarros {
    int nCarros;
    vector<int>carro;//anchura del carro
};
struct tCaminos {
    int mCaminos;
    vector<int>caminos;//anchira del camino
};

// función que resuelve el problema
bool esSolucion(int k, int carros) {
    return k == carros - 1;
}
bool esValido(const vector<int>& maquina,const vector<int>& carretera,int i,int k) {
    return maquina[k] <= carretera[i];
}
void solucion(int k, const tCarros& c, const tCaminos& ca, matriz& calidad, const vector<int>& calidadAcumulado, vector<bool>& marcaje, int& calidadActual, int& calidadMejor) {
    for (int i = 0; i < ca.mCaminos;i++) {
        if (esValido(c.carro, ca.caminos, i, k) && !marcaje[i]) {
            calidadActual += calidad[k][i];
            marcaje[i] = true;
            if (esSolucion(k, c.nCarros)) {
                calidadMejor = max(calidadMejor, calidadActual);
            }
            else if (calidadActual + calidadAcumulado[k + 1] > calidadMejor) {
                    solucion(k + 1, c, ca, calidad, calidadAcumulado, marcaje, calidadActual, calidadMejor);
            }
            calidadActual -= calidad[k][i];
            marcaje[i] = false;
        }
   }
    //si la maquina no cabe en ninguna carretera
    if (esSolucion(k, c.nCarros)) {
        calidadMejor = max(calidadMejor, calidadActual);
    }
    else    if (calidadActual + calidadAcumulado[k + 1] > calidadMejor) {
        solucion(k + 1, c, ca, calidad, calidadAcumulado, marcaje, calidadActual, calidadMejor);
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    tCarros c; tCaminos ca;
    cin >> c.nCarros >> ca.mCaminos;
    c.carro.resize(c.nCarros);
    ca.caminos.resize(ca.mCaminos);
    for (int& i : c.carro)cin >> i;//maquina
    for (int& i : ca.caminos)cin >> i;//carretera
    matriz calidad(c.nCarros, vector<int>(ca.mCaminos, 0));

    for (int i = 0; i < c.nCarros; i++) {
        for (int j = 0; j < ca.mCaminos; j++) {
            cin >> calidad[i][j];
        }
    }
    vector<int> calidadTotal(ca.mCaminos);
    for (int j = 0; j < ca.mCaminos; j++) {
        int aux = 0;
        for (int i = 0; i < c.nCarros; i++) {
            if (c.carro[i] <= ca.caminos[j]&& aux<calidad[i][j]) {
                aux = calidad[i][j];
            }
        }
        calidadTotal[j] = aux;
    }
    //acumular la calidad
    for (int i = ca.mCaminos-1; i >0 ; i--) {
        calidadTotal[i - 1] += calidadTotal[i];
    }
    vector<bool> marcaje(ca.mCaminos, false);
    int calidadActual = 0, calidadMejor = 0;
    // escribir sol
    if (c.nCarros > 0) {
        solucion(0, c, ca, calidad, calidadTotal, marcaje, calidadActual, calidadMejor);
    }
    cout << calidadMejor << endl;
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