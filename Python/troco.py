moedas = 0
while True:
    troco = float(input('Change owed: '))
    if troco > 0:
        break
cent = round(troco*100)
while cent >= 25:
    cent = cent - 25
    moedas += 1
while cent >= 10:
    cent = cent - 10
    moedas += 1
while cent >= 5:
    cent = cent - 5
    moedas += 1
while cent >= 1:
    cent= cent - 1
    moedas += 1
print(moedas)


