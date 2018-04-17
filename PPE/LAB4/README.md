
#### student gr. FAF-161: Sclifos Corina
# Laboratory Work nr. 4 at PPE


## Contents
* Windows timer

## Mandatory Objectives
* Create an animation based on Windows timer which involves at least 5 different drawn objects

## Objectives With Points
* Increase and decrease animation speed using mouse wheel `(2 pt)`
* Solve flickering problem `(2 pt)` _please describe in your `readme/report` how you did it_
* Add animated objects which interact with each other `(2-6 pt)`, ex.:
  * Few balls which have different velocity and moving angles. In order to get max points, add balls with mouse, make balls to change color on interaction and any other things that will show your engineering spirit
  * Any other interesting and reach in animation application
* Animate a Nyan Cat that leaves a rainbow tail `(Math.floor(+35% for task with interacting objects))`



## Screenshots
https://github.com/corincic161/Laboratories/blob/master/PPE/LAB4/screen.png



## Development
This laboratory work was very interesting because it has cats, bubbles and music.
It was a little tough but since I made third laboratory work I had a some presentation about how to draw. What remained it was to implement collisions and to make them fly. I found some info about how to implement this, so it wasn’t so difficult.
Remained only to animate some photo – nyan cat’s images and rainbow images.
But what remained it was flickering. One of the inks that you present was usefule..
I used double-buffing and memory-DC's. All I need was to change a little my code and that’s all

Yes, and forgot to mention about speed up by using mouse wheel .Only by using event WM_MOUSEWHEEL and changing timer data with this.


 
