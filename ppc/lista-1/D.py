tests_quantity = int(input())

for test in range(1, tests_quantity + 1):
    is_symmetric = True

    matrix_size = int(input().split("=")[1])
    matrix = []

    for i in range(matrix_size):
        matrix.append([int(x) for x in input().split()])
    
    for row in range(matrix_size):
        for column in range(matrix_size):
            if (matrix[row][column] != matrix[matrix_size - row - 1][matrix_size - column - 1]) or matrix[row][column] < 0:
                is_symmetric = False
                break
    
    print(f"Test #{test}: Symmetric.") if is_symmetric else print(f"Test #{test}: Non-symmetric.")