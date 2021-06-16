/*
Autor: Gutiérrez Dueñas Raúl Leonardo
Desripcion:Sistema Indoorcycling
*/
#include "PYCT_LB_ROLOGDRL.H"//libreria personalizada
#include <iostream>
#include <sstream>
using namespace std;

main()
{
    nodo *raiz;
    SetTree(raiz);//Iniciamos el árbol del sistema
    do{
        raiz=Login(raiz);//Login de entrada
        do{
            Menu_Ad();//Menu de opciones de administrador
            cout<<"Ingrese opcion: ";cin>>r;
            switch (r){
                case 1:
                    raiz=raiz->sig1; //hijo 1 clases
                    do{
                        Menu_Cls();//Menu de opciones de clase
                        cout<<"Ingrese opcion: ";cin>>r;
                            switch (r){
                                case 1:
                                    List_Cls(raiz);//lista de todas las clases
                                    break;
                                case 2:
                                    Est_Cls(raiz);//estadisticas de todas las clases
                                    break;
                                case 3:
                                    raiz=Creador_Cls(raiz);//Crear una clase
                                    break;
                                case 4:
                                    raiz=Reserva_Cls(raiz);//reservación de clase
                                    break;
                                case 5:
                                    raiz=Cancelacion_Cliente(raiz);//Cancelación de usuario en una clase
                                    break;
                                case 6:
                                    Busqueda_Cls(raiz);//Busqueda de clase
                                    break;
                                case 7:
                                    raiz=Iniciar_Cls(raiz);//Inicio de una clase
                                    break;
                                case 8:
                                    raiz=Cancelacion_Clase(raiz);//Cancelar una clase
                                    break;
                                default:
                                    cout<<"Opcion no valida"<<endl;
                            }
                        cout<<"Desea regresar al menu de clases? 1.-Si 2.-No ";cin>>r;
                    }while(r==1);
                    break;
                case 2:
                    raiz=raiz->sig2;//hijo 2 clientes
                    do{
                        Menu_C_I_S(1);//Menu de opciones de cliente
                        cout<<"Ingrese opcion: ";cin>>r;
                            switch (r){
                                case 1:
                                    List_Cliente(raiz);//lista de todos los clientes
                                    break;
                                case 2:
                                    raiz=Nuevo_Perfil(raiz,"Cliente");//Creador de perfiles de Cliente
                                    break;
                                case 3:
                                    raiz=Eliminar_Cliente(raiz);//Eliminar un cliente
                                    break;
                                case 4:
                                    Busqueda_Cliente(raiz,1);//Buscar un cliente
                                    break;
                                case 1234:
                                    raiz=Bots_Ins_Cliente(raiz,"cliente");//Creador de bots
                                    break;
                                default:
                                    cout<<"Opcion no valida"<<endl;
                            }
                        cout<<"Desea regresar al menu de clientes? 1.-Si 2.-No ";cin>>r;
                    }while(r==1);
                    break;
                case 3:
                    raiz=raiz->sig3;//hijo 3 instructores
                    do{
                        Menu_C_I_S(2);//Menu de opciones de instructor
                        cout<<"Ingrese opcion: ";cin>>r;
                            switch (r){
                                case 1:
                                    List_Ins(raiz);//lista de todos los Instructores
                                    break;
                                case 2:
                                    raiz=Nuevo_Perfil(raiz,"Instructor");//Creador de perfiles de Instructor
                                    break;
                                case 3:
                                    raiz=Eliminar_Ins(raiz);//Eliminar un instructor
                                    break;
                                case 4:
                                    Busqueda_Ins(raiz);//Buscar un instructor
                                    break;
                                case 1234:
                                    raiz=Bots_Ins_Cliente(raiz,"instructor");//Creador de bots
                                    break;
                                default:
                                    cout<<"Opcion no valida"<<endl;
                            }
                        cout<<"Desea regresar al menu de instructores? 1.-Si 2.-No ";cin>>r;
                    }while(r==1);
                    break;
                case 4:
                    raiz=raiz->sig4;//hijo 4 sucursales
                    do{
                        Menu_C_I_S(3);//Menu de opciones de sucursales
                        cout<<"Ingrese opcion: ";cin>>r;
                            switch (r){
                                case 1:
                                    List_Suc(raiz);//lista de todas las Sucursales
                                    break;
                                case 2:
                                    raiz=Nueva_Suc(raiz);//Creador de sucursales
                                    break;
                                case 3:
                                    raiz=Eliminar_Suc(raiz);//Eliminar una sucursal
                                    break;
                                case 4:
                                    Busqueda_Suc(raiz);//Buscar una sucursal
                                    break;
                                case 1234:
                                    raiz=Bots_Suc(raiz);//Creador de bots
                                    break;
                                default:
                                    cout<<"Opcion no valida"<<endl;
                            }
                        cout<<"Desea regresar al menu de sucursales? 1.-Si 2.-No ";cin>>r;
                    }while(r==1);
                    break;
                default:
                    system("cls");
                    cout<<"Opcion no valida"<<endl;
            }
            raiz=raiz->ant;
            cout<<"Desea regresar al menu de administrador? 1.-Si 2.-No ";cin>>r;
        }while(r==1);
        cout<<"Haz cerrado sesion"<<endl;
        cout<<"Desea cerrar el programa? 1.-Si 2.-No ";cin>>r;
        while(raiz->ant!=NULL){
            raiz=raiz->ant;
        }
    }while(r==2);
}
