## Approximation of Derivative Using Difference Quotient (Task Sheet 1 - Task 6)
[Link to code](../tasks_source/task_sheet_1/task_6/task6.c)

In this code, I used an arbitrary example function of the sine function to calculate derivatives, with an also arbitrary value of 2 to plug in.
This program will not be part of the shared library since it is demonstrating a concept, and for that reason there is a "driver" functionality that is occuring with the main function.

The "example\_function" function is the one that will return the value of the sine function.

The "calculate\_derivative" function is the one that will simply return the value of the central difference that was given in the task sheet.

Inside the main function, we set an initial value of h to be 1. Afterwards, we loop 100 times (just for good measure to get h very small) and calculate the derivative using that small h-value.

As expected, the output gets closer and closer to the real value of the derivative of sine evaluated at 2. (We can check using cosine of 2) Eventually, the approximate derivate starts getting bigger and then eventually goes to a nonsensical answer, where h has surpassed our machine precision limit and we no longer can represent h accurately, which in turn gives the nonsensical answers.

A screenshot of the machine output has been included below.

![Console Output Picture](../images/s1_t6_cmdoutput.png)

As we can see, around the first few iterations, the approximation to the derivative is off by quite a bit. The approximation becomes best around 20 iterations, and then slowly starts to diverge away until eventually becoming unusable around the 53rd iteration. The 21st iteration is where the machine precision starts to affect the output after using the h value in the calculations, and the 53rd iteration is where the h completely disappears out of view due to becoming too small for the double type.
