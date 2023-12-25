#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

struct tCristal {
    int nivel = 0;  // Nivel de grupo
    int totalAttack = 0;  // Total de ataque en grupo
    vector<int> gHeroes;  // Héroes en el grupo
};

struct tHeroes {
    vector<int> clase;
    vector<int> nivel;
    vector<int> attack;
    tHeroes(int H) : clase(H), nivel(H), attack(H) {}
};

const int MAXIMO = numeric_limits<int>::max();
int Max_Cristal;

bool esSolucion(const int k, const int H) {
    return k == H;
}

int IAttack(const int suma, const int numero) {
    double factor = static_cast<double>(numero) / Max_Cristal;
    return suma + round(factor * suma);
}

bool compatible(const int k, const tCristal& grupo, const int M, const vector<int>& cl, const vector<int>& nv) {
    // Si el cristal no brinda sus poderes a todos los héroes
    if (grupo.gHeroes.size() == Max_Cristal) return false;
    // No nos pasamos del nivel que acepta el cristal
    if (grupo.nivel + nv[k] > M) return false;
    // No hay más de 2 héroes de la misma clase
    bool ok = true;
    int i = 0, cont = 1;
    while (ok && i < grupo.gHeroes.size()) {
        if (cl[grupo.gHeroes[i]] == cl[k]) {  // Si son de la misma clase
            ++cont;
        }
        ok = cont <= 2;
        ++i;
    }
    return ok;
}

int poda(const int usados, const int k, const int H, const int huecos) {
    double factor = static_cast<double>(H - 1 - k - huecos) / Max_Cristal;
    return usados + max(0, static_cast<int>(ceil(factor)));  // Puede ser negativo
}

void dragon(int k, vector<int>& sol, int& minCristales, const int H, const int N, const int M, const int PV,
            const tHeroes& h, vector<tCristal>& grupos, int& cristales, int& ataque, int& huecos) {
    // Probamos a asignar al héroe a un cristal ya usado
    for (int i = 0; i < cristales; i++) {
        if (compatible(k, grupos[i], M, h.clase, h.nivel)) {
            sol[k] = i;
            int puntosAnt = IAttack(grupos[i].totalAttack, grupos[i].gHeroes.size());
            // Marcación
            grupos[i].nivel += h.nivel[k];
            grupos[i].totalAttack += h.attack[k];
            grupos[i].gHeroes.push_back(k);
            --huecos;
            // Actualizando el ataque
            int NowPuntos = IAttack(grupos[i].totalAttack, grupos[i].gHeroes.size());
            ataque += NowPuntos - puntosAnt;
            if (esSolucion(k, H - 1)) {
                if (ataque >= PV) {
                    minCristales = min(minCristales, cristales);
                }
            } else {
                // Quedan héroes para formar una party
                if (poda(cristales, k, H, huecos) < minCristales) {
                    dragon(k + 1, sol, minCristales, H, N, M, PV, h, grupos, cristales, ataque, huecos);
                }
            }
            // Desmarcamos
            grupos[i].gHeroes.pop_back();
            grupos[i].totalAttack -= h.attack[k];
            grupos[i].nivel -= h.nivel[k];
            ++huecos;
            ataque += -NowPuntos + puntosAnt;
        }
    }
    // Usando un nuevo cristal
    if (cristales < N) {
        sol[k] = cristales;
        grupos[cristales].gHeroes.push_back(k);  // Añadimos a un héroe
        grupos[cristales].nivel += h.nivel[k];
        grupos[cristales].totalAttack += h.attack[k];
        int NowPuntos = IAttack(grupos[cristales].totalAttack, grupos[cristales].gHeroes.size());
        // Marcamos
        ++cristales;
        ataque += NowPuntos;
        huecos += Max_Cristal - 1;
        if (esSolucion(k, H - 1)) {
            if (ataque >= PV) {
                minCristales = min(minCristales, cristales);
            }
        } else {  // Quedan héroes para formar una party
            if (poda(cristales, k, H, huecos) < minCristales) {
                dragon(k + 1, sol, minCristales, H, N, M, PV, h, grupos, cristales, ataque, huecos);
            }
        }
        // Desmarcar
        --cristales;
        grupos[cristales].gHeroes.pop_back();
        grupos[cristales].nivel -= h.nivel[k];
        grupos[cristales].totalAttack -= h.attack[k];
        ataque -= NowPuntos;
        huecos -= Max_Cristal - 1;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Leer los datos de la entrada
    int H, N, M, PV;
    cin >> H >> N >> M >> PV;
    tHeroes h(H);
    for (auto& i : h.clase) cin >> i;
    for (auto& i : h.nivel) cin >> i;
    for (auto& i : h.attack) cin >> i;
    Max_Cristal = N;
    vector<int> sol(H);
    int minimoCristal = N;
    int cristal = 0;
    vector<tCristal> grupos(N);

    int huecos = N;  // Inicializar huecos

    int ataque = 0;
    dragon(0, sol, minimoCristal, H, N, M, PV, h, grupos, cristal, ataque, huecos);

    // Escribir solución
    if (minimoCristal == N) {
        cout << "DERROTA\n";
    } else {
        cout << minimoCristal << '\n';
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