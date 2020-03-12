import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from os import listdir
from os.path import join


DATA_PATH = "data/experiments/load_factor_"
PLOT_PATH = "data/experiments/plots"
DICTIONARY_TYPE_COL = 'dictionaryType'
N_HASH_TYPES = 7

def order_and_split(tables):
    table = pd.concat(tables)
    table = table.sort_values(by=[DICTIONARY_TYPE_COL])
    chunks = N_HASH_TYPES
    tables = np.array_split(table, chunks)
    return tables


def create_table(path):
    """
    Generates a mean table for each of the repeated tests
    @param path is the dir to the experiments
    """
    files = [join(path, file) for file in listdir(path)]
    tables = []
    for file in files:
        tables.append(pd.read_csv(file))


    tables = order_and_split(tables)

    for i, entry in enumerate(tables):
        numerical_cols = entry.iloc[:, 1:]
        entry = numerical_cols.mean().to_frame().T
        entry[DICTIONARY_TYPE_COL] = tables[i].iloc[0,0]
        tables[i] = entry

    table = pd.concat(tables)

    return table

def plot(x, y, y_label, x_label, path):
    plt.plot(x, y)
    plt.ylabel(y_label)
    plt.xlabel(x_label)
    plt.savefig(join(PLOT_PATH, path))

def create_plots(table):
    seed_col = table["seed"]
    load_factor_col = table["loadFactor"]
    #plot(seed_col, load_factor_col, "Load Factor", "Seed", "seed_plot.png")
    plt.boxplot(seed_col)
    plt.savefig(join(PLOT_PATH, "seed_boxplot.png"))


def main():
    print("Starting data ploter...")
    tables = [] # contains the mean tables for each load factor
    for i in range(10, 100, 10):
        current_path = DATA_PATH +  str(i)
        tables.append(create_table(current_path))

    tables = order_and_split(tables)
    for hash_table in tables:
        create_plots(hash_table)





if __name__ == "__main__":
    main()
