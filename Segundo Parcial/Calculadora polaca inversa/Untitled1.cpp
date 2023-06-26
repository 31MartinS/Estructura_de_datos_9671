class Queue:
    def __init__(self):
        self.items = []
    
    def enqueue(self, item):
        self.items.append(item)
    
    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
    
    def is_empty(self):
        return len(self.items) == 0
    
    def size(self):
        return len(self.items)


def calcular_expresion(expresion):
    operandos = Queue()
    operadores = ['+', '-', '*', '/']

    for elemento in expresion:
        if elemento.isdigit():
            operandos.enqueue(int(elemento))
        elif elemento in operadores:
            operando2 = operandos.dequeue()
            operando1 = operandos.dequeue()
            resultado = realizar_operacion(elemento, operando1, operando2)
            operandos.enqueue(resultado)

    return operandos.dequeue()


def realizar_operacion(operador, operando1, operando2):
    if operador == '+':
        return operando1 + operando2
    elif operador == '-':
        return operando1 - operando2
    elif operador == '*':
        return operando1 * operando2
    elif operador == '/':
        return operando1 / operando2


def convertir_infija_a_postfija(expresion):
    precedencia = {'+': 1, '-': 1, '*': 2, '/': 2}
    operadores = []
    postfija = []

    for elemento in expresion:
        if elemento.isdigit():
            postfija.append(elemento)
        elif elemento in precedencia:
            while (not operadores) or (operadores[-1] == '(') or (precedencia[operadores[-1]] < precedencia[elemento]):
                operadores.append(elemento)
                break
            else:
                while (operadores) and (operadores[-1] != '(') and (precedencia[operadores[-1]] >= precedencia[elemento]):
                    postfija.append(operadores.pop())
                operadores.append(elemento)
        elif elemento == '(':
            operadores.append(elemento)
        elif elemento == ')':
            while (operadores) and (operadores[-1] != '('):
                postfija.append(operadores.pop())
            operadores.pop()

    while operadores:
        postfija.append(operadores.pop())

    return postfija


def convertir_infija_a_prefija(expresion):
    expresion = expresion[::-1]
    precedencia = {'+': 1, '-': 1, '*': 2, '/': 2}
    operadores = []
    prefija = []

    for elemento in expresion:
        if elemento.isdigit():
            prefija.append(elemento)
        elif elemento in precedencia:
            while (not operadores) or (operadores[-1] == ')') or (precedencia[operadores[-1]] < precedencia[elemento]):
                operadores.append(elemento)
                break
            else:
                while (operadores) and (operadores[-1] != ')') and (precedencia[operadores[-1]] >= precedencia[elemento]):
                    prefija.append(operadores.pop())
                operadores.append(elemento)
        elif elemento == ')':
            operadores.append(elemento)
        elif elemento == '(':
            while (operadores) and (operadores[-1] != ')'):
                prefija.append(operadores.pop())
            operadores.pop()

    while operadores:
        prefija.append(operadores.pop())

    return prefija[::-1]


expresion = input("Ingresa la expresión en notación polaca inversa: ")
resultado = calcular_expresion(expresion)

print("Resultado: ", resultado)

expresion_infija = convertir_infija_a_postfija(expresion)
expresion_postfija = expresion
expresion_prefija = convertir_infija_a_prefija(expresion)

print("Notación Infija: ", "".join(expresion_infija))
print("Notación Postfija: ", expresion_postfija)
print("Notación Prefija: ", "".join(expresion_prefija))