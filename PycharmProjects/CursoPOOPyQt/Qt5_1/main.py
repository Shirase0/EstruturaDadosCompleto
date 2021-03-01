from PyQt5 import *
from PyQt5 import  QtWidgets
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton
import sys

class MainWindow (QMainWindow):
    def __init__(self):
        super().__init__()

        # Atributos de Layout de Janela
        self.topo = 100
        self.esquerda = 100
        self.largura = 800
        self.altura = 600
        self.titulo = "Minha Primeira Janela"

        # Objetos de Janela
        self.botao1 = QPushButton("Botao 1", self)
        self.botao1.move(0, 0)    # posicionamento do botao, x e y
        self.botao1.resize(150, 50)  # dimensionamento do botao, x e y
        self.botao1.setStyleSheet("QPushButton {background-color:#00FF00; font:bold}")  # estilo de layout do botao
        self.botao1.clicked.connect(self.botao_event)
        print(self.botao1.width())

        self.LoadWindow()



    def LoadWindow(self):
        self.setGeometry(self.esquerda,self.topo, self.largura, self.altura)
        self.setWindowTitle(self.titulo)
        self.setWindowOpacity(0.8)
        self.show()

    def botao_event(self):
        if self.largura == self.botao1.width():
            self.largura = 600
            self.LoadWindow()
        else:
            self.largura = self.botao1.width()
            self.LoadWindow()
        print(self.width())


application = QApplication(sys.argv)
janela = MainWindow()
sys.exit(application.exec_())
