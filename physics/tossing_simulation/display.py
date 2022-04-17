import numpy as np  # for storing data that will be plotted
import matplotlib.pyplot as plt  # for plotting
with open('data.txt', 'r') as infile:  # open file
    lines = infile.readlines()
num_datapoints = len(lines)


r = np.empty((num_datapoints, 2))
for index, line in enumerate(lines):
    data = line.split()
    r[index, 0] = float(data[0])
    r[index, 1] = float(data[1])
plt.plot(r[:, 0], r[:, 1])
plt.xlabel('x [m]')
plt.ylabel('y [m]')
plt.savefig('plot.png')