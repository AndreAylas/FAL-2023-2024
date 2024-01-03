// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

//ESPECIFICA la funcion que resuelve el problema
//CORRECTO
//noMas(v,i,j,l)= l>=(#k: i<=k<j:v[k]%2!=0)
//Precondicion:
//{true}
//para todo z: 0<=z<k:v[z]%2=0 and para todo m: 0<=m<v.size():v[m]>=0 and k,l>=0 y k<=v.size()
//func contar(vector<int>v,intk,int l) return (r:int)

//post condicion;
//r=#i:0<=i<=n-k:noMas(v,i,i+k,l)

//invariante
//r=#i:0<=i<=j-k:noMas(v,i,i+k,l)
//j=k,r=1,imp=0
//imp=#z:j-k<=z<j:v[z]%2=1
//cota:v.size()-j


// función que resuelve el problema
int resolver(std::vector<int> const& v, int k, int l) {
	int contarsegm;
	int contarimp = 0;
	if (k == 0) {
		return v.size() + 1;
	}
	else {
		
		// longitud deseada
		
		//cuento el primer segmento
		contarsegm = 1;
		int i = k;
		while ( i < v.size() ) {
			if (v[i -k] % 2 != 0) {
				contarimp--;
			}
			if (v[i] % 2 != 0) { contarimp++; }
			if (contarimp <= l) {
				contarsegm ++;
			}
			i++;
		}
	}

	return contarsegm;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int numElems = 0; int k, l;
	cin >> numElems >> k >> l;
	vector<int> v(numElems);
	for (int& i : v) std::cin >> i;
	int sol = resolver(v, k, l);
	cout << sol << "\n";
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
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