# Bubble Trouble Game
Features implemented in the Project :-

1. **main.cpp**

   - Two new functions have been written to create the bubbles in levels 2 and 3. Corresponding to them, two new functions have been created to move the bubbles in           levels 2 and 3. The new functions move_bubbles_1 and move_bubbles_2  map to the memeber functions nextStep_1 and nextStep_2 in bubble.h.

   - Different Text outputs have been included to show the beginning of a new level, shooter's death or time out situation. These outputs are transient and disappear        from the screen after 2-3 seconds.

   - A timer has been included in the main.cpp file. The timer for level 1 counts down to 50s, for level 2 40s and for level 3 30s. The timer executes through a for          loop at each game level and its speed has been normalised to account for the large computing speed of the computer using greatest integer function concept.

   - A health counter has been added in the program with 5 health points. The game terminates if health of shooter becomes zero. The health counter is run using the          same loop that checks for a collision between shooter and bubble. The health points are kept track of using an int variable.

   - Loops have been executed in the main.cpp file to check for collision between bubbles + bullets and bubbles + shooter. There are two bubbles in level 1, four in          level 2 and six in level 3.

   - Conditional statements in main.cpp ensure that the game gets terminated whenever we run out of time in any particular level or the shooter is dead.

   - Some const int variables in main_program have been transferred to the shooter.h file due to the need for defining some new const int variables in the shooter.h          file. These new variables are essential to create the obstacles in the game for levels 2 and 3.

2. **bubble.h**
   - The Bubble class has been updated to introduce the effects of gravity and introduce the requird parabolic path in the game.

   - Two new member functions nextStep_1 and nextStep_2 have been added to the Bubble class. These functions add the obstacles in the game in the form of  'bars' which      are implemented by lines. The bubble bounces off the bar if it reaches it and the bullets disappear if they hit the bar. So the shooter's chances of hitting the        bubbles decrease slightly with each game. There are two such bars in level 2 and three such bars in level 3.

   - The speed and number of bubbles increases with increase in the level of the game.
     
3. **shooter.h** and **bullet.h** : No changes in code were made in these programs

Link to the game videos :-
  - All videos link:  [Here](https://drive.google.com/drive/folders/1K9UkRVpEcFqPaWQKiqjdrI1Xoh0veSY9?usp=sharing)
  - Game win:     [Here](https://drive.google.com/file/d/1KVEQAWEMVCCJwilqP4qq8rz0IhVvsZmz/view?usp=sharing) 
  - Game win:     [Here](https://drive.google.com/file/d/17O8HLVwsP-WQN8YLhaizy5miBEDOYBNl/view?usp=sharing)
  - Game lose:    [Here](https://drive.google.com/file/d/1BDOxxyorslx6HYfkvpCKXCqlqPwbhGWg/view?usp=sharing)
