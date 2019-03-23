# words
words - application for get info about set of words. <br />
Options: <br />
>  -h [ --help ]         Help screen <br />
>  -w [ --words ] arg    Set of words <br />

# build environment
```
apt install cmake build-essential \
libboost-dev libboost-test-dev libboost-program-options-dev
```

# build
```
cd {project directory}
mkdir build && cd build
cmake ..
make 
make test
```

# run
```
cd {project directory}/Release/bin
./words -w "It looks good!"
```
# run tests
```
{project directory}/run_tests.sh
```
