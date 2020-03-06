import matplotlib.pyplot as plt
import csv

x=[]
y=[]

with open('random.csv', 'r') as csvfile:
    plots= csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))


plt.plot(x,y)

plt.title('Epoch vs Error graph')

plt.xlabel('Epoch')
plt.ylabel('Error')

plt.show()

