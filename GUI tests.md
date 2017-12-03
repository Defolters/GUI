#### v. 0.2.0 (30.11.2017)
## GUI tests
### Elements:
1. <a href="#node-1" id="ref-1"> ProgressBar </a>
2. <a href="#node-2" id="ref-2"> ScrollBar </a>
3. <a href="#node-3" id="ref-3"> Button </a>
4. <a href="#node-4" id="ref-4"> CheckBox </a>
5. <a href="#node-5" id="ref-5"> MenuBar </a>
6. <a href="#node-6" id="ref-6"> ComboBox  </a>
7. <a href="#node-7" id="ref-7"> RadioButton </a>
8. <a href="#node-8" id="ref-8"> Slider </a>
9. <a href="#node-9" id="ref-9"> StatusBar </a>
10. <a href="#node-10" id="ref-10"> Label </a>
11. <a href="#node-11" id="ref-11"> Table </a>
12. <a href="#node-12" id="ref-12"> ScrollPanel </a>
13. <a href="#node-13" id="ref-13"> TextBox </a>
14. <a href="#node-14" id="ref-14"> TextArea </a>
15. <a href="#node-15" id="ref-15"> ColorChooser </a>
16. <a href="#node-16" id="ref-16"> PasswordField </a>

#### <li id="node-1"><a href="#ref-1">↩</a> ProgressBar
1. The correct display of the ProgressBar -> **false**
2. The percent do not go beyond the frame -> **not all**
3. Non ability to specify negative left margin -> **false**
4. Non ability to specify negative right margin -> **false**
5. The correct сhange the ProgressBar to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
6. The correct display of the Lable -> **true**

#### <li id="node-2"><a href="#ref-1">↩</a> Scroll Bar
1. The correct display of the ScrollBar -> **not all** 
		1. Not overlap of sliders -> **false**
2. The slider does not go beyond the scrollbar -> **true**
3. The correct сhange the ScrollBar to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
4. The correct sending of coordinates to the ScrollPanel -> **false**
5. The ability to scroll by mouse -> **false**

#### <li id="node-3"><a href="#ref-1">↩</a> Button

1. The correct display of the image -> **true**
2. The correct display of the label of Button -> **true**
3. The correct working out pressing -> **true**
4. The correct сhange the Button to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
5. The correct function call -> **true**

#### <li id="node-4"><a href="#ref-1">↩</a> CheckBox
1. The correct display of the CheckBox -> **false**
2. The correct return of the value (true or false) -> **false**
3. The correct сhange the CheckBox to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
#### <li id="node-5"><a href="#ref-1">↩</a> MenuBar

1. The correct display of the MenuBar -> **false**
2. The correct display vector of Buttons -> **false**
3. The correct сhange the MenuBar to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 

#### <li id="node-6"><a href="#ref-1">↩</a> ComboBox 

1. The correct display of the ComboBox -> **false**
2. The correct display vector of Buttons -> **false**
3. The correct сhange the ComboBox  to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 


#### <li id="node-7"><a href="#ref-1">↩</a> RadioButton

1. The correct display of the RadioButton -> **false**
2. The correct work of users choice (only one choice available) -> **false**
3. The correct сhange the RadioButton to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 


#### <li id="node-8"><a href="#ref-1">↩</a> Slider

1. The correct display of the Slider -> **true**
2. The button of the slider does not go beyond the bounds -> **true**
3. The slider button moves only one axis -> **true**
4. The correct сhange the Slider to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
5. The ability to create vertical-axis -> **false** 


#### <li id="node-9"><a href="#ref-1">↩</a> StatusBar

1. The correct display of the StatusBar -> **true**
2. The correct display of elements on the StatusBar -> **true**
3. The correct сhange the StatusBar to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 

#### <li id="node-10"><a href="#ref-1">↩</a> Label 

1. The correct display of the Labels text -> **true**
2. The correct display of the Labels icon -> **true**
3. The correct сhange the Label to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 

#### <li id="node-11"><a href="#ref-1">↩</a> Table

1. The correct display of the Table -> **false** 
2. The correct сhange the Table to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
3. Support for text editing -> **false** 
4. Hotkey support -> **false** 
5. Compression of the cell size written after the input -> **false** 
6. Support of formulas -> **false** 
7. The correct display of the cell written at the opening -> **false** 

#### <li id="node-12"><a href="#ref-1">↩</a> ScrollPanel

1. The correct display of the ScrollPanel -> **false** 
2. Objects do not go beyond scrollbar -> **false** 
3. The correct сhange the ScrollPanel to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
4. The correct scrolling and display of objects -> **false** 

#### <li id="node-13"><a href="#ref-1">↩</a> TextBox

1. The correct display of the TextBox -> **not all**
2. Objects do not go beyond TextBox -> **false**
3. Support for text editing -> **not all**
4. Ability to set cursor on the desired position -> **false** 
5. Hotkey support -> **true**
6. Support of another language -> **false** 
7. The non independence of the field of printing and display fields -> **false** 
8. The correct сhange the TextBox to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 

#### <li id="node-14"><a href="#ref-1">↩</a> TextArea

1. The correct display of the TextArea -> **not all**
2. Objects do not go beyond TextArea -> **false**
3. Support for text editing -> **not all**
4. Ability to set cursor on the desired position -> **false**
5. Hotkey support -> **true**
6. The correct text scrolling -> **false**
7. The correct сhange the TextArea to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
8. The non independence of the field of printing and display fields -> **false**

#### <li id="node-15"><a href="#ref-1">↩</a> ColorChooser

1. The correct display of the ColorChooser -> **false**
2. The correct сhange the ColorChooser to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
3. The correct color storage -> **false**
4. The possibility of transferring color information to another block -> **false**

#### <li id="node-16"><a href="#ref-1">↩</a> PasswordField

1. The correct display of the PasswordField -> **false**
2. Configurable minimum and maximum password lengths -> **false**
3. Ability to hide the password when typing -> **false**
4. Ability to show password when typing -> **false**
5. Inability to set a blank password -> **false**
6. The correct сhange the PasswordField to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
 


