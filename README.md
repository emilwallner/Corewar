<img src="https://cdn.rawgit.com/emilwallner/Corewar/master/images/corewarlogo.svg" width="100%">

---

**Core War was inspired by a malicious virus written in the 80’s.** To deal with the self-replicating virus, a white hat hacker invented Reaper. It was a virus designed to spread and eliminate the malware. They fought fire with fire.

This inspired A. K. Dewdney to coin the idea for Core War.

The idea was simple. You compete by designing viruses to overtake a computer. You win by protecting your own program and overwriting your opponent's programs. This is all happening on a virtual computer. Think, a mini computer within a computer. 

This is what is looks like in action:

![Alt text](http://g.recordit.co/pyyAggYcWm.gif "Optional title")

Let’s focus on the high level game dynamics: 

- The game board, the memory of our virtual computer. It’s represented in a 64 X 64 grid of bytes.
- The players, small programs represented in different colors. The white parts are empty memory.
- Cursors, the moving parts with inverted color. They read from the game board. 

The cursors have a couple of features. They can jump in the game board, store and write values, and clone themselves. The cursors belong to no-one, they just read from the game board. 

When the game starts, all players have one cursor at the beginning of their program. The game advances as the cursors read the commands stored in their programs. 

![Alt text](http://g.recordit.co/Y9r9E78FVY.gif "Optional title")
---
![Alt text](http://g.recordit.co/XQdhVmqvrV.gif "Optional title")
---
