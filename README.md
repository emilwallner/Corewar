<img src="https://cdn.rawgit.com/emilwallner/Corewar/master/images/corewarlogo.svg" width="100%">

---

**Core War was inspired by a malicious virus written in the 80’s.** To deal with the self-replicating virus, a white hat hacker invented Reaper. It was a virus designed to spread and eliminate the malware. They fought fire with fire.

This inspired A. K. Dewdney to coin the idea for Core War.

The idea was simple. You compete by designing viruses to overtake a computer. You win by protecting your own program and overwriting your opponent's programs. This is all happening on a virtual computer. Think, a mini computer within a computer. 

This is what is looks like in action:

![Alt text](http://g.recordit.co/pyyAggYcWm.gif "Optional title")

Let’s focus on the high level game dynamics: 

- **The game board**, the memory of our virtual computer. It’s represented in a 64 X 64 grid of bytes.
- **The players**, small programs represented in different colors. The white parts are blank memory.
- **Cursors**, the moving parts with inverted color. They read from the game board. 

The cursors have a couple of features. They can jump in the game board, store and write values, and clone themselves. The cursors belong to no-one, they just read from the game board.

When the game starts, all players have one cursor at the beginning of their program. The game advances as the cursors read the commands stored in their programs. If they end up on a faulty command or a blank memory, it moves to the next byte. 

Below, we see how the pink player starts by cloning their cursors. It then starts attacking the blue player.

![Alt text](http://g.recordit.co/Y9r9E78FVY.gif "Optional title")

Let’s get into a little bit more depth. 

Every byte you see, the pairs of numbers or letters, are represented in hexadecimals. If you don’t know what a hexadecimal is, don’t worry about it. The pairs represent a digit from 0 - 255. 

There are different implementations of Core War. We choose to allow 16 operations. The first 16 hexadecimals are **coding bytes**, they all store a different operation. The remaning digits, 17 - 255, are regular numbers. 

The coding byte decides which operation to execute and how many bytes to read. In the image above, the pink player goes to the hexadecimal **0c**, 12 in decimal, telling the cursor to clone itself. The two bytes after, decide where the cloned cursor starts. 

![Alt text](http://g.recordit.co/XQdhVmqvrV.gif "Optional title")

There are three main components to determine who wins: 

- **Game rounds**, every game round is measured in cycles. It determines how much each cursor can read from the game board. 
- **Lives**, if a cursor reads a player life from the game board, they are given a life for that round. These are visualized in the colorful progress bars. 
- **Cycle to die**, for every game round, the amount of bytes a cursor can read from the game board is reduced. 

You win if your program is the last one to receive a life. 

There are more nuances to the game that I don’t cover. They best way to learn about them is to execute the game in your terminal.  

<br>
<br>
<br>

# Executing Core War

Open your terminal and make it full-screen, copy paste the below, and hit enter.

```git clone https://github.com/emilwallner/Core-War.git ; cd Core-War ; make ; ./corewar -visual ./Players/Compiled/helltrain.cor ./Players/Compiled/bee_gees.cor ./Players/Compiled/turtle.cor ./Players/Compiled/bigzork.cor```






