import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('func3CHC.csv', sep=',', header=0)

xCoord = [0] * 76
yMaxFCoord = [0] * 76
yMinFCoord = [0] * 76
yAvgFCoord = [0] * 76

yMaxOCoord = [0] * 76
yMinOCoord = [0] * 76
yAvgOCoord = [0] * 76

for i in range(0,76):
    xCoord[i] = i
    yMaxFCoord[i] = df.loc[df["Gen"] == i, "MaxFitness"].mean()
    yMinFCoord[i] = df.loc[df["Gen"] == i, "MinFitness"].mean()
    yAvgFCoord[i] = df.loc[df["Gen"] == i, "AvgFitness"].mean()

    yMaxOCoord[i] = round(df.loc[df["Gen"] == i, "MaxObjVal"].mean(), 4)
    yMinOCoord[i] = round(df.loc[df["Gen"] == i, "MinObjVal"].mean(), 4)
    yAvgOCoord[i] = round(df.loc[df["Gen"] == i, "AvgObjVal"].mean(), 4)

plt.plot(xCoord, yMaxFCoord)
plt.plot(xCoord, yMinFCoord)
plt.plot(xCoord, yAvgFCoord)
plt.savefig('func3CHCfitness.png', bbox_inches = 'tight')

# plt.plot(xCoord, yMaxOCoord)
# plt.plot(xCoord, yMinOCoord)
# plt.plot(xCoord, yAvgOCoord)
# plt.savefig('func5objective.png', bbox_inches = 'tight')