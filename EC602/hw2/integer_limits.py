# Copyright 2017 Chao Ma mc163@bu.edu
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 13 14:54:18 2017

@author: macha
"""

Table = "{:<6} {:<22} {:<22} {:<22}"
#print(Table)
print(Table.format('Bytes', 'Largest Unsigned Int', 'Minimum Signed Int', 'Maximum Signed Int'))
for i in range(1, 9):
    a = 2 ** (8 * i)
    b = 2 ** (8 * i - 1) - 1
    print(Table.format(i, int(a - 1), int(-a/2), int(b)))
