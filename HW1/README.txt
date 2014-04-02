Name: Josh Bronstein
Homework #1:

Question 1, 2, 3:
Basic setup, nothing complicated and everything ran as expected. I think these all worked correctly from what I see and are built out as expected. Nothing to add.

Question 4:
I struggled a lot with this question and wrote out my thoughts. I think I finally figured out how to approach it. I wanted to make an insertion sort function that sorts two arrays. One array would be the user inputted array and the second would be the dictionary txt file. I wanted to sort them both and store the dictionary sorted values memory location, so I could recall them later, but got significantly messed up with pointers and other issues and then ran out of time. Theoretically, if I sort user's word (able into abel), and all dictionary words (abel to abel, albe to abel…). This should work, I just couldn't figure out the proper way to do this using temporary arrays and memory addresses and ran out of time.

Question 5:
I made a function to compare both chars and words. I thought it would be intelligent to kill two birds with one stone with nested loops, but this escalated quickly and was a nightmare to debug. I still have one remaining bug I can't figure out. The last word of the file doesn't get counted correctly. I think it has to be when I read the file in the main method, but I've played around with those values and nothing seems to do the trick. If you can figure it out I would love to know what I'm missing here.

Question 6: 
The code I had for this program isn't worth submitting. I got very tricked up on this and moved on to the other questions.

Question 7 and 8:
I think my programs work effectively/efficiently here. Just shifting bits around with the idea that 255 is 11111111 in the 4th byte and using that to flip values for 8.

Question 9:
Works effectively, just looked at each char value by value and if I caught something non-numeric or decimal, I stopped the process and returned the appropriate error.

Question 10:
This gave me a surprising headache. I thought the best approach was to copy into a new array the number of zeroes to start with based on the window, then append the values given in the file. This did not work however, I think I need a crash course on Arrays/Pointer Arrays in C because this perfectly summed up my problem. I got it too work by writing a function to operate on one condition (if zeroes were still remaining from the window or not). This is definitely not the fastest way to find averages here, but it works as described in the program. 

Final Notes:

For this HW I struggled a lot with arrays/pointers and although I think I have a far better handle of them now, I'm still very unsure when it comes to copying values and properly checking everything. A huge issue I'm sure is that I don't know how to debug using vim and desperately need a debugger. I think I spent twice as long on this HW as the average student, so I'm fairly concerned right now and would really like to meet with you to go over some concepts and receive any helpful insight. 

As for sources/references, I googled a lot and had to use stack overflow a ton to figure out most of my errors. I used algorithm notes for my insertionSort pseudocode (that doesn't work). I verbatim copied the leap year logic from K&R because I remembered reading it. I worked alongside Andre and Steve for a majority of this assignment and we shared ideas and approaches for these questions.
