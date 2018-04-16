# Windows Programming
#### student gr. FAF-161: Sclifos Corina
# Laboratory Work nr. 2 at PPE

## Contents

  - The Keyboard
  - Child Window Controls
    - Scroll Bar
    - Listbox
  - Menus and Other Resources
  - Dialog Boxes


## Executed Tasks:
  - **Mandatory Tasks:**
    - Display a dialog box on some event.
    - Add a system menu with 3+ items.
    - Add a scrollbar that changes a visible parameter of on element.
    - Hook keyboard input. Add 2 custom events for key combinations.

  - **Tasks With Points:**
    - Add a listbox, attach events to it. (2 pt)
    - Add 2 scroll bars that will manage main window size or position. (1 pt)
    - Customize the application by adding an icon and cursor. (1 pt)
    - Use a scroll bar to scroll through application's working space. Scrolls should appear when necessary. (1 pt)

## What I used

  - **Display a dialog box on some event**

In order to popup a dialog box I've created one in the .rc file. Therefore `AboutDlgProc()` procedure was created, function that will handle the displaying of my dialog box. Dialog box is appearing when I'm pressing the `Help` option from the menu. This is the part of code that is responsible for this `DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG), hwnd, AboutDlgProc);`

  - **Add a system menu to your application with at least 3 items**

The menu has been created in the .rc file. `POPUP` defines a menu item, `MENUITEM` - defines a submenu item. <br> Three items were created : `File -> Exit` - exits from the program, `Actions -> Change background color` - changes background color and `Help -> Help` - displaying a dialog box.

  - **Add a scroll bar that will change any visible parameter of any other element**

I've created a scrollbar using `CreateWindowEx()` by specifying the 2nd parameter as `"SCROLLBAR"` and a `xPos` variable that is changing the way messages in the `WM_HSCROLL` are called. Color of the text is changing by using the `SetTextColor()` function together with `xPos` variable

  - **Hook keyboard input. Add 2 custom events for 2 different keyboard combinations**

Hooks : `CTRL + W` for exiting from the application, and `CTRL + I` for displaying a dialog box. These actions are managed in the `WM_HOTKEY` case.

  - **Add a listbox and attach some events when any element is accessed**

I've created the listbox using `CreateWindowEx()` by specifying the 2nd parameter as `"LISTBOX"`. Elements in the listbox are added from the interaction between an editbox and a button. When an element from listbox is double-clicked, a messagebox with the name of selected element is displayed; when on a selected element from listbox is pressed right click, an alert is displayed about deleting the selected element. (this is done in the `WM_CONTEXTMENU` case. )

  - **Customize your application by adding an icon and using different cursor in application**

A custom cursor and icon were added in the main folder. Then they were declared in the .rc file `IDI_ICON ICON DISCARDABLE "icon.ico"`
and `ID_CURSOR CURSOR DISCARDABLE "cursor.cur"`. Also some of windowclass fields were changed `hIcon, hIconSm, hCursor` .

## Image
https://github.com/corincic161/Laboratories/blob/master/PPE/LAB2/SCREEN.JPG

