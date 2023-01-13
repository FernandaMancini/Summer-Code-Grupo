inicio = 0
fim = 0
while inicio < 9:
    inicio = int(input('Inicio da população: '))
while fim < inicio:
    fim = int(input('Valor final: '))
ano = 1
mortos = int(inicio / 4)
nasc = int(inicio / 3)
tot = inicio + nasc - mortos
while tot < fim:
    mortos = int(tot/4)
    nasc = int(tot/3)
    tot = tot + nasc - mortos
    ano +=1
print(ano)   