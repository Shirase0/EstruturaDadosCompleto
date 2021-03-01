from MyClassesLib import Pessoa


p1 = Pessoa()
print(p1.nome)
p1.nome = "Alfredo"
print(p1.nome)

p2 = Pessoa(nome="Clara")
print(p2.nome)
print(p2.idade)
p2.idade = 20


meu_dicionario = dict()

meu_dicionario.