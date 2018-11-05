import matplotlib.pyplot as plt
import numpy as np

# Draw three scatter plot. 
# Three colors and three size to identify them.
 
N = 20
 
plt.scatter(np.random.rand(N) * 100,
            np.random.rand(N) * 100,
            c='r', s=100, alpha=0.5)
 
plt.scatter(np.random.rand(N) * 100,
            np.random.rand(N) * 100,
            c='g', s=200, alpha=0.5)
 
plt.scatter(np.random.rand(N) * 100,
            np.random.rand(N) * 100,
            c='b', s=300, alpha=0.5)
 
plt.show()