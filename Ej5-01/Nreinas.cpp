// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
int idXDiagonal_princ(int x, int y, int N) {
    return (x - y + (N - 1));
}

int idxDiagonal_sec(int x, int y) {
    return x + y;
}

bool doNotAttack(vector<int>& sol, vector<bool>& diag_princ, vector<bool>& diag_sec, vector<bool>& fila, int k, int N) {
    return !fila[sol[k]] && !diag_princ[idXDiagonal_princ(k, sol[k], N)] && !diag_sec[idxDiagonal_sec(k, sol[k])];
}


bool esSolucion(vector<int>& sol, vector<bool>& diag_princ, vector<bool>& diag_sec, vector<bool>& fila, int k, int N) {
    return (k == N - 1) && doNotAttack(sol, diag_princ, diag_sec, fila,k, N);
}



bool esCompletable(vector<int>& sol, vector<bool>& diag_princ, vector<bool>& diag_sec, vector<bool>& fila, int k, int N) {
    return k<N-1 && doNotAttack(sol, diag_princ, diag_sec, fila, k, N);
}

// función que resuelve el problema
void resolver(vector<int>& sol,vector<bool> &diag_princ,vector<bool>& diag_sec,vector<bool> &fila,int k,int N,int &contar) {
    for (int i = 0;i < N;i++) {
        sol[k] = i;
        if (esSolucion(sol, diag_princ, diag_sec, fila, k, N)) {
            contar++;
        }
        else if (esCompletable(sol, diag_princ, diag_sec, fila, k, N)) {
            //marcamos
            fila[i] = true;
            diag_sec[idxDiagonal_sec(k, sol[k])] = true;
            diag_princ[idXDiagonal_princ(k, sol[k], N)] = true;
            resolver(sol, diag_princ, diag_sec, fila, k + 1, N, contar);
            //desmarcamos
            fila[i] = false;
            diag_sec[idxDiagonal_sec(k, sol[k])] = false;
            diag_princ[idXDiagonal_princ(k, sol[k], N)] = false;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    vector<int> sol(N);
    vector<bool> filas(N,false);
    vector<bool> diag_princ(2 * N - 1,false);
    vector<bool> diag_sec(2 * N - 1,false);
    int k = 0;
    int contar = 0;
    resolver(sol, diag_princ, diag_sec,filas, k,N,contar);
    // escribir sol
    cout << contar << "\n";
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