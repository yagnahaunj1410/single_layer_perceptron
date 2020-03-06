import numpy as np
import matplotlib.pyplot as plt
import csv

x=[]
y=[]

xf=[]
yf=[]

with open('training_data.csv', 'r') as csvfile:
    plots= csv.reader(csvfile, delimiter=' ')
    for row in plots:
        if int(row[2]) == 0:
            x.append(float(row[0]))
            y.append(float(row[1]))
        else:
            xf.append(float(row[0]))
            yf.append(float(row[1]))

with open('line.csv','r' ) as csvfile1:
    plots1 = csv.reader(csvfile1, delimiter=',')
    for row in plots1:
        w1= float(row[0])
        w2= float(row[1])
        w3= float(row[2])

xn = np.linspace(0,2,100)   
plt.plot(xn,(w3-w1*xn)/w2,color='red')
plt.scatter(x,y,color='yellow')
plt.scatter(xf,yf,color='green')

plt.title('Data Points')

plt.xlabel('mass')
plt.ylabel('speed')

plt.show()

