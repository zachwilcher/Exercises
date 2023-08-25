import numpy as np
import pickle



def func():
    print("hello, world!")


class Foo:

    def __init__(self, func):
        self.arr = np.random.randn(5,4)
        self.func = func


    def bar(self, x):
        return np.matmul(self.arr, x)

    def foo(self):
        self.func()

    


f = Foo(func)
x = np.random.randn(4, 1)

f.foo()
s = pickle.dumps(f)

f = None

f = pickle.loads(s)

f.foo()
