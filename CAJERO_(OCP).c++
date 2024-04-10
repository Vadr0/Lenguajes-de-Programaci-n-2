#include <iostream>
using namespace std;

class CuentaBancaria 
{
private:
    float saldo;

public:
    CuentaBancaria(float saldoInicial) 
    {
        saldo = saldoInicial;
    }

    float getSaldo() 
    {
        return saldo;
    }

    void modificarSaldo(float cantidad) 
    {
        saldo += cantidad;
    }

    void consultarSaldo() 
    {
        cout << "Su saldo actual es de: S/ " << saldo << endl;
    }
};

// Interfaz genérica para operaciones bancarias
class OperacionBancaria 
{
public:
    virtual void realizarOperacion(float cantidad, CuentaBancaria& cuenta, CuentaBancaria* cuentaDestino = nullptr) = 0;
    virtual ~OperacionBancaria() {} // Destructor virtual para permitir la destrucción segura de subclases
};

// Subclase para operaciones de depósito
class Deposito : public OperacionBancaria 
{
public:
    void realizarOperacion(float cantidad, CuentaBancaria& cuenta, CuentaBancaria* cuentaDestino = nullptr) override 
    {
        if (cantidad > 0) 
        {
            cuenta.modificarSaldo(cantidad);
            cout << "Depositó S/ " << cantidad << " en su cuenta." << endl;
        } 
        else 
        {
            cout << "No puede depositar una cantidad negativa." << endl;
        }
    }
};

// Subclase para operaciones de retiro
class Retiro : public OperacionBancaria 
{
public:
    void realizarOperacion(float cantidad, CuentaBancaria& cuenta, CuentaBancaria* cuentaDestino = nullptr) override 
    {
        if (cantidad <= cuenta.getSaldo() && cantidad > 0) 
        {
            cuenta.modificarSaldo(-cantidad);
            cout << "Retiró S/ " << cantidad << " de su cuenta." << endl;
        } 
        else 
        {
            cout << "No tiene suficiente saldo para realizar esta operación." << endl;
        }
    }
};

// Subclase para operaciones de cambio de divisas
class CambioDivisas : public OperacionBancaria {
public:
    void realizarOperacion(float cantidad, CuentaBancaria& cuenta, CuentaBancaria* cuentaDestino = nullptr) override {
        // Supongamos que 1 dólar equivale a 3.69 soles peruanos
        float tipoCambio = 3.69;
        if (cantidad <= cuenta.getSaldo() && cantidad > 0) 
        {
            cuenta.modificarSaldo(-cantidad);
            float cantidadDolares = cantidad / tipoCambio;
            cout << "Cambiaste S/ " << cantidad << " a $" << cantidadDolares << " dólares." << endl;
        } 
        else 
        {
            cout << "No tiene suficiente saldo para realizar esta operación." << endl;
        }
    }
};

// Subclase para operaciones de transferencia bancaria
class TransferenciaBancaria : public OperacionBancaria 
{
public:
    void realizarOperacion(float cantidad, CuentaBancaria& cuentaOrigen, CuentaBancaria* cuentaDestino) override 
    {
        if (cuentaDestino == nullptr) 
        {
            cout << "La cuenta de destino no está especificada." << endl;
            return;
        }
        
        if (cantidad <= cuentaOrigen.getSaldo() && cantidad > 0) {
            cuentaOrigen.modificarSaldo(-cantidad);
            cuentaDestino->modificarSaldo(cantidad);
            cout << "Transferencia exitosa. Se transfirieron $" << cantidad << " a la cuenta del destinatario." << endl;
        } 
        else 
        {
            cout << "No tiene suficiente saldo para realizar esta operación." << endl;
        }
    }
};

int main() 
{
    CuentaBancaria cuenta(10000);
    CuentaBancaria cuentaDestino(0);
    int opcion;
    float cantidad;
    OperacionBancaria* operacion;

    do {
        cout << "Bienvenido al cajero automático" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Transferir dinero" << endl;
        cout << "4. Cambiar dinero a dólares" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) 
        {
            case 1:
                cuenta.consultarSaldo();
                break;
            case 2:
                cout << "Ingrese la cantidad a retirar: S/";
                cin >> cantidad;
                operacion = new Retiro();
                operacion->realizarOperacion(cantidad, cuenta);
                delete operacion;
                break;
            case 3:
                cout << "Ingrese la cantidad a transferir: S/";
                cin >> cantidad;
                operacion = new TransferenciaBancaria();
                operacion->realizarOperacion(cantidad, cuenta, &cuentaDestino);
                delete operacion;
                break;
            case 4:
                cout << "Ingrese la cantidad a cambiar a dólares: S/";
                cin >> cantidad;
                operacion = new CambioDivisas();
                operacion->realizarOperacion(cantidad, cuenta);
                delete operacion;
                break;
            case 5:
                cout << "Gracias por utilizar el cajero automático. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 5);

    return 0;
}
