/*
 * Plantilla para la Práctica 3
 * Escribid vuestro nombre y usuarios:
 *   -
 *   -
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using matriz = vector<vector<int>>;
/*
F04 oscar andre aylas herandnez
F58 Carlos Mayorga Santiago

*/

/*
 * ESCRIBE LA FUNCIÓN DIVIDE Y VENCERÁS.
 * LA RECURSIÓN DEL COSTE
 * la funcion de recurrencia
 * caso base:
 * T(0)=C_0   para todo ini+2==fin
 * T(0)=C_1   para todo ini+2>fin
 * caso recurrencia
 * 
 * T(M)=2T(M/2) +C_k caso contrario
 * a=2 b=2 k=0 2>2^0 M^log(2) base 2
 * 
Esta recurrencia presenta un costo lineal, siendo 'M' el tamaño de la collumna de la matriz imagen.
El programa se enfoca en dividir la fila en dos partes, asegurando que la suma de la parte izquierda sea menor 
que la derecha en cada subdivisión. Este proceso continúa hasta alcanzar el caso base, que implica evaluar
dos valores específicos. La función se completa cuando se determina que el lado izquierdo es mayor que el derecho.
 * 
 * 
 * EL COSTE QUE OBTENGAS
 */


 /*
  * Función iterativa que llama a una función recursiva que comprueba si la fila es un degradado.
  * ¡¡¡COMPLETALA!!
  */
struct tSol {
    int sum;
    bool esDeg;
};

tSol degradado(const matriz& v, int i,int ini, int fin) {
    if (ini + 2 == fin) {
        if (v[i][ini] < v[i][fin - 1]) return { v[i][ini] + v[i][fin - 1],true};
        else return { v[i][ini] + v[i][fin - 1],false };
    }
    else if (ini + 2 > fin) {
        if (v[i][ini] < v[i][fin - 1]) return { v[i][ini] + v[i][fin - 1],false };
        else return { v[i][ini] + v[i][fin - 1],true };
    }
    else {
        int m = (ini + fin) / 2;
        tSol izq = degradado(v, i, ini, m);
        tSol der = degradado(v, i, m, fin);
        bool b = izq.esDeg && der.esDeg;
        b = b&& izq.sum<der.sum;
        return { izq.sum + der.sum,b };
    }
}
bool comprueba_matriz(const matriz& v, const int N, const int M) {
    bool lo_es = true;
    int i = 0;
    while (lo_es && i < N) { //O(N*M) //donde N es el tamaño de las filas y M es el tamaño de las columnas
        //LLama a la función recursiva y actualiza las variables
       tSol s= degradado(v, i,0, M);//O(M)
       lo_es = s.esDeg;
        i++;
    }

    return lo_es;
}

//--- NO MODIFIQUES NADA AQUÍ -----//
//------------------------------------------------------
bool resuelveCaso() {

    //Lectura de datos
    int N, M; //filas y columnas
    cin >> N >> M;
    if (!cin)
        return false;

    matriz imagen;
    for (int i = 0; i < N; i++) {
        vector<int> fila(M); //para leer la fila
        for (int j = 0; j < M; j++)
            cin >> fila[j];
        imagen.push_back(fila);
    }

    //En imagen hay N filas y cada una de ellas es un vector de tamaño M

    bool sol = comprueba_matriz(imagen, N, M);

    if (sol)
        cout << "SI\n";
    else
        cout << "NO\n";

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