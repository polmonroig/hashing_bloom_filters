import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from os import listdir
from os.path import join


DATA_PATH = "data/experiments/load_factor_"
PLOT_PATH = "data/experiments/plots"
DICTIONARY_TYPE_COL = 'dictionaryType'
LOAD_FACTOR_TYPE_COL = "loadFactor"
COMPARATIVE_COLS = [ 'keyPercentage', 'avgSuccessProbes',
                    'avgFailProbes', 'buildTime', 'successMeanTime',
                    'failMeanTime', 'successMaxTime', 'successMinTime',
                    'failMaxTime', 'failMinTime', 'successTheoricalValue', 'failTheoricalValue']
LOAD_FACTOR_ARRAY = [i / 100 for i in range(10, 100, 10)]
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


def create_plots(tables):
    tables = [table.sort_values(by=LOAD_FACTOR_TYPE_COL) for table in tables] # sort by load factor
    for col_name in COMPARATIVE_COLS:
        data = []
        legend = []
        for table in tables:
            legend.append(table[DICTIONARY_TYPE_COL].iloc[0])
            data.append(table[col_name])

        plt.ylabel(col_name)
        plt.xlabel("Load Factor")
        for d in data:
            plt.plot(LOAD_FACTOR_ARRAY, d)
        path = join(PLOT_PATH, "loadFactor_vs_" + col_name)
        plt.legend(legend, loc='upper left')
        plt.savefig(path)
        plt.clf()
        print("Saving plot " + path + ".png")



def main():
    print("Starting data ploter...")
    tables = [] # contains the mean tables for each load factor
    for i in range(10, 100, 10):
        current_path = DATA_PATH +  str(i)
        tables.append(create_table(current_path))

    tables = order_and_split(tables)
    create_plots(tables)





if __name__ == "__main__":
    main()
