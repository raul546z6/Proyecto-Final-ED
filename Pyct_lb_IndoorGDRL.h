#ifndef PYCT_LB_ROLOGDRL_H_INCLUDED
#define PYCT_LB_ROLOGDRL_H_INCLUDED
#include <iostream>
#include <sstream>

using namespace std;
struct inst_cliente{
    string nombre,paterno,materno,correo,telefono,usuario,contr;
    int clases,clases_tomadas=0;
};
struct clase{
    string sucursal,usuario,id="Clase_",lista[10],hora;
    int dia,mes,ano,clase_realizada;
};
struct sucursal{
    string sucursal,direccion;
};
struct nodo{
    inst_cliente usuario;
    clase cls;
    sucursal suc;
    nodo *sig1,*sig2,*sig3,*sig4,*ant;
};

nodo *nuevoNodo,*copiaNodo,*copiaNodo2,*copiaNodo3,*copiaNodo4,*copiaNodo5;
int r,contador;
string resp;

void SetTree(nodo *&raiz){
    //Declaración de la raiz;
    raiz=new(nodo);
    raiz->ant=NULL;
    //Rama administrador
    nuevoNodo=new(nodo);
    nuevoNodo->ant=raiz;
    nuevoNodo->usuario.usuario="Admin";
    nuevoNodo->usuario.contr="1234";
    raiz->sig1=nuevoNodo;
    //hijo 1 clases
    copiaNodo=new(nodo);
    nuevoNodo->sig1=copiaNodo;
    copiaNodo->ant=nuevoNodo;
    copiaNodo->sig3=NULL;
    //hijo 2 clientes
    copiaNodo=new(nodo);
    nuevoNodo->sig2=copiaNodo;
    copiaNodo->ant=nuevoNodo;
    copiaNodo->sig3=NULL;
    //hijo 3 instructores
    copiaNodo=new(nodo);
    nuevoNodo->sig3=copiaNodo;
    copiaNodo->ant=nuevoNodo;
    copiaNodo->sig3=NULL;
    //hijo 4 sucursales
    copiaNodo=new(nodo);
    nuevoNodo->sig4=copiaNodo;
    copiaNodo->ant=nuevoNodo;
    copiaNodo->sig3=NULL;
}

nodo* Login(nodo *raiz){
    system("CLS");
    raiz=raiz->sig1;
    cout<<"Bienvenido al administrador de Indoor Cycling"<<endl;
    do{
        cout<<"Ingrese el usuario: ";cin>>resp;
        if(resp!=raiz->usuario.usuario){
            cout<<"Usuario incorrecto"<<endl;
        }
    }while(resp!=raiz->usuario.usuario);
    do{
        cout<<"Ingrese la contrasena: ";cin>>resp;
        if(resp!=raiz->usuario.contr){
            cout<<"contrasena incorrecta"<<endl;
        }
    }while(resp!=raiz->usuario.contr);
    return raiz;
}

void Promedio(int ocupacion, int total_ocupacion, int promedio_ocupacion){
    promedio_ocupacion=(ocupacion*100)/total_ocupacion;
    cout<<"    Total de Reservaciones: "<<ocupacion<<" de "<<total_ocupacion<<endl;
    cout<<"    Promedio de ocupacion: "<<promedio_ocupacion<<"%"<<endl<<endl;
}

void Coinsidencia(){
    if(contador==0){
        cout<<"No se han encontrado coinsidencias"<<endl;
    }
}

void Menu_Ad(){
    system("CLS");
    cout<<"Menu Administrador Indoor cycling"<<endl;
    cout<<"1.-Clases"<<endl;
    cout<<"2.-Clientes"<<endl;
    cout<<"3.-Instructores"<<endl;
    cout<<"4.-Sucursales"<<endl;
}

void Menu_Cls(){
    system("cls");
    cout<<"Bienvenido al menu de clases"<<endl;
    cout<<"1.-Lista de clases"<<endl;
    cout<<"2.-Estadisticas totales"<<endl;
    cout<<"3.-Agregar una clase"<<endl;
    cout<<"4.-Reservar una clase"<<endl;
    cout<<"5.-Cancelar reserva"<<endl;
    cout<<"6.-Buscar una clase"<<endl;
    cout<<"7.-Iniciar clase"<<endl;
    cout<<"8.-Cancelar una clase"<<endl;
}

void Clase_Found(nodo *raiz,int tipo){
    if(tipo==1)cout<<endl<<"Clase encontrada"<<endl;
    cout<<"Clase id: "<<raiz->cls.id<<endl;
    cout<<" Instructor: "<<raiz->cls.usuario<<endl;
    cout<<" Sucursal: "<<raiz->cls.sucursal<<endl;
    cout<<"  Fecha: "<<raiz->cls.dia<<"/"<<raiz->cls.mes<<"/"<<raiz->cls.ano<<endl;
    cout<<"  Horario: "<<raiz->cls.hora<<endl<<endl;
}

