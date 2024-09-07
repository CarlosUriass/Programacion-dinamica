#include <iostream>
#include <string>
#include <algorithm> // Libreria para transformar en mayusculas y/o minusculas
#include <cstdlib>  // Libreria para limpiar la consola

using namespace std;


// Variables globales
void clearConsole();
void menu();
void continuarMenu();
void parImpar();
void diaSemana();
void numeroMes();
void positivoNegativo();
void esVocal();
void sumaTresNumeros();

void clearConsole() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls"); // Comando para limpiar consola en Windows
    #else
        system("clear"); // Comando para limpiar consola en Unix/Linux/Mac
    #endif
}

void continuarMenu(int programa) {
    string continuar = "";

    cout << "¿Regresar al menú? (SI/NO)" << endl;
    cin >> continuar;
    
    transform(continuar.begin(), continuar.end(), continuar.begin(), ::tolower);

    if (continuar == "si") {
        clearConsole();
        menu(); 
    } else if (continuar == "no") {
        switch (programa) {
        case 1:
            parImpar();  
            break;
        case 2:
            diaSemana(); 
            break;
        case 3:
            numeroMes();
            break;
        case 4:
            positivoNegativo();
            break;
        case 5:
            esVocal();
            break;
        case 6:
            sumaTresNumeros();
        }
    } else {
        cout << "Ingrese una opción válida" << endl;
        menu();
    }
}


void menu() {

    int opcion = 0;

    cout << "*** MENÚ ***" << endl;
    cout << "1. Par o impar" << endl;
    cout << "2. Día de la semana" << endl;
    cout << "3. Número de mes" << endl;
    cout << "4. Positivo o negativo" << endl;
    cout << "5. Es Vocal" << endl;
    cout << "6. n1 + n2 = n3" << endl;
    cout << "7. Salir" << endl;

    cout << "Ingrese su opción: ";
    cin >> opcion;

    switch (opcion) {
            case 1:
                parImpar();
                break;
            case 2:
                diaSemana();
                break;
            case 3:
                numeroMes();
                break;
            case 4:
                positivoNegativo();
                break;
            case 5:
                esVocal();
                break;
            case 6:
                sumaTresNumeros();
                break;
            default:
                break;
    }

}


void parImpar(){

    int programa = 1;
    string resultado = "";
    int numero = 0;
    string continuarStr;
    cout << "Ingrese el numero a verificar si es par o impar: ";
    cin >> numero;

    if(numero % 2 == 0){
        resultado = "El numero es par";
    } else {
        resultado = "El numero es impar";
    }

    cout << resultado << endl;

    continuarMenu(programa);

    
    
}

void diaSemana(){
    // declarar variables
    int programa = 2;
    int dia = 0;
    string nombreDia = "";
    string continuar = "";


    cout << "Ingrese numero de la semana: " << endl;
    cin >> dia;

    switch (dia)
    {
    case 1:
        nombreDia = "Lunes"; // segun el estándar ISO 8601
        break;
    case 2:
        nombreDia = "Martes";
        break;
    case 3:
        nombreDia = "Miercoles";
        break;
    case 4:
        nombreDia = "Jueves";
        break;
    case 5:
        nombreDia = "Viernes";
        break;
    case 6:
         nombreDia = "Sabado";
         break;
    case 7:
        nombreDia = "Domingo";
        break;
    default:

        cout << "El numero no es valido";

        cout << "¿Intentar de nuevo? (SI/NO)" << endl;
        cin >> continuar;
        
        transform(continuar.begin(), continuar.end(), continuar.begin(), :: tolower);

        if (continuar == "si") {
            diaSemana();
        } else{
            return;
        }

        break;
    }

    cout << nombreDia << endl;

    continuarMenu(programa);


}

void numeroMes() {
    int programa = 3;
    int numMes = 0;
    string mes = "";
    string continuar = "";

    cout << "Ingrese el numero de mes: " << endl;
    cin >> numMes;

    switch (numMes) {
        case 1:
            mes = "Enero";
            break;
        case 2:
            mes = "Febrero";
            break;
        case 3:
            mes = "Marzo";
            break;
        case 4:
            mes = "Abril";
            break;
        case 5:
            mes = "Mayo";
            break;
        case 6:
            mes = "Junio";
            break;
        case 7:
            mes = "Julio";
            break;
        case 8:
            mes = "Agosto";
            break;
        case 9:
            mes = "Septiembre";
            break;
        case 10:
            mes = "Octubre";
            break;
        case 11:
            mes = "Noviembre";
            break;
        case 12:
            mes = "Diciembre";
            break;
        default:
            cout << "Numero de mes invalido." << endl;

            cout << "¿Intentar de nuevo? (SI/NO)" << endl;
            cin >> continuar;
            transform(continuar.begin(), continuar.end(), continuar.begin(), :: tolower);

            if (continuar == "si") {
                numeroMes();
            } else{
                continuarMenu(programa);
            }

    }

    cout << "El numero de mes: " << numMes << " corresponde al mes de " << mes << endl; 

    continuarMenu(programa);

} 

void positivoNegativo(){
    int numero = 0;
    int programa = 4;

    cout << "Ingrese el numero para validar si es poisitivo o negativo: " << endl;
    cin >> numero;

    if(numero == 0){
        cout << "El cero es un elemento neutro " << endl;
    } else if(numero > 0) {
        cout << "El numero es positivo" << endl;
    } else {
        cout << "El numero es negativo" << endl;
    }

    continuarMenu(programa);
}

void esVocal(){
    int programa = 5;
    string letra = "";
    string continuar = "";

    cout << "Ingrese una letra para validar si es vocal: " << endl;
    cin >> letra;

    if(letra.length() != 1){
        cout << "Solo se permite una letra" << endl;
        cout << "¿Intentar de nuevo? (SI/NO)" << endl;
        cin >> continuar;
        transform(continuar.begin(), continuar.end(), continuar.begin(), :: tolower);

            if (continuar == "si") {
                esVocal();
            } else{
                continuarMenu(programa);
            }
    } else {
        transform(letra.begin(), letra.end(), letra.begin(), :: tolower);

        if (letra == "a" || letra == "e" || letra == "i" || letra == "o" || letra == "u")
        {
            cout << "La letra ingresada es vocal" << endl;
        } else {
            cout << "La letra ingresada no es vocal" << endl;
        }
    }

    continuarMenu(programa);
}


void sumaTresNumeros(){
    int programa = 6;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;

    cout << "Ingrese el resultado esperado de la suma de dos numeros: " << endl;
    cin >> n3;

    cout << "Ingrese el primer numero: " << endl;
    cin >> n1;

    cout << "Ingrese el segundo numero: " << endl;
    cin >> n2;

    if ((n1 + n2) != n3 )
    {
        cout << "La suma de " << n1 << " + " << n2 << " no es igual a " << n3 << endl;
    } else {
        cout << "La suma de " << n1 << " + " << n2 << " es igual a " << n3 << endl;
    }
    
    continuarMenu(programa);
}

int main() {

    menu();

    return 0;
}