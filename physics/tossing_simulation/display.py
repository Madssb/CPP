import numpy as np
import matplotlib.pyplot as plt



num_datapoints = sum(1 for line in open('data.txt'))
r = np.zeros((2,num_datapoints))
v = np.zeros((2,num_datapoints))
with open('data.txt', 'r') as infile: # open file
    for index, line in  enumerate(infile):
        data  = line.split()
        r[0,index] = float(data[0])
        r[1,index] = float(data[1])
        v[0,index] = float(data[2])
        v[1,index] = float(data[3])


plt.plot(r[0,:],r[1,:])
plt.xlabel('x [m]')
plt.ylabel('y [m]')
plt.show()