void List_Cls(nodo *raiz){
    system("cls");
    raiz=raiz->sig3;
    cout<<"Lista de clases"<<endl;
    while(raiz!=NULL){
        int ocupacion=0;
        Clase_Found(raiz,2);
        for(int i=0;i<10;i++){
            if(raiz->cls.lista[i]!="vacio"){
                ocupacion++;
            }
        }
        cout<<" Reservaciones: "<<ocupacion<<" de 10"<<endl<<endl;
        raiz=raiz->sig3;
    }
}

void Est_Cls(nodo *raiz){
    system("cls");
    raiz=raiz->sig3;
    int ocupacion=0, ocupacion_total=0, porcentaje_ocupacion=0;
    cout<<"Estadisticas de Clases"<<endl;
    if(raiz!=NULL){
        while(raiz!=NULL){
            for(int i=0;i<10;i++){
                if(raiz->cls.lista[i]!="vacio"){
                    ocupacion++;
                }
            }
            ocupacion_total+=10;
            raiz=raiz->sig3;
        }
        cout<<"Total de clases registradas: "<<ocupacion_total/10<<endl;
        cout<<"Total de posible ocupacion: "<<ocupacion_total<<endl;
        cout<<"Total de ocupacion: "<<ocupacion<<endl;
        porcentaje_ocupacion=(ocupacion*100)/ocupacion_total;//calculo de porcentaje
        cout<<"Porcentaje de ocupacion: "<<porcentaje_ocupacion<<"%"<<endl;
    }
}

void Add_Cls(nodo *raiz, int tipo){
    raiz=copiaNodo;
    raiz=raiz->ant;
    if(tipo==1)raiz=raiz->sig3;
    if(tipo==2)raiz=raiz->sig4;
    raiz=raiz->sig3;
    while(raiz!=NULL){
        if(nuevoNodo->cls.usuario==raiz->usuario.usuario && tipo==1){
            nuevoNodo->sig1=raiz->sig1;
            raiz->sig1=nuevoNodo;
            contador++;
        }
        if(nuevoNodo->cls.sucursal==raiz->suc.sucursal && tipo==2){
                nuevoNodo->sig2=raiz->sig2;
                raiz->sig2=nuevoNodo;
                contador++;
        }
        raiz=raiz->sig3;
    }
}

void Deslindar_Cls(nodo *raiz, int tipo){
    copiaNodo2=copiaNodo->ant;
    if(tipo==1)copiaNodo2=copiaNodo2->sig3;//Reposicionando copia al nodo de Instructores;
    if(tipo==2)copiaNodo2=copiaNodo2->sig4;//Reposicionando copia al nodo de Sucursales;
    copiaNodo2=copiaNodo2->sig3;//Reposicionando copia, para que apunte a la lista
    while(copiaNodo2!=NULL){
        if((raiz->cls.usuario==copiaNodo2->usuario.usuario && tipo==1) || (raiz->cls.sucursal==copiaNodo2->suc.sucursal && tipo==2)){
            copiaNodo3=copiaNodo2;//Hacemos una copia que recorrera la lista de clases del coach hasta llegar a una antes de la clase que borraremos
            while(copiaNodo3!=NULL){
                if((copiaNodo3->sig1==raiz && tipo==1) || (copiaNodo3->sig2==raiz && tipo==2)){//Aqui buscamos que la siguiente sea la clase que queremos eliminar
                    if(tipo==1){
                        copiaNodo3->sig1=raiz->sig1;//Aqui la deslindamos de dicha lista
                        cout<<"Se a eliminado de la lista de clases del instructor: "<<raiz->cls.usuario<<endl;
                    }
                    if(tipo==2){
                        copiaNodo3->sig2=raiz->sig2;//Aqui la deslindamos de dicha lista
                        cout<<"Se a eliminado de la lista de clases de la sucursal: "<<raiz->cls.sucursal<<endl;
                    }
                }
                if(tipo==1)copiaNodo3=copiaNodo3->sig1;
                if(tipo==2)copiaNodo3=copiaNodo3->sig2;
            }
        }
        copiaNodo2=copiaNodo2->sig3;
    }
}

