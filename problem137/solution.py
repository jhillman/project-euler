N = 15 
a, b = 1, 1 
counter = 0 
while True: 
    a, b = (a * 3 + b * 5) / 2, (a + b * 3) / 2 
    if a% 5 == 1: 
        print (a - 1) / 5
        counter += 1 
        if counter == N: 
            n = (a - 1) / 5 
            print n 
            break
