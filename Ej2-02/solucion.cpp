// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
using lli=long long int;
// función que resuelve el problema
/*

P=(0<n<=v.size() && forall i:0<=i<n:v[i]!=vacio)

func minimal(const in v[],int n) dev bool r



Q=(minimo=v[0] && contar=# u:0<u<n:v[u]=minimo && contar<2)

*/

bool resolver(const vector<lli>&v) {
    bool b=true;
    int i=1;
    int minimo=v[0];
    //I=(minimo=v[0] && contar=# u:0<u<n:v[u]=minimo && contar<2)
    while(b && i<v.size()){
        if(minimo<v[i]){
            b=true;
        }
        else if(minimo>v[i]){
            minimo=v[i];
            b=true;
        }
        else{
            b=false;
        }
        i++;
    }
    return b;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli n;
    cin>>n;
    if (n==-1)
        return false;
    vector<lli>v(n);
    for(auto&i:v)cin>>i;
    bool sol = resolver(v);
    
    // escribir sol
    if(sol){
        cout<<"SI";
    }
    else{
        cout<<"NO";
    }
    cout<<"\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("casos.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
