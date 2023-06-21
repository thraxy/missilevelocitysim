import matplotlib.pyplot as plt
import pandas as pd
import os

# current dir path
currentDir = os.path.abspath(os.curdir)
# since the output dir is two levels up i am specifying a relative path
outputDir = os.path.abspath(os.path.join(currentDir, "..", "..", "output"))

# gets list of file names in output dir
fileList = os.listdir(outputDir)
# printing to see if list of files are printed
print(fileList)

# goes thru each file
for filename in fileList:
    # will check if the file is a csv or not
    if filename.endswith(".csv"):
        # full path to file
        outputFile = os.path.join(outputDir, filename)    
        # read the output file and make a dataframe
        dataFrame = pd.read_csv(outputFile)
        # extract data
        time = dataFrame.iloc[:, 0]
        alt = dataFrame.iloc[:, 1]
        vel = dataFrame.iloc[:, 2]
        
        # plotting
        plt.figure()
        plt.plot(time, alt, label="Altitude")
        plt.plot(time, vel, label="Velocity")
        plt.xlabel("Time(s)")
        plt.ylabel("Altitude")
        plt.title(filename)
        plt.legend()
        
        # image file
        dataImage = os.path.splitext(filename)[0] + ".png"
        img_Path = os.path.join(outputDir, dataImage)
        plt.savefig(img_Path)
        
        plt.close()
        
                
        

