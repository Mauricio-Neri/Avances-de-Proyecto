#include <iostream> // Bibliotecas necesarias para ejecutar el programa. NO ELIMINAR
#include <string>
#include <fstream>

using namespace std;

struct Tienda
{
    int nart;
    string art;
    string des;
    string gen;
    string clas;
    string con;
    float prec;
    float tprec;
    char status;
}; // Uso de estructuras para guardar datos y usarlos en todas las funciones

Tienda* Videojuegos; // Punteros
int contador = 0;

void Articulos(); // Para dar de alta los articulos de la tienda, en este caso videojuegos
void Modificacion(); // Para modificar articulos ya dados de alta
void Baja(); // Para eliminar articulos
void Lista(); // Para mostrar la lista de los articulos
void Archivo(); // Para crear un archivo donde se muestre la lista, una vez hecho se cierra el programa

int main()
{
    int opcion;
    Videojuegos = new Tienda[100];

    do // Do While para continuar trabajando con el codigo SIEMPRE Y CUANDO no se presione un numero diferente a los que aparecen en el menu
    {
        cout << "\t ***MENU DE OPCIONES***" << endl; // Menu de opciones para que el usuario pueda escoger que hacer
        cout << "1. Articulos" << endl;
        cout << "2. Modificacion de Articulos" << endl;
        cout << "3. Baja de Articulos" << endl;
        cout << "4. Lista de Articulos" << endl;
        cout << "5. Limpiar Pantalla" << endl; // Limpia la pantalla eliminando todo lo que se mostro. Aclaro que no se eliminan datos guardados y no se cierra el programa, solo limpia pantalla
        cout << "6. Salir" << endl; // Aqui se guarda el archivo, una vez que presione salir se generara un archivo para guardar todos los datos ya puestos en el proyecto
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            Articulos();
            break;
        case 2:
            Modificacion();
            break;

        case 3:
            Baja();
            break;

        case 4:
            Lista();
            break;

        case 5:
            system("cls");
            break;
        case 6:
            Archivo();
            exit(1);
            break;
        }
    } while (opcion != 6);

    delete[] Videojuegos;

    return 0;
}

void Articulos()
{
    cout << "¿Cuántos registros desea dar de alta?" << endl;
    cin >> contador;
    for (int i = 0; i < contador; i++)
    {
        cout << "Ingrese número del item: "; // El item es el articulo o videojuego que se quiera agregar al registro
        cin >> Videojuegos[i].nart;

        cin.ignore();

        cout << "Ingrese nombre del item: ";
        getline(cin, Videojuegos[i].art);

        cout << "Ingrese descripción del item: ";
        getline(cin, Videojuegos[i].des);

        cout << "Ingrese genero del item: "; // El genero se define en cuanto a lo que se trata el juego. En caso de tener mas de un genero, solo precione la tecla de SPACE y agregue el otro genero, preferiblemente la primera letra en Mayuscula para distinguirla
        getline(cin, Videojuegos[i].gen);

        cout << "Ingrese clasificacion del item: "; // La clasificacion de un videojuego esta definido con una letra y en ocaciones una letra y un numero, pero segun las nuevas regulaciones en Mexico solo se usaran A, B, B15, C, D
        getline(cin, Videojuegos[i].clas);

        cout << "Ingrese consola del item: ";
        getline(cin, Videojuegos[i].con);

        cout << "Ingrese precio del item sin el IVA incluido: "; // El precio con IVA lo generara el codigo
        cin >> Videojuegos[i].prec;
    }
}

void Lista()
{
    for (int i = 0; i < contador; i++)
    {
        if (Videojuegos[i].status == 'E') // En caso de que el articulo sea eliminado solo se mostrara que esta eliminado
        {
            cout << "Articulo: " << i + 1 << endl;
            cout << "Eliminado" << endl;
        }
        else
        {
            cout << "Articulo: " << i + 1 << endl; // Numero de articulo asignado por el codigo. Este no reemplaza el numero ingresado del item, solo se usa como numeracion para encontrarlo y eliminarlo o modificarlo segun lo que quiera el usuario
            Videojuegos[i].tprec = Videojuegos[i].prec * 1.16; // Precio con el IVA incluido ya se hace aparte
            cout << "Numero del Item: " << Videojuegos[i].nart << endl;
            cout << "Nombre del Item: " << Videojuegos[i].art << endl;
            cout << "Descripcion del Item: " << Videojuegos[i].des << endl;
            cout << "Genero del Item: " << Videojuegos[i].gen << endl;
            cout << "Clasificacion del Item: " << Videojuegos[i].clas << endl;
            cout << "Consola del Item: " << Videojuegos[i].con << endl;
            cout << "Precio del Item sin IVA: " << Videojuegos[i].prec << endl;
            cout << "Precio del Item con IVA: " << Videojuegos[i].tprec << endl;
        }
    }
}

