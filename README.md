<!DOCTYPE html>
<html>
<head>
    <h1 align="center"> Get_next_line</h1>
</head>
<body>
    <h3>Abaut Get next line 'GNL':</h3>
    <p>
        The main idea of ​​this project is understand the concept of static variables.<br>
        'GNL' takes a file descriptor and return a string contains one complete text line (until the next line break ['\n' char]). when use again return the next line, and like this, as many times as we want or until the end of the text. The subject says that we have to use always the same buffersize (chars that can be read each time), and our function can read only one time each time be used, for this reason, we should save the part of line that we read if the function not found the '\n' first time that we used it, or the rest part of the next line if the buffersize is large than first position of '\n'char, for attach it to next line next time that 'GNL' is used...🤯<br><br>
        ...🤔Maby better if I explain you with an example, right?<br>
        If we have the next text in the opened file:
        <img src=".readmedata/1st_img.png">
        And we should to use this time for eample a buffersize of 7, our fuction can't get the first complete line and should save this chars:
        <img src=".readmedata/2nd_img.png">
        <a href="https://github.com/Develoi89/libft_42/blob/main/.readmedata/en.subject.pdf" target="blank" >subject</a>.

    </p>

    <h3>Compiling...⏱️</h3>
    <p>
        For compile the library I use a Makefile
    </p>
    <h3>Grade</h3>
    <p>
        Completed only the mandatory, all free of mem leaks.
    </p>
    <img src=".readmedata/grade.png">
</body>
</html>