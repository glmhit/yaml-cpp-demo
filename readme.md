# yaml-cpp demo 

## 1 install

```shell
# cd yourdir
git clone https://github.com/jbeder/yaml-cpp.git
cd yaml-cpp
mkdir build
cd build
cmake ../ 
make 
sudo make install
```

## 2 demos
```
mkdir build 
cd build
cmake ../
make 
cd ../
ln -s ./build/test ./test 
./test
```

output
```
basic emitting
hello world!

yaml simple list
- eggs
- bread
- milk


yaml simple map
name: Ryan Braun
position: LF

Jim
Last logged in: 2017-10-2
name: Ogre
position: 
powers: 8
name: Dragon
position: [1, 0, 10]
powers: 9
name: Wizard
position: [5, -3, 0]
powers: 50
1B is Prince Fielder
2B is Rickie Weeks
LF is Ryan Braun

```

