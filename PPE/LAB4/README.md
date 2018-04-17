# WP Laboratory Work #4

## Title

Windows Timer. Animation.

## Contents

  * Windows timer


## Executed Tasks:
  - **Mandatory Tasks:**
    - Create an animation based on Windows timer which involves at least 5 different drawn objects

  - **Tasks With Points:**
    - Increase and decrease animation speed using mouse wheel (2 pt)
    -Solve flicking problem please describe in your readme/report how you did it (2pt)
    -Add animated objects which interact with each other  ex.: (2pt)
    -Few balls which have different velocity and moving angles. In order to get max points, add balls with mouse, make          balls to change color on interaction and any other things that will show your engineering spirit
    -Any other interesting and reach in animation application
    -Animate a Nyan Cat that leaves a rainbow tail (Math.floor(+35% for task with interacting objects))
  


## Screenshots

1. The application

    ![Screenshot1](https://raw.githubusercontent.com/TUM-FAF/FAF-121-Gaitur-Iurie/master/WP/Lab%234/screen.png)



## Development
This laboratory work was very interesting because it has cats, bubbles and music.
It was a little tough but since I made third laboratory work I had a some presentation about how to draw. What remained it was to implement collisions and to make them fly. I found some info about how to implement this, so it wasn’t so difficult.
Remained only to animate some photo – nyan cat’s images and rainbow images. Since I used timer even in the first laboratory work I had some idea how to implement it.
But what remained it was flickering.Thanks to your links I was able to resolve this problem.
I used double-buffing and memory-DC's. All I need was to change a little my code and that’s all

Yes, and forgot to mention about speed up by using mouse wheel .It was easy, only by using event WM_MOUSEWHEEL and changing timer data with this.
So, my opinion is that this was a good practice and also it was very useful especially because I learned how to solve flickering problem and also understood the concepts of collisions.


 
