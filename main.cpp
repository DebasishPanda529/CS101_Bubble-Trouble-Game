#include <simplecpp>
#include <cmath>
#include "shooter.h"
#include "bubble.h"

/* Simulation Vars */
const double STEP_TIME = 0.02;

/* Game Vars */
const int LEFT_MARGIN = 70;
const int RIGHT_MARGIN = 400;
const int TOP_MARGIN = 25;
const int BOTTOM_MARGIN = (PLAY_Y_HEIGHT+TOP_MARGIN);


void move_bullets(vector<Bullet> &bullets){
    // move all bullets
    for(unsigned int i=0; i<bullets.size(); i++){
        if(!bullets[i].nextStep(STEP_TIME)){
            bullets.erase(bullets.begin()+i);  //this line deletes those buubles which go out of the screen's range
        }
    }
}

void move_bubbles(vector<Bubble> &bubbles){
    // move all bubbles
    for (unsigned int i=0; i < bubbles.size(); i++)
    {
        bubbles[i].nextStep(STEP_TIME);
    }
}

vector<Bubble> create_bubbles()
{
    // create initial bubbles in the game
    vector<Bubble> bubbles;
    bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX, 0, COLOR(255,105,180), 1.50*GRAVITY_DEFAULT));
    bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, 0, COLOR(255,105,180), 1.50*GRAVITY_DEFAULT));
    return bubbles;   // creates only two bubbles in the screen for level 1 game
}


void move_bubbles_1(vector<Bubble> &bubbles_1){
    // move all bubbles
    for (unsigned int i=0; i < bubbles_1.size(); i++)
    {
        bubbles_1[i].nextStep_1(STEP_TIME);
    }
}

vector<Bubble> create_bubbles_1()
{
    // create initial bubbles in the game for level 2
    vector<Bubble> bubbles_1;
    bubbles_1.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, 1.25*BUBBLE_DEFAULT_RADIUS, -2*BUBBLE_DEFAULT_VX, 0, COLOR(255,60,120), 2.50*GRAVITY_DEFAULT));
    bubbles_1.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, 1.25*BUBBLE_DEFAULT_RADIUS, 2*BUBBLE_DEFAULT_VX, 0, COLOR(255,60,120), 2.50*GRAVITY_DEFAULT));
    bubbles_1.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, 1.25*BUBBLE_DEFAULT_RADIUS, 2*BUBBLE_DEFAULT_VX, 0, COLOR(255,60,120), 2.50*GRAVITY_DEFAULT));
    bubbles_1.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, 1.25*BUBBLE_DEFAULT_RADIUS, -2*BUBBLE_DEFAULT_VX, 0, COLOR(255,60,120), 2.50*GRAVITY_DEFAULT));
    return bubbles_1;   // creates four bubbles in the screen for level 1 game
}


void move_bubbles_2(vector<Bubble> &bubbles_2){
    // move all bubbles
    for (unsigned int i=0; i < bubbles_2.size(); i++)
    {
        bubbles_2[i].nextStep_2(STEP_TIME);
    }
}

vector<Bubble> create_bubbles_2()
{
    // create initial bubbles in the game for level 3
    vector<Bubble> bubbles_2;
    bubbles_2.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, 1.50*BUBBLE_DEFAULT_RADIUS, -3*BUBBLE_DEFAULT_VX, 0, COLOR(200,150,90), 4*GRAVITY_DEFAULT));
    bubbles_2.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, 1.50*BUBBLE_DEFAULT_RADIUS, 3*BUBBLE_DEFAULT_VX, 0, COLOR(200,150,90), 4*GRAVITY_DEFAULT));
    bubbles_2.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, 1.50*BUBBLE_DEFAULT_RADIUS, 3*BUBBLE_DEFAULT_VX, 0, COLOR(200,150,90), 4*GRAVITY_DEFAULT));
    bubbles_2.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, 1.50*BUBBLE_DEFAULT_RADIUS, -3*BUBBLE_DEFAULT_VX, 0, COLOR(200,150,90), 4*GRAVITY_DEFAULT));
    bubbles_2.push_back(Bubble(3*WINDOW_X/4.0, BUBBLE_START_Y, 1.50*BUBBLE_DEFAULT_RADIUS, -2*BUBBLE_DEFAULT_VX, 0, COLOR(200,150,90), 4*GRAVITY_DEFAULT));
    bubbles_2.push_back(Bubble(3*WINDOW_X/4.0, BUBBLE_START_Y, 1.50*BUBBLE_DEFAULT_RADIUS, 2*BUBBLE_DEFAULT_VX, 0, COLOR(200,150,90), 4*GRAVITY_DEFAULT));
    return bubbles_2;   // creates six bubbles in the screen for level 1 game
}


