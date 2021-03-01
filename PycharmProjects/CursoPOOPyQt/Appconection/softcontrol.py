import subprocess

process = subprocess.Popen("/home/ats/PycharmProjects/CursoPOOPyQt/Appconection/teste", stdin=subprocess.PIPE, stdout=subprocess.PIPE)
entrada, output = process.stdin, process.stdout


entrada.write('a'.encode())
print(output.read().decode('latin1'))

entrada.close()
output.close()
status = process.wait()