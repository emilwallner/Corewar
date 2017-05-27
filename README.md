<img src="https://cdn.rawgit.com/emilwallner/Corewar/master/images/corewarlogo.svg" width="100%">

---

**Core War was inspired by a malicious virus written in the 80’s.** To deal with the self-replicating virus, a white hat hacker invented Reaper. It was a virus designed to spread and eliminate the malware. He fought fire with fire.

This inspired A. K. Dewdney to coin the idea for Core War.

The idea was simple. You compete by designing viruses to overtake a computer. You win by protecting your own program and overwriting your opponent's programs. This is all happening on a virtual computer. Think, a simple computer within your computer. 

This is what is looks like in action:

![Alt text](http://g.recordit.co/pyyAggYcWm.gif "Optional title")

Let’s focus on the high-level game dynamics: 

- **The game board**, the memory of our virtual computer. It’s represented in a 64 X 64 grid of bytes.
- **The players**, small programs represented in different colors. The white parts have blank memory.
- **Cursors**, the moving parts with inverted color. They read from the game board. 

The cursors have a couple of features. They can jump on the game board, store and write values, and clone themselves. The cursors belong to no-one, they just read from the game board.

When the game starts, all players have one cursor at the beginning of their program. The game advances as the cursors read the commands stored in their programs. If they end up on a faulty command or a blank memory, it moves to the next byte. 

Below, we see how the pink player starts by cloning their cursors. It then starts attacking the blue player.

![Alt text](http://g.recordit.co/Y9r9E78FVY.gif "Optional title")

Let’s get into a little bit more depth. 

Every byte you see, the pairs of numbers or letters, are represented in hexadecimal. Each hexadecimal has the value of a digit, from 0 - 255. 

There are 16 operations in the game. The operations decide if the cursor should jump to a different address, clone itself and so on. The first 16 hexadecimal are **coding bytes**, they all store a different operation. The remaining digits, 17 - 255, are regular numbers. 

The coding byte decides which operation to execute and how many bytes to read. In the image above, the pink player goes to the hexadecimal **0c**. It's 12 in decimal, telling the cursor to clone itself. The two bytes after decide where the cloned cursor starts. 

![Alt text](http://g.recordit.co/XQdhVmqvrV.gif "Optional title")

There are three main components to determine who wins: 

- **Game rounds**, every game round is measured in cycles. It determines how much each cursor can read from the game board. 
- **Lives**, if a cursor reads a player life from the game board, they are given a life for that round. These are visualized in the colorful progress bars. 
- **Cycle to die**, for every game round, the number of bytes a cursor can read from the game board is reduced.

You win if your program is the last one to receive a life. 

There are more nuances to the game that I don’t cover. The best way to learn about them is to run it with the below code.  

<br>
<br>

## Executing Core War

Open your terminal and make it full-screen, copy paste the below, and hit enter.

```shell
git clone https://github.com/emilwallner/Core-War.git ; cd Core-War ; make ; ./corewar -visual ./Players/Compiled/bigzork.cor ./Players/Compiled/fluttershy.cor ./Players/Compiled/turtle.cor ./Players/Compiled/helltrain.cor
```
Once the cycle to die reaches 0, it will announce a winner. Then you can press any key to leave the program.

The usage for the Core War game: 

```
Usage:
 	Example: ./corewar -visual -n -1 filename.cor
 	GUI: ./corewar -visual [Players]
 	Default Player Numbers: 1, 2, 3, 4...
 	Change Player Number: -n -1 filename.cor
 	Dump: ./corewar -dump 300 [Players](prints the memory after 300 cycles)
 	Game on! 👾 🤖 🔫
```
If you want to create and then compile players, use the asm: 

```
Usage : 
  ./asm [filename.s]
```

<br>
<br>


## Technical Implementation Overview

I did Core War with three friends: @mhza, @Natansab, and @tlenglin. 

The Core War consists of players that are written in assembly, a compiler to turn them into binary, and the virtual computer to run the programs on. 

I focussed on the main architecture of the virtual machine (VM), the game dynamics, implementing three operations, handling the cursors and implementing the graphical user interface (GUI).  

The program is written using read, open, write, malloc, free and exit from **stdlib.h**. We used the **ncurses** library to create the GUI.  

This is an example of a simple player, a normal player has around 150 lines of assembly code:


```assembly
    .name "zork"
    .comment "I'M ALIIIIVE"
    
    l2:          sti r1,%:live,%1
                 and r1,%0,r1
    
    live:        live %1
                 zjmp %:live
```

This is complied to binary which is later represented in hexadecimal. The above programs looks like this when it’s compiled: 

```binary
    0000000 00 ea 83 f3 7a 6f 72 6b 00 00 00 00 00 00 00 00
    0000010 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    *
    0000080 00 00 00 00 00 00 00 00 00 00 00 17 49 27 4d 20
    0000090 41 4c 49 49 49 49 56 45 00 00 00 00 00 00 00 00
    00000a0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    *
    0000890 0b 68 01 00 0f 00 01 06 64 01 00 00 00 00 01 01
    00008a0 00 00 00 01 09 ff fb
```

The first part includes an identification code and the name, followed by the comment, and ending with the program which will be stored in the memory of the virtual machine. 

<br>
<br>

## My Technical Implementation

As I mentioned earlier, I focussed on the main architecture of the virtual machine, the game dynamics, implementing three hexadecimal operations, handling the cursors and the GUI.  

This is the main I created for the VM:

```C
    int                        main(int ac, char **av)
    {
            t_env e;
    
            if (ac == 1)
                    ft_error_usage();
            init_e(&e, av);
            ft_parse_flags(&e, ac, av);
            ft_files_to_string(&e);
            init_players(&e);
            ft_parsing(&e);
            ft_build_arena(&e);
            ft_init_cursor(&e);
            ft_move_cursors(&e);
            ft_declare_winner(&e);
            ft_exit(&e, 0);
            return (0);
    }
```
It should give you a rough understanding of the main logic. We parse the flags entered in the terminal, turn the files into strings, initiate the players; parse the player data, set up the memory for the VM, initiate the cursors, run the game, declare the winners, and free the data.   

Below is the main struct and it gives you a rough idea what’s going on. 

```C
    typedef struct                s_env
    {
            t_player        player[MAX_PLAYERS + 1];
            t_cursor        *head;
            t_arena         a[MEM_SIZE];
            int             cursors;
            int             dump;
            int             dump_value;
            int             cycle;
            int             tot_cycle;
            int             lives;
            int             check;
            int             bonus;
            int             winner;
            int             last_alive;
            int             cycles_to_die;
            char            arena[MEM_SIZE];
            int             player_amount;
            char            **files;
            t_op            p_tab[17];
    }                             t_env;
```
The game board, the memory of the virtual machine, is stored in a static struct array, **t_arena**. It could have been an int array, but this enabled more flexibility to mange the GUI.  

The cursor are stored in a doubly linked list, it’s circular, and has an extra node to keep track of the beginning of the list. Every time a cursor reads the coding byte to clone itself, it adds a new cursor in the end of the list. The core structure performed well up to 10M cursors. 

I choose a function pointer to handle the 16 operations mentioned in the first section. This allowed us to easily work on different functions and access them when necessary. 

```C
    static void (*g_func_ptr[17])(t_env *e, t_cursor *cursor) =
    {
            ft_live, ft_live, ft_ld, ft_st, ft_add, ft_sub, ft_and, ft_or,
            ft_xor, ft_zjmp, ft_ldi, ft_sti, ft_fork, ft_lld, ft_lldi,
            ft_lfork, ft_aff
    };
```
That’s it for me. If you have any questions or find and issues with the game, ping me an email. 
