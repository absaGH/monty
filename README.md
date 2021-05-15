<h4> 0x18. C - Stacks, Queues - LIFO, FIFO </h4>
This project is an interpreter for monty script. The interpreter
applys the concept of stack and queue. 
Files containing Monty byte codes usually have the .m extension.
<p><strong>The tasks in the project</strong></p>
<ul>
  <li><b>0. push, pall</b> - add (or push) an element to the stack and print all values in the stack, respectively. </li>
  <li><b>1. pint</b> - prints the value at the top of the stack.</li>
  <li><b>2. pop</b> - removes the top element of the stack.</li>
  <li><b>3. swap</b> - swaps the top two elements of the stack.</li>
  <li><b>4. add</b> - adds the top two elements of the stack.</li>
  <li><b>5. nop</b> - an opcode that does nothing.</li>
  <li><b>6. sub</b> - subtracts the top element of the stack from the second top element of the stack.</li>
  <li><b>7. div</b> - divides the second top element of the stack by the top element of the stack.</li>
  <li><b>8. mul</b> - multiplies the second top element of the stack with the top element of the stack.</li>
  <li><b>9. mod</b> - modulous of the division of the second top element of the stack by the top element of the stack.</li>
  <li><b>10. comments</b> - if the first non-space character of a line is # then it is treated as comment.</li>
  <li><b>11. pchar</b> - prints the char at the top of the stack, followed by a new line.</li>
  <li><b>12. pstr</b> - prints the string starting at the top of the stack, followed by a new line.</li>
  <li><b>13. rotl</b> - rotates the stack to the top.</li>
  <li><b>14. rotr</b> - rotates the stack to the bottom.</li>
  <li><b>15. stack, queue</b> - STACK sets the format of the data to a stack (LIFO). this is the default behavior of the program. QUEUE sets the format of the data to a queue (FIFO).</li>
  <li><b>16. Holberton</b> - a brainf*ck code that prints out <code>Holberton</code>, followed by a new line.</li>
  <li><b>17. Add two digits</b> - a brainf*ck code that prints out the sum of two digits given by the user.</li>
  <li><b>18. Multiplication</b> - a brainf*ck code that prints out two digits given by the user. the result of the multiplication will be one digit-long</li>
  <li><b>19. Multiplication level up</b> - Multiply two digits given by the user.</li>
  </ul>
  <p><strong>How to use the program</strong></p>
  <ul>
  <li><b>Usage:</b> after compiling the source files type <code>monty file</code>. where <code>file</code> is the path to the file containing Monty byte code. Example: <code><b>./monty 00.m</b></code></li>
  <li><b>Errors:</b> depending on the situation the program displays different kind of error messages. here are some of them:
    <ul>
      <li><code>USAGE: monty file</code> - if no file is given or more than one argument to the program.</li>
      <li><code>Error: Can't open file <file></code> - if, for any reason it's not possible to read the file.</li>
      <li><code>L<line_number>: unknown instruction <opcode></code> - if the file contains an invalid instruction.</li>
        <li><code>Error: malloc failed</code> - if you can't malloc anymore.</li>
        <li><code>L<line_number>: usage: push integer</code> - if <code> &lt;int&gt;</code> in <code>push &lt;int&gt;</code> is not an integer or if there is no argument to <code>push</code>.</li>
          <li><code>L<line_number>: can't pop an empty stack</code> - if the stack is empty.</li>
          <li><code>L<line_number>: can't add, stack too short</code> - if the stack is less than two element long.</li>
       </li>
    </ul>
  </ul>
