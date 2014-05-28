echo "tests 1"
./kplc ../tests/example1.kpl ../tests/out; cmp ../tests/out ../tests/example1 

echo "tests 2"
./kplc ../tests/example2.kpl ../tests/out; cmp ../tests/out ../tests/example2 

echo "tests 3"
./kplc ../tests/example3.kpl ../tests/out; cmp ../tests/out ../tests/example3 

echo "tests 4"
./kplc ../tests/example4.kpl ../tests/out; cmp ../tests/out ../tests/example4 

echo "tests 5"
./kplc ../tests/example5.kpl ../tests/out; cmp ../tests/out ../tests/example5 

echo "tests 6"
./kplc ../tests/example6.kpl ../tests/out; cmp ../tests/out ../tests/example6 

echo "tests 7"
./kplc ../tests/example7.kpl ../tests/out; cmp ../tests/out ../tests/example7 

echo "tests 8"
./kplc ../tests/example8.kpl ../tests/out; cmp ../tests/out ../tests/example8 

echo "tests 9"
./kplc ../tests/example9.kpl ../tests/out; cmp ../tests/out ../tests/example9 