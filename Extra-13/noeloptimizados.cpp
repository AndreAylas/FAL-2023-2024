// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;
using tMatriz=vector<vector<int>>;
struct tDatos{
  int m;//juguetes
  int n;//numero de niños
  tMatriz satisfaccion; 

};

bool esSolucion(int k,int n){
    return k==n-1;
}

// función que resuelve el problema
void resolver(const tDatos &d,int k,vector<bool>&marcaje,const vector<int>&acumulado,vector<int> &sol,int &satisActual,int &satisMejor) {
    for(int i=0;i<d.m;i++){
        sol[k]=i;
        if(!marcaje[i]){
            //marcaje
            satisActual+=d.satisfaccion[k][i];
            marcaje[i]=true;
            if(esSolucion(k,d.n)){
                satisMejor=max(satisMejor,satisActual);
            }else{
                //optimizacion
                if(satisActual+acumulado[k+1]>satisMejor){
                    resolver(d,k+1,marcaje,acumulado,sol,satisActual,satisMejor);
                }
            }
            //desmarcaje
              satisActual-=d.satisfaccion[k][i];
            marcaje[i]=false;
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    tDatos d;
    cin>>d.m;    
    if (! std::cin)
        return false;
    cin>>d.n;
    d.satisfaccion.assign(d.n,vector<int>(d.m));
    for(int i=0;i<d.n;i++){
        for(int j=0;j<d.m;j++){
            cin>>d.satisfaccion[i][j];
        }
    }

    //vector de acumulados de satisfaccion;
    vector<int> acum;
    int aux=0;
    for(int i=0;i<d.n;i++){
        for(int j=0;j<d.m;j++){
            aux=max(aux,d.satisfaccion[i][j]);
        }
        acum.push_back(aux);
    }

    //acumular el vector
    for(int j=d.n-1;j>0;j--){
        acum[j-1]+=acum[j];
    }

    vector<bool> marcaje(d.m,false);
    int satisMejor=0;
    int satisActual=0;
    vector<int> sol(d.n);
    resolver(d,0,marcaje,acum,sol,satisActual,satisMejor);
    
    // escribir sol
    cout<<satisMejor<<"\n";
    
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