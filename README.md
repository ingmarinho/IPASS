<h1>IPASS - mlx90615</h1>
<h2>Introduction</h2>
This project/repository contains my final project this year called: IPASS.
<br>
<br>
I've made a covid scanner (in this case also known as the COVID HUNTER) which allows for measuring temperatures on humans from a small distance. During this so called 'pandemic' it's ofcourse of utmost importance we keep distance to make sure we don't spread the virus and that's exactly why I came up with this idea.
<br>
<br>
The COVID HUNTER has 2 scan modes: continuous scanning (with a toggle) & specific scanning. Continous scanning is useful when you are constantly measuring peoples temperatures. Whilst on the other hand specific scanning is more useful when you're not constantly scanning and require more accurate results.

<h2>Libraries used</h2>
This projects makes use of the following 2 libraries:
<a href="https://github.com/wovo/bmptk">bmptk</a>
<a href="https://github.com/wovo/hwlib">hwlib</a>

<h2>Hardware used</h2>
-   The main driver behind this project is the <a href="https://store.arduino.cc/arduino-due">Arduino Due</a>.
<br>
-   The second most important piece of hardware used is the <a href="https://hu-hbo-ict.gitlab.io/turing-lab/ti-lab-shop/sensor-temp-ir-1.html">mlx90615</a>.
<br>
-   The oled used is the <a href="https://hu-hbo-ict.gitlab.io/turing-lab/ti-lab-shop/oled-1.html">ssd1306</a>.
<br>
-   Other than that I've used a very crappy cheap button and a cheap led.

<h2>Author</h2>
<table style="width:100%">

| Name            | Student number | Username      |
| --------------- | -------------- | ------------- |
| Ingmar Fontijne | 1764875        | ingmarinho    |
</table>

<h2>How to install</h2>

<pre style="position: relative;" lang="git"><code>git clone https://github.com/ingmarinho/IPASS.git</code></pre>
<div class="zeroclipboard-container position-absolute right-0 top-0">
    <clipboard-copy aria-label="Copy" class="ClipboardButton btn js-clipboard-copy m-2 p-0 tooltipped-no-delay" data-copy-feedback="Copied!" data-tooltip-direction="w" value="git clone https://github.com/ingmarinho/IPASS.git
" tabindex="0" role="button">
      <svg aria-hidden="true" viewBox="0 0 16 16" version="1.1" data-view-component="true" height="16" width="16" class="octicon octicon-clippy js-clipboard-clippy-icon m-2">
    <path fill-rule="evenodd" d="M5.75 1a.75.75 0 00-.75.75v3c0 .414.336.75.75.75h4.5a.75.75 0 00.75-.75v-3a.75.75 0 00-.75-.75h-4.5zm.75 3V2.5h3V4h-3zm-2.874-.467a.75.75 0 00-.752-1.298A1.75 1.75 0 002 3.75v9.5c0 .966.784 1.75 1.75 1.75h8.5A1.75 1.75 0 0014 13.25v-9.5a1.75 1.75 0 00-.874-1.515.75.75 0 10-.752 1.298.25.25 0 01.126.217v9.5a.25.25 0 01-.25.25h-8.5a.25.25 0 01-.25-.25v-9.5a.25.25 0 01.126-.217z"></path>
</svg>
      <svg aria-hidden="true" viewBox="0 0 16 16" version="1.1" data-view-component="true" height="16" width="16" class="octicon octicon-check js-clipboard-check-icon color-text-success d-none m-2">
    <path fill-rule="evenodd" d="M13.78 4.22a.75.75 0 010 1.06l-7.25 7.25a.75.75 0 01-1.06 0L2.22 9.28a.75.75 0 011.06-1.06L6 10.94l6.72-6.72a.75.75 0 011.06 0z"></path>
</svg>
    </clipboard-copy>
  </div>
  </div>

<h2>Installation</h2>
1. You'll need hwlib.
2. You'll also need bmptk.
3. Include both in the project.
<br>
4. Fill in the Makefile.
5. Execute the '_run.bat'.

<h2>Notes</h2>
Make sure to contact me on discord for any questions relating this project: Ingmar#0001

<h2>License</h2>

Copyright © Ingmar Fontijne (ingmar.fontijne@student.hu.nl), 2021

Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

Note: See license file for a detailed description.
