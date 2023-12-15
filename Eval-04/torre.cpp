/*
 * Plantilla para la práctica 4
 * Escribid vuestro nombre y usuarios:
 *   -F04 : oscar andre aylas hernandez
 *    -F58: carlos Mayorga Santiago
 *   -
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/* Para los colores usamos 3 valores enteros:
 *    0 -> azul
 *    1 -> rojo
 *    2 -> verde
 * Esta función devuelve un string según el valor del entero
 */
string color(const int i) {
    switch (i) {
    case 0:
        return "azul";
    case 1:
        return "rojo";
    case 2:
        return "verde";
    }
}

/*
 * Explica el espacio de búsqueda, solución y marcadores utilizados
 * el arbol de exploracion tiene longitud de m colores(3) y una profundidad de H-1 por que el k=1 empieza de 1 ya que el problema nos pide
 * que empecemos con el color rojo
 * Marcadores:vector<int> piezas usadas cada vez que exploramos y elegimos un color se incrementa en 1 la pieza usada
 * la funcion esValida verifica las condiciones del problema como por ejemplo que no se debe repetir color verde que las piezas usada
 * no supere a las disponibles que las piezas usadas azules superen a las verdes
 * y cuando k es el ultimo nivel es solucion siempre y cuando canitdad usada de color rojo supere a la suma del verde y azul
 */
void escribirSolucion(std::vector <int > const& v) {
    for (int num : v) std::cout << color(num) << " ";

    std::cout << '\n';
}

bool esValida(std::vector <int >const& sol, int k, int color, std::vector <int >const& piezasDisposibles, std::vector <int >const& piezasUsadas) {
    if (color == 2) {
        if (piezasUsadas[2] >= piezasUsadas[0])return false;//el numero de piezas verdes supere al de piezas azules

        if (sol[k - 1] == 2) return false;//No puede haber dos verdes seguidas
    }

    if (piezasDisposibles[color] <= piezasUsadas[color]) return false;

    return true;
}
// Calcula de forma recursiva las variaciones de los elementos
void variaciones(int m, int n, int k, std::vector <int >const& piezasDisposibles, std::vector <int >& piezasUsadas, std::vector <int >& sol, bool& haySol) {

    for (int i = 0; i < m; i++) {

        sol[k] = i;

        if (esValida(sol, k, i, piezasDisposibles, piezasUsadas)) {

            piezasUsadas[i]++;

            if (k == n - 1) { // Es solucion
                if (piezasUsadas[1] > piezasUsadas[0] + piezasUsadas[2]) { //el numero de piezas rojas debe ser mayor que la suma de las piezas azules y verdes.
                    escribirSolucion(sol);
                    if (!haySol) haySol = true;
                }
            }
            else { // Sigue completando la solucion
                variaciones(m, n, k + 1, piezasDisposibles, piezasUsadas, sol, haySol);
            }

            piezasUsadas[i]--;

        }
    }
}



bool resuelveCaso() {
    int H, A, R, V; //Altura, Azul, Rojo y Verde
    cin >> H >> A >> R >> V;
    if (H == 0 && A == 0 && R == 0 && V == 0)
        return false;

    //Crea los datos para la solución, marcadores, etc
    const int COLORS = 3; // azul(0),rojo(1),verde(2)

    std::vector <int> sol(H);
    std::vector <int> piezasDisposibles(COLORS);
    std::vector <int> piezasUsadas(COLORS, 0);

    bool haySol = false;
    piezasDisposibles[0] = A;
    piezasDisposibles[1] = R;
    piezasDisposibles[2] = V;


    if (piezasDisposibles[1] > 0) {
        sol[0] = 1; //la torre empieza en el color rojo siempre
        piezasUsadas[1]++;

        //la torre contiene H >= 2 piezas
        variaciones(COLORS, H, 1, piezasDisposibles, piezasUsadas, sol, haySol);
    }

    if (!haySol)std::cout << "SIN SOLUCION \n";

    std::cout << '\n';


    //Llama a la función vuelta atrás


    //Escribe el resultado: 


    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}