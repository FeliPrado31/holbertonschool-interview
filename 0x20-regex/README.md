<h1 class="gap">0x20. RegEx</h1>

<h2 class="gap">Tasks</h2>

<div data-role="task3787" data-position="1" id="task-num-0">
        <div class="panel panel-default task-card " id="task-3787">
  <span id="user_id" data-id="1283"></span>

  <div class="panel-heading">
    <h3 class="panel-title">
      0. Simple RegEx
    </h3>

  </div>

  <div class="panel-body">
    <span id="user_id" data-id="1283"></span>

<!-- Task Body -->
<p>Write a function that checks whether a given pattern matches a given string.</p>

<ul>
<li>Prototype: <code>int regex_match(char const *str, char const *pattern);</code>, where:

<ul>
<li><code>str</code> is the string to scan</li>
<li><code>pattern</code> is the regular expression</li>
</ul></li>
<li>Your function must return <code>1</code> if the pattern matches the string, or <code>0</code> if it doesn’t</li>
<li><code>str</code> can be empty, and can contain any ASCII character in the exception of <code>.</code> and <code>*</code></li>
<li><code>pattern</code> can be empty, and can contain any ASCII character, including <code>.</code> and <code>*</code></li>
<li>The regular expression matching must support the characters <code>.</code> and <code>*</code>

<ul>
<li><code>.</code> matches any single character</li>
<li><code>*</code> matches zero or more of the preceding character</li>
</ul></li>
</ul>

<pre><code>alex@~/holbertonschool-interview_prep/0x20-regex$ cat main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;

#include "regex.h"

#define TEST_MATCH(s, p)    do {\
    {\
        int res = regex_match(s, p);\
        printf("%s -&gt; %s = %d\n", s, p, res);\
    }\
} while(0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    TEST_MATCH("H", "H");
    TEST_MATCH("HH", "H");
    TEST_MATCH("HH", "H*");
    TEST_MATCH("HHHHHHHHHHHHHHHHH", "H*");

    TEST_MATCH("Holberton", ".*");
    TEST_MATCH("Alex", ".*");
    TEST_MATCH("Guillaume", ".*");
    TEST_MATCH("Julien", ".*");

    TEST_MATCH("Holberton", "Z*H.*");
    TEST_MATCH("Holberton", "Z*H.*olberton");
    TEST_MATCH("Holberton", "Z*H.*o.");
    TEST_MATCH("Holberton", "Z*H.*o");

    TEST_MATCH("Holberton", "holberton");
    TEST_MATCH("Holberton", ".olberton");

    TEST_MATCH("!H@o#l$b%e^r&amp;t(o)n_", "!.@.#.$.%.^.&amp;.(.)._");

    return (EXIT_SUCCESS);
}
alex@~/holbertonschool-interview_prep/0x20-regex$ gcc -Wall -Wextra -Werror -pedantic main.c regex.c
alex@~/holbertonschool-interview_prep/0x20-regex$ ./a.out
H -&gt; H = 1
HH -&gt; H = 0
HH -&gt; H* = 1
HHHHHHHHHHHHHHHHH -&gt; H* = 1
Holberton -&gt; .* = 1
Alex -&gt; .* = 1
Guillaume -&gt; .* = 1
Julien -&gt; .* = 1
Holberton -&gt; Z*H.* = 1
Holberton -&gt; Z*H.*olberton = 1
Holberton -&gt; Z*H.*o. = 1
Holberton -&gt; Z*H.*o = 0
Holberton -&gt; holberton = 0
Holberton -&gt; .olberton = 1
!H@o#l$b%e^r&amp;t(o)n_ -&gt; !.@.#.$.%.^.&amp;.(.)._ = 1
alex@~/holbertonschool-interview_prep/0x20-regex$
</code></pre>

  </div>

  <div class="list-group">
    <!-- Task URLs -->

<!-- Github information -->
<div class="list-group-item">
<p><strong>Repo:</strong></p>
<ul>
    <li>GitHub repository: <code>holbertonschool-interview</code></li>
    <li>Directory: <code>0x20-regex</code></li>
    <li>File: <code>regex.c, regex.h</code></li>
</ul>
</div>

<!-- Self-paced manual review -->
</div>

<!-- Panel footer - Controls -->
</div>

</div>

</div>

</div>
