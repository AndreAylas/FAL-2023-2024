// Nombre del alumno .....
// Usuario del Juez ......
//

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
using lli = long long int;

// función que resuelve el problema
// F58 Carlos Mayorga Santiago
// F04 Oscar Andre Aylas Hernandez 
/*
ecuacion recursiva:
funcion complementario 
caso base:
T(n)=C0 si n<10
caso recursivo:
T(n)=T(n/10) + C1 si n>=10

coste de la implmentacion:
cada vez que se realiza la llamada recursiva el numero se divide entre 10 y retorna cuando le numero es un solo digito
por eso el coste es de O(logn) donde n es el numero de la entrada

*/
// función que resuelve el problema
lli complementario(lli const& num) {
    if (num < 10) {
        return 9 - num;
    }
    else {
        return complementario(num / 10) * 10 + (9 - num % 10);
    }

}

/*
ecuacion recursiva:
funcion invertirnum
caso base:
T(n)=C0 si n<10
caso recursivo:
T(n)=T(n/10) + C1 si n>=10

coste de la implmentacion:
cada vez que se realiza la llamada recursiva el numero se divide entre 10 y retorna cuando le numero es un solo digito
por eso el coste es de O(logn) donde n es el numero de la entrada

*/

void invertirnum(lli const& num, lli& numinv, int& pot) {
    if (num < 10) {
        numinv = 9 - num;
    }
    else {
        invertirnum(num / 10, numinv, pot);
        pot = pot * 10;
        numinv = numinv + (9 - num % 10) * pot;

    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    lli num;
    cin >> num;

    // escribir sol
    int pot = 1;
    lli numinv;
    invertirnum(num, numinv, pot);
    cout << complementario(num) << " " << numinv << "\n";

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