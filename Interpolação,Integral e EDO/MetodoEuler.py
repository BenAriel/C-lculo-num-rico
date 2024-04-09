import numpy as np
import matplotlib.pyplot as plt


def f(x, y):
    return x - 3*y
 

def euler_method(x0, xn, y0, n):
    h = (xn - x0) / n
    x_values = np.linspace(x0, xn, n+1)
    y_values = np.zeros(n+1)
    y_values[0] = y0

    for i in range(1, n+1):
        y_values[i] = y_values[i-1] + h * f(x_values[i-1], y_values[i-1])

    return x_values, y_values

x0 = 0.0
xn = 2.0 
y0 = 1.0  
n = 10    

x_values, y_values = euler_method(x0, xn, y0, n)

print(y_values)
# Plotando o gráfico da solução
plt.figure(figsize=(10, 8))
plt.plot(x_values, y_values, label='Método de Euler')
plt.title(f'Método de Euler para dy/dx = x - 3*y')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid(True)

plt.xticks(x_values)

plt.show()
