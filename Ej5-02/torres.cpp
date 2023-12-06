// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

using matriz=vector<vector<bool>>;
using marcador=vector<bool>;

int diag_asc(int f,int c,int n){
    return c+f+2*n-1;
}
int diag_desc(int f,int c,int n){
    return c-f+n-1;
}

bool casilla_valida(matriz const & invalidas,int f, int c,int n, marcador const&filas,marcador const& diag_reinas){
    return !invalidas[f][c] && !filas[f] && !diag_reinas[diag_asc(f,c,n)] && !diag_reinas[diag_desc(f,c,n)];
}

bool esSolucion(int k,int n){
    return k==n-1;
}

bool esCompletable(int k,int n){
    return k<n-1;
}

bool HayTorresDiag(int k,int n,vector<int> & sol,marcador const&diag_torres){
    return diag_torres[diag_asc(sol[k],k,n)] || diag_torres[diag_desc(sol[k],k,n)];
}

void marcar_desmarcar(bool marca_f,bool marca_d_asc, bool marca_d_desc,marcador &filas,marcador&diagonales,int fila,int col,int n){
    filas[fila]=marca_f;
    diagonales[diag_asc(fila,col,n)]=marca_d_asc;
    diagonales[diag_desc(fila,col,n)]=marca_d_desc;
}

void torres_reinas(int&torres,int &reinas,int n,matriz const& invalidas,int k,vector<int>&sol,int &cuantas_sol,marcador&filas,marcador&diag_torres,marcador & diag_reinas){
    for(int i=0;i<n;i++){
        if(casilla_valida(invalidas,i,k,n,filas,diag_reinas)){
            sol[k]=i;//colocamos la figura en la pos [i,k]
            //colocamos torres:
            if(torres>0){
                --torres;
                if(esSolucion(k,n)){
                    ++cuantas_sol;
                }
                else if(esCompletable(k,n)){
                    //guardamos marcadores anteriores por si ya habia una torre en la diagonal
                    bool anterior_asc=diag_torres[diag_asc(i,k,n)], anterior_desc=diag_torres[diag_desc(i,k,n)];
                    marcar_desmarcar(true,true,true,filas,diag_torres,i,k,n);
                    torres_reinas(torres,reinas,n,invalidas,k+1,sol,cuantas_sol,filas,diag_torres,diag_reinas);
                    marcar_desmarcar(false,anterior_asc,anterior_desc,filas,diag_torres,i,k,n);
                }
                ++torres;
            }
            //colocamos reinas:
            if(reinas>0){
                --reinas;
                if(esSolucion(k,n) && !HayTorresDiag(k,n,sol,diag_torres)){
                    ++cuantas_sol;
                }
                else if(esCompletable(k,n)&&  !HayTorresDiag(k,n,sol,diag_torres)){
                    marcar_desmarcar(true,true,true,filas,diag_torres,i,k,n);
                    torres_reinas(torres,reinas,n,invalidas,k+1,sol,cuantas_sol,filas,diag_torres,diag_reinas);
                    marcar_desmarcar(false,false,false,filas,diag_torres,i,k,n);
                }
                ++reinas;
            }
        }
    }
}

int resolver(int T,int R,int N, matriz const & invalidas){
    int torres=T,reinas=R;
    int k=0;
    vector<int> sol(N);
    int cuantas_sol=0;
    if(N>0){
        marcador filas(N,false);
        marcador diag_torres(4*N-2,false);
        marcador diag_reinas(4*N-2,false);
        torres_reinas(torres,reinas,N,invalidas,k,sol,cuantas_sol,filas,diag_torres,diag_reinas);
    }
    return cuantas_sol;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int T;
    cin>>T;
    if (! std::cin)
        return false;
    int R,I;
    cin>>R;
    int N=T+R;
    cin>>I;
    matriz invalidas(N,vector<bool>(N,false));
    int fila,col;
    for(int i=0;i<I;++i){
        cin>>fila;
        cin>>col;
        invalidas[fila-1][col-1]=true;
    }
    int sol=resolver(T,R,N,invalidas);
    cout<<sol<<"\n";
    
    
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