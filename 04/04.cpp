#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>  

using namespace std;

// variables y funciones

void capturarNumero();
int fibonacci();
void imprimirFibonacci();
void continuar();
void clearConsole();

void clearConsole() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls"); // Comando para limpiar consola en Windows
    #else
        system("clear"); // Comando para limpiar consola en Unix/Linux/Mac
    #endif
}

void continuar(){
    string continuar = "";

    cout << "¿Desea continuar generando secuencias ? (SI/NO) " << endl;
    cin >> continuar;

   
    transform(continuar.begin(), continuar.end(), continuar.begin(), :: tolower);

    if (continuar == "si") {
        clearConsole();
        capturarNumero();
    } else {
        return;
    }
}

int fibonacci(int numero){

   if(numero == 0){
    return 0;
   } else if(numero == 1){
    return 1;
   } else {
        return(fibonacci(numero -1) + fibonacci(numero -2));
   }

}

void imprimirFibonacci(int numero){

    for(int i = 0; i <= numero; i ++){
        cout << fibonacci(i) << " ";
    }

    cout << endl;

    continuar();
}



void capturarNumero(){
    int numero = 0;

    cout << "Ingrese el numero del cual quiere obtener la secuencia de Fibonacci" << endl;
    cin >> numero;

    if(numero < 0){
        cout << "El numero no puede ser menor de 0. Intente de nuevo" << endl;
        capturarNumero();
    } else {
        imprimirFibonacci(numero);
    }
}


int main() {

    capturarNumero();

    return 0;
}