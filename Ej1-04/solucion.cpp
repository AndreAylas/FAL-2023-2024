// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;
/*
n=v.size()
0<n<50000
 P={(forall u: 0<=i<n:v[u]>0 and v[u]<10^6) and (forall i:0<=p<n-1:v[p]!=v[p+1]) }

 func resolver(v[],n) dev int r

 Q={contar=#i,j:0<=i<j<n:v[i]%2!=0 and v[j]%2==0}

 invariante:
  inv={contar=#i,j:0<=i<j<n:v[i]%2!=0 and v[j]%2==0}
  cota=i-n;
  coste O(n) donde n es el tamaño del vector
*/

// función que resuelve el problema
int resolver(const vector<int>& datos) {
    
    int i=0,idx=0;
    bool b=true;
    int contar=0;//numero de impares
    int resul=0;
    while(b && i<datos.size()){
        if(datos[i]%2!=0){
            b=false;
            idx=i;
            contar++;
        }
        i++;
    }
    int suma=datos[idx];
    for(int j=idx+1;j<datos.size();j++){
        if(datos[j]%2==0){
            resul+=contar;
        }else{
            contar++;
        }
    }
    
    return resul;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin>>num;
    vector<int> sol(num);
    for(auto&i:sol)cin>>i;
    int nparejas = resolver(sol);
    // escribir sol
    cout<<nparejas<<"\n";
    
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