#### v. 0.2.1 (05.12.2017)
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
1. Correct display of the ProgressBar -> **false**
2. Percent do not go beyond the frame -> **not all**
3. Non ability to specify negative left margin -> **false**
4. Non ability to specify negative right margin -> **false**
5. Correct сhange the ProgressBar to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
6. Correct display of the Lable -> **true**

#### <li id="node-2"><a href="#ref-1">↩</a> Scroll Bar
1. Correct display of the ScrollBar -> **true** 
		1. Not overlap of sliders -> **true**
2. Slider does not go beyond the scrollbar -> **true**
3. Correct сhange the ScrollBar to fit the screen (resizing): *more* -> **true**, *less* -> **true**, *width* -> **true**, *height* -> **true** 
4. Correct sending of coordinates to the ScrollPanel -> **true**
5. Ability to scroll by mouse -> **false**

#### <li id="node-3"><a href="#ref-1">↩</a> Button

1. Correct display of the image -> **true**
2. Correct display of the label of Button -> **true**
3. Correct working out pressing -> **true**
4. Correct сhange the Button to fit the screen (resizing): *more* -> **true**, *less* -> **true**, *width* -> **true**, *height* -> **true** 
5. Correct function call -> **true**

#### <li id="node-4"><a href="#ref-1">↩</a> CheckBox
1. Correct display of the CheckBox -> **true**
2. Correct return of the value (true or false) -> **true**
3. Correct сhange the CheckBox to fit the screen (resizing): *more* -> **true**, *less* -> **true**, *width* -> **true**, *height* -> **true** 
#### <li id="node-5"><a href="#ref-1">↩</a> MenuBar

1. Correct display of the MenuBar -> **true**
2. Correct display vector of Buttons -> **true**
3. Correct сhange the MenuBar to fit the screen (resizing): *more* -> **true**, *less* -> **true**, *width* -> **true**, *height* -> **true** 

#### <li id="node-6"><a href="#ref-1">↩</a> ComboBox 

1. Correct display of the ComboBox -> **false**
2. Correct display vector of Buttons -> **false**
3. Correct сhange the ComboBox  to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 


#### <li id="node-7"><a href="#ref-1">↩</a> RadioButton

1. Correct display of the RadioButton -> **true**
2. Correct work of users choice (only one choice available) -> **true**
3. Correct сhange the RadioButton to fit the screen (resizing): *more* -> **true**, *less* -> **true**, *width* -> **true**, *height* -> **true** 
4. Correct sending a choice -> **true**


#### <li id="node-8"><a href="#ref-1">↩</a> Slider

1. Correct display of the Slider -> **true**
2. Button of the slider does not go beyond the bounds -> **true**
3. Slider button moves only one axis -> **true**
4. Correct сhange the Slider to fit the screen (resizing): *more* -> **true**, *less* -> **true**, *width* -> **true**, *height* -> **true** 
5. Ability to create vertical-axis -> **false** 


#### <li id="node-9"><a href="#ref-1">↩</a> StatusBar

1. Correct display of the StatusBar -> **true**
2. Correct display of elements on the StatusBar -> **true**
3. Correct сhange the StatusBar to fit the screen (resizing): *more* -> **true**, *less* -> **true**, *width* -> **true**, *height* -> **true** 

#### <li id="node-10"><a href="#ref-1">↩</a> Label 

1. Correct display of the Labels text -> **true**
2. Correct display of the Labels icon -> **true**
3. Correct сhange the Label to fit the screen (resizing): *more* -> **true**, *less* -> **true**, *width* -> **true**, *height* -> **true** 

#### <li id="node-11"><a href="#ref-1">↩</a> Table

1. Correct display of the Table -> **false** 
2. Correct сhange the Table to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
3. Correct display elements -> **false**

#### <li id="node-12"><a href="#ref-1">↩</a> ScrollPanel

1. Correct display of the ScrollPanel -> **true** 
2. Objects do not go beyond scrollbar -> **true** 
3. Correct сhange the ScrollPanel to fit the screen (resizing): *more* -> **true**, *less* -> **true**, *width* -> **true**, *height* -> **true** 
4. Correct scrolling and display of objects -> **true** 

#### <li id="node-13"><a href="#ref-1">↩</a> TextBox

1. Correct display of the TextBox -> **not all**
2. Objects do not go beyond TextBox -> **false**
3. Support for text editing -> **not all**
4. Ability to set cursor on the desired position -> **false** 
5. Hotkey support -> **not all**
6. Support of another language -> **false** 
8. The correct сhange the TextBox to fit the screen (resizing): *more* -> **true**, *less* -> **true**, *width* -> **true**, *height* -> **true** 

#### <li id="node-14"><a href="#ref-1">↩</a> TextArea

1. Correct display of the TextArea -> **not all**
2. Objects do not go beyond TextArea -> **false**
3. Support for text editing -> **not all**
4. Ability to set cursor on the desired position -> **false**
5. Hotkey support -> **not all**
6. Correct text scrolling -> **false**
7. Correct сhange the TextArea to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
8. Ability to scroll the text -> **false**


#### <li id="node-15"><a href="#ref-1">↩</a> ColorChooser

1. Correct display of the ColorChooser -> **false**
2. Correct сhange the ColorChooser to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
3. Correct color storage -> **false**
4. Possibility of transferring color information to another block -> **false**

#### <li id="node-16"><a href="#ref-1">↩</a> PasswordField

1. Correct display of the PasswordField -> **false**
2. Configurable minimum and maximum password lengths -> **false**
3. Ability to hide the password when typing -> **false**
4. Ability to show password when typing -> **false**
5. Inability to set a blank password -> **false**
6. Correct сhange the PasswordField to fit the screen (resizing): *more* -> **false**, *less* -> **false**, *width* -> **false**, *height* -> **false** 
 


