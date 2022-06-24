import math
import random
class Globals:

    @staticmethod
    def Task1():
        a = None
        b = None
        c = None
        print("Enter the length:", end = '')
        a = input
        print("\nEnter the width:", end = '')
        b = input
        print("\nEnter the height:", end = '')
        c = input
        V = None
        S = None
        S = 2 * (a * b + b * c + a * c)
        print("S = ", end = '')
        print(S, end = '')
        print("\n", end = '')
        V = a * b * c
        print("V = ", end = '')
        print(V, end = '')
        print("\n", end = '')

    @staticmethod
    def Task2():
        n = None #n - кол-во входящих чисел, s - кол-во подходящих чисел
        s = None
        s = 0
        print("Enter the number of items in the selection: ", end = '')
        n=input
        nums = [0 for _ in range(n)] #инициализация массива

        for i in range(1, n + 1):
            nums[i] = random.random() #рандом значений
            print(nums[i], end = '')
            print(" ", end = '')

        print("\n", end = '')

        for i in range(1, n + 1):
            o = nums[i] #значение из вектора
            k = 0 #кол-во цифр
            if o != 0:
                while o != 0:
                    o = math.trunc(o / float(10))
                    k += 1
                if math.fmod(k, 2) == 1:
                    s += 1

        print(s, end = '')


    @staticmethod
    def Task3():
        while True:
            num = None
            print("Enter The number:", end = '')
            num = input
            if num >= 100 and num < 1000:
                if math.trunc(num / float(100)) == math.fmod(num, 10): # Проверка, является ли число полиндромом
                    print("Yes", end = '')
                    print("\n", end = '')
                else:
                    print("No", end = '')
                    print("\n", end = '')
            else:
                print("No", end = '')
                print("\n", end = '')
            num = 0
            res = None
            print("Continue or not(1/0):", end = '')
            res = input
            if res == False:
                break
def main():
    task = None
    print("Select a task:", end = '')
    task = input
    if task == 1:
        print("Task 1:", end = '')
        print("\n", end = '')
        Globals.Task1()
    if task == 2:
        print("\nTask 2:", end = '')
        print("\n", end = '')
        Globals.Task2()
    if task == 3:
        print("\nTask 3:", end = '')
        print("\n", end = '')
        Globals.Task3()
    else:
        print("Invalid value", end = '')
