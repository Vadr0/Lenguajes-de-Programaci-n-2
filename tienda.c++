#include <iostream>
using namespace std;
class Productos{
public:
    int cod1p;
    int cod1g;
    int cod2p;
    int cod2g;
    int cod3p;
    int cod3g;
    string descrip1p;
    string descrip2p;
    string descrip3p;
    string descrip1g;
    string descrip2g;
    string descrip3g;
    int stock1p;        //STOCK papitas pequeñas
    int stock1g;        //STOCK papitas grandes
    int stock2p;        //stock piqueos pequeños 
    int stock2g;        //stock piqueos grandes
    int stock3p;        //stock cocacolas pequeñas
    int stock3g;        //stock cocacolas grandes
    float precio1p;       // 1 papitas 
    float precio2p;       //2 piqueos
    float precio3p;       // 3 coca cola
    float precio1g;       // g por grande
    float precio2g;       // p por pequeña
    float precio3g;

    Productos(){                               //los atributos se colocan por defecto en priva
        cod1p=1;
        cod1g=2;
        cod2p=3;
        cod2g=4;
        cod3p=5;
        cod3g=6;
        stock1p=10;
        stock1g=10;
        stock2p=10;
        stock2g=10;
        stock3p=10;
        stock3g=10;
        precio1p=1.5;
        precio1g=5;
        precio2p=2;
        precio2g=7;
        precio3p=3;
        precio3g=12;
        descrip1p="bolsa pequeña de papitas  -> contiene 100g";
        descrip1g="bolsa grande de papitas -> contiene 500g";
        descrip2p="bolsa pequeña de piqueos -> contiene 100g";
        descrip2g="bolsa grande de piqueos -> contiene 500g";
        descrip3p="botella pequeña de Coca Cola -> contiene 500 ml";
        descrip3g="botella pequeña de Coca Cola ->  contiene 3 L (litros)";

    }
    void cambiar_precio(){
        precio1g*=2;
    }
};

class Pedidos{
   public:
   Productos prodAC;   //produto a comprar
   int cantP1p;
   int cantP1g;
   int cantP2p;
   int cantP2g;
   int cantP3p;
   int cantP3g;
   Pedidos(){
    cantP1p+=cantP1p;
    cantP1g+=cantP1g;
    cantP2p+=cantP2p;
    cantP2g+=cantP2g;
    cantP3p+=cantP3p;
    cantP3g+=cantP3g;

   }


};
class gestor_inventario{
   public:
   Productos proges;
   int neto1p;
   int neto1g;
   int neto2p;
   int neto2g;
   int neto3p;
   int neto3g;

   gestor_inventario(){
    neto1g=proges.stock1g;
    neto1p=proges.stock1p;
    neto2p=proges.stock2p;
    neto2g=proges.stock2g;
    neto3p=proges.stock3p;
    neto3g=proges.stock3g;

   }
};

class reportes{
    public:
    Pedidos gr;
    int ventas1p;
    int ventas1g;
    int ventas2p;
    int ventas2g;
    int ventas3p;
    int ventas3g;

