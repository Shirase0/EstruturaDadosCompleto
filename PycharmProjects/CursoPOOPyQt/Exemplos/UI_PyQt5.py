from PyQt5 import *
from PyQt5 import  QtWidgets
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QToolTip, QLabel
from  PyQt5 import QtGui
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

        # Primeiro Botão
        selfbotao1 = QPushButton("Botao 1", self)
        self.botao1.move(0, 100)    # posicionamento do botao, x e y
        self.botao1.resize(150, 50)  # dimensionamento do botao, x e y
        self.botao1.setStyleSheet("QPushButton {background-color:#00FF00; font:bold}")  # estilo de layout do botao
        self.botao1.clicked.connect(self.botao_event)

        # Segundo Botão
        self.botao2 = QPushButton("Botao 2", self)
        self.botao2.move(200, 100)  # posicionamento do botao, x e y
        self.botao2.resize(150, 50)  # dimensionamento do botao, x e y
        self.botao2.setStyleSheet("QPushButton {background-color:#00FF00; font:bold}")  # estilo de layout do botao
        self.botao2.clicked.connect(self.eventoBtn2)

        # Label
        self.label = QLabel("Minha Label", self)
        self.label.move(50, 10)  # posicionamento do botao, x e y
        self.label.resize(150, 50)  # dimensionamento do botao, x e y
        self.label.setStyleSheet("QPushButton {background-color:#00FF00; font:bold}")  # estilo de layout do botao

        # Adiciona Imagem
        #self.imagem = QLabel(self)
        #self.imagem.move(50, 300)
        #self.imagem.setPixmap(QtGui.QPixmap("Minha_Imagem.png"))

        # Edit
        self.edit = QtWidgets.QLineEdit(self)
        self.edit.move(0, 0)
        self.edit.resize(100, 50)

        # Label Exibe EditText
        self.exibe = QLabel(self)
        self.exibe.setText("Nda Ainda")
        self.exibe.move(300, 50)

        print(self.botao1.width())

        self.LoadWindow()


    def eventoLbl(self):
        print("Label foi clickada")
        return


    def eventoBtn2(self):
        print("Botão 2")
        self.label.setStyleSheet("color:red")
        self.exibe.setText(self.edit.text())
        return

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
