class Productos:
    def __init__(self):
        self.cod1p = 1
        self.cod1g = 2
        self.cod2p = 3
        self.cod2g = 4
        self.cod3p = 5
        self.cod3g = 6
        self.stock1p = 10
        self.stock1g = 10
        self.stock2p = 10
        self.stock2g = 10
        self.stock3p = 10
        self.stock3g = 10
        self.precio1p = 1.5
        self.precio1g = 5
        self.precio2p = 2
        self.precio2g = 7
        self.precio3p = 3
        self.precio3g = 12
        self.descrip1p = "bolsa pequeña de papitas -> contiene 100g"
        self.descrip1g = "bolsa grande de papitas -> contiene 500g"
        self.descrip2p = "bolsa pequeña de piqueos -> contiene 100g"
        self.descrip2g = "bolsa grande de piqueos -> contiene 500g"
        self.descrip3p = "botella pequeña de Coca Cola -> contiene 500 ml"
        self.descrip3g = "botella pequeña de Coca Cola -> contiene 3 L (litros)"

class Pedidos:
    def __init__(self):
        self.cantP1p = 0
        self.cantP1g = 0
        self.cantP2p = 0
        self.cantP2g = 0
        self.cantP3p = 0
        self.cantP3g = 0

class GestorInventario:
    def __init__(self):
        self.proges = Productos()
        self.neto1p = self.proges.stock1p
        self.neto1g = self.proges.stock1g
        self.neto2p = self.proges.stock2p
        self.neto2g = self.proges.stock2g
        self.neto3p = self.proges.stock3p
        self.neto3g = self.proges.stock3g

class Reportes:
    def __init__(self):
        self.gr = Pedidos()
        self.ventas1p = self.gr.cantP1p
        self.ventas1g = self.gr.cantP1g
        self.ventas2p = self.gr.cantP2p
        self.ventas2g = self.gr.cantP2g
        self.ventas3p = self.gr.cantP3p
        self.ventas3g = self.gr.cantP3g

class Acumulada:
    def __init__(self):
        self.ac = Pedidos()
        self.acu1p = 0
        self.acu1g = 0
        self.acu2p = 0
        self.acu2g = 0
        self.acu3p = 0
        self.acu3g = 0

class AgregarStock:
    def __init__(self):
        self.agre1p = 0
        self.agre1g = 0
        self.agre2p = 0
        self.agre2g = 0
        self.agre3p = 0
        self.agre3g = 0

