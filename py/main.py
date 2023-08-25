import numpy as np

r = lambda t: np.array([4 - 2 * t, 3 + 5 * t, 7 + 4 * t])

p = np.array([6, 0, -2])


p1 = p - r(0)
p2 = r(1) - r(0)
p3 = np.cross(p1, p2)



