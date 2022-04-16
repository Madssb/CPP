import numpy as np  # for storing data that will be plotted
import matplotlib.pyplot as plt  # for plotting
import cProfile
import re
cProfile.run('re.compile("foo|bar")', 'restats')


"""
def numpy_dumpy():
    return np.loadtxt("data.txt")
data = numpy_dumpy()

"""
num_datapoints = sum(1 for line in open("data.txt"))
data = np.zeros((num_datapoints, 4))
with open('data.txt', 'r') as infile:  # open file
    for index, line in enumerate(infile):
        data_ = line.split()
        data[index, 0] = float(data_[0])
        data[index, 1] = float(data_[1])
        data[index, 2] = float(data_[2])
        data[index, 3] = float(data_[3])


plt.plot(data[:, 0], data[:, 1])
plt.xlabel('x [m]')
plt.ylabel('y [m]')
plt.savefig('plot.png')

import pstats
from pstats import SortKey
p = pstats.Stats('restats')
p.sort_stats(SortKey.NAME)
p.print_stats()