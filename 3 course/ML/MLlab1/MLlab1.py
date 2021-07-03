import numpy as np
import scipy as sp
import seaborn as sns
import matplotlib.pyplot as plt
import plotly
import plotly.graph_objects as go

car_crashes = sns.load_dataset('car_crashes')
columns = ['total','speeding','alcohol']
print(car_crashes[columns])

car_crashes['Zscore'] = 0

for i in columns:
    std = float(np.std(car_crashes[i], ddof = 0))
    mean = float(np.mean(car_crashes[i]))
    print(i,'\n np.std: ', std, '\n mean: ', mean)

    car_crashes[i+'_Zscore'] = abs((car_crashes[i] - mean) / std)
    print(car_crashes[i+'_Zscore'],'\n')
    car_crashes['Zscore'] += car_crashes[i + '_Zscore']

car_crashes['Zscore'] = car_crashes['Zscore'] / len(columns)

car_crashes_top = car_crashes.loc[car_crashes['Zscore'] >= 3]
if len(car_crashes_top.index) < 5:
    car_crashes = car_crashes.sort_values('Zscore',ascending = False)
    car_crashes_top = car_crashes.head(7)

car_crashes_bot = car_crashes.tail(len(car_crashes.index) - len(car_crashes_top.index))

print(car_crashes.head(len(car_crashes_top.index)), '\n', car_crashes.head(len(car_crashes_top.index))['Zscore'])

fig = go.Figure()
fig.add_trace(go.Scatter3d(x = car_crashes_bot['total'], y = car_crashes_bot['speeding'], z = car_crashes_bot['alcohol'], mode = 'markers'))
fig.add_trace(go.Scatter3d(x = car_crashes_top['total'], y = car_crashes_top['speeding'], z = car_crashes_top['alcohol'], mode = 'markers'))
fig.update_layout(scene = dict(xaxis_title='total', yaxis_title='speeding', zaxis_title='alcohol'))
plotly.offline.plot(fig, filename='visualize.html')

