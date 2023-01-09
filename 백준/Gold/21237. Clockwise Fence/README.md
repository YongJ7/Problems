# [Gold V] Clockwise Fence - 21237 

[문제 링크](https://www.acmicpc.net/problem/21237) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

애드 혹(ad_hoc), 너비 우선 탐색(bfs), 기하학(geometry), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 구현(implementation)

### 문제 설명

<p>The fence surrounding Farmer John's largest pasture has fallen into disrepair, and he has finally decided to replace it with a new fence.</p>

<p>Unfortunately, as Farmer John is laying out the new fence, a large bee ends up chasing him around the pasture, and as a result, the fence ends up following a rather irregular path. The fence can be described by a string of characters, each either "N" (north), "E" (east), "S" (south), or "W" (west). Each character describes a 1-meter run of the fence. For example, if the string is NESW, this means the fence starts by moving north for 1 meter, then east for 1 meter, then south for 1 meter, then west for 1 meter, returning to its starting point.</p>

<p>The fence ends at the position where it started, and this is the only point visited more than once by the path of the fence (and the starting point is only re-visited once, at the end). As a result, the fence does indeed enclose a single connected region of the grassy pasture, even though this region could have a rather strange shape.</p>

<p>Farmer John is curious if the path in which he laid the fence traveled clockwise (with the enclosed region on the right side of the fence as one walks along the path of the fence in the order specified by the string) or counter-clockwise (with the enclosed region on the left side of the fence).</p>

### 입력 

 <p>The first line of input contains an integer <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>20</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \leq N \leq 20$</span></mjx-container>). Each of the next <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> lines contains a string of length at least 4 and at most 100, describing a single fence path.</p>

### 출력 

 <p>For each of the <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> fence paths described in the input, output a line containing either "CW" (clockwise) or "CCW" (counterclockwise).</p>

