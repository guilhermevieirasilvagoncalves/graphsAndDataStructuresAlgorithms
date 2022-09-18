from typing import List

def buscaBinaria(arr: List[int], elemento: int):
    i: int = 0
    f: int = len(arr) - 1
    while i <= f:
        pivo: int = int((i + f) / 2)
        if elemento > arr[pivo]:
            i = pivo + 1
        elif elemento < arr[pivo]:
            f = pivo - 1
        else:
            return pivo
    return -1


arr = [1, 4, 2, 5, 6, 7, 3]
print("Array:")
print(arr)

arr.sort()
print("Array ordenado:")
print(arr)
print(buscaBinaria(arr, 4))