nodo* Creador_Cls(nodo *raiz){
    system("cls");
    cout<<"Creador de clase"<<endl;
    int num;
    nuevoNodo=new(nodo);
    contador=0;
    copiaNodo=raiz->sig3;
    cout<<"Ingrese numero de clase: ";cin>>num;
    ostringstream id;
    id<<num;
    nuevoNodo->cls.id+=id.str();
    while(copiaNodo!=NULL){
        if(nuevoNodo->cls.id==copiaNodo->cls.id){
            contador++;
            cout<<"Se a encontrado una clase con ese numero"<<endl;
            cout<<" Se a cancelado el registro dada la coincidencia"<<endl;
            delete nuevoNodo;
        }
        copiaNodo=copiaNodo->sig3;
    }
    copiaNodo=raiz;
    if(contador==0){
        cin.ignore();
        cout<<"Clase id: "<<nuevoNodo->cls.id<<endl;
        contador=0;//Vamos a utilizar coin para comprobar que se encontro algun match
        cout<<" Usuario del Instructor: ";getline(cin, nuevoNodo->cls.usuario);
        Add_Cls(raiz, 1);//Aqui vamos a agregar la clase a la lista de clases del instructor
        Coinsidencia();
        system("cls");
        if(contador==1){
            contador=0;//Vamos a utilizar coinsidencia para comprobar que se encontro algun match
            cout<<"Clase id: "<<nuevoNodo->cls.id<<endl;
            cout<<" Instructor: "<<nuevoNodo->cls.usuario<<endl;
            cout<<" Sucursal de la clase: ";getline(cin, nuevoNodo->cls.sucursal);
            Add_Cls(raiz, 2);//Aqui vamos a agregar la clase a la lista de clases de la sucursal
            Coinsidencia();
        }
        raiz=copiaNodo;
        if(contador==1){
            cout<<" Ingrese el dia en el que se impartira la clase: ";cin>>nuevoNodo->cls.dia;
            cout<<" Ingrese el mes en el que se impartira la clase: ";cin>>nuevoNodo->cls.mes;
            cout<<" Ingrese el ano en el que se impartira la clase: ";cin>>nuevoNodo->cls.ano;
            cout<<" Ingrese la hora a la que se impartira la clase: ";cin>>nuevoNodo->cls.hora;
            for(int i=0;i<10;i++){//aqui iniciamos la lista de la clase
                    nuevoNodo->cls.lista[i]="vacio";
            }
            nuevoNodo->cls.clase_realizada=0;//Aqui declaramos que las reservas estan abiertas
            nuevoNodo->sig4=NULL;//Aqui iniciamos la cola de espera
            nuevoNodo->sig3=raiz->sig3;//Aqui agregamos la clase a la lista de clases
            raiz->sig3=nuevoNodo;//Aqui agregamos la clase a la lista de clases
        }else{
            Deslindar_Cls(nuevoNodo, 1);//ELIMINAR LA CLASE DE LA LISTA DE CLASES DEL INSTRUCTOR
            cout<<" Se a cancelado el registro dado a que no se han tenido coincidencias"<<endl;
            delete nuevoNodo;
        }
    }
    return raiz;
}

nodo* Find_Clase_Instructor(nodo *raiz, int tipo){
    while(raiz!=NULL){
        if((resp==raiz->cls.id || resp==raiz->cls.usuario) && raiz->cls.clase_realizada!=1){
            copiaNodo2=raiz;
            Clase_Found(raiz,1);
            if (tipo==3){
                for(int i=0;i<10;i++){
                    cout<<i+1<<".- "<<raiz->cls.lista[i]<<endl;
                }
            }
            contador++;
            return copiaNodo2;
        }
        raiz=raiz->sig3;
    }
    Coinsidencia();
    return 0;
}

void Cliente_Found(nodo *raiz, int tipo){
    if(tipo!=2){
        cout<<"Cliente encontrado"<<endl;
        cout<<" Nombre del cliente: "<<raiz->usuario.nombre<<" "<<raiz->usuario.paterno<<" "<<raiz->usuario.materno<<endl;
        cout<<" Email: "<<raiz->usuario.correo<<endl;
        cout<<" Telefono: "<<raiz->usuario.telefono<<endl<<endl;
    }
    cout<<" Nombre de usuario: "<<raiz->usuario.usuario<<endl;
    cout<<" Clases tomadas: "<<raiz->usuario.clases_tomadas<<endl;
    cout<<" Clases disponibles: "<<raiz->usuario.clases<<endl<<endl;
}

