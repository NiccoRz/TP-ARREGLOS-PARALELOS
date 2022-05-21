#include <stdio.h>
#include <stdlib.h>

int main()
{
    int op;
    do{
    system("cls");
    printf("RUIZ NICOLAS - TP ARREGLOS PARALELOS\n\n");
    for(int i=1;i<=5;i++)
    {
        printf("Ejercicio %i\n",i);
    }
    printf("Para salir ingrese 0 (cero)\n");
    printf("\nIngrese una opcion: ");
    scanf("%d",&op);

    switch(op)
    {
    case 1:
        system("cls");
        Ejercicio1();
        printf("\n\n");
        system("PAUSE");
        break;
    case 2:
        system("cls");
        Ejercicio2();
        printf("\n\n");
        system("PAUSE");
        break;
    case 3:
        system("cls");
        Ejercicio3();
        printf("\n\n");
        system("PAUSE");
        break;
    case 4:
        system("cls");
        Ejercicio4();
        printf("\n\n");
        system("PAUSE");
        break;
    case 5:
        system("cls");
        Ejercicio5();
        printf("\n\n");
        system("PAUSE");
        break;
    case 0:
        break;
    default:
        system("cls");
        printf("La opcion ingresada no existe...\n\n");
        system("PAUSE");
        break;
    }
    }while(op!=0);
    return 0;
}

int cargarParalelo(char nombres[][30],int legajos[],int nivel[],int dimension)
{
    char op='s';
    int i=0;

    while(op=='s'&& i<dimension)
    {
        printf("Ingrese nombre(Max. 30 caracteres): ");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese legajo: ");
        scanf("%d",&legajos[i]);

        printf("Ingrese nivel: ");
        scanf("%d",&nivel[i]);

        i++;

        printf("Desea seguir cargando datos? Presione s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    return i;
}

void mostrarParalelo(char nombres[][30],int legajos[],int nivel[],int val)
{
    for(int i=0;i<val;i++)
    {
        printf("\nNombre: %s",nombres[i]);
        printf("\nLegajo: %d",legajos[i]);
        printf("\nNivel: %d",nivel[i]);
        printf("\n----------------------");
    }
}

int retornarPosLegajo(int legajos[],int val,int dato)
{
   int i = 0;
   int pos;
   while(i<val && dato!=legajos[i])
   {
       i++;
   }
   if(dato==legajos[i])
    {
        pos=i;
    }
    else
    {
        pos=-1;
    }
    return pos;
}

void mostrarPorLegajo(char nombres[][30],int legajos[],int nivel[],int val,int dato)
{
    int pos=retornarPosLegajo(legajos,val,dato);
    if(pos!=-1)
    {
    printf("LOS DATOS DEL LEGAJO INGRESADO PERTENECEN A: ");
    printf("\nNombre: %s",nombres[pos]);
    printf("\nLegajo: %d",legajos[pos]);
    printf("\nNivel: %d",nivel[pos]);
    }else
    {
        printf("El legajo ingresado NO SE HALLA cargado en el sistema...\n");
    }
}

void ordenarArregloParaleloSeleccion(char nombres[][30],int legajos[],int nivel[],int val)
{
    int i,j,min,comp,auxL,auxN;
    char aux[val][30];
    for(i=0;i<val;i++)
    {
        min=i;
        for(j=i+1;j<val;j++)
        {
           comp= strcmp(nombres[j],nombres[min]);
            if(comp<0)
            {
                min=j;
            }
        }
        strcpy(aux, nombres[i]);
        strcpy(nombres[i],nombres[min]);
        strcpy(nombres[min],aux);

        auxL=legajos[i];
        legajos[i]=legajos[min];
        legajos[min]=auxL;

        auxN=nivel[i];
        nivel[i]=nivel[min];
        nivel[min]=auxN;
    }
}

int Ejercicio1()
{
    printf("EJERCICIO 1 - TP ARREGLOS PARALELOS\n\n");
    printf("Crear una funcion que los cargue, hasta que el usuario lo decida.\n\n");
    char nombres[20][30];
    int legajos[20];
    int nivel[20];
    int val= cargarParalelo(nombres,legajos,nivel,20);
    mostrarParalelo(nombres,legajos,nivel,val);
}

int Ejercicio2()
{
    printf("EJERCICIO 2 - TP ARREGLOS PARALELOS\n\n");
    printf("Crear una funcion que busque dentro del arreglo de legajos y retorne la posicion de un determinado valor.\n\n");
    int legajos[20];
    int nivel[20];
    char nombres[20][30];
    char op='s';
    int val= cargarParalelo(nombres,legajos,nivel,20);
    int dato;
    do{
    printf("\n\nIngrese legajo a buscar: ");
    scanf("%d",&dato);
    int pos= retornarPosLegajo(legajos,val,dato);
    if(pos!=-1)
    {
    printf("La posicion del legajo es: %d",pos);
    }
    else
    {
        printf("El legajo no existe!");
    }
    printf("\nDesea buscar otro legajo? Presione 's'/'n': ");
    fflush(stdin);
    scanf("%c",&op);

    }while(op=='s');
}

int Ejercicio3()
{
    printf("EJERCICIO 3 - TP ARREGLOS PARALELOS\n\n");
    printf("Hacer una funcion que reciba como parametro todos los arreglos y encuentre el nombre correspondiente a un determinado legajo y lo imprima por pantalla. Se debe invocar la funcion 2.\n\n");
    int legajos[20];
    int nivel[20];
    char nombres[20][30];
    int dato;
    int val= cargarParalelo(nombres,legajos,nivel,20);
    char op='s';
    do{
    printf("\n\nIngrese legajo a buscar: ");
    scanf("%d",&dato);
    mostrarPorLegajo(nombres,legajos,nivel,val,dato);
    printf("\nDesea seguir buscando? Presione 's'/'n': ");
    fflush(stdin);
    scanf("%c",&op);
    }while(op=='s');
}

int Ejercicio4()
{
    printf("EJERCICIO 4 - TP ARREGLOS PARALELEOS\n\n");
    printf("Hacer una funcion que reciba como parametro todos los arreglos y los ordene por nombre. (por el metodo de seleccion o insercion).\n\n");
    int legajos[20];
    int nivel[20];
    char nombres[20][30];
    int val= cargarParalelo(nombres,legajos,nivel,20);
    ordenarArregloParaleloSeleccion(nombres,legajos,nivel,val);
    printf("\nARREGLO ORDENADO:\n");
    mostrarParalelo(nombres,legajos,nivel,val);
}

int Ejercicio5()
{
    printf("EJERCICIO 5 - TP ARREGLOS PARALELOS\n\n");
    printf("Mostrar por pantalla los 3 arreglos pero de a un “registro” o alumno por vez (es decir: muestra el legajo, nombre y años del 1er alumno, luego el legajo, nombre y años del 2do alumno, y así sucesivamente)..\n\n");

    char nombres[20][30];
    int legajos[20];
    int nivel[20];
    int val = cargarParalelo(nombres,legajos,nivel,20);
    printf("\nREGISTRO DE ALUMNOS: \n");
    mostrarParalelo(nombres,legajos,nivel,val);
}
