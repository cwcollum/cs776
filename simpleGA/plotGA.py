import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('func1GA.csv', sep=',', header=0)

print(df.loc[df["Seed"] == 1, "Gen"])

print(df.loc[df["Gen"] == 0, "MaxFitness"].mean())

plt.plot(df.loc[df["Seed"] == 1, "Gen"], df.loc[df["Seed"] == 1, "AvgFitness"])
plt.plot(df.loc[df["Seed"] == 1, "Gen"], df.loc[df["Seed"] == 1, "MaxFitness"])
plt.plot(df.loc[df["Seed"] == 1, "Gen"], df.loc[df["Seed"] == 1, "MinFitness"])
# plt.show()