    reportes(){
        ventas1p=gr.cantP1p;
        ventas1g=gr.cantP1g;
        ventas2p=gr.cantP2p;
        ventas2g=gr.cantP2g;
        ventas3p=gr.cantP3p;
        ventas3g=gr.cantP3g;
    }
};
class acumulada {
    public:
    Pedidos ac;
    int acu1p;
    int acu1g;
    int acu2p;
    int acu2g;
    int acu3p;
    int acu3g;


};
int main (){
    int a,b,c,d;
    string resp1,resp2;
    Productos pr1;
    Pedidos pedYa;
    gestor_inventario inven;
    string repe;
    repe="si";
    while (repe=="si"){
        cout<<"¿Que productos deseas comprar?"<<endl;
        do{
            cout<<"1-papitas"<<endl;
            cout<<"2-piqueos"<<endl;
            cout<<"3-Coca Cola"<<endl;
            cin>>a;
        }while(a<0 or a>3);
        switch (a)
        {
        case 1:
            c=0;
            cout<<"contamos con "<<pr1.stock1p<<" "<<pr1.descrip1p<<" con un costo de: "<<pr1.precio1p<<endl;
            cout<<"contamos con "<<pr1.stock1g<<" "<<pr1.descrip1g<<" con un costo de: "<<pr1.precio1g<<endl;
            do{
                cout<<"ingrese 1 para comprar: "<<pr1.descrip1p<<endl;
                cout<<"ingrese 2 para comprar: "<<pr1.descrip1g<<endl;
                cin>>b;
            }while(b<0 or b>2);
            switch (b)
            {
            case 1:
               c=0;
                do{
                    cout<<"Elija la cantidad a comprar:";
                    cin>>c;
                }while (c<0 or c>pr1.stock1p);
                pedYa.cantP1p=c;
                inven.neto1p=inven.proges.stock1p-pedYa.cantP1p;
                break;
            case 2:
               do{
                    cout<<"Elija la cantidad a comprar:";
                    cin>>c;
                }while (c<0 or c>pr1.stock1g);
                pedYa.cantP1g=c;
                inven.neto1g=inven.proges.stock1g-pedYa.cantP1g;
                break;
            }
            break;
        case 2:
            cout<<"contamos con "<<pr1.stock2p<<" "<<pr1.descrip2p<<" con un costo de: "<<pr1.precio2p<<endl;
            cout<<"contamos con "<<pr1.stock2g<<" "<<pr1.descrip2g<<" con un costo de: "<<pr1.precio2g<<endl;
            do{
                cout<<"ingrese 1 para comprar: "<<pr1.descrip2p<<endl;
                cout<<"ingrese 2 para comprar: "<<pr1.descrip2g<<endl;
                cin>>b;
            }while(b<0 or b>2);
            switch (b)
            {
            case 1:
                c=0;
                do{
                    cout<<"Elija la cantidad a comprar:";
                    cin>>c;
                }while (c<0 or c>pr1.stock2p);
                pedYa.cantP2p=c;
                inven.neto2p=inven.proges.stock2p-pedYa.cantP2p;
                break;
            case 2:
                c=0;
                do{
                    cout<<"Elija la cantidad a comprar:";
                    cin>>c;
                }while (c<0 or c>pr1.stock2g);
                pedYa.cantP2g=c;
                inven.neto2g=inven.proges.stock2g-pedYa.cantP2g;
                break;    
            }
            break;
        case 3:
            cout<<"contamos con "<<pr1.stock3p<<" "<<pr1.descrip3p<<" con un costo de: "<<pr1.precio3p<<endl;
            cout<<"contamos con "<<pr1.stock3g<<" "<<pr1.descrip3g<<" con un costo de: "<<pr1.precio3g<<endl;
            do{
                cout<<"ingrese 1 para comprar: "<<pr1.descrip3p<<endl;
                cout<<"ingrese 2 para comprar: "<<pr1.descrip3g<<endl;
                cin>>b;
            }while(b<0 or b>2);
            switch (b)
            {
            case 1:
                c=0;
                do{
                    cout<<"Elija la cantidad a comprar:";
                    cin>>c;

                }while (c<0 or c>pr1.stock3p);
                pedYa.cantP3p=c;
                inven.neto3p=inven.proges.stock3p-pedYa.cantP3p;
                break;
            case 2:
                c=0;
                do{
                    cout<<"Elija la cantidad a comprar:";
                    cin>>c;
                }while (c<0 or c>pr1.stock3g);
                pedYa.cantP3g=c;
                inven.neto3g=inven.proges.stock3g-pedYa.cantP3g;

                break;
            }    
            break;
        }
        cout<<"desea volver a comprar ?"<<endl;
        cin>>repe;
    }
    cout<<"¿Desea saber cuantos objetos hay en el inventario? ";
    cin>>resp1;
    if (resp1=="si"){
        cout<<"hay "<<inven.neto1p<<" "<<pr1.descrip1p<<endl;
        cout<<"hay "<<inven.neto1g<<" "<<pr1.descrip1g<<endl;
        cout<<"hay "<<inven.neto2p<<" "<<pr1.descrip2p<<endl;
        cout<<"hay "<<inven.neto2g<<" "<<pr1.descrip2g<<endl;
        cout<<"hay "<<inven.neto3p<<" "<<pr1.descrip3p<<endl;
        cout<<"hay "<<inven.neto3g<<" "<<pr1.descrip3g<<endl;
        }
    cout<<"La empresa desea ver las ventas del dia?"<<endl;
    cin>>resp2;
    if (resp2=="si"){
        cout<<"el stock inicial de"<<pr1.descrip1p<<" fue: "<<pr1.stock1p<<" y los productos vendidos fueron: "<<pedYa.cantP1p<<endl;
        cout<<"el stock inicial de"<<pr1.descrip1g<<" fue: "<<pr1.stock1g<<" y los productos vendidos fueron: "<<pedYa.cantP1g<<endl;
        cout<<"el stock inicial de"<<pr1.descrip2p<<" fue: "<<pr1.stock2p<<" y los productos vendidos fueron: "<<pedYa.cantP2p<<endl;
        cout<<"el stock inicial de"<<pr1.descrip2g<<" fue: "<<pr1.stock2g<<" y los productos vendidos fueron: "<<pedYa.cantP2g<<endl;
        cout<<"el stock inicial de"<<pr1.descrip3p<<" fue: "<<pr1.stock3p<<" y los productos vendidos fueron: "<<pedYa.cantP3p<<endl;
        cout<<"el stock inicial de"<<pr1.descrip3g<<" fue: "<<pr1.stock3g<<" y los productos vendidos fueron: "<<pedYa.cantP3g<<endl;
    }
    return 0;
}