if __name__ == "__main__":
    x, y, z = "", "", ""
    a, b, c1p, c1g, c2p, c2g, c3p, c3g = 0, 0, 0, 0, 0, 0, 0, 0
    d, k, j = 0, 0, 0
    resp1, resp2, resp3 = "", "", ""
    pr1 = Productos()
    pedYa = Pedidos()
    inven = GestorInventario()
    repe = "si"
    acum = Acumulada()
    agre = AgregarStock()
    resp3 = "si"
    while resp3 == "si":
        while repe == "si":
            print("¿Qué productos deseas comprar?")
            a = int(input("1-papitas\n2-piqueos\n3-Coca Cola\n"))
            if a < 0 or a > 3:
                continue
            if a == 1:
                print(f"contamos con {pr1.stock1p - pedYa.cantP1p} {pr1.descrip1p} con un costo de: {pr1.precio1p}")
                print(f"contamos con {pr1.stock1g - pedYa.cantP1g} {pr1.descrip1g} con un costo de: {pr1.precio1g}")
                b = int(input(f"ingrese 1 para comprar: {pr1.descrip1p}\ningrese 2 para comprar: {pr1.descrip1g}\n"))
                if b < 0 or b > 2:
                    continue
                if b == 1:
                    c1p = int(input("Elija la cantidad a comprar:"))
                    acum.acu1p += c1p
                    pedYa.cantP1p = acum.acu1p
                    inven.neto1p = inven.proges.stock1p - acum.acu1p
                elif b == 2:
                    c1g = int(input("Elija la cantidad a comprar:"))
                    acum.acu1g += c1g
                    pedYa.cantP1g = acum.acu1g
                    inven.neto1g = inven.proges.stock1g - acum.acu1g
            elif a == 2:
                print(f"contamos con {pr1.stock2p - pedYa.cantP2p} {pr1.descrip2p} con un costo de: {pr1.precio2p}")
                print(f"contamos con {pr1.stock2g - pedYa.cantP2g} {pr1.descrip2g} con un costo de: {pr1.precio2g}")
                b = int(input(f"ingrese 1 para comprar: {pr1.descrip2p}\ningrese 2 para comprar: {pr1.descrip2g}\n"))
                if b < 0 or b > 2:
                    continue
                if b == 1:
                    c2p = int(input("Elija la cantidad a comprar:"))
                    acum.acu2p += c2p
                    pedYa.cantP2p = acum.acu2p
                    inven.neto2p = inven.proges.stock2p - acum.acu2p
                elif b == 2:
                    c2g = int(input("Elija la cantidad a comprar:"))
                    acum.acu2g += c2g
                    pedYa.cantP2g = acum.acu2g
                    inven.neto2g = inven.proges.stock2g - acum.acu2g
            elif a == 3:
                print(f"contamos con {pr1.stock3p - pedYa.cantP3p} {pr1.descrip3p} con un costo de: {pr1.precio3p}")
                print(f"contamos con {pr1.stock3g - pedYa.cantP3g} {pr1.descrip3g} con un costo de: {pr1.precio3g}")
                b = int(input(f"ingrese 1 para comprar: {pr1.descrip3p}\ningrese 2 para comprar: {pr1.descrip3g}\n"))
                if b < 0 or b > 2:
                    continue
                if b == 1:
                    c3p = int(input("Elija la cantidad a comprar:"))
                    acum.acu3p += c3p
                    pedYa.cantP3p = acum.acu3p
                    inven.neto3p = inven.proges.stock3p - acum.acu3p
                elif b == 2:
                    c3g = int(input("Elija la cantidad a comprar:"))
                    acum.acu3g += c3g
                    pedYa.cantP3g = acum.acu3g
                    inven.neto3g = inven.proges.stock3g - acum.acu3g
            repe = input("¿Desea volver a comprar ?\n")

        x = input("¿Desea ingresar como administrador?\n")
        if x == "si":
            y = input("Ingrese la clave\n")  # la clave es 123
            if y == "123":
                resp1 = input("¿Desea saber cuántos objetos hay en el inventario?\n")
                if resp1 == "si":
                    print(f"Hay {inven.neto1p + agre.agre1p} {pr1.descrip1p}")
                    print(f"Hay {inven.neto1g + agre.agre1g} {pr1.descrip1g}")
                    print(f"Hay {inven.neto2p + agre.agre2p} {pr1.descrip2p}")
                    print(f"Hay {inven.neto2g + agre.agre2g} {pr1.descrip2g}")
                    print(f"Hay {inven.neto3p + agre.agre3p} {pr1.descrip3p}")
                    print(f"Hay {inven.neto3g + agre.agre3g} {pr1.descrip3g}")
                resp2 = input("La empresa desea ver las ventas del día?\n")
                if resp2 == "si":
                    print(f"El stock inicial de {pr1.descrip1p} fue: {pr1.stock1p} y los productos vendidos fueron: {pedYa.cantP1p}")
                    print(f"El stock inicial de {pr1.descrip1g} fue: {pr1.stock1g} y los productos vendidos fueron: {pedYa.cantP1g}")
                    print(f"El stock inicial de {pr1.descrip2p} fue: {pr1.stock2p} y los productos vendidos fueron: {pedYa.cantP2p}")
                    print(f"El stock inicial de {pr1.descrip2g} fue: {pr1.stock2g} y los productos vendidos fueron: {pedYa.cantP2g}")
                    print(f"El stock inicial de {pr1.descrip3p} fue: {pr1.stock3p} y los productos vendidos fueron: {pedYa.cantP3p}")
                    print(f"El stock inicial de {pr1.descrip3g} fue: {pr1.stock3g} y los productos vendidos fueron: {pedYa.cantP3g}")
                z = input("¿Desea agregar productos a la tienda?\n")
                if z == "si":
                    print("¿Qué producto desea agregar al inventario?")
                    print(f"1->{pr1.descrip1p}\n2->{pr1.descrip1g}\n3->{pr1.descrip2p}\n4->{pr1.descrip2g}\n5->{pr1.descrip3p}\n6->{pr1.descrip3g}")
                    k = int(input())
                    if k in range(1, 7):
                        print("Ingrese la cantidad que agregará:")
                        j = int(input())
                        if k == 1:
                            agre.agre1p = j
                            pr1.stock1p = inven.neto1p + agre.agre1p
                        elif k == 2:
                            agre.agre1g = j
                            pr1.stock1g = inven.neto1g + agre.agre1g
                        elif k == 3:
                            agre.agre2p = j
                            pr1.stock2p = inven.neto2p + agre.agre2p
                        elif k == 4:
                            agre.agre2g = j
                            pr1.stock2g = inven.neto2g + agre.agre2g
                        elif k == 5:
                            agre.agre3p = j
                            pr1.stock3p = inven.neto3p + agre.agre3p
                        elif k == 6:
                            agre.agre3g = j
                            pr1.stock3g = inven.neto3g + agre.agre3g
        resp3 = input("¿Desea repetir para verificar si se aumentó el stock?\n")
