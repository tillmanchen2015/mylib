import numpy as np

# 10 random integer
np.random.rand(10)*100

# one random integer ranged [0, 10]
np.random.randint(10)

# one random float ranged [0,1]
np.random.sample()

# ten random integer ranged [0, 10]
np.random.randint(0, 10, 10)

# random uniform range. 100 random (not always integer) between -10 and 10
np.linspace(-10, 10, 100)