void Modificacion()
{
    int num, j;
    bool encontrado = false; // Variable condicional para que no se ejecute en caso de ser falso
    cout << "Ingrese el número del artículo que desea modificar: ";
    cin >> num; // Recuerde checar Lista para saber que numero de articulo es, y ese numero es el asignado por el codigo
    for (int i = 0; i < contador; i++)
    {
        if (Videojuegos[i].nart == num && Videojuegos[i].status != 'E')
        {
            encontrado = true;
            cout << "Número de Articulo: " << Videojuegos[i].nart << endl; // Se muestran los datos puestos en el articulo para que el usuario pueda modificar solo lo que se quiere modificar, en caso de querer dejarlo igual solo se debe de reescribir en el apartado que se desea dejar igual
            cout << "Nombre del Articulo: " << Videojuegos[i].art << endl;
            cout << "Descripción del Articulo: " << Videojuegos[i].des << endl;
            cout << "Genero del Articulo: " << Videojuegos[i].gen << endl;
            cout << "Clasificacion del Articulo: " << Videojuegos[i].clas << endl;
            cout << "Consola del Articulo: " << Videojuegos[i].con << endl;
            cout << "Precio del Articulo sin IVA: " << Videojuegos[i].prec << endl;
            cout << "Precio del Articulo con IVA: " << Videojuegos[i].tprec << endl;

            cout << "\nIngrese los nuevos datos: " << endl;
            cout << "Ingrese nuevo número del item: ";
            cin >> Videojuegos[i].nart;

            cin.ignore();

            cout << "Ingrese nuevo nombre del item: "; // En caso de no querer modificar se reescriben los datos que pusiste. En caso de modificarse se elimina la informacion anterior y es reemplazada por la nueva
            getline(cin, Videojuegos[i].art);

            cout << "Ingrese nueva descripción del item: ";
            getline(cin, Videojuegos[i].des);

            cout << "Ingrese nuevo genero del item: ";
            getline(cin, Videojuegos[i].gen);

            cout << "Ingrese nueva clasificacion del item: ";
            getline(cin, Videojuegos[i].clas);

            cout << "Ingrese nueva consola del item: ";
            getline(cin, Videojuegos[i].con);

            cout << "Ingrese nuevo precio del item sin el IVA incluido: ";
            cin >> Videojuegos[i].prec;

            cout << "Artículo modificado con éxito." << endl;
            break;
        }
    }
    if (!encontrado) // En caso de no encontrar el articulo se recomienda
    {
        cout << "Artículo no encontrado." << endl;
    }
}

void Baja()
{
    int num;
    bool encontrado = false;
    cout << "Ingrese el número del artículo que desea dar de baja: ";
    cin >> num;
    for (int i = 0; i < contador; i++)
    {
        if (Videojuegos[i].nart == num && Videojuegos[i].status != 'E')
        {
            encontrado = true;
            Videojuegos[i].status = 'E';
            cout << "Artículo dado de baja con éxito." << endl; // Una vez dado de baja el articulo no se puede recuperar. En caso de no querer eliminar el articulo solo escriba un numero que no tenga un articulo asignado. RECOMENDACION: Checar la lista los numeros de los articulos
            break;
        }
    }
    if (!encontrado)
    {
        cout << "Artículo no encontrado." << endl;
    }
}

void Archivo()
{
    ofstream archivo;
    string nombreArchivo = "articulostienda.txt";

    archivo.open(nombreArchivo.c_str(), ios::out | ios::binary);

    if (!archivo) // En caso de que el archivo no se abra
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    archivo.write(reinterpret_cast<const char*>(Videojuegos), sizeof(Tienda) * contador);
    archivo.close();

    cout << "Datos guardados en el archivo correctamente." << endl;
}
