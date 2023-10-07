// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int>&v,int l) {
    int cant=0;
    int ceros=0,unos=0;
    for(int i=0;i<l;i++){
        if(v[i]==0){
            ceros++;
        }
        else if(v[i]==1){
            unos++;
        }
    }
    if(ceros==unos)cant++;

    for(int j=l;j<v.size();j++){
        if(v[j]==0){
            ceros++;
        }
        else if(v[j]==1){
            unos++;
        }
        if(v[j-l]==0){
            ceros--;
        }
        else if(v[j-l]==1){
            unos--;
        }
        if(ceros==unos)cant++;
    }
    return cant;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int l,n;
    cin>>l>>n;
    vector<int> v(n);
    for(auto&i:v)cin>>i;

    
    int sol = resolver(v,l);
    // escribir sol
    cout<<sol<<"\n";
    
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