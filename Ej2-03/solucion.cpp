// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

using namespace std;

struct tSol{
    int ini;
    int fin;
    int gananciaMax;
   // bool esBeneficioso;
};
/*
N=lista de la entrada
S=beneficio esperado

P=(0<=N<=10^8 and 0<=S and forall i:0<=i<N:v[i]!=vacio)

funcion resolver(v[],N,S) dev {ini:int,fin:int,ganaciaMax:int}

suma(v,i,j)=sum k:i<=k<j:v[k]

Q=(ganancia>=0 <=> ganancia=max i,j:0<=i<=j<N and suma(v,i,j+1)>=S:suma(v,i,j+1) 
                                    &&
    ganancia=-1 <=> ganancia=max i,j:0<=i<=j<N and suma(v,i,j+1)<>=>S:suma(v,i,j+1) )



*/
// función que resuelve el problema
tSol resolver(const vector<int>&v,int s) {
    tSol sol={0,0,0};
    int acum=0,i=0,idx,fin;
    idx=fin=i;
    //cota:N-fin
    for(;i<v.size();i++){
        acum+=v[i];
        if(acum>=0){
            fin=i;
            if(acum>=s && sol.gananciaMax<acum){
                sol={idx,fin,acum};
            }
        }
        else{
            if((acum-v[i])>=s && sol.gananciaMax<(acum-v[i])){
                sol={idx,fin,acum-v[i]};
            }
            acum=0;
            idx=i+1;
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N,S;
    cin>>N>>S;
    vector<int>ruleta(N);
    for(auto&i:ruleta)cin>>i;
    
    tSol sol = resolver(ruleta,S);
    // escribir sol
    if(sol.gananciaMax==0){
        cout<<"NO COMPENSA\n";
    }else{
        cout<<sol.gananciaMax<<" "<<sol.ini<<" "<<sol.fin<<"\n";
    }
    
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