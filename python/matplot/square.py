import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-10, 10, 50)
y = np.power(x,2)
plt.plot(x,y)

#shape
plt.plot(x,y, '.')

#color
plt.plot(x,y, 'r')

plt.plot(x,y, '.r')