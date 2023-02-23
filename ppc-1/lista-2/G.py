test_cases = int(input())

for _ in range(test_cases):
    jobs, position = map(int, input().split())
    job_list = list(map(int, input().split()))

    time = 0

    while True:
        if max(job_list) != job_list[0]:
            job_list.append(job_list[0])
        
        else:
            time += 1
            
            if position == 0:
                print(time)
                break

        job_list.pop(0)

        if position == 0:
            position = len(job_list) - 1
        else:
            position -= 1