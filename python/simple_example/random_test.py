import random

for i in range(10):
    print(random.random())  # 产生 0~1 的随机数字
    print(random.randint(0, 10))  # 产生 0~10 之间的整数
    print(random.randrange(0, 10, 2))  # 产生 range(0,10,2) 内的随机数
    print(random.uniform(0, 10))  # 产生 0~10 之间的均匀分布数
    print(random.normalvariate(4, 1.5))  # 正态分布，期望为4，方差为1.5