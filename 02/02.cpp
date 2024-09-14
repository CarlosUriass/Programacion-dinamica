#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>  // Libreria para limpiar la consola


using namespace std;

double imc();
void capturarDatos();
string condicion();
void imprimirResultados();
void continuar();
void clearConsole();

void clearConsole() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls"); // Comando para limpiar consola en Windows
    #else
        system("clear"); // Comando para limpiar consola en Unix/Linux/Mac
    #endif
}

double imc(double peso, double altura){
    double indiceMasaCorporal = 0;

    indiceMasaCorporal = peso / (altura * altura);

    return indiceMasaCorporal;


}

string condicion(double imc){

    string condicion = "";

    if(imc < 18.5){
        condicion = "Bajo peso";
    } else if(imc >= 18.5 && imc < 25){
        condicion = "Saludable";
    } else if(imc >= 25 && imc < 30){
        condicion = "Sobrepeso";
    } else if(imc >= 30 && imc < 35){
        condicion = "Obesidad I";
    } else if(imc >=35 && imc < 40){
        condicion = "Obesidad II";
    } else if(imc >= 40){
        condicion = "Obesidad III";
    }

    return condicion;

}

void imprimirResultados(string nombre, string condicion, double imc){

    cout << nombre << " tiene un indice de masa corporal: " << imc << " su condición es: " << condicion << endl; 

    continuar();

}


void capturarDatos(){
    double altura = 0;
    double peso = 0;
    string nombre = "";

    cout << "Ingrese su nombre: " << endl;
    cin.ignore(); // ignora entradas residuales
    getline(cin, nombre); // captura espacios

    cout << "Ingrese su peso: " << endl;
    cin >> peso;

    cout << "Ingrese su altura: " << endl;
    cin >> altura;

    double indiceMasaCorpotal = imc(peso, altura);
    string condicionImc = condicion(indiceMasaCorpotal);

    imprimirResultados(nombre, condicionImc, indiceMasaCorpotal);

}


void continuar(){
    string continuar = "";

    cout << "¿Desea calcular otro indice de masa corporal? (SI/NO)" << endl;
    cin >> continuar;

   
    transform(continuar.begin(), continuar.end(), continuar.begin(), :: tolower);

    if (continuar == "si") {
        clearConsole();
        capturarDatos();
    } else {
        return;
    }
}




int main() {

    capturarDatos();

    return 0;
}