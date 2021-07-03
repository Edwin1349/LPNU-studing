import pandas as pd
import KN311TkachukOrest as dr
from datetime import datetime

def Convert(df):
    for idx, row in df.iterrows():
        #date converter
         date = df.loc[idx,'Date']
         dtConverted  = datetime.strptime(date,"%d.%b").strftime("%d/%m") + "/2019"
         df.loc[idx,'Date'] = dtConverted
         
        #time converter
         time = df.loc[idx,'Time']
         tmConverted = datetime.strptime(time,"%I:%M %p").strftime("%H:%M")
         df.loc[idx,'Time'] = tmConverted
         
        #speed converter
         speed = df.loc[idx,'Wind Speed']
         spConverted = ''.join([n for n in speed if n.isdigit()])
         df.loc[idx,'Wind Speed'] = round(float(spConverted)*1.61,2)
         
         speed = df.loc[idx,'Wind Gust']
         spConverted = ''.join([n for n in speed if n.isdigit()])
         df.loc[idx,'Wind Gust'] = round(float(spConverted)*1.61,2)
         
        #percentage converter1
         percentage = df.loc[idx,'Humidity']
         prConverted =  percentage.strip('%')
         df.loc[idx,'Humidity'] = (float(prConverted))/100
         
        #temperature converter
         temperature = df.loc[idx,'Temperature']
         tmpConverted = round((float(temperature)-32)*5/9,2)
         df.loc[idx,'Temperature'] = tmpConverted
         
         temperature = df.loc[idx,'Dew Point']
         tmpConverted = round((float(temperature)-32)*5/9,2)
         df.loc[idx,'Dew Point'] = tmpConverted
         
    df['Wind Speed'] = pd.to_numeric(df['Wind Speed'])
    df['Wind Gust'] = pd.to_numeric(df['Wind Gust'])
    df['Temperature'] = pd.to_numeric(df['Temperature'])
    df['Dew Point'] = pd.to_numeric(df['Dew Point'])
    df['Humidity'] = pd.to_numeric(df['Humidity'])
  
df=pd.read_csv('C:\\Users\Orest\\Desktop\\lpnu\\DATABASE.csv',sep=';', decimal=',')
df.rename(columns={'day/month': 'Date'},inplace = True)

Convert(df)

arrX=[]
arrY=[]

# Examples

#arrX.append(df['Date'].drop_duplicates())
#arrY.append(df.groupby('Date')['Temperature'].mean())
#arrX.append(df['Time'].drop_duplicates())
#arrY.append(df.groupby('Time')['Wind Speed'].mean())
#arrX.append(df['Time'].drop_duplicates())
#arrY.append(df.groupby('Time')['Wind Gust'].mean())
#arrX.append(df['Time'].drop_duplicates())
#arrY.append(df.groupby('Time')['Pressure'].mean())
#arrX.append(df['Time'].drop_duplicates())
#arrY.append(df.groupby('Time')['Humidity'].mean())

#arrX.append(df['Time'].drop_duplicates())
#arrY.append(df.groupby('Time')['Temperature'].mean())
#arrY.append(df.groupby('Time')['Wind Speed'].mean())
#arrY.append(df.groupby('Time')['Wind Gust'].mean())
#arrY.append(df.groupby('Time')['Pressure'].mean())
#arrY.append(df.groupby('Time')['Humidity'].mean())

arrX.append(df.groupby('Wind')['Time'].count())
arrX.append(df.groupby('Condition')['Time'].count())

dr.Draw(arrX, arrY, False)

df.to_csv('test.csv', sep=';', decimal=',')