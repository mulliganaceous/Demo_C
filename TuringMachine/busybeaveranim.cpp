/*
 * GL01Hello.cpp: Test OpenGL/GLUT C/C++ Setup
 * Tested under Eclipse CDT with MinGW/Cygwin and CodeBlocks with MinGW
 * To compile with -lfreeglut -lglu32 -lopengl32
 * Version 0.0.1, by Mulliganaceous
 */
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include "busybeaver.cpp"
#include <unistd.h>
#include <iomanip>

#define COUNTDOWN1 5
#define COUNTDOWN2 5
#define INSTRUCTIONS instructions6
/* Ratio */
const int SIDE = 1024;
float r = 1;

/* Color mapping */
float colormap[7][3] = {{1.0f,0.0f,0.0f},
                        {233.f/255.f, 61.f/255.f,  105.f/255.f} /* red */,
                        { 61.f/255.f, 233.f/255.f,  87.f/255.f} /* green */,
                        { 61.f/255.f, 174.f/255.f, 233.f/255.f} /* blue */,
                        {232.f/255.f, 203.f/255.f,  45.f/255.f} /* yellow */,
                        {233.f/255.f, 93.f/255.f,  61.f/255.f} /* orange */,
                        {192.f/255.f, 61.f/255.f,  192.f/255.f} /* purple */};

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    // glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE);
    // glEnable(GL_BLEND);
    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    InstructionSet *instructions2 = new InstructionSet(2, 2);
    instructions2->setInstruction(1,0,1,+1,2);
    instructions2->setInstruction(1,1,1,-1,2);
    instructions2->setInstruction(2,0,1,-1,1);
    instructions2->setInstruction(2,1,1, 0,0);

    InstructionSet *instructions3 = new InstructionSet(3, 2);
    instructions3->setInstruction(1,0,1,+1,2);
    instructions3->setInstruction(1,1,1, 0,0);
    instructions3->setInstruction(2,0,1,-1,2);
    instructions3->setInstruction(2,1,0,+1,3);
    instructions3->setInstruction(3,0,1,-1,3);
    instructions3->setInstruction(3,1,1,-1,1);

    InstructionSet *instructions3s = new InstructionSet(3, 2);
    instructions3s->setInstruction(1,0,1,+1,2);
    instructions3s->setInstruction(1,1,1, 0,0);
    instructions3s->setInstruction(2,0,0,+1,3);
    instructions3s->setInstruction(2,1,1,+1,2);
    instructions3s->setInstruction(3,0,1,-1,3);
    instructions3s->setInstruction(3,1,1,-1,1);

    InstructionSet *instructions4 = new InstructionSet(4, 2);
    instructions4->setInstruction(1,0,1,+1,2);
    instructions4->setInstruction(1,1,1,-1,2);
    instructions4->setInstruction(2,0,1,-1,1);
    instructions4->setInstruction(2,1,0,-1,3);
    instructions4->setInstruction(3,0,1, 0,0);
    instructions4->setInstruction(3,1,1,-1,4);
    instructions4->setInstruction(4,0,1,+1,4);
    instructions4->setInstruction(4,1,0,+1,1);

    InstructionSet *instructions5 = new InstructionSet(5, 2);
    instructions5->setInstruction(1,0,1,-1,2);
    instructions5->setInstruction(1,1,1,+1,3);
    instructions5->setInstruction(2,0,1,-1,3);
    instructions5->setInstruction(2,1,1,-1,2);
    instructions5->setInstruction(3,0,1,-1,4);
    instructions5->setInstruction(3,1,0,+1,5);
    instructions5->setInstruction(4,0,1,+1,1);
    instructions5->setInstruction(4,1,1,+1,4);
    instructions5->setInstruction(5,0,1, 0,0);
    instructions5->setInstruction(5,1,0,+1,1);

    InstructionSet *instructions5s = new InstructionSet(5, 2);
    instructions5s->setInstruction(1,0,1,-1,2);
    instructions5s->setInstruction(1,1,1,-1,1);
    instructions5s->setInstruction(2,0,1,+1,3);
    instructions5s->setInstruction(2,1,1,+1,2);
    instructions5s->setInstruction(3,0,1,-1,1);
    instructions5s->setInstruction(3,1,1,+1,4);
    instructions5s->setInstruction(4,0,1,-1,1);
    instructions5s->setInstruction(4,1,1,+1,5);
    instructions5s->setInstruction(5,0,1, 0,0);
    instructions5s->setInstruction(5,1,0,+1,3);

    InstructionSet *instructions6 = new InstructionSet(6, 2);
    instructions6->setInstruction(1,0,1,+1,2);
    instructions6->setInstruction(1,1,0,-1,4);
    instructions6->setInstruction(2,0,1,+1,3);
    instructions6->setInstruction(2,1,0,+1,6);
    instructions6->setInstruction(3,0,1,-1,3);
    instructions6->setInstruction(3,1,1,-1,1);
    instructions6->setInstruction(4,0,0,-1,5);
    instructions6->setInstruction(4,1,1, 0,0);
    instructions6->setInstruction(5,0,1,-1,6);
    instructions6->setInstruction(5,1,0,+1,2);
    instructions6->setInstruction(6,0,0,+1,3);
    instructions6->setInstruction(6,1,0,+1,5);

    TuringMachine *busybeaver = new TuringMachine(INSTRUCTIONS);
    Tape *tape = busybeaver->getTape();
    std::cout << busybeaver->toString() << "\n";

    // OMG
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    int i = 0;
    int period = TAPESIZE/2;
    int fps = 1;
    long long cooldown = -1;
    long long cooldowntimer = cooldowntimer;
    char loop = 1;
    int statechange = 0;

    long long position = busybeaver->getSeq()*TAPESIZE + busybeaver->getPos();
    long long cooldownendpoint1 = position;
    long long cooldownendpoint2 = position;
    int offsetseq = busybeaver->getSeq();
    int offset = (period/TAPESIZE - 1)/2 ;

    for (int k = 0; k < COUNTDOWN2; k++) {
        std::cout << "\nCountdown in " << COUNTDOWN2 + COUNTDOWN1 - k << " s";
        usleep(1000000);
    }
    
    // Begin turing machine
    while (loop)
    {
        unsigned color = busybeaver->getColor();
        unsigned state = busybeaver->getState();
        int increase = 0;
        bool skip = false;
        bool whitelist = !busybeaver->getSteps();

        // Declare increase
        if (state) {
            increase = busybeaver->getInstructionSet()->getWriteWith(busybeaver->getState(), color) != color;
        }

        // Set up skips and whitelists
        if (period > 32) {
            skip = true;
            if (state == 4) {
                skip = false;
                whitelist = true;
            }
            if ((statechange || increase)) {
                if (cooldown != -1 || cooldown <= 256) {
                }
                else if (busybeaver->getSteps() % 65536 == 0) {
                    skip = false;
                }
            }
            if (whitelist) {
                increase = true;
            }
        }


        // Draw a Red 1x1 Square centered at origin
        if ( !skip && (statechange || increase) || !cooldowntimer || whitelist ) {
            // Turing machine
            std::cout << "\n[*]State: " << busybeaver->getState() << " @ " << busybeaver->getColor() << ", Delta = " << busybeaver->getTransitionStr() << "\n" ;
            std::cout << "Position: " << std::setw(12) << position - TAPESIZE / 2 << " " ;
            std::cout << "[" << (int)(busybeaver->getMinseq()[0]*TAPESIZE + busybeaver->getMinseq()[1]) - TAPESIZE / 2<< ",";
            std::cout << (int)(busybeaver->getMaxseq()[0]*TAPESIZE + busybeaver->getMaxseq()[1]) - TAPESIZE / 2<< "]\n";
            std::cout << "Steps   : " << std::setw(12) << busybeaver->getSteps() << "\t" << "\n";
            std::cout << "Erased  : " << std::setw(12) << busybeaver->getScore()[0] << ",\t";
            for (int k = 1; k < busybeaver->getInstructionSet()->getColors(); k++) {
                std::cout << "score #" << k << ": " << busybeaver->getScore()[k] << "[" << busybeaver->getBest()[k] << "]" << ",    ";
            }
            // Draw
            glBegin(GL_QUADS);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            float s = 1.0f / period;
            float sb = SIDE/TAPESIZE;
            if (true || period/SIDE/4 == 0 || i % (period/SIDE/4) == 0 || whitelist) {
                for (TapeSegment *segment = tape->getLeftmost(); segment; segment = segment->getNext()) {
                    int k = (-offset + segment->getSeq())*TAPESIZE - 1;
                    for (int pos = 0; pos < TAPESIZE && segment; pos++) {
                        // Determine position and cooled down colors
                        k++;
                        if (k < 0) {
                            continue;
                        }
                        char otherposition = segment->getSeq() != busybeaver->getSeq() || pos != busybeaver->getPos();
                        int scanposition = segment->getSeq()*TAPESIZE + pos;
                        int cooldownendpointL = cooldownendpoint1;
                        int cooldownendpointR = cooldownendpoint2;
                        if (cooldownendpointL > cooldownendpoint2) {
                            int temp = cooldownendpointR;
                            cooldownendpointR = cooldownendpointL;
                            cooldownendpointL = temp;
                        }
                        // Draw tile
                        bool incooldown = cooldownendpointR - cooldownendpointL >= 1 && cooldownendpointL <= scanposition && scanposition <= cooldownendpointR;
                        
                        // Set color
                        if (!otherposition) {
                            glColor3d(colormap[state][0], colormap[state][1], colormap[state][2]);
                        }
                        else if (incooldown) {
                            if (segment->getColor(pos))
                                glColor3d(colormap[state][0]/2. + 0.5, colormap[state][1]/2. + 0.5, colormap[state][2]/2. + 0.5);
                            else {
                                glColor3d(colormap[state][0]/4., colormap[state][1]/4., colormap[state][2]/4);
                            }
                        }
                        else if (segment->getColor(pos) == 1) {
                            glColor3d(1.0f, 1.0f, 1.0f);
                        }
                        else {
                            // Must be present to accommodate for multisampling.
                            glColor3d(0,0,0);
                        }

                        // Set whitelisted areas
                        if (segment->getSeq() < 4) {
                            whitelist = true;
                        }

                        // Draw tile
                        if (s < 1.0f/SIDE && whitelist) {
                            // Zoomed out or whitelist
                            glVertex2f(-1.f + k * s                  , 1.f - i * s/r); // x, y
                            glVertex2f(-1.f + (k + 1) * s + 2.0f/SIDE, 1.f - i * s/r);
                            glVertex2f(-1.f + (k + 1) * s + 2.0f/SIDE, 1.f - (i + 1) * s/r + 2.0f/SIDE);
                            glVertex2f(-1.f + k * s                  , 1.f - (i + 1) * s/r + 2.0f/SIDE);
                        }
                        else {
                            // Full resolution
                            glVertex2f(-1.f + k * s      , 1.f - i * s/r); // x, y
                            glVertex2f(-1.f + (k + 1) * s, 1.f - i * s/r);
                            glVertex2f(-1.f + (k + 1) * s, 1.f - (i + 1) * s/r);
                            glVertex2f(-1.f + k * s      , 1.f - (i + 1) * s/r);
                            // Draw hole
                            if (!segment->getColor(pos)) {
                                glColor3d(0.f, 0.f, 0.f);
                                glVertex2f(-1.f + (k + 1.f/4) * s, 1.f - (i + 1.f/4)* s/r); // x, y
                                glVertex2f(-1.f + (k + 1 - 1.f/4) * s, 1.f - (i + 1.f/4)* s/r);
                                glVertex2f(-1.f + (k + 1 - 1.f/4) * s, 1.f - (i + 1 - 1.f/4) * s/r);
                                glVertex2f(-1.f + (k + 1.f/4) * s, 1.f - (i + 1 - 1.f/4) * s/r);
                            }
                        }
                    }
                    // Break once printing is out of bounds
                    if (k*s > 2) {
                        segment = tape->getRightmost();
                    }
                }
            }

            // Print current tape
            s = 1.0f / TAPESIZE * 2;
            TapeSegment *segment = busybeaver->getSegment();
            for (int pos = 0; pos < TAPESIZE; pos++) {
                char otherposition = segment->getSeq() != busybeaver->getSeq() || pos != busybeaver->getPos();
                if (!otherposition) {
                    int colorindex = busybeaver->getState();
                    glColor3d(colormap[colorindex][0], colormap[colorindex][1], colormap[colorindex][2]);
                }
                else {
                    glColor3d(1.f, 1.f, 1.f);
                }
                glVertex2f(-1.f + pos * s, -1.f); // x, y
                glVertex2f(-1.f + (pos + 1) * s, -1.f);
                glVertex2f(-1.f + (pos + 1) * s, -1.f + s/r);
                glVertex2f(-1.f + pos * s, -1.f + s/r);
                if (segment->getColor(pos) == 0) {
                    glColor3d(0.f, 0.f, 0.f);
                    int kkk = !otherposition ? 4 : sb;
                    glVertex2f(-1.f + (pos + 1.f/kkk) * s, -1.f + s/kkk/r); // x, y
                    glVertex2f(-1.f + (pos + 1 - 1.f/kkk) * s, -1.f + s/kkk/r);
                    glVertex2f(-1.f + (pos + 1 - 1.f/kkk) * s, -1.f + (1 - 1.f/kkk)*s/r);
                    glVertex2f(-1.f + (pos + 1.f/kkk) * s, -1.f + (1 - 1.f/kkk)*s/r);
                }
            }
            
            glEnd();
            glFlush();

            // Countdown after draw, plus sleep
            if (statechange || increase)
                cooldownendpoint1 = position;
            cooldownendpoint2 = position;
            if (busybeaver->getSteps() == 0) {
                for (int k = 0; k < COUNTDOWN1; k++) {
                    std::cout << "\nCountdown in " << COUNTDOWN1 - k << " s";
                    usleep(1000000);
                }
            }
            else if (true || busybeaver->getSteps() < 47176870 - TAPESIZE)
                usleep(1E6/fps);
            else if (fps < 65536)
                usleep(1E6/4);
            cooldowntimer = cooldown;
        }
        else {
            // Cooled down steps
            cooldownendpoint2 = position;
            if (cooldowntimer > 0)
                cooldowntimer--;
            increase = 0;
            if (busybeaver->getSteps() % (2<<24) == 0) {
                // Turing machine
                std::cout << "\n" << "   State: " << busybeaver->getState() << " @ " << busybeaver->getColor() << ", Delta = " << busybeaver->getTransitionStr() << "\n" ;
                std::cout << "Position: " << std::setw(12) << (int)(busybeaver->getSeq()*TAPESIZE + busybeaver->getPos()) - TAPESIZE / 2 << " " ;
                std::cout << "[" << (int)(busybeaver->getMinseq()[0]*TAPESIZE + busybeaver->getMinseq()[1]) - TAPESIZE / 2<< ",";
                std::cout << (int)(busybeaver->getMaxseq()[0]*TAPESIZE + busybeaver->getMaxseq()[1]) - TAPESIZE / 2<< "]\n";
                std::cout << "Steps   : " << std::setw(12) << busybeaver->getSteps() << "\t" << "\n";
                std::cout << "Erased  : " << std::setw(12) << busybeaver->getScore()[0] << ",\t";
                for (int k = 1; k < busybeaver->getInstructionSet()->getColors(); k++) {
                    std::cout << "score #" << k << ": " << busybeaver->getScore()[k] << "[" << busybeaver->getBest()[k] << "]" << ",    ";
                }
            }
        }

        // Determine if view should be refreshed
        int seqdistance = offsetseq - busybeaver->getSeq();
        statechange = busybeaver->step() - state;
        position = busybeaver->getSeq()*TAPESIZE + busybeaver->getPos();        
        
        if (increase) {
            i += increase;
            i %= (int)(2*period*r*31/32);
            if (!i) {
                int seqdiff = busybeaver->getMaxseq()[0] - busybeaver->getMinseq()[0];
                offset = (0 - period/TAPESIZE)/4;
                if (seqdiff >= period/TAPESIZE || !seqdiff && busybeaver->getMaxseq()[1] - busybeaver->getMinseq()[1] < TAPESIZE*7/8) {
                    if (true) {
                        period *= 2;
                    }
                    if (fps < 65536) {
                        fps *= 2;
                    }
                }
                if (cooldown >= 0) { 
                    if (cooldown < 65536) {
                        cooldown = cooldown ? 2*(cooldown + 1)-1: 1;
                    }
                    else if (cooldown < 400000000) {
                        cooldown = cooldown ? 5*(cooldown + 1)-1: 1;
                    }
                }

                glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
                glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
                std::cout << "\n Resolution: " << period << ", FPS: " << fps << ", Cooldown: " << cooldown;
                i = 0;
            }
        }

        // End of while true loop
        loop = state;
    }

    std::cout << "\nMachine halted\n";
    usleep(5000000);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInitDisplayMode(GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(SIDE, (int)(SIDE*r));   // Set the window's initial width & height
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("Busy Beaver game"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}