nodo* Reserva_Cls(nodo *raiz){//Checar este do while para que no haga un loop infinito
    system("cls");
    cout<<"Reserva de clase"<<endl;
    copiaNodo=raiz;
    raiz=raiz->sig3;
    contador=0;
    cin.ignore();
    cout<<"Ingrese el usuario del Instructor de la clase a reservar: ";getline(cin,resp);
    copiaNodo2=Find_Clase_Instructor(raiz,1);
    if(contador>1){
        do{
            contador=0;
            cout<<"Ingrese el id de la clase a reservar: ";cin>>resp;
            copiaNodo2=Find_Clase_Instructor(raiz,2);
        }while(contador==0);
    }
    if(contador!=0){
        contador=0;
        raiz=copiaNodo;
        raiz=raiz->ant;
        raiz=raiz->sig2;
        raiz=raiz->sig3;
        cout<<"Ingrese el nombre de usuario del cliente: ";getline(cin,resp);
        while(raiz!=NULL){
            if(resp==raiz->usuario.usuario){
                Cliente_Found(raiz,1);
                do{
                    r=0;
                    int i=0;
                    if(raiz->usuario.clases>0){
                        while(i<10){//Aqui agregamos el cliente a la lista
                            if(copiaNodo2->cls.lista[i]=="vacio"){
                                copiaNodo2->cls.lista[i]=raiz->usuario.usuario;
                                break;
                            }
                            i++;
                        }
                        if(i>9){
                            cout<<"La clase esta llena"<<endl;
                            cout<<"Desea entrar a la lista de espera? 1.-Si 2.-No ";cin>>r;
                            if(r==1){
                                if(raiz->sig4==NULL && copiaNodo2->sig4!=raiz){
                                    raiz->sig4=copiaNodo2->sig4;
                                    copiaNodo2->sig4=raiz;
                                    cout<<"Se agregado exitosamente a la lista de espera"<<endl;
                                    raiz->usuario.clases--;
                                    cout<<"Clases disponibles: "<<raiz->usuario.clases<<endl<<endl;
                                    r=0;
                                }else{
                                    cout<<"El cliente ya se encuentra en una lista de espera"<<endl;
                                    r=0;
                                }
                            }
                        }else{
                            raiz->usuario.clases--;
                            raiz->usuario.clases_tomadas++;
                            cout<<"Se a agregado exitosamente el cliente a la lista"<<endl;
                            cout<<"Clases disponibles: "<<raiz->usuario.clases<<endl<<endl;
                        }
                    }else{
                        cout<<"El cliente no cuenta con clases suficientes"<<endl;
                        cout<<"Desea adquirir mas clases? 1.-Si 2.-No ";cin>>r;
                        if(r==1){
                            cout<<"Agregar numero de clases adquiridas: ";cin>>r;
                            raiz->usuario.clases=r;
                            cout<<"Clases disponibles: "<<raiz->usuario.clases<<endl<<endl;
                            cout<<"Desea agregar cliente a la lista? 1.-Si 2.-No ";cin>>r;
                        }
                    }
                }while(r==1);
                contador++;
            }
            raiz=raiz->sig3;
        }
        Coinsidencia();
    }
    raiz=copiaNodo;
    return raiz;
}

nodo* Cancelacion_Cliente(nodo *raiz){
    system("cls");
    cout<<"Cancelador de cliente en clase"<<endl;
    copiaNodo=raiz;
    raiz=raiz->sig3;
    contador=0;
    cin.ignore();
    cout<<"Ingrese el usuario del Instructor de la clase donde se realizara la cancelacion: ";getline(cin,resp);
    copiaNodo2=Find_Clase_Instructor(raiz,1);
    if(contador>1){
        contador=0;
        cout<<"Ingrese el id de la clase donde se realizara la cancelacion: ";cin>>resp;
        copiaNodo2=Find_Clase_Instructor(raiz,2);
    }
    if(contador==1){
        contador=0;
        raiz=copiaNodo;
        raiz=raiz->ant;
        raiz=raiz->sig2;
        raiz=raiz->sig3;
        cout<<"Ingrese el nombre de usuario del cliente: ";getline(cin,resp);
        while(raiz!=NULL){
            if(resp==raiz->usuario.usuario){
                Cliente_Found(raiz,1);
                int i=0;
                while(i<10){//Aqui cancelamos la clase del cliente y agregamos al primero de la lista de espera
                    if(copiaNodo2->cls.lista[i]==raiz->usuario.usuario){
                        contador++;
                        raiz->usuario.clases++;
                        raiz->usuario.clases_tomadas--;
                        cout<<"Cancelacion exitosa del cliente: "<<raiz->usuario.usuario<<endl;
                        cout<<"Clases disponibles: "<<raiz->usuario.clases<<endl;
                        copiaNodo3=copiaNodo2->sig4;
                        copiaNodo4=copiaNodo2;
                        if(copiaNodo3!=NULL){
                            cout<<"Lista de espera"<<endl;
                            while(copiaNodo3!=NULL){
                                cout<<"*.-"<<copiaNodo3->usuario.usuario<<endl;
                                if(copiaNodo3->sig4==NULL){
                                    copiaNodo2->cls.lista[i]=copiaNodo3->usuario.usuario;
                                    cout<<"El usuario: "<<copiaNodo3->usuario.usuario<<endl;
                                    cout<<"A pasado de la lista de espera a la lista de la clase"<<endl<<endl;
                                    copiaNodo3->usuario.clases_tomadas++;
                                    copiaNodo4->sig4=NULL;
                                }
                                copiaNodo4=copiaNodo3;
                                copiaNodo3=copiaNodo3->sig4;
                            }
                        }else{
                            cout<<"El lugar "<<i+1<<" a quedado vacio"<<endl<<endl;
                            copiaNodo2->cls.lista[i]="vacio";
                        }
                    }
                    i++;
                }
                Coinsidencia();
                contador++;
            }
            raiz=raiz->sig3;
        }
        Coinsidencia();
    }
    raiz=copiaNodo;
    return raiz;
}

void Busqueda_Cls(nodo *raiz){
    system("cls");
    raiz=raiz->sig3;
    contador=0;
    cout<<"Buscador de clase"<<endl;
    cout<<"Ingrese el id de la clase a buscar: ";cin>>resp;
    Find_Clase_Instructor(raiz,3);
}

