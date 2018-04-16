WINDOWS PROGRAMMING Laboratory Work #3
======================================

Basics of Working with Mouse. GDI Primitives. Bezier Curve.
-----------------------------------------------------------
<br>
##Completed Tasks
######Laboratory Work is done in Code::Blocks IDE

  - **Draw few lines of different colors and weights**

Lines are drawn with the `MoveToEx()` function which moves to the specified point and `LineTo()` - draws a line from specified position to another one. Color is set according to selected button from the group-box. Weight is equal to value entered in the weight field (by def = 4).

  - **Draw a Bezier curve**

Bezier Curve is determined by 4 points(x,y). I've specified a POINT array with custom points. Therefore curve is drawn with the `PolyBezier()` function.

  - **Draw few plane objects of different colors, weights, filled and not**

Drawn objects : Ellipse with `Ellipse()` function, rectangle with `Rectangle()` function. Weight is determined by the value of `weight` variable. For filled option there is a checkbox, if it is checked - the object is drawn filled, otherwise - not.

  - **Draw 2 different objects using mouse**

Objects that are drawn with mouse, are managed in the `WM_LBUTTONDOWN` , `WM_LBUTTONUP` , `WM_MOUSEMOVE` and `WM_RBUTTONDOWN`. Objects that are drawn with mouse - Pen, Line, Polyline, Ellipse, Rectangle.

  - **Draw a custom bitmap image (1 pt)**

The bitmap image is drawn in Adobe Photoshop and has the resolution 20x170. The bitmap was attached to the application with the help of `LoadImage()` , `GetObject()` and `BitBlt()` functions.

  - **Add a switch (button, select list...) that will change mouse ability to draw objects**

There is a group-box of radiocheck buttons for choosing desired color, made with `WS_GROUP` style.
Also there are several push buttons that allows the user to choose the desired tool to draw (paint).

###Program Overview
![overview](https://raw.githubusercontent.com/TUM-FAF/FAF-121-Gira-Dumitru/master/WP/WP_LAB_3/work.gif)
