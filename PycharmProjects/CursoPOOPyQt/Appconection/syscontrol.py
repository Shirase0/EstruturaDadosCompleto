import subprocess

# fileT = input("File Type: ")
# command1 = subprocess.run(f"ls *.{fileT}", shell=True )

# Unit Testing
# Integration Testing
# E2E

ct1 = [4, 5, 9]

programName = "operation"
subprocess.call(f"gcc {programName}.c -o {programName}", shell=True)
caso_teste1 = subprocess.run(f"echo '5 4' | ./{programName}", shell=True)  #executa programa em C

if (saida == saida_esperada):
    print("PASSED")
else:
    print("FAILED")
    print(f"Expected: {ct1[2]} Actual:{saida}")

caso_teste2 = subprocess.run(f"echo '5 -4' | ./{programName}", shell=True)  #executa programa em C
caso_teste2 = subprocess.run(f"echo '5 string' | ./{programName}", shell=True)  #executa programa em C


# List of results

# print(f"\n{command1.stdout}")
# print(command1.args) # args of the command
# print(command1.returncode)  # erroes