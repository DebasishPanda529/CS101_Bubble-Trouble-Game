#include <simplecpp>

/* Bubble Vars */
const int BUBBLE_START_X = 250;
const int BUBBLE_START_Y = 50;
const int BUBBLE_DEFAULT_RADIUS = 10;
const int BUBBLE_RADIUS_THRESHOLD = 10;
const int BUBBLE_DEFAULT_VX = 200;
const int BUBBLE_DEFAULT_VY = 0;
const int GRAVITY_DEFAULT = 10;

// Variables to get co-ordinates of bubble hit by bullets
int bubble_center_x=0, bubble_center_y=0;

class Bubble
{
private:
    Circle circle;  // the circle representing the bubble
    double vy,gravity;  // velocity in y direction
    Color color;    // color of the bubble

public:
    double vx;   // velocity in x direction, had to change to private in order to ensure bouncing when bubble hits shooter

    Bubble(double cx, double cy, double r, double vx_=BUBBLE_DEFAULT_VX, double vy_=BUBBLE_DEFAULT_VY, Color color_=COLOR(0, 0, 255), double g_value=GRAVITY_DEFAULT)
    {
        // Bubble constructor
        color = color_;
        circle = Circle(cx, cy, r);
        circle.setColor(color);
        circle.setFill(true);

        vx = vx_;
        vy = vy_;
        gravity = g_value;
    }

    void nextStep(double t)
    {
        // move the bubble
        vy = vy + gravity*t;  //takes into account gravity factor
        double new_x = circle.getX() + vx*t;
        double new_y = circle.getY() + vy*t;

        if ((vx < 0 && new_x < (0 + circle.getRadius())) // bounce along X direction at left border
            ||
            (vx > 0 && new_x > (WINDOW_X - circle.getRadius()))) // bounce along X direction at right border
        {

            vx = -vx;
            new_x = circle.getX() + vx*t;

        }

        if (new_y >= PLAY_Y_HEIGHT - circle.getRadius()) {  // bounce along Y direction if bubble touches bottom

        vy = -vy;
        new_y = circle.getY() + vy*t;

        }

        circle.moveTo(new_x, new_y);
    }


    void nextStep_1(double t)
    {
        //move the bubble
        vy = vy + gravity*t;
        double new_x = circle.getX() + vx*t;
        double new_y = circle.getY() + vy*t;

        if ((vx < 0 && new_x < (0 + circle.getRadius())) // bounce along X direction at left border
            ||
            (vx > 0 && new_x > (WINDOW_X - circle.getRadius())))// bounce along X direction at right border
        {

            vx = -vx;
            new_x = circle.getX() + vx*t;

        }

        if ((new_y >= PLAY_Y_HEIGHT - circle.getRadius())  // bounce along Y direction if bubble touches bottom
            ||
            (new_y >= (BAR_HEIGHT - circle.getRadius()) && new_y <= (BAR_HEIGHT + circle.getRadius()) && new_x >= circle.getRadius() && new_x <= BAR_LENGTH)  // bounce along Y direction if bubbles strikes the bars
            ||
            (new_y >= (3*BAR_HEIGHT - circle.getRadius()) && new_y <= (3*BAR_HEIGHT + circle.getRadius()) && new_x >= 4*BAR_LENGTH && new_x <= (WINDOW_X - circle.getRadius()))){

        vy = -vy;
        new_y = circle.getY() + vy*t;

        }

        circle.moveTo(new_x, new_y);

    }


    void nextStep_2(double t)
    {
        //move the bubble
        vy = vy + gravity*t;
        double new_x = circle.getX() + vx*t;
        double new_y = circle.getY() + vy*t;

        if ((vx < 0 && new_x < (0 + circle.getRadius())) // bounce along X direction at left border
            ||
            (vx > 0 && new_x > (WINDOW_X - circle.getRadius())))// bounce along X direction at right border
        {

            vx = -vx;
            new_x = circle.getX() + vx*t;

        }

        if ((new_y >= PLAY_Y_HEIGHT - circle.getRadius())
            ||
            (new_y >= (BAR_HEIGHT - circle.getRadius()) && new_y <= (BAR_HEIGHT + circle.getRadius()) && new_x >= circle.getRadius() && new_x <= BAR_LENGTH)
            ||
            (new_y >= (3*BAR_HEIGHT - circle.getRadius()) && new_y <= (3*BAR_HEIGHT + circle.getRadius()) && new_x >= circle.getRadius() && new_x <= BAR_LENGTH)
            ||
            (new_y >= (2*BAR_HEIGHT - circle.getRadius()) && new_y <= (2*BAR_HEIGHT + circle.getRadius()) && new_x >= 4*BAR_LENGTH && new_x <= (WINDOW_X - circle.getRadius()))){

        vy = -vy;
        new_y = circle.getY() + vy*t;

        }

        circle.moveTo(new_x, new_y);

    }


    double get_radius()
    {
        // return the radius of the bubble
        return circle.getRadius();
    }

    double get_center_x()
    {
        // return the x coordinate of the center of the bubble
        return circle.getX();
    }

    double get_center_y()
    {
        // return the y coordinate of the center of the bubble
        return circle.getY();
    }

    double get_vx()
    {
        // return the x velocity of the bubble
        return vx;
    }
    double get_vy()
    {
        // return the y velocity of the bubble
        return vy;
    }

    Color get_color()
    {
        // return the color of the bubble
        return color;
    }
};
