# Team-001-6-homework04

Team-001-6, Jillian Slater (slate248), Codey Camerer (camer441)

## What is the project about/What does the simulation do?

  This project is a drone simulation system around the University of Minnesota campus. There is functionality to schedule a trip, in which a robot is given a name, starting position, destination, strategy (how the route to its destination is calculated, one of Astar, Dijkstra, and DFS), and is then placed on a map. You can schedule multiple trips at a time. A drone is created upon creation of the simulation, which locates the nearest robot by starting position, navigates to the robot using a Beeline strategy, and carries it to its destination using the strategy chosen at the robot’s creation. After the robot is delivered, the drone becomes available to take the next nearest robot to its destination. On top of this base simulation, there have been additional features added. One feature is adding additional vehicles around the map that move around continuously. This was done by importing assets for a helicopter, car, and ufo, and giving them functionality to move around the map. The drone has been given battery functionality through a Battery wrapper class. This allows its battery to be continuously depleted while it is moving, and once it reaches a certain battery level, it will travel to the nearest recharge station, where its battery will be charged to 100 percent. 

## How to run the simulation?

After the docker image is pulled (link found below), in the terminal, run:
> docker run -it –rm -p 8081:8081 codeyc/hw4

Once the server is started, open your browser and navigate to http://127.0.0.1:8081 to see the visualization of the simulation.
You can then schedule trips through  http://127.0.0.1:8081/schedule.html



## New Feature:

#### What does it do?

This feature implements battery functionality to the drone. While the drone is moving, its battery is continuously depleted, and once it reaches a certain level, it will find the nearest recharge station and go there to recharge. There are 5 recharge stations around the map that are created when the simulation begins. We implemented front end components to show the user what percentage the drone’s battery is at, with the drone changing color from green to yellow to red as it depletes, as well as the exact percentage being outputted to the screen. 

#### Why is it significantly interesting?

This is significantly interesting because it replicates a real world problem, and a real world solution to the problem. In a real world scenario, the drone cannot deliver robots endlessly, and would need to stop and recharge at times. We also used 2 design patterns (Decorator and Factory) to accomplish this, as well as including front-end changes.

#### How does it add to the existing work?

It builds on top of classes we have already created. The BatteryDecorator class inherits from IEntity and is used to wrap a Drone, RechargeStation also inherits from IEntity, RechargeStationFactory inherits from the preexisting IEntityFactory.h, and ChargingStrategy inherits from IStrategy. The drone still performs its main functionality of picking up and delivering robots, but with the added feature of needing to recharge its battery after a certain amount of time. 

#### Which design pattern did you choose to implement and why?

For the battery functionality, we used the Decorator pattern, as it allows us to add new behavior to the drone by wrapping it in a class (BatteryDecorator) containing the behavior. For the recharge stations, we used the Composite Factory design pattern, as this allows a subclass to decide which class to instantiate. We could add a new class RechargeStationFactory, which inherits from IEntityFactory, which will instantiate a new recharge station.

#### Instruction to use this new feature 

This feature runs automatically while the simulation runs, and requires no work on the part of the user.

## Sprint retrospective

#### What went well:
- Easy to divide tasks and visually see what needed to be done.
- 1 week iterations worked well for a small team and a quick deadline.

#### What didn’t go well: 
- Hard to plan the week ahead, sometimes planned too much for a week. 
- Difficult to do regular check-ins and share what we worked on.

#### What we would change in the future:
- Check in more regularly, do a standup everyday/every other day. 


## UML

![UML](https://github.umn.edu/umn-csci-3081-F22/Team-001-6-homework04/blob/main/New%20Feature%20UML%20diagram.jpeg)


## Docker link
https://hub.docker.com/repository/docker/codeyc/hw4

pull using 
> docker pull codeyc/hw4

instructions for running simulation see above

## Video link
https://drive.google.com/file/d/18NwLqmqVPhdnULPYHG71KIF1mITF0HbI/view?usp=share_link
