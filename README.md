<!DOCTYPE html>
<html>
<head>
    <h1 align="center"> Get_next_line</h1>
</head>
<body>
    <h3>Abaut Get next line 'GNL':</h3>
    <p>
        The main idea of ​​this project is to understand the concept of static variables.<br>
        'GNL' takes a file descriptor and return a string that contains one complete text line (until the next line break ['\n' char]). When used again, it return the next line, and we can use it, as many times as we want or until the end of the text. The subject says that we have to use always the same buffersize (chars that can be read each time), and our function should read as few times as possible each time be used For this reason, we should save the part of line that we read if the function doesn't find the '\n' first time we used it, or the rest part of the next line if the buffersize is larger than first position of '\n'char, for attach it to next line next time that 'GNL' reads...🤯<br><br>
        ...🤔Maby better if I explain it to you with an example, right?<br>
        If we have the next text in the opened file:<br>
        <img src=".readmedata/1st_img.png"><br>
        This time, for example, we have a buffersize of 7, our fuction can't get the first complete line so it should save this chars:<br>
        <img src=".readmedata/2nd_img.png"><br>
        At this point our funtion can't return a complete line so it should read again:<br>
        <img src=".readmedata/3th_img.png"><br>
        And return a line attaching the first that was saved with the last was readed until '\n', and save the two chars that were read from the next line.<br>
        <img src=".readmedata/4th_img.png"><br>
        Now you can execute 'Gnl' as many as you want to get next lines from file.<br>
        You can find the PDF of complete subject <a href="https://github.com/Develoi89/Get_next_line_42/blob/master/.readmedata/en.subject.pdf" target="blank" >here</a>.<br>
    </p>
    <h3>Compiling...⏱️</h3>
    <p>
        To compile the function I use a Makefile, you can modify here BUFFER_SIZE argument, I added too a main and text file to testing that you can modify or substitute your own. 
    </p>
    <h3>Grade</h3>
    <p>
        Completed only the mandatory, all free of mem leaks.
    </p>
    <img src=".readmedata/grade.png">
</body>
</html>