nodo* Iniciar_Cls(nodo *raiz){
    system("cls");
    copiaNodo=raiz;
    raiz=copiaNodo;
    raiz=raiz->sig3;
    contador=0;
    cout<<"Iniciador de clase"<<endl;
    cout<<"Ingrese el id de la clase a iniciar: ";cin>>resp;
    while(raiz!=NULL){
        if(resp==raiz->cls.id){
            if(raiz->cls.clase_realizada==1){
                cout<<"Dicha clase ya a sido iniciada previamente"<<endl;
            }else{
                raiz->cls.clase_realizada=1;//Para hacer que ya no se pueda reservar en la clase
                cout<<"Clase correctamente iniciada"<<endl;
                Clase_Found(raiz,1);
                cout<<"Lista de la clase"<<endl;
                for(int i=0;i<10;i++){
                    cout<<i+1<<".- "<<raiz->cls.lista[i]<<endl;
                }
                copiaNodo2=raiz->sig4;
                if(copiaNodo2!=NULL){
                    cout<<"Vaciando lista de espera"<<endl;
                    while(copiaNodo2!=NULL){
                        copiaNodo2->usuario.clases++;
                        cout<<"Se le a regresado exitosamente la clase al usuario: "<<endl;
                        cout<<"  *.-"<<copiaNodo2->usuario.usuario<<endl;
                        cout<<"   Clases disponibles: "<<copiaNodo2->usuario.clases<<endl<<endl;
                        copiaNodo3=copiaNodo2;
                        copiaNodo2=copiaNodo2->sig4;
                        copiaNodo3->sig4=NULL;//Aqui lo sacamos de la lista de espera
                    }
                }
            }
            contador++;
        }
        raiz=raiz->sig3;
    }
    Coinsidencia();
    raiz=copiaNodo;
    return raiz;
}

nodo* Cancelacion_Clase(nodo *raiz){
    system("cls");
    copiaNodo=raiz;
    copiaNodo2=raiz;//Nodo para seguir detras al nodo que vallamos a borrar
    raiz=raiz->sig3;
    contador=0;
    cout<<"Cancelador de clases"<<endl;
    cout<<"Las clases previamente iniciadas no podran ser canceladas"<<endl;
    cout<<"Ingrese el id de la clase a cancelar: ";cin>>resp;
    while(raiz!=NULL){
        if(resp==raiz->cls.id && raiz->cls.clase_realizada!=1){
            Clase_Found(raiz,1);
            cout<<"Seguro que desea cancelar dicha clase? 1.-Si 2.-No ";cin>>r;
            if(r==1){
                copiaNodo2->sig3=raiz->sig3;//Aqui deslindamos la clase de la lista de clases
                cout<<"Se a eliminado de la lista de clases"<<endl;
                copiaNodo2=copiaNodo->ant;
                copiaNodo2=copiaNodo2->sig2;//Reposicionando copia al nodo de clientes;
                copiaNodo2=copiaNodo2->sig3;//Reposicionando copia, para que apunte a la lista de clientes
                copiaNodo3=copiaNodo2;//Realizamos copia del inicio de la lista de clientes
                for(int i=0;i<10;i++){
                    while(copiaNodo2!=NULL){//Aqui reembolsamos la lista
                        if(raiz->cls.lista[i]==copiaNodo2->usuario.usuario){
                            copiaNodo2->usuario.clases++;
                            copiaNodo2->usuario.clases_tomadas--;
                        }
                        copiaNodo2=copiaNodo2->sig3;
                    }
                    copiaNodo2=copiaNodo3;//Aqui lo regresamos al inicio de la lista de clientes
                }
                copiaNodo2=raiz->sig4;//Aqui reembolsamos la lista de espera
                if(copiaNodo2!=NULL){
                    while(copiaNodo2!=NULL){
                        copiaNodo2->usuario.clases++;
                        copiaNodo3=copiaNodo2;
                        copiaNodo2=copiaNodo2->sig4;
                        copiaNodo3->sig4=NULL;
                    }
                }
                cout<<"Se han hecho todos los reembolsos"<<endl;
                Deslindar_Cls(raiz, 1);//ELIMINAR LA CLASE DE LA LISTA DE CLASES DEL INSTRUCTOR
                Deslindar_Cls(raiz, 2);//ELIMINAR LA CLASE DE LA LISTA DE CLASES DE LA SUCURSAL
            }
            contador++;
            delete raiz; //Eliminamos clase por completo
            break;
        }
        copiaNodo2=raiz;
        raiz=raiz->sig3;
    }
    Coinsidencia();
    raiz=copiaNodo;
    return raiz;
}

void Menu_C_I_S(int tipo){
    system("cls");
    string entidad;
    if(tipo==1)entidad=" client";
    if(tipo==2)entidad=" instructor";
    if(tipo==3)entidad=" sucursal";
    cout<<"Bienvenido al menu de"<<entidad<<"es"<<endl;
    cout<<"1.-Lista de"<<entidad<<"es"<<endl;
    if(tipo==1)entidad=" cliente";
    if(tipo==3)entidad="a sucursal";
    cout<<"2.-Agregar un"<<entidad<<endl;
    cout<<"3.-Eliminar un"<<entidad<<endl;
    cout<<"4.-Buscar un"<<entidad<<endl;
}

