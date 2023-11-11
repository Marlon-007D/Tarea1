#ifndef PROCESOS_H_INCLUDED
#define PROCESOS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
void burbuja(int n, string arreglonombres[]) {
    int i, j;
    string aux;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (arreglonombres[j] > arreglonombres[j + 1]) {
                aux = arreglonombres[j];
                arreglonombres[j] = arreglonombres[j + 1];
                arreglonombres[j + 1] = aux;
            }
        }
    }
}
void encabezado(){
    int i;
    int n=8;
string cabeza[n];

    cabeza[0]="            Docente: Ing. Christian Camacho";
    cabeza[1]="            Proyecto Final";
    cabeza[2]="            Unidad 1";
    cabeza[3]="            Estudiante: Marlon Demera";
    cabeza[4]="            Universidad de las fuerzas Armadas ESPE SS";
    cabeza[5]="            Primer nivel";
    cabeza[6]="            Paralelo: A";
    cabeza[7]="            Carrera: Tecnologias de la informacion";
    //Ordanamiento por el metodo de burbuja
    burbuja(n,cabeza);
    cout<<"*****************************************************************************************************************"<<endl;
    for(i=0;i<n;i++){
        cout<<cabeza[i]<<endl;
    }
}
void dibujarAhorcado(int intentos) {
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;

    switch (intentos) {
        case 0:
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
        case 1:
            cout << "  O   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
        case 2:
            cout << "  O   |" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
        case 3:
            cout << "  O   |" << endl;
            cout << " /|   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
        case 4:
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
        case 5:
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " /    |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
        case 6:
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
    }

    cout << "      |" << endl;
    cout << "=========" << endl;
}
bool juegoCompletado(const vector<bool>& letrasEncontradas) {
    for (bool encontrada : letrasEncontradas) {
        if (!encontrada) {
            return false;
        }
    }
    return true;
}

// Función para imprimir el estado actual de la palabra
void dibujarPalabra(const vector<bool>& letrasEncontradas, const string& palabraSecreta) {
    cout << "Palabra: ";
    for (size_t i = 0; i < palabraSecreta.length(); ++i) {
        if (letrasEncontradas[i]) {
            cout << palabraSecreta[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}
void juego(){
    const int INTENTOS = 6;
    int eleccion;
    //int opcion;
     const vector<string> palabras = {
      "lluvia", "acida", "emisiones", "contaminacion", "azufre",
        "ambiente", "precursores", "atmosfera", "ecosistema", "degradacion"};
    const vector<string> preguntas = {
        "Fenomeno meteorologico que transporta particulas y gases contaminantes a la superficie terrestre. (Pista: Relacionado con el clima)",
        "Termino que describe la naturaleza acida de la lluvia debido a su pH bajo. (Pista: Sustancia quimica)",
        "Liberaciones de sustancias nocivas a la atmosfera provenientes de fabricas y vehiculos. (Pista: Contribuye a la polucion)",
        "Presencia de componentes daninos en el aire, agua y suelo debido a actividades humanas. (Pista: Causa danio al entorno)",
        "Elemento quimico liberado en forma de dioxido que contribuye a la lluvia acida. (Pista: Amarillo y olor a huevo podrido)",
        "Entorno en el que viven los seres vivos y que puede ser afectado por la lluvia acida. (Pista: Incluye plantas y animales)",
        "Sustancias quimicas que son transformadas en la atmosfera en precursores de la lluvia acida. (Pista: Antes de la lluvia)",
        "Capa gaseosa que rodea la Tierra y en la que ocurren los procesos de la lluvia acida. (Pista: Donde respiramos)",
        "Sistema natural compuesto por seres vivos y su entorno, vulnerable a la lluvia acida. (Pista: Conjunto de organismos)",
        "Proceso de deterioro de la calidad del aire, el agua y el suelo debido a la lluvia acida. (Pista: Causa descomposicion)"
    };
    system("Color 0b");
    //system("Color 0a");
    bool opcion = true;
    while(opcion){
    srand(static_cast<unsigned int>(time(0)));
    int indicePalabra = rand() % palabras.size();
    string palabraSecreta = palabras[indicePalabra];
    string pregunta = preguntas[indicePalabra];
        vector<bool> letrasEncontradas(palabraSecreta.length(), false);
        int intentos = 0;
        cout << "Bienvenido al juego del ahorcado" << endl;
        cout << pregunta << endl;
        while (intentos < INTENTOS) {
            dibujarAhorcado(intentos);
            dibujarPalabra(letrasEncontradas, palabraSecreta);
            char letra;
            cout << "Introduce una letra: ";
            fflush(stdin);
            cin >> letra;
            cout << endl;
            bool letraEncontrada = false;
            for (size_t i = 0; i < palabraSecreta.length(); ++i) {
                if (palabraSecreta[i] == letra) {
                    letrasEncontradas[i] = true;
                    letraEncontrada = true;
                }
            }
            if (!letraEncontrada) {
                cout << "¡Letra incorrecta!" << endl;
                intentos++;
            } else {
                cout << "¡Letra correcta!" << endl;
            }
            cout << endl;
            if (juegoCompletado(letrasEncontradas)) {
                dibujarAhorcado(intentos);
                dibujarPalabra(letrasEncontradas, palabraSecreta);
                cout << "¡Felicidades! ¡Has adivinado la palabra correctamente!" << endl;
                break;
            }
        }
        if (intentos >= INTENTOS) {
            dibujarAhorcado(intentos);
            cout << "¡Oh no! ¡Has perdido! La palabra secreta era: " << palabraSecreta << endl;
        }
        cin.ignore();
        cout<<"*************************************************************"<<endl;
        cout << "¿Quieres jugar de nuevo? (1 para si, 0 para no): "<<endl;
        cout<<"*************************************************************"<<endl;
        cin >> eleccion;
        while (eleccion != 1 && eleccion != 0) {
            cout << "Error. Por favor, elige 1 para jugar de nuevo o 0 para salir: ";
            cin >> eleccion;
        }
        opcion=(eleccion == 1);
    }
}



#endif // PROCESOS_H_INCLUDED
