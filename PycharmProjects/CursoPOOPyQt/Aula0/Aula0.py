# uma classe é um molde
# objetos são criados a partir deste molde
# atributos são variáveis de classe (presentes nos objetos)
# método é uma função de uma classe (chamadas pelo objeto)

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