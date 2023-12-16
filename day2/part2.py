INPUT = "puzzle.txt"
# INPUT = "easy.txt"
total_sum = 0

with open(INPUT) as file:
    for line in file:
        line = line.rstrip()
        game_num = int(line.split(":")[0].split()[1])
        sets = line.split(":")[1].strip().split(";")
        marbles = {"red": 0, "green": 0, "blue": 0}

        for s in sets:
            for data in s.split(","):
                count, color = data.strip().split(" ")
                marbles[color] = max(marbles[color], int(count))
        # print(marbles)
        multiplication = 1
        for num in marbles.values():
            multiplication *= num
        total_sum += multiplication

print(total_sum)
