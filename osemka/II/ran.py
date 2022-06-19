n = int(input().rstrip())

x = 0
slowo = False
for _ in range(n):
    line = input().rstrip()
    if line not in ("SOCKET", "gniazdoPCI", "pin", "BIOSROM", "chipset", "zlaczeZasilania", "bateria"):
        if slowo:
            x += 1
        slowo = False
    else:
        slowo = True
print(x)
