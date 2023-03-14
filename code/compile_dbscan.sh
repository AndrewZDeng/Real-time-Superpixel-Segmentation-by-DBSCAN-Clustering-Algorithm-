g++ -c -fPIC DBscan_supel.cpp -o DBscan_supel.o
g++ -shared -Wl,-soname,DBscan_supel.so -o DBscan_supel.so  DBscan_supel.o