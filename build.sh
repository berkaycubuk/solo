# remove outpu
rm output

# compile code
eval cc main.c $(pkg-config --libs --cflags raylib) -o output

# run it
./output
