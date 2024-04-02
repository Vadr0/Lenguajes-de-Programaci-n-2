class Mision:
    def __init__(self, dest, dur, trip):
        self.destino = dest
        self.duracion = dur
        self.tripulacionNecesaria = trip

    def simularMision(self):
        print(f"Simulando la misión hacia {self.destino} por {self.duracion} horas")

    def verificarCombustibleSuficiente(self, combustibleActual, tanqueLleno):
        if tanqueLleno:
            return True
        else:
            return combustibleActual >= self.duracion * 10

class Avion:
    def __init__(self, t):
        self.tipo = t

    def mostrarTipoAvion(self):
        print(f"Viajaras en el tipo de avion: {self.tipo}")

opcion = int(input("Elija el destino de la misión:\n1. Guatemala\n2. Panamá\n3. Costa Rica\n"))

destinos = {
    1: ("Guatemala", 24, 4),
    2: ("Panamá", 36, 6),
    3: ("Costa Rica", 30, 5)
}

if opcion in destinos:
    destinoElegido, duracionMision, tripulacionNecesaria = destinos[opcion]
    m = Mision(destinoElegido, duracionMision, tripulacionNecesaria)
    m.simularMision()
else:
    print("Opción no válida")
    exit(1)

opcionAvion = int(input("Elija el tipo de avión en el que va a viajar:\n1. Clase Económica\n2. Clase Ejecutiva\n3. Primera Clase\n"))

tiposAvion = {
    1: "Clase Económica",
    2: "Clase Ejecutiva",
    3: "Primera Clase"
}

if opcionAvion in tiposAvion:
    tipoAvionElegido = tiposAvion[opcionAvion]
    print(f"Su boleto de avion esta en {tipoAvionElegido.lower()}")
else:
    print("Opción no válida")

opcionTanque = int(input("Elija el estado del tanque de combustible:\n1. Tanque lleno\n2. Tanque vacío\n"))
tanqueLleno = (opcionTanque == 1)

combustibleActual = 1000 if tanqueLleno else 0

if m.verificarCombustibleSuficiente(combustibleActual, tanqueLleno):
    print("El avión tiene suficiente combustible va a despegar con éxito.")
    print(f"Disfrute su viaje en {tipoAvionElegido.lower()}")
else:
    print("El avión no tiene suficiente combustible para completar la misión con éxito")