void List_Cliente(nodo *raiz){
    system("cls");
    raiz=raiz->sig3;
    cout<<"Lista de clientes"<<endl;
    while(raiz!=NULL){
        Cliente_Found(raiz,2);
        raiz=raiz->sig3;
    }
}

nodo* Bots_Ins_Cliente(nodo *raiz, string entidad){
    system("cls");
    cout<<"Creando bots"<<endl;
    copiaNodo=raiz;
    for(int x=1;x<5;x++){
        ostringstream id;
        id<<x;
        nuevoNodo=new(nodo);
        nuevoNodo->usuario.usuario=id.str();
        nuevoNodo->usuario.paterno=id.str();
        nuevoNodo->usuario.materno=id.str();
        nuevoNodo->usuario.nombre=id.str();
        nuevoNodo->usuario.telefono=id.str();
        nuevoNodo->usuario.correo=id.str();
        cout<<" Nombre de usuario del "<<entidad<<": "<<nuevoNodo->usuario.usuario<<endl;
        if(entidad=="cliente"){
                nuevoNodo->usuario.clases=10;
                nuevoNodo->sig4=NULL;//Iniciamos el apuntador de lista de espera
        }
        if(entidad=="instructor")nuevoNodo->sig1=NULL;//iniciamos la lista de clases relacionadas
        nuevoNodo->sig3=raiz->sig3;//agregamos la entidad a la lista
        raiz->sig3=nuevoNodo;
        raiz=raiz->sig3;
    }
    raiz=copiaNodo;
    return raiz;
}

nodo* Eliminar_Cliente(nodo *raiz){
    system("cls");
    contador=0;
    copiaNodo=raiz;
    copiaNodo3=raiz;//Copia del nodo que estara justo detras del nodo actual
    raiz=raiz->sig3;
    cin.ignore();
    cout<<"Eliminador de clientes"<<endl;
    cout<<"Ingrese el apodo del cliente a eliminar: ";getline(cin,resp);
    while(raiz!=NULL){
        if(raiz->usuario.usuario==resp){
            Cliente_Found(raiz,1);
            contador++;
            cout<<"Esta seguro de hacer la eliminacion? 1.-Si 2.-No ";cin>>r;
            if(r==1){
                copiaNodo2=copiaNodo->ant;//Eliminarlo de las listas de espera y las listas activas
                copiaNodo2=copiaNodo2->sig1;
                copiaNodo2=copiaNodo2->sig3;//Aqui reposicionamos el nodo a que apunte a la lista de clases
                while(copiaNodo2!=NULL){//Aqui recorremos la lista de clases
                    if(copiaNodo2->cls.clase_realizada!=1){//Comprobamos que la clase siga activa
                        copiaNodo4=copiaNodo2->sig4;//Aqui copiamos el nodo que apunta a la clase, para recorrer la lista de espera
                        if(copiaNodo4!=NULL){//Comprobamos que tenga lista de espera
                            copiaNodo5=copiaNodo2;//Aqui hacemos una copia, la cual siempre ira detras de la otra;
                            while(copiaNodo4!=NULL){//Aqui recorremos la lista de espera
                                if(copiaNodo4==raiz){
                                    copiaNodo5->sig4=copiaNodo4->sig4;
                                    cout<<"Se a eliminado de la lista de espera de la: "<<copiaNodo2->cls.id<<endl;
                                }
                                copiaNodo5=copiaNodo4;
                                copiaNodo4=copiaNodo4->sig4;
                            }
                        }
                        int i=0;
                        while(i<10){//Aqui cancelamos la clase del cliente y agregamos al primero de la lista de espera
                            if(copiaNodo2->cls.lista[i]==raiz->usuario.usuario){
                                cout<<"Cancelacion exitosa del cliente: "<<raiz->usuario.usuario<<" en la: "<<copiaNodo2->cls.id<<endl;
                                copiaNodo4=copiaNodo2->sig4;
                                copiaNodo5=copiaNodo2;
                                if(copiaNodo4!=NULL){
                                    cout<<"Lista de espera"<<endl;
                                    while(copiaNodo4!=NULL){
                                        cout<<"*.-"<<copiaNodo4->usuario.usuario<<endl;//Aqui haz todo ese show de la cola
                                        if(copiaNodo4->sig4==NULL){
                                            copiaNodo2->cls.lista[i]=copiaNodo4->usuario.usuario;
                                            cout<<"El usuario: "<<copiaNodo4->usuario.usuario<<endl;
                                            cout<<"A pasado de la lista de espera a la lista de la clase"<<endl<<endl;
                                            copiaNodo4->usuario.clases_tomadas++;
                                            copiaNodo5->sig4=NULL;
                                        }
                                        copiaNodo5=copiaNodo4;
                                        copiaNodo4=copiaNodo4->sig4;
                                    }
                                }else{
                                    cout<<"El lugar "<<i+1<<" a quedado vacio"<<endl<<endl;
                                    copiaNodo2->cls.lista[i]="vacio";
                                }
                            }
                            i++;
                        }
                    }
                    copiaNodo2=copiaNodo2->sig3;
                }
                copiaNodo3->sig3=raiz->sig3;
                delete raiz;
                cout<<"Cliente totalmente eliminado"<<endl;
                break;
            }
        }
        copiaNodo3=raiz;
        raiz=raiz->sig3;
    }
    Coinsidencia();
    raiz=copiaNodo;
    return raiz;
}

