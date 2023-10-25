// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

using namespace std;
struct tSol {
    int ini;
    int fin;
};
/*
n=v.size()
P={n>=1 && exit i:0<=i<n:v[i]>t};
func resolver(v[],n,t)dev {out ini,out fin}

Q={ intervalo(v[],n,t,ini,fin) &&ladoIzq(v[],n,t,ini,fin)}
intervalo(v[],n,t,ini,fin)=((0<=ini<=fin<n) && (forall:ini<=i<=fin:v[i]>t))
ladoIzq(v[],n,t,ini,fin)={forall i,j:0<=i<=j<n:&&intervalo(v,n,t,i,j):(fin-ini>j-i)|| (fin-ini)=j-i->ini<i)}
el coste es de O(n) donde n es el numero de altura,esto es porque se recorre una vez el vector donde se busca
el mayor intervalo donde los elementos del vector supere a t   
*/
// función que resuelve el problema
tSol resolver(const vector<int>& v, int t) {
    tSol s={0,0};
    int segmento = 0,segMax=0;
    //I=(intervalo(v[],n,t,ini,fin) &&ladoIzq(v[],n,t,ini,fin))
    for (int i = 0; i<v.size(); i++) {
        if (v[i] > t) {
            segmento++;
            if (segmento > segMax) {
                segMax = segmento;
                s.fin = i;
            }
        }
        else {
            segmento = 0;
        }
    }
    if (s.fin != 0)s.ini = s.fin - segMax + 1;
    return s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (auto& i : v)cin >> i;
    tSol sol = resolver(v, t);
    // escribir sol
    cout << sol.ini << " " << sol.fin << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.in");
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