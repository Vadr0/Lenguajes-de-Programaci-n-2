class Alumno:
    def __init__(self, nombre, edad, promedio):  #constructor
        self.nombre = nombre
        self.edad = edad
        self.promedio = promedio

    def __str__(self):
        return f"Nombre: {self.nombre}, Edad: {self.edad}, Promedio: {self.promedio}"

    def __lt__(self, otro):
        return self.promedio < otro.promedio

class Grupo:
    def __init__(self, cantidad):
        self.alumnos = [None] * cantidad
        self.cantidad = 0

    def __str__(self):
        info_alumnos = "\n".join(str(alumno) for alumno in self.alumnos if alumno is not None)
        return f"Grupo de {self.cantidad} alumnos:\n{info_alumnos}"

    def agregar_alumno(self, nombre, edad, promedio):
        nuevo_alumno = Alumno(nombre, edad, promedio)
        self.alumnos[self.cantidad] = nuevo_alumno
        self.cantidad += 1

    def ordenar_por_promedio(self):
        for i in range(self.cantidad - 1):
            for j in range(self.cantidad - 1 - i):
                if self.alumnos[j].promedio > self.alumnos[j + 1].promedio:
                    # Intercambiar los objetos Alumno si el promedio es mayor
                    self.alumnos[j], self.alumnos[j + 1] = self.alumnos[j + 1], self.alumnos[j]

    def promedio_grupo(self):
        if self.cantidad == 0:
            return 0
        else:
            total_promedios = 0
            for i in range(self.cantidad):
                total_promedios+=self.alumnos[i].promedio
            return total_promedios / self.cantidad

    def mejor_promedio(self):
        if self.cantidad == 0:
            return None
        else:
            mejor_alumno = self.alumnos[0]  # Suponemos que el primer alumno tiene el mejor promedio inicialmente
            for alumno in self.alumnos[1:]:
                if alumno.promedio > mejor_alumno.promedio:
                    mejor_alumno = alumno
            return mejor_alumno


# Programa principal:
grupo = Grupo(5)  #aqui definimos la cantidad de alumnos 
##se agregan diferentes alumnos con nombre,edad y nota 
grupo.agregar_alumno("Juan", 20, 12.5)
grupo.agregar_alumno("María", 21, 15)
grupo.agregar_alumno("Pedro", 19, 9.0)
grupo.agregar_alumno("Ana", 22, 7)
grupo.agregar_alumno("Carlos", 20, 19)

print(grupo)

grupo.ordenar_por_promedio()
print("\nGrupo ordenado por promedio:")
print(grupo)

print("Promedio del grupo:", grupo.promedio_grupo())

mejor_alumno = grupo.mejor_promedio()
if mejor_alumno:
    print("Alumno con el mejor promedio del grupo:", mejor_alumno)
else:
    print("No hay alumnos en el grupo.")
