#!/usr/bin/python3.9
#coding:utf-8

import matplotlib.pyplot as plt
from numpy import column_stack

fic = open("Logs.LogIM", "r")


list_var_names = []
list_of_list_of_vars = []
scale_list = []
data_found = False
names_of_var_passed = False

counter = 0

for line in fic :

    if data_found :
        if names_of_var_passed :
            i = 0
            restick_number = ""
            for char in line :
                if char == " " : pass
                elif char == "\n" : pass
                elif char == "|" : 
                    list_of_list_of_vars[i].append(float(restick_number))
                    restick_number = ""
                    i += 1
                else :
                    restick_number += char
            scale_list.append(counter)
            counter += 1
                    

        else :
            i = 0
            list_var_names.append("")
            for char in line :
                if char == " " : pass
                elif char == "\n" : 
                    list_var_names.pop(i)
                elif char == "|" : 
                    i += 1
                    list_var_names.append("")
                    list_of_list_of_vars.append([])
                else :
                    list_var_names[i] += char

            names_of_var_passed = True

    elif line == "Data :\n" :
        print("Data found")
        data_found = True

i = 0
for list in list_of_list_of_vars :
    plt.plot(scale_list, list,label = list_var_names[i])
    i += 1
plt.grid()
plt.legend()
plt.show()
