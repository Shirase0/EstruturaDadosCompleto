# uma classe é um molde
# objetos são criados a partir deste molde
# atributos são variáveis de classe (presentes nos objetos)
# método é uma função de uma classe (chamadas pelo objeto)



class CriaturaMosuta:
    def __init__(self):
        self.hp
        self.sp
        self.sp
        self.stren

class Cidade:
    def __init__(self, nome="Cidade Desconhecida", pais="Desconhecido"):
        self.nome = nome
        self.pais = pais


class Pessoa:
    def __init__(self, nome='Pessoa', idade=0, comendo=False, falando=False):
        self.nome = nome
        self.idade = idade
        self.comendo = comendo
        self.falando = falando


    def falar(self): # self define qual instancia está sendo chamada
        print(f"{self.nome} está falando!")

    def comer(self, alimento=''): # self define qual instancia está sendo chamada
        if self.comendo:
            print(f"{self.nome} já está comendo")
            return

        print(f"{self.nome} está comendo!")
        self.falando=True


class Creature:
   def __init__(self, atk, dfe, life):
       self.atk = atk
       self.dfe = dfe
       self.life = life

   def receberDano(self, dano):
      self.life -= dano

   def atacar(self, inimigo):
       print("Atacando")
       dano = self.atk - inimigo.dfn
       inimigo.receberDano(dano)

# String com os métodos
string_eh_objeto = "Oh No!!"
palavra = "ola"
print(palavra.upper())
print(palavra)
palavra = palavra.upper()
print(palavra)
