INPUT = "puzzle.txt"
# INPUT = "easy.txt"
total_right = 0

with open(INPUT) as file:
    for line in file:
        line = line.rstrip()
        game_num = int(line.split(":")[0].split()[1])
        sets = line.split(":")[1].strip().split(";")
        marbles = {"red": float("inf"), "green": float("inf"), "blue": float("inf")}
        for s in sets:
            for data in s.split(","):
                count, color = data.strip().split(" ")
                marbles[color] = max(marbles[color], int(count))
        if marbles["red"] <= 12 and marbles["green"] <= 13 and marbles["blue"] <= 14:
            total_right += game_num
            print(game_num)

print(total_right)
