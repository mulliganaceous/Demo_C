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

/* Ratio */
const float SIDE = 1024.;
float r = 1;

/* Color mapping */
float colormap[7][3] = {{1.0f,0.0f,0.0f},
                        {233.f/255.f,61.f/255.f,105.f/255.f},
                        {61.f/255.f,233.f/255.f,87.f/255.f},
                        {61.f/255.f,174.f/255.f,233.f/255.f},
                        {232.f/255.f,203.f/255.f,45.f/255.f},
                        {233.f/255.f,120.f/255.f,61.f/255.f},
                        {192.f/255.f,61.f/255.f,192.f/255.f}};

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

    TuringMachine *busybeaver = new TuringMachine(instructions5);
    Tape *tape;
    std::cout << busybeaver->toString() << "\n";
    usleep(1000000);

    // OMG
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    int i = 0;
    int period = TAPESIZE/2;
    int fps = 2;
    int cooldowntimer = 2;
    int cooldown = 2;
    char loop = 1;
    int statechange = 0;

    int position = busybeaver->getSeq()*TAPESIZE + busybeaver->getPos();
    int cooldownendpoint1 = position;
    int cooldownendpoint2 = position;
    
    // Begin turing machine
    while (loop)
    {
        unsigned color = busybeaver->getColor();
        int state = busybeaver->getState();
        int increase = 0;
        if (state) {
            increase = busybeaver->getInstructionSet()->getWriteWith(busybeaver->getState(), color) != color;
        }
        else {
            loop = 0;
        }
        tape = busybeaver->getTape();

        // Draw a Red 1x1 Square centered at origin
        if ( (statechange || increase) || !cooldowntimer ) {
            // Turing machine
            std::cout << "\n" << "State   : " << busybeaver->getState() << " @ " << busybeaver->getColor() << ", Delta = " << busybeaver->getTransitionStr() << "\n" ;
            std::cout << "Position:" << std::setw(12) << position - TAPESIZE / 2 << " " ;
            std::cout << "[" << (int)(busybeaver->getMinseq()[0]*TAPESIZE + busybeaver->getMinseq()[1]) - TAPESIZE / 2<< ",";
            std::cout << (int)(busybeaver->getMaxseq()[0]*TAPESIZE + busybeaver->getMaxseq()[1]) - TAPESIZE / 2<< "]\n";
            std::cout << "Steps   :" << std::setw(12) << busybeaver->getSteps() << "\t" << "\n";
            std::cout << "Zero OW : " << busybeaver->getScore()[0] << ",\t";
            for (int k = 1; k < busybeaver->getInstructionSet()->getColors(); k++) {
                std::cout << "score #" << k << ": " << busybeaver->getScore()[k] << "[" << busybeaver->getBest()[k] << "]" << ",    ";
            } std::cout << "\n";

            glBegin(GL_QUADS);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            float s = 1.0f / period;
            for (TapeSegment *segment = tape->getLeftmost(); segment; segment = segment->getNext())
            {
                for (int pos = 0; pos < TAPESIZE; pos++)
                {
                    int k = ((period/TAPESIZE - 1)/2 + segment->getSeq())*TAPESIZE + pos;
                    char otherposition = segment->getSeq() != busybeaver->getSeq() || pos != busybeaver->getPos();
                    char scanposition = segment->getSeq()*TAPESIZE + pos;
                    if (cooldownendpoint1 > cooldownendpoint2) {
                        int temp = cooldownendpoint2;
                        cooldownendpoint2 = cooldownendpoint1;
                        cooldownendpoint1 = temp;
                        std::cout << cooldownendpoint1 << "-" << cooldownendpoint2 << "\n";
                    }
                    if (segment->getColor(pos) == 1 || !otherposition)
                    {
                        if (!otherposition || cooldownendpoint2 - cooldownendpoint1 >= 2 && cooldownendpoint1 <= scanposition && scanposition <= cooldownendpoint2) {
                            glColor3f(colormap[state][0], colormap[state][1], colormap[state][2]);
                        }
                        else {
                            glColor3f(1.0f, 1.0f, 1.0f);
                        }
                        if (true || s >= 2.0f/SIDE) {
                            glVertex2f(-1.f + k * s, 1.f - i * s/r); // x, y
                            glVertex2f(-1.f + (k + 1) * s, 1.f - i * s/r);
                            glVertex2f(-1.f + (k + 1) * s, 1.f - (i + 1) * s/r);
                            glVertex2f(-1.f + k * s, 1.f - (i + 1) * s/r);
                            if (!segment->getColor(pos)) {
                                glColor3f(0.f, 0.f, 0.f);
                                glVertex2f(-1.f + (k + 1.f/4) * s, 1.f - (i + 1.f/4)* s/r); // x, y
                                glVertex2f(-1.f + (k + 1 - 1.f/4) * s, 1.f - (i + 1.f/4)* s/r);
                                glVertex2f(-1.f + (k + 1 - 1.f/4) * s, 1.f - (i + 1 - 1.f/4) * s/r);
                                glVertex2f(-1.f + (k + 1.f/4) * s, 1.f - (i + 1 - 1.f/4) * s/r);
                            }
                        }
                        if (!otherposition && s < 2.0f/SIDE) {
                            if (!otherposition) {
                                glColor3f(colormap[state][0], colormap[state][1], colormap[state][2]);
                            }
                            else {
                                glColor3f(1.0f, 1.0f, 1.0f);
                            }
                            glVertex2f(-1.f + k * s, 1.f - i * s/r); // x, y
                            glVertex2f(-1.f + (k + 1) * s + 2.0f/SIDE, 1.f - i * s/r);
                            glVertex2f(-1.f + (k + 1) * s + 2.0f/SIDE, 1.f - (i + 1) * s/r + 2.0f/SIDE);
                            glVertex2f(-1.f + k * s, 1.f - (i + 1) * s/r + 2.0f/SIDE);
                        }
                    }
                }
            }
            s = 1.0f / TAPESIZE * 2;
            TapeSegment *segment = busybeaver->getSegment();
            for (int pos = 0; pos < TAPESIZE; pos++)
            {
                char otherposition = segment->getSeq() != busybeaver->getSeq() || pos != busybeaver->getPos();
                if (!otherposition) {
                    int colorindex = busybeaver->getState();
                    glColor3f(colormap[colorindex][0], colormap[colorindex][1], colormap[colorindex][2]);
                }
                else {
                    glColor3f(1.f, 1.f, 1.f);
                }
                glVertex2f(-1.f + pos * s, -1.f); // x, y
                glVertex2f(-1.f + (pos + 1) * s, -1.f);
                glVertex2f(-1.f + (pos + 1) * s, -1.f + s/r);
                glVertex2f(-1.f + pos * s, -1.f + s/r);

                if (segment->getColor(pos) == 0) {
                    glColor3f(0.f, 0.f, 0.f);
                    glVertex2f(-1.f + (pos + 1.f/16) * s, -1.f + s/16.0f/r); // x, y
                    glVertex2f(-1.f + (pos + 1 - 1.f/16) * s, -1.f + s/16.0f/r);
                    glVertex2f(-1.f + (pos + 1 - 1.f/16) * s, -1.f + (1 - 1.f/16)*s/r);
                    glVertex2f(-1.f + (pos + 1.f/16) * s, -1.f + (1 - 1.f/16)*s/r);
                }
            }
            cooldownendpoint1 = position;
            cooldownendpoint2 = position;
            if (true || busybeaver->getSteps() < 47176870 - TAPESIZE)
                usleep(1E6/fps);
            else
                usleep(1E6/4);
            
            glEnd();
            glFlush();
            cooldowntimer = cooldown;
        }
        else {
            cooldownendpoint2 = position;
            if (cooldowntimer > 0)
                cooldowntimer--;
            increase = 0;
            if (busybeaver->getSteps() % 65536 == 0) {
                // Turing machine
                std::cout << "\n" << "State   : " << busybeaver->getState() << " @ " << busybeaver->getColor() << ", Delta = " << busybeaver->getTransitionStr() << "\n" ;
                std::cout << "Position:" << std::setw(12) << (int)(busybeaver->getSeq()*TAPESIZE + busybeaver->getPos()) - TAPESIZE / 2 << " " ;
                std::cout << "[" << (int)(busybeaver->getMinseq()[0]*TAPESIZE + busybeaver->getMinseq()[1]) - TAPESIZE / 2<< ",";
                std::cout << (int)(busybeaver->getMaxseq()[0]*TAPESIZE + busybeaver->getMaxseq()[1]) - TAPESIZE / 2<< "]\n";
                std::cout << "Steps   :" << std::setw(12) << busybeaver->getSteps() << "\t" << "\n";
                std::cout << "Zero OW : " << busybeaver->getScore()[0] << ",\t";
                for (int k = 1; k < busybeaver->getInstructionSet()->getColors(); k++) {
                    std::cout << "score #" << k << ": " << busybeaver->getScore()[k] << "[" << busybeaver->getBest()[k] << "]" << ",    ";
                } std::cout << "\n";
            }
        }

        statechange = busybeaver->step() - state;
        position = busybeaver->getSeq()*TAPESIZE + busybeaver->getPos();        

        if (increase) {
            i += increase;
            i %= (int)(2*period*r*127/128);
            if (!i) {
                int seqdiff = busybeaver->getMaxseq()[0] - busybeaver->getMinseq()[0];

                if (seqdiff >= period/TAPESIZE || !seqdiff && busybeaver->getMaxseq()[1] - busybeaver->getMinseq()[1] < TAPESIZE*7/8) {
                    period *= 2;
                    if (fps < 65536)
                        fps *= 2;
                    else if (cooldown < 1000000000 && cooldown > 0) { 
                        cooldown = cooldown ? 2*(cooldown + 1)-1: 1;
                    }
                }

                glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
                glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
            }
        }

    }
    std::cout << "\nMachine halted\n";
    return;
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    glutInitWindowSize(SIDE, (int)(SIDE*r));   // Set the window's initial width & height
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("Busy Beaver game"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}