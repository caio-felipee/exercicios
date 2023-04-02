while True:
    try:
        first_connector, second_connector = [int(x) for x in input().split()], [int(x) for x in input().split()]

        is_valid = True

        for i in range(5):
            if first_connector[i] == second_connector[i]:
                is_valid = False
                break

        print("Y") if is_valid else print("N")

    except EOFError:
        break
