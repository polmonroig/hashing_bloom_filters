import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from os import listdir
from os.path import join

DATA_PATH = "data/experiments/load_factor_"



def create_plots(path):
    files = [join(path, file) for file in listdir(path)]
    for file in files:
        loaded_file = pd.read_csv(file)
        print(loaded_file)




def main():
    print("Starting data ploter...")
    for i in range(10, 100, 10):
        current_path = DATA_PATH + str(i)
        create_plots(current_path)






if __name__ == "__main__":
    main()