void Busqueda_Cliente(nodo *raiz, int tipo){
    contador=0;
    raiz=raiz->sig3;
    if(tipo==1){
        system("cls");
        cin.ignore();
        cout<<"Buscador de clientes"<<endl;
        cout<<"Ingrese el nombre de usuario del cliente a buscar: ";getline(cin,resp);
    }
    while(raiz!=NULL){
        if(raiz->usuario.usuario==resp){
            Cliente_Found(raiz,1);
            contador++;
        }
        raiz=raiz->sig3;
    }
    Coinsidencia();
}

void Find_Removal(nodo *raiz, int tipo, string entidad){
    while(raiz!=NULL){
        if((raiz->usuario.usuario==resp && entidad=="Instructor") || (raiz->suc.sucursal==resp && entidad=="Sucursal")){
            contador++;
            if(tipo!=3)cout<<entidad<<" encontrad@"<<endl;
            int ocupacion=0,total_ocupacion=0,promedio_ocupacion=0;
            if(entidad=="Sucursal"){
                cout<<"Nombre de Sucursal: "<<raiz->suc.sucursal<<endl;
                cout<<" Direccion de la Sucursal: "<<raiz->suc.direccion<<endl;
                copiaNodo2=raiz->sig2;
            }
            if(entidad=="Instructor"){
                cout<<"Usuario del Instructor: "<<raiz->usuario.usuario<<endl;
                if(tipo==2){
                    cout<<"Nombre: "<<raiz->usuario.nombre<<" "<<raiz->usuario.paterno<<" "<<raiz->usuario.materno<<endl;
                    cout<<"Telefono: "<<raiz->usuario.telefono<<endl;
                    cout<<"Email: "<<raiz->usuario.correo<<endl;
                }
                copiaNodo2=raiz->sig1;
            }
            if(copiaNodo2!=NULL){
                while(copiaNodo2!=NULL){
                    cout<<" Clase: "<<copiaNodo2->cls.id<<endl;
                    for(int i=0;i<10;i++){
                        if(copiaNodo2->cls.lista[i]!="vacio"){
                            ocupacion++;
                        }
                    }
                    total_ocupacion+=10;
                    if(entidad=="Instructor")copiaNodo2=copiaNodo2->sig1;
                    if(entidad=="Sucursal")copiaNodo2=copiaNodo2->sig2;
                }
                Promedio(ocupacion, total_ocupacion, promedio_ocupacion);
            }
            if(tipo==1){
                cout<<"Esta seguro de hacer la eliminacion? 1.-Si 2.-No ";cin>>r;
                if(r==1){
                    copiaNodo3->sig3=raiz->sig3;
                    delete raiz;
                    cout<<"Eliminacion exitosa"<<endl;
                    break;
                }
            }
        }
        copiaNodo3=raiz;
        raiz=raiz->sig3;
    }
    if(tipo!=4)Coinsidencia();
}

nodo* Nuevo_Perfil(nodo *raiz, string entidad){
    system("cls");
    contador=0;
    copiaNodo=raiz;
    nuevoNodo=new(nodo);
    cin.ignore();
    cout<<"Creador de perfil de "<<entidad<<endl;
    cout<<"Ingrese un nombre de usuario para el perfil: ";getline(cin,resp);
    if(entidad=="Cliente")Busqueda_Cliente(raiz,2);//Comprobamos que no tengamos Clientes iguales
    if(entidad=="Instructor")Find_Removal(raiz,4,"Instructor");//Comprobamos que no tengamos Instructores iguales
    if(contador==0){
        nuevoNodo->usuario.usuario=resp;
        cout<<"Ingrese el apellido paterno del nuevo perfil: ";getline(cin, nuevoNodo->usuario.paterno);
        cout<<"Ingrese el apellido materno del nuevo perfil: ";getline(cin, nuevoNodo->usuario.materno);
        cout<<"Ingrese el nombre real del nuevo perfil: ";getline(cin, nuevoNodo->usuario.nombre);
        cout<<"Ingrese el numero de celular del nuevo perfil: ";cin>>nuevoNodo->usuario.telefono;
        cout<<"Ingrese el email del nuevo perfil: ";cin>>nuevoNodo->usuario.correo;
        if(entidad=="Cliente"){
                cout<<"Ingrese el numero de clases adquiridas por el cliente: ";cin>>nuevoNodo->usuario.clases;
                nuevoNodo->sig4=NULL;//Iniciamos el apuntador de lista de espera
        }
        if(entidad=="Instructor")nuevoNodo->sig1=NULL;//Iniciamos la lista de clases relacionadas
        nuevoNodo->sig3=raiz->sig3;//agregamos el perfil a la lista de la entidad
        raiz->sig3=nuevoNodo;
        raiz=raiz->sig3;
        cout<<"El perfil a sido creado"<<endl;
    }else{
        cout<<"No se a creado el perfil dada la coincidencia encontrada"<<endl;
        delete nuevoNodo;
    }
    raiz=copiaNodo;
    return raiz;
}

