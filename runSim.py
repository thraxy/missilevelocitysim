import subprocess
import os

# compile missile sim
subprocess.run(["make"])

# run simulation
subprocess.run(["./myprogram"])

# run python script to plot
# cd dir to viz dir
vizDir = os.path.join(os.getcwd(), "src", "visualization")
os.chdir(vizDir)

# run python script
subprocess.run(["python3", "viz.py"])