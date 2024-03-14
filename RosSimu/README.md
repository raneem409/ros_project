# Waiteronix

This package contian simulation of waiteronix robot. 

## Dependencies

* Ununtu 20.04
* ROS Neotic

## Installation(Setup)

follow the instructions below to install the simulation part:
first create your workspace...
```bash
mkdir -p waiteronix_Ws/src
```
then clone the repository...
```bash
git clone https...
```
then excute and souce the package
```bash
cd ..
catkin_make
source devel/setup.bash
```

## Run

```bash
roslaunch PKG_NAME FILE.LAUNCH
```

>Note: keep in mind that WheelSperatation = "0.0"