void List_Ins(nodo *raiz){
    system("cls");
    raiz=raiz->sig3;
    copiaNodo=raiz;
    cout<<"Lista de instructores"<<endl;
    while(raiz!=NULL){
        resp=raiz->usuario.usuario;
        Find_Removal(copiaNodo,3,"Instructor");
        raiz=raiz->sig3;
    }
}

nodo* Eliminar_Ins(nodo *raiz){
    system("cls");
    contador=0;
    copiaNodo=raiz;
    copiaNodo3=raiz;
    raiz=raiz->sig3;
    cin.ignore();
    cout<<"Eliminador de instructores"<<endl;
    cout<<"Ingrese el apodo del instructor a eliminar: ";getline(cin,resp);
    Find_Removal(raiz,1,"Instructor");
    raiz=copiaNodo;
    return raiz;
}

void Busqueda_Ins(nodo *raiz){
    system("cls");
    contador=0;
    raiz=raiz->sig3;
    cin.ignore();
    cout<<"Buscador de instructores"<<endl;
    cout<<"Ingrese el apodo del instructor a buscar: ";getline(cin,resp);
    Find_Removal(raiz,2,"Instructor");

}

void List_Suc(nodo *raiz){
    system("cls");
    raiz=raiz->sig3;
    copiaNodo=raiz;
    cout<<"Lista de sucursales"<<endl;
    while(raiz!=NULL){
        resp=raiz->suc.sucursal;
        Find_Removal(copiaNodo,3,"Sucursal");
        raiz=raiz->sig3;
    }
}

nodo* Nueva_Suc(nodo *raiz){
    system("cls");
    contador=0;
    copiaNodo=raiz;
    nuevoNodo=new(nodo);
    cout<<"Creador de Sucursal"<<endl;
    cin.ignore();
    cout<<"Ingrese el nombre de la sucursal: ";getline(cin,resp);
    Find_Removal(raiz,4,"Sucursal");//Comprobamos que no tengamos sucursales iguales
    if(contador==0){
        nuevoNodo->suc.sucursal=resp;
        cout<<"Ingrese la direccion de la sucursal: ";getline(cin,nuevoNodo->suc.direccion);
        nuevoNodo->sig3=raiz->sig3;//agregamos la sucursal a la lista de sucursales
        raiz->sig3=nuevoNodo;
        raiz=raiz->sig3;
        nuevoNodo->sig2=NULL;//Iniciamos la lista de clases relacionadas
        cout<<"La sucursal a sido creada"<<endl;
    }else{
        cout<<"No se a creado la sucursal dada la coincidencia encontrada"<<endl;
        delete nuevoNodo;
    }
    raiz=copiaNodo;
    return raiz;
}

nodo* Bots_Suc(nodo *raiz){
    system("cls");
    cout<<"Creando bots"<<endl;
    copiaNodo=raiz;
    for(int x=1;x<5;x++){
        ostringstream id;
        id<<x;
        nuevoNodo=new(nodo);
        nuevoNodo->suc.sucursal=id.str();
        nuevoNodo->suc.direccion=id.str();
        cout<<"Nombre de la Sucursal: "<<nuevoNodo->suc.sucursal<<endl;
        cout<<" Direccion de la Sucursal: "<<nuevoNodo->suc.direccion<<endl;
        nuevoNodo->sig3=raiz->sig3;//agregamos la sucursal a la lista de sucursales
        raiz->sig3=nuevoNodo;
        raiz=raiz->sig3;
        nuevoNodo->sig2=NULL;//Iniciamos la lista de clases relacionadas
    }
    raiz=copiaNodo;
    return raiz;
}

nodo* Eliminar_Suc(nodo *raiz){
    system("cls");
    contador=0;
    copiaNodo=raiz;
    copiaNodo3=raiz;
    raiz=raiz->sig3;
    cin.ignore();
    cout<<"Eliminador de sucursales"<<endl;
    cout<<"Ingrese la sucursal a eliminar: ";getline(cin,resp);
    Find_Removal(raiz,1,"Sucursal");
    raiz=copiaNodo;
    return raiz;
}

void Busqueda_Suc(nodo *raiz){
    system("cls");
    contador=0;
    raiz=raiz->sig3;
    cin.ignore();
    cout<<"Busqueda de sucursales"<<endl;
    cout<<"Ingrese la sucursal a buscar: ";getline(cin,resp);
    Find_Removal(raiz,2,"Sucursal");
}
#endif // PYCT_LB_ROLOGDRL_H_INCLUDED