int main()
{
    initCanvas("Bubble Trouble", WINDOW_X, WINDOW_Y);

    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
    b1.setColor(COLOR(0, 0, 255));

    string msg_cmd("Cmd: _");
    Text charPressed(LEFT_MARGIN, BOTTOM_MARGIN, msg_cmd);

    string score_cmd("Score: ");
    Text scoreEarned(RIGHT_MARGIN, BOTTOM_MARGIN, score_cmd);

    string timer_cmd("Timer: ");
    Text timeTaken(TOP_MARGIN, 30, timer_cmd);

    string health_cmd("Health: ");
    Text health(RIGHT_MARGIN, 30, health_cmd);

    string health_level_cmd("  / 5");
    Text healthLevel(RIGHT_MARGIN+45, 30, health_level_cmd);

    // Intialize the shooter
    Shooter shooter(SHOOTER_START_X, SHOOTER_START_Y, SHOOTER_VX);

    // Initialize the bubbles
    vector<Bubble> bubbles = create_bubbles();

    // Initialize the bullets (empty)
    vector<Bullet> bullets;

    int a=0, n=0;

    int health_level=5;

    bool check_time_over_1=false;   // variables to keep track of time out condition at each level of game
    bool check_time_over_2=false;
    bool check_time_over_3=false;

    bool check_bubbles_shot=false;  // checks whether all bubbles have been shot

    while(true){
     Text Level1_start(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "Level 1!");
     Level1_start.setColor(COLOR(90,255,80));
     wait(3);
     break;
    }

    XEvent event;

    // Main game loop  ----------------------------------------------------------------------------
    while (true)
    {

        a+=4;
        Text timer_1(TOP_MARGIN+30, 30, 1+(a/100));

        if((1+(a/100))==50) check_time_over_1 = true;

        Text time_l1(TOP_MARGIN+50, 30, " / 50");
        time_l1.imprint();

        Text levelNumber(WINDOW_X/2.0, BOTTOM_MARGIN, "Level: 1/3");
        levelNumber.imprint();

        bool pendingEvent = checkEvent(event);
        if (pendingEvent)
        {
            // Get the key pressed
            char c = charFromEvent(event);
            msg_cmd[msg_cmd.length() - 1] = c;
            charPressed.setMessage(msg_cmd);

            // Update the shooter
            if(c == 'a')
                shooter.move(STEP_TIME, true);
            else if(c == 'd')
                shooter.move(STEP_TIME, false);
            else if(c == 'w')
                bullets.push_back(shooter.shoot());
            else if(c == 'q')
                return 0;
        }

        // Update the bubbles
        move_bubbles(bubbles);

        // Update the bullets
        move_bullets(bullets);

        // Loop to check if bullet hits the bubble
        for(unsigned int i=0; i<bullets.size(); i++){

           for(unsigned int j=0; j<bubbles.size(); j++){

             if( (abs(bullets[i].get_center_x() - bubbles[j].get_center_x()) <= (bullets[i].get_width())*0.50 + bubbles[j].get_radius())
                 &&
                 (abs(bullets[i].get_center_y() - bubbles[j].get_center_y()) <= (bullets[i].get_height())*0.50 + bubbles[j].get_radius()) ) {

                  bullets.erase(bullets.begin()+i);                    // erase the bullets and bubbles upon collision
                  bubbles.erase(bubbles.begin()+j);
                  n++;

               }
            }
         }

    Text score(425, BOTTOM_MARGIN, n);

    if(n==2) {check_bubbles_shot = true;}

      // Loop to check if bubble hits shooter
      for(unsigned int i=0; i<bubbles.size(); i++){

          double center_distance;
          center_distance = sqrt( pow((bubbles[i].get_center_x() - shooter.get_head_center_x()),2) + pow((bubbles[i].get_center_y() - shooter.get_head_center_y()),2) );

          if( ( (abs(bubbles[i].get_center_y() - shooter.get_body_center_y()) <= (shooter.get_body_height())/2.0)
               &&
              (abs(bubbles[i].get_center_x() - shooter.get_body_center_x()) <= (shooter.get_body_width())/2.0) )
              ||
              (center_distance <= bubbles[i].get_radius() + shooter.get_head_radius()) ) {

               double v_x = bubbles[i].get_vx();
               bubbles[i].vx = -v_x;
               health_level--;                          // update the health level upon collision of bubble with shooter

              }
           }

      Text healthLevel_current(RIGHT_MARGIN+30, 30, health_level);
      healthLevel_current.imprint();

      if(health_level == 0) {

        while(true){
        Text shooter_death(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "Shooter dead!");
        shooter_death.setColor(COLOR(90,255,80));
        wait(2);
        Text lost_game(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "You lost the game!");
        lost_game.setColor(COLOR(90,255,80));
        wait(2);
        break;
        }

        break;}  // ends the game if shooter is dead

      if(check_time_over_1 == true) {

        while(true){
        Text time_out(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "Time out!");
        time_out.setColor(COLOR(90,255,80));
        wait(2);
        Text lost_game(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "You lost the game!");
        lost_game.setColor(COLOR(90,255,80));
        wait(2);
        break;
        }

       break;}  // ends the game if we run out of time

      if(check_bubbles_shot==true && health_level>=1){

        for(unsigned int j=0; j<bullets.size(); j++) {
        bullets.erase(bullets.begin()+j);
        }

      wait(3);
      break;

     }

        wait(STEP_TIME);
     }   //Level 1 game loop ends ------------------------------------------------------------------------------------


     if(check_bubbles_shot==true && health_level>=1 && check_time_over_1==false) {

    while(true){
    Text Level2_start(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "Level 2!");
    Level2_start.setColor(COLOR(255,80,90));
    wait(3);
    break;
    }

    Line l1(0, BAR_HEIGHT, BAR_LENGTH, BAR_HEIGHT);
    l1.setColor(COLOR(0,255,0));

    Line l2(4*BAR_LENGTH, 3*BAR_HEIGHT, WINDOW_X, 3*BAR_HEIGHT);
    l2.setColor(COLOR(0,255,0));

    // Initialize bubbles for level 2
    vector<Bubble> bubbles_1 = create_bubbles_1();

    a=0;

    bool check_bubbles_shot=false;  // checks whether all bubbles have been shot

    XEvent event;

    // Main game loop
    while (true)
    {

        a+=4;
        Text timer_1(TOP_MARGIN+30, 30, 1+(a/100));

        if((1+(a/100))==40) check_time_over_2 = true;

        Text time_l2(TOP_MARGIN+50, 30, " / 40");
        time_l2.imprint();

        Text levelNumber(WINDOW_X/2.0, BOTTOM_MARGIN, "Level: 2/3");
        levelNumber.imprint();

        bool pendingEvent = checkEvent(event);
        if (pendingEvent)
        {
            // Get the key pressed
            char c = charFromEvent(event);
            msg_cmd[msg_cmd.length() - 1] = c;
            charPressed.setMessage(msg_cmd);

            // Update the shooter
            if(c == 'a')
                shooter.move(STEP_TIME, true);
            else if(c == 'd')
                shooter.move(STEP_TIME, false);
            else if(c == 'w')
                bullets.push_back(shooter.shoot());
            else if(c == 'q')
                return 0;
        }

        // Update the bubbles
        move_bubbles_1(bubbles_1);

        // Update the bullets
        move_bullets(bullets);

        for(unsigned int i=0; i<bullets.size(); i++){     // erase the bullets which hit the bars

        if((bullets[i].get_center_x() <= BAR_LENGTH && bullets[i].get_center_y() <= (BAR_HEIGHT + bullets[i].get_height()*0.50))
           ||
           (bullets[i].get_center_x() >= 4*BAR_LENGTH && bullets[i].get_center_y() <= (3*BAR_HEIGHT + bullets[i].get_height()*0.50)))
          {

           bullets.erase(bullets.begin()+i);

           }

        }

          // Loop to check if bullet hits the bubble
        for(unsigned int i=0; i<bullets.size(); i++){

           for(unsigned int j=0; j<bubbles_1.size(); j++){

             if( (abs(bullets[i].get_center_x() - bubbles_1[j].get_center_x()) <= (bullets[i].get_width())*0.50 + bubbles_1[j].get_radius())
                 &&
                 (abs(bullets[i].get_center_y() - bubbles_1[j].get_center_y()) <= (bullets[i].get_height())*0.50 + bubbles_1[j].get_radius()) ) {

                  bullets.erase(bullets.begin()+i);                // erase the bubbles and bullets upon collision
                  bubbles_1.erase(bubbles_1.begin()+j);
                  n++;

               }
            }
         }

     Text score(425, BOTTOM_MARGIN, n);

     if(n==6) {check_bubbles_shot=true;}

       // Loop to check if bubble hits shooter
      for(unsigned int i=0; i<bubbles_1.size(); i++){

          double center_distance;
          center_distance = sqrt( pow((bubbles_1[i].get_center_x() - shooter.get_head_center_x()),2) + pow((bubbles_1[i].get_center_y() - shooter.get_head_center_y()),2) );

          if( ( (abs(bubbles_1[i].get_center_y() - shooter.get_body_center_y()) <= (shooter.get_body_height())/2.0)
               &&
              (abs(bubbles_1[i].get_center_x() - shooter.get_body_center_x()) <= (shooter.get_body_width())/2.0) )
              ||
              (center_distance <= bubbles_1[i].get_radius() + shooter.get_head_radius()) ) {

              double v_x = bubbles_1[i].get_vx();
              bubbles_1[i].vx = -v_x;
              health_level--;                        // update the health level of the shooter

              }
           }

     Text healthLevel_current(RIGHT_MARGIN+30, 30, health_level);
     healthLevel_current.imprint();

     if(health_level == 0) {

        while(true){
        Text shooter_death(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "Shooter dead!");
        shooter_death.setColor(COLOR(255,80,90));
        wait(2);
        Text lost_game(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "You lost the game!");
        lost_game.setColor(COLOR(255,80,90));
        wait(2);
        break;
        }

      break;}  // ends the game if shooter is dead

     if(check_time_over_2 == true) {

        while(true){
        Text time_out(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "Time out!");
        time_out.setColor(COLOR(255,80,90));
        wait(2);
        Text lost_game(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "You lost the game!");
        lost_game.setColor(COLOR(255,80,90));
        wait(2);
        break;
        }

     break;}  // ends the game if we run out of time

      if(check_bubbles_shot==true && health_level>=1){

        for(unsigned int j=0; j<bullets.size(); j++) {
        bullets.erase(bullets.begin()+j);                   // erase the bullets upon collision with obstacles
        }

      wait(3);
      break;

     }

      wait(STEP_TIME);

     }  // Level 2 game ends

   }   // ------------------------------------------------------------------------------------------------

     if(check_bubbles_shot==true && health_level>=1 && check_time_over_2==false) {

    while(true){
    Text Level3_start(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "Level 3!");
    Level3_start.setColor(COLOR(80,90,255));
    wait(3);
    break;
    }

    Line l1(0, BAR_HEIGHT, BAR_LENGTH, BAR_HEIGHT);
    l1.setColor(COLOR(255,0,0));

    Line l2(0, 3*BAR_HEIGHT, BAR_LENGTH, 3*BAR_HEIGHT);
    l2.setColor(COLOR(255,0,0));

    Line l3(4*BAR_LENGTH, 2*BAR_HEIGHT, WINDOW_X, 2*BAR_HEIGHT);
    l3.setColor(COLOR(255,0,0));

    // Initialize bubbles for level 2
    vector<Bubble> bubbles_2 = create_bubbles_2();

    a=0;

    bool check_bubbles_shot=false;  // checks whether all bubbles have been shot

    XEvent event;

    // Main game loop
    while (true)
    {

        a+=4;
        Text timer_1(TOP_MARGIN+30, 30, 1+(a/100));

        if((1+(a/100))==30) check_time_over_3 = true;

        Text time_l3(TOP_MARGIN+50, 30, " / 30");
        time_l3.imprint();

        Text levelNumber(WINDOW_X/2.0, BOTTOM_MARGIN, "Level: 3/3");
        levelNumber.imprint();

        bool pendingEvent = checkEvent(event);
        if (pendingEvent)
        {
            // Get the key pressed
            char c = charFromEvent(event);
            msg_cmd[msg_cmd.length() - 1] = c;
            charPressed.setMessage(msg_cmd);

            // Update the shooter
            if(c == 'a')
                shooter.move(STEP_TIME, true);
            else if(c == 'd')
                shooter.move(STEP_TIME, false);
            else if(c == 'w')
                bullets.push_back(shooter.shoot());
            else if(c == 'q')
                return 0;
        }

        // Update the bubbles
        move_bubbles_2(bubbles_2);

        // Update the bullets
        move_bullets(bullets);

        for(unsigned int i=0; i<bullets.size(); i++){    // erase the bullets which hit the bars

        if((bullets[i].get_center_x() <= BAR_LENGTH && bullets[i].get_center_y() <= (3*BAR_HEIGHT + bullets[i].get_height()*0.50))
           ||
           (bullets[i].get_center_x() >= 4*BAR_LENGTH && bullets[i].get_center_y() <= (2*BAR_HEIGHT + bullets[i].get_height()*0.50)))
          {

           bullets.erase(bullets.begin()+i);             // erase the bullets if they hit the obstacles

           }

        }


          // Loop to check if bullet hits the bubble
        for(unsigned int i=0; i<bullets.size(); i++){

           for(unsigned int j=0; j<bubbles_2.size(); j++){

             if( (abs(bullets[i].get_center_x() - bubbles_2[j].get_center_x()) <= (bullets[i].get_width())*0.50 + bubbles_2[j].get_radius())
                 &&
                 (abs(bullets[i].get_center_y() - bubbles_2[j].get_center_y()) <= (bullets[i].get_height())*0.50 + bubbles_2[j].get_radius()) ) {

                  bullets.erase(bullets.begin()+i);
                  bubbles_2.erase(bubbles_2.begin()+j);                  // erase the bubbles and bullets upon collision
                  n++;

               }
            }
         }

     Text score(425, BOTTOM_MARGIN, n);

     if(n==12) {check_bubbles_shot=true;}

       // Loop to check if bubble hits shooter
      for(unsigned int i=0; i<bubbles_2.size(); i++){

          double center_distance;
          center_distance = sqrt( pow((bubbles_2[i].get_center_x() - shooter.get_head_center_x()),2) + pow((bubbles_2[i].get_center_y() - shooter.get_head_center_y()),2) );

          if( ( (abs(bubbles_2[i].get_center_y() - shooter.get_body_center_y()) <= (shooter.get_body_height())/2.0)
               &&
              (abs(bubbles_2[i].get_center_x() - shooter.get_body_center_x()) <= (shooter.get_body_width())/2.0) )
              ||
              (center_distance <= bubbles_2[i].get_radius() + shooter.get_head_radius()) ) {

              double v_x = bubbles_2[i].get_vx();
              bubbles_2[i].vx = -v_x;
              health_level--;                   // update the health level of the shooter upon collision with bubbles

              }
           }

     Text healthLevel_current(RIGHT_MARGIN+30, 30, health_level);
     healthLevel_current.imprint();

     if(health_level == 0) {

        while(true){
        Text shooter_death(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "Shooter dead!");
        shooter_death.setColor(COLOR(80,90,255));
        wait(2);
        Text lost_game(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "You lost the game!");
        lost_game.setColor(COLOR(80,90,255));
        wait(2);
        break;
        }

      break;}  // ends the game if shooter is dead

     if(check_time_over_3 == true) {

         while(true){
        Text time_out(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "Time out!");
        time_out.setColor(COLOR(80,90,255));
        wait(2);
        Text lost_game(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "You lost the game!");
        lost_game.setColor(COLOR(80,90,255));
        wait(2);
        break;
        }

      break;}  // ends the game if we run out of time

      if(check_bubbles_shot==true && health_level>=1){

        for(unsigned int j=0; j<bullets.size(); j++) {
        bullets.erase(bullets.begin()+j);
        }

      while(true){

      Text win_game(WINDOW_X/2.0, PLAY_Y_HEIGHT/2.0, "You won the game!");
      win_game.setColor(COLOR(80,90,255));
      wait(3);
      break;
      }

      break;

     }

      wait(STEP_TIME);

     }  // Level 3 game ends

   }  // ---------------------------------------------------------------------------------------------

}
