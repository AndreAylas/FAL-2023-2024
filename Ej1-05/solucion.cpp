// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema

/*
n=numero de elementos a analizar
r=datos erroneos;
P={existe i:0<=i<n:v[i]=r and (-2^63<r and r<2^63)}
func resolver(inout: v[],inout: n,int r)

resolver(v,r)={ idx=0 && (datos[idx]=(forall i:0<=i<n && v[i]!=r:v[i])&& idx=(forall i:0<=i<n && v[i]!=r:idx+1)}
*/

//funcion que resuelve el problema

void resolver(vector<int> &v,int r){
    vector<int> aux;
    int n=v.size();
    int idx=0;
    for(int i=0;i<n;i++){
        if(v[i]!=r){
            v[idx]=v[i];
            idx++;
        }
    }
    v.resize(idx);
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int error;int n;
    cin>>n>>error;
    vector<int> sol(n);
    for(auto&i:sol)cin>>i;
    resolver(sol,error);
    // escribir sol
    cout<<sol.size()<<"\n";
    for(auto&i:sol)cout<<i<<" ";
    cout<<"\n";
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