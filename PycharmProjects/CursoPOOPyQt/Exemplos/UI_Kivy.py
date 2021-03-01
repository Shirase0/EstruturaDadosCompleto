from kivy.app import App
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.label import Label
from  kivy.uix.boxlayout import BoxLayout

class Test(App):
    def build(self):
        box = BoxLayout()
        button = Button(text = "Botao 1")
        label = Label(text = "Label 1")
        box.add_widget(label)
        box.add_widget(button)
        return box

textinput = TextInput(text='Hello world')

Test().run()