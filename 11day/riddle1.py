"""
This work is licensed under the IDGAF v1.0 license, a copy should be included.
If I forgot to include it you may wanna google it but basically:
    -Do whatever but don't blame me if something bad happens
    -Would be cool if you credited me if you use my code but whatever
    -You should use the same license
    -or don't, just don't put some gay, lefty ethical license nonsense
"""

with open("input.txt") as file:
    lines = file.readlines()

class octopus():
    def __init__(self, energy):
        self.flashed = False
        self.energy = energy
        self.counted = False

    def flash(self):
        """
        flashes
        """
        self.flashed = True
        self.energy = 0

octs = []
for line in lines:
    octoline = []
    for point in line:
        if point != "\n":
            octoline.append(octopus(int(point)))
    octs.append(octoline)

for octo in octs:
    for pus in octo:
        print(pus.energy, end="")
    print("")

total = 0
times = 1000
equal = 0
for i in range(0, times):
    if equal != 0:
        break
    for y in range(0, len(octs)):
        for x in range(0, len(octs[0])):
            octs[y][x].energy += 1
            if octs[y][x].energy > 9:
                octs[y][x].flash()

    flashing = True
    while flashing:
        flashing = False
        x, y = 0, 0
        for octo in octs:
            for pus in octo:
                if pus.flashed and not pus.counted:
                    octs[y][x].counted = True
                    total += 1
                    flashing = True
                    if x - 1 >= 0:
                        if not octs[y][x - 1].flashed:
                            octs[y][x - 1].energy += 1
                            if octs[y][x - 1].energy > 9:
                                octs[y][x - 1].flash()
                    if x + 1 < len(octs[0]):
                        if not octs[y][x + 1].flashed:
                            octs[y][x + 1].energy += 1
                            if octs[y][x + 1].energy > 9:
                                octs[y][x + 1].flash()
                    if x - 1 >= 0 and y - 1 >= 0:
                        if not octs[y - 1][x - 1].flashed:
                            octs[y - 1][x - 1].energy += 1
                            if octs[y - 1][x - 1].energy > 9:
                                octs[y - 1][x - 1].flash()
                    if y - 1 >= 0:
                        if not octs[y - 1][x].flashed:
                            octs[y - 1][x].energy += 1
                            if octs[y - 1][x].energy > 9:
                                octs[y - 1][x].flash()
                    if x + 1 < len(octs[0]) and y - 1 >= 0:
                        if not octs[y - 1][x + 1].flashed:
                            octs[y - 1][x + 1].energy += 1
                            if octs[y - 1][x + 1].energy > 9:
                                octs[y - 1][x + 1].flash()
                    if x - 1 >= 0 and y + 1 < len(octs):
                        if not octs[y + 1][x - 1].flashed:
                            octs[y + 1][x - 1].energy += 1
                            if octs[y + 1][x - 1].energy > 9:
                                octs[y + 1][x - 1].flash()
                    if y + 1 < len(octs):
                        if not octs[y + 1][x].flashed:
                            octs[y + 1][x].energy += 1
                            if octs[y + 1][x].energy > 9:
                                octs[y + 1][x].flash()
                    if x + 1 < len(octs[0]) and y + 1 < len(octs):
                        if not octs[y + 1][x + 1].flashed:
                            octs[y + 1][x + 1].energy += 1
                            if octs[y + 1][x + 1].energy > 9:
                                octs[y + 1][x + 1].flash()
                x += 1
            y += 1
            x = 0

    simul = []
    for pus in octs:
        for octo in pus:
            octo.flashed = False
            octo.counted = False
            simul.append(octo.energy)

    equal = i
    for x in simul:
        if x != simul[0]:
            equal = 0
            break

print(" ----------- ")
for pus in octs:
    for octo in pus:
        print(octo.energy, end="")
    print("")

print("Total flashes:", total)
print("In sync at step", equal + 1)
