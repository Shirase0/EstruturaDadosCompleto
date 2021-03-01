from tkinter import *
from tkinter import ttk
from functools import partial
#import tempControl as tc
window = Tk()
window.title("Interface Tkinter Python3")
window.geometry('400x400')
#window.configure(background="grey");


def call_result(label_result, d, m, a):
    dia = (d.get())
    mes = (m.get())
    ano = (a.get())
    label_result.config(text=f"{dia} {tc.meses[(int)(mes)-1]}, {ano}")
    return

# Variaveis de Sistema
dia = StringVar()
mes = StringVar()
ano = StringVar()

# Labels
space = Label(window, text=" ").grid(row=0, column=0)
lblNome = Label(window, text="Nome").grid(row=1, column=0)
lblIdade = Label(window, text="Idade").grid(row=2, column=0)
c = Label(window, text="Gênero").grid(row=3, column=0)
d = Label(window, text="IEEE").grid(row=4, column=0)


lblResult = Label(window)
lblResult.place(x=200, y=200)

# Inputs
edtNome = Entry(window, textvariable=dia).grid(row=1, column=1)
edtIdade = Entry(window, textvariable=mes).grid(row=2, column=1)
c1 = Entry(window, textvariable=ano).grid(row=3, column=1)
d1 = Entry(window).grid(row=4, column=1)

# Options Selector
list1 = ["Brasil", "Inglaterra", "Japão", "India", "Vietnã"]
c = StringVar()
c.set("Select your country")
droplist = OptionMenu(window, c, *list1)
droplist.config(width=15)
droplist.grid(row=5, column=2)

list2 = ["Fone de Ouvido", "Lapis", "Computador", "Impressora"]
optionLista2 = StringVar()
optionLista2.set("Objeto")
droplist = OptionMenu(window, optionLista2, *list2)
droplist.config(width=10)
droplist.grid(row=6, column=2)


def clicked(lbl, txt):
    res = "Welcome to " + txt.get()
    lbl.configure(text=res)


call_result = partial(call_result, lblResult, dia, mes, ano)
btn=ttk.Button(window, text="Submit", command=call_result).place(x=2, y=230)
window.mainloop()