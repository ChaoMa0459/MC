# Copyright 2017 Chao Ma mc163@bu.edu

mass_earth = 5.972 * 10 ** 24
mass_proton = 1.6726 * 10 ** -27
hydrogen_relative_atomic_mass = 1
hydrogen_electrons = 1
oxygen_relative_atomic_mass = 16
oxygen_electrons = 8
terabyte = 1024 ** 4 * 8
# all O
lower_electrons = mass_earth / mass_proton * oxygen_electrons / oxygen_relative_atomic_mass
# all H 
upper_electrons = mass_earth / mass_proton * hydrogen_electrons / hydrogen_relative_atomic_mass
# half O, half H
average_electrons = (lower_electrons + upper_electrons) / 2
print(average_electrons / terabyte)
print(lower_electrons / terabyte)
print(upper_electrons / terabyte)
