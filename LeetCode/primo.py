def primo(number):
    n = 2     
    for i in range(0, number+1):
        if (i < 2):
            print(" No primo ", i)
        elif (i == n):
            print(" Primo " , i)
        elif (i %n == 0):
            print (" No primo " , i)
        else:
            # print (" Primo " , i)
            print(f" Primo {i} ")
            

# Otra forma
def es_primo(num):
    if num < 2: # 0 y 1 no son primos
        return False

    # for i in range(2, int(num**.5)+1):
    for i in range(2, num):
        print(f"La ecuacion es {num} iterador {i}")
        if num % i == 0: # si num es divisible por algún número en el rango, no es primo
            return False
    return True

def check_number(n):
    if (n % 5 == 0):
        print("asdf")
    elif n % 8 == 0:
        print("zxcv")
    else:
        print("qwer")

# Prueba la función con un número
check_number(10)

# primo(100)
n = 100 # puedes cambiar esto por cualquier número
for i in range(n+1):
    if es_primo(i):
        print(f"{i} es Primo")
    else:
        print(f"{i} No es Primo")