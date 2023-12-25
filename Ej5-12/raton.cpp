// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;
using matriz=vector<vector<int>>;

// función que resuelve el problema
//
bool dentroDelRango(const int castigo,const int C){
    return castigo<=C;
}
bool esSolucion(int k,int m){
    return k==m;
}
int poda(const int &recompensa_actual,const int &recompensa_max,int k,int m){
    int esperado=(m-k+1)*recompensa_max;
    return recompensa_actual+esperado;
}
void raton(int k,int n,int m,int C,int&recompensa_max,int&castigo,int&recompensa_actual,int&recompensa_mejor,const matriz& teclas, vector<int>&sol){
    for(int i=0;i<n;i++){
        sol[k]=i;//pisa cualquier tecla de la fila i
        if(k>0){
            if(teclas[sol[k-1]][i]>=0){  
                    recompensa_actual+=teclas[sol[k-1]][i];
            } else{
                castigo-=teclas[sol[k-1]][i];
            }
        }
        if(dentroDelRango(castigo,C)){
            if(esSolucion(k,m-1)){
                if(recompensa_actual>recompensa_mejor){
                    recompensa_mejor=recompensa_actual;
                }
            }
            else{
                if(poda(recompensa_actual,recompensa_max,k,m)>recompensa_mejor)
                raton(k+1,n,m,C,recompensa_max,castigo,recompensa_actual,recompensa_mejor,teclas,sol);
            }
        }
                if(k>0){
            if(teclas[sol[k-1]][i]>=0){  
                    recompensa_actual-=teclas[sol[k-1]][i];
            } else{
                castigo+=teclas[sol[k-1]][i];
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n,m,C;
    cin>>n>>m>>C;
    matriz teclas(n,vector<int>(n));
    int recompensa_max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>teclas[i][j];
            recompensa_max=max(recompensa_max,teclas[i][j]);
        }
    }
    vector<int> sol(m);
    int castigo=0,recompensa_actual=0,recompensa_mejor=-10000000;

    raton(0,n,m,C,recompensa_max,castigo,recompensa_actual,recompensa_mejor,teclas,sol);

    // escribir sol
    if(recompensa_mejor==-10000000)cout<<"NO";
    else cout<<recompensa_mejor;
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