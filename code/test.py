import ctypes
import numpy as np
from numpy.ctypeslib import ndpointer
import matplotlib.pyplot as plt

lib = ctypes.CDLL('./DBscan_supel.so')
DBSCAN_supel = lib.DBSCAN_supel