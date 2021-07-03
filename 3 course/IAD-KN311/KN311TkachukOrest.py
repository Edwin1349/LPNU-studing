import matplotlib.pyplot as plt
def Draw(arrX, arrY, subplots):
    if not arrY:#1 array  
        if not subplots:
            counter =  int(1)
            for i in arrX:
                var = int(input('1) Pie\n2) Bar\n'))
                if var == 1:
                    plt.pie(i.values, labels=i.index)
                    
                elif var == 2:
                    plt.bar(i.index,i.values,  label = 'Count', width = 0.4)
                    
                plt.xticks(rotation=65)
                plt.tick_params(axis='x',  labelsize=4)
                plt.legend(loc='upper center', bbox_to_anchor=(1.5,0), borderaxespad=4)
                plt.savefig(str(counter)+".png", dpi = 400,  bbox_inches = "tight")
                plt.show()  
                counter += int(1)
                
        elif subplots:
            fig, axes = plt.subplots(ncols = len(arrX))
            plt.subplots_adjust(wspace = 2, hspace = None)
            for i,ax in zip(arrX,axes):
                var = int(input('1) Pie\n2) Bar\n'))
                if var == 1:
                    ax.pie(i.values, labels = i.index)
                    
                elif var == 2:
                    ax.bar(i.index,i.values,  label = 'Count', width = 0.4)
                    
                fig.autofmt_xdate(rotation = 65)
                ax.tick_params(axis = 'x',  labelsize = 4)
                ax.legend(loc='upper center', bbox_to_anchor = (1.5,0), borderaxespad = 4)
            plt.savefig(i.name+".png", dpi = 400,  bbox_inches = "tight")
            plt.show()
                
    else:#2 arrays
        for i in arrX:
            if i.name == 'Wind' or i.name == 'Condition':
                print('can`t draw ploth for this type of data')
                return 1
            for j in arrY:
                if (i.name == 'Time' or i. name == 'Date') and (j.name == 'Time' or j.name == 'Date'):
                   print('can`t draw ploth for this type of data')
                   return 1
            
        if not subplots:
           for i, j in zip(arrX, arrY):
                plt.title(j.name + ' to ' + i.name)
                plt.ylabel(j.name)
                plt.xlabel(i.name)
                var = int(input('1) Linear\n2) Scatter\n '))
                if var == 1:
                    plt.plot(i.values, j.values, label = j.name)
                    
                elif var == 2:
                    plt.scatter(i.values,j.values, label = j.name)
                
                plt.xticks(rotation=65)
                plt.tick_params(axis='x',  labelsize=4)
                plt.legend(loc='upper center', bbox_to_anchor=(1.5,0), borderaxespad=4)
                plt.savefig(j.name+".png", dpi=400,  bbox_inches = "tight")
                plt.show()   
                
        elif subplots and len(arrX) == 1:
            labelY = ''
            for j in arrY:
                labelY = labelY + str(j.name) + '/'
            for j in arrY:
                var = int(input('1) Linear\n2) Scatter\n '))
                plt.ylabel(labelY)
                plt.xlabel(arrX[0].name)
                if var == 1:
                    plt.plot(arrX[0].values, j.values, label = j.name)
                    
                elif var == 2:
                    
                    plt.scatter(arrX[0],j.values, label = j.name)
                    
                plt.xticks(rotation=65)
                plt.tick_params(axis='x',  labelsize=4)
                plt.legend(loc='upper center', bbox_to_anchor=(1.5,0), borderaxespad=4)
            
            plt.legend()
            plt.savefig(j.name+".png", dpi=400,  bbox_inches = "tight")
            plt.show()
            
        else:
            print('can`t draw subplots')
            return 1;