// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;



// función que resuelve el problema
void imprimir(const vector<char>&sol,int n){
    for(auto&i:sol){
        cout<<i;
    }
    cout<<"\n";
}
void variaciones(vector<bool> & marcador,vector<char> &sol,int k,int n,int m){
    for(char i='a';i<'a'+n;i++){
        sol[k]=i;
        if(!marcador[i-'a']){
            marcador[i-'a']=true;
            if(k==m-1){
                imprimir(sol,n);
            }
            else{
                variaciones(marcador,sol,k+1,n,m);
            }
            marcador[i-'a']=false;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,m;
    cin>>n;
    if (! std::cin)
        return false;
    cin>>m;
    vector<char> sol(m);
    vector<bool> marcador(m,false);
    variaciones(marcador,sol,0,n,m);
    cout<<"\n";
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
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