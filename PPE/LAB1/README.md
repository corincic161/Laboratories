#### student gr. FAF-161: Sclifos Corina

# Laboratory work nr.1

## Executed Tasks:
  - ####Mandatory Tasks:
    - Create a Windows application
    - Choose a _Programming Style Guideline_ that you'll follow
    - Add 2 buttons to window: one with default styles, one with custom styles (size, background, text color, font family, font size)
    - Add 2 text elements to window: one with default styles, one with custom styles (size, background, text color, font family, font size)
    -On windows resize, one of the texts should "reflow" and be in window's center (vertically and horizontally)
  
##PSG - The hardest part

I am going to make small changes into PSG 

####Comments
```
    //Flag for checking
    int font = 1;
    //Declare Windows procedure
    LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
```

As you can see , my line of comment is written above the line of code , and between a line of code and a line of comment there is always a blank line left.A comment must start with an upper case.

####Case Blocks

The case statement should have the following form:

```
   case do:
      {
      
      }
      
    break;
```

####Curly Braces

Position of curly braces after any statement ,class.

```
   for (int i ; i < 0 ; i++ )
    {
  
    }
```  

I still need a lot of , to get used to it in order to write everything according to the PSG

##Result

1. Text Editor on the up for inputing the message
2. List Box on the down for outputing the message
3. Send button for sending message from Tex Editor to the List Box
4. Delete button for deleting message from the List Box
5. Custom Font button for switching to a font created by me for message text from List Box
6. Default Font button for switching to the default system font for message text from List Box
7. Close button for clossing the application with a Custom Font created
8. There is an resize handler and a restriction for width/height on resizing 
9. There are 3 behaviors for Minimize/Maximize/Close button
10. Added 1 static text with created font and colors on a changed main window background color

##Conclusion

This laboratory work was a difficult challenge for me since  Win32 API was new for me. Working with the messages and manipulating the parameters helped me to create a window and some child elements . Also this experience gave me an image of Windows API, and how it is structured, even if it didn't covered any advanced topics.
