import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from os import listdir
from os.path import join

DATA_PATH = "data/experiments/load_factor_"
PLOT_PATH = "plots"



def create_plots(path):
    files = [join(path, file) for file in listdir(path)]
    tables = []
    for file in files:
        tables.append(pd.read_csv(file))

    table = pd.DataFrame()

    if len(tables) > 0: # remove later 
        table = pd.concat(tables)
        table = table.sort_values(by=['dictionaryType'])
        chunks = len(files)
        print(np.array_split(table, chunks))






def main():
    print("Starting data ploter...")
    for i in range(10, 100, 10):
        current_path = DATA_PATH + str(i)
        create_plots(current_path)






if __name__ == "__main__":
    main()
