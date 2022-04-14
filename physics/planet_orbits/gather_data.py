# module used for AST2000 course for UIO, will be used to gather generated planetary orbits initial conditions:
from ast2000tools.solar_system import SolarSystem
import ast2000tools.constants as const
import numpy as np
seed = 6497  # seed for generating system data.

pjokknes = SolarSystem(6497)
print("planet initial positions (AU)")
for i in range(pjokknes.number_of_planets):
    print(pjokknes.initial_positions[:, i])
print("planet initial velocities [AU/yr]")
for i in range(pjokknes.number_of_planets):
    print(pjokknes.initial_velocities[:,i])

print('star mass: ',pjokknes.star_mass)
print('Gravitational constant in solar system units [AU^3/yr^2/m_sun]',const.G_sol)