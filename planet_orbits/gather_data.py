from ast2000tools.solar_system import SolarSystem #module used for AST2000 course for UIO, will be used to gather generated planetary orbits initial conditions:
import numpy as np
seed = 6497 #seed for generating system data.

pjokknes = SolarSystem(6497)

planet_positions = pjokknes.initial_positions

print(np.shape(planet_positions))
print("planet positions:\t",planet_positions)

print('star mass in solar masses:\t',pjokknes.star_mass)