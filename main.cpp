#include <raylib.h>
#include <raymath.h>


#define SCREEN_HEIGHT 900
#define SCREEN_WIDTH 1800
#define PPM 200                     // How many pixels represent one metre

Vector2 gravity = {0, 9.81};

struct Particle {

    Vector2 pos;
    Vector2 vel;
    float restitution;
    float radius;
    float mass;
    Color colour;

};

struct Wall {

    float friction;

};


int main(){

    // Initialisation
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Window");
    InitAudioDevice();
    SetTargetFPS(60);   

    // Creating objects
    Wall floor;
        floor.friction = 0.15f;

    Particle ball;
        ball.pos = {SCREEN_WIDTH / 2.0f, 0.0f};
        ball.vel = {3000.0f, 0.0f};
        ball.restitution = 0.7f;
        ball.radius = 20.0f;
        ball.mass = 5.0f;
        ball.colour = BLACK;


    // LOOP
    while (!WindowShouldClose()){

        float dt = GetFrameTime();


        // PHYSICS

        // Action of Gravity
        ball.vel.y += PPM * gravity.y * dt;
        ball.pos.x += ball.vel.x * dt;
        ball.pos.y += ball.vel.y * dt;

        // Collisions with walls
        if ((ball.pos.x + ball.radius) >= SCREEN_WIDTH){
            ball.pos.x = SCREEN_WIDTH - ball.radius;
            ball.vel.x *= -ball.restitution;
        }

        if ((ball.pos.x - ball.radius) <= 0){
            ball.pos.x = 0 + ball.radius;
            ball.vel.x *= -ball.restitution;
        }
        
        if ((ball.pos.y - ball.radius) <= 0){
            ball.pos.y = 0 + ball.radius;
            ball.vel.y *= -ball.restitution;
        }
        
        if ((ball.pos.y + ball.radius) >= SCREEN_HEIGHT){
            ball.pos.y = SCREEN_HEIGHT - ball.radius;
            ball.vel.y *= -ball.restitution;

            // Friction on the floor
            float frictionDecel = floor.friction * gravity.y * PPM * dt;
            if (fabsf(ball.vel.x) > frictionDecel){
                ball.vel.x -= frictionDecel * (ball.vel.x > 0 ? 1.0f : -1.0f);
            }
            else{
                ball.vel.x = 0;
            }
        }






        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircleV(ball.pos, ball.radius, ball.